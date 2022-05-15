class Solution {
public:
     map<string, map<string, double>> g;
    vector<double> calcEquation(vector<vector<string>> &e, vector<double> &v, vector<vector<string>> &q)
    {
        build(e, v);
        vector<double> qres;
        unordered_map<string,int> visited;
        for (int i = 0; i < q.size(); i++)
        {
            string start = q[i][0];
            string end = q[i][1];
            if(g.find(start)==g.end()||g.find(end)==g.end())
                 qres.push_back(-1);
            else{
                 double res= dfs(start, end,visited);
                 qres.push_back(res==0?-1:res);
            }
        }
        return qres;
    }

    void build(vector<vector<string>> &e, vector<double> &v)
    {
        for (int i = 0; i < e.size(); i++)
        {
            string start = e[i][0];
            string end = e[i][1];
            double cost = v[i];
            g[start].insert({end, cost});
            g[end].insert({start, 1 / cost});
        }
    }

    double dfs(string start, string end,  unordered_map<string,int> visited)
    {
        if (start == end)
            return 1;
        visited[start]=1;
        for (auto nbr : g[start])
        {
            if (visited.find(nbr.first)==visited.end())
            {
                double cost = dfs(nbr.first, end,visited);
                if (cost != 0)
                {
                    return cost * nbr.second;
                }
            }
        }
        return 0;
    }
//     double dfs(unordered_map<string,vector<pair<string,double>>>&m,string src,string dest,unordered_map<string,int>vis)
//     {
//         vis[src]=1;
//         vector<pair<string,double>>temp=m[src];
//         for(int i=0;i<temp.size();i++)
//         {
//             if(temp[i].first==dest)
//             {
//                 return temp[i].second;
//             }
//         }
//         // double ans=1;
//         for(int i=0;i<temp.size();i++)
//         {
//                 double ans=dfs(m,temp[i].first,dest,vis);
//                 if(ans>0)
//                     return ans*temp[i].second;
            
//         }
//         // vis[src]=0;
//         return -1*1.0;
//     }
//     vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& qu)    {
//         unordered_map<string,vector<pair<string,double>>>m;
//         for(int i=0;i<eq.size();i++)
//         {
//             string a,b;
//             a=eq[i][0];
//             b=eq[i][1];
//             // cout<<1/val[i];
//             m[a].push_back({b,val[i]});
//             m[b].push_back({a,1/val[i]});
//         }
//         vector<double>v;
//         for(int i=0;i<qu.size();i++)
//         {
//             string a=qu[i][0],b=qu[i][1];
//             if(!m.count(a) || !m.count(b))
//             {
//                 v.push_back(-1*1.0);
//                 // continue;
//             }
//             else if(a==b)
//                 v.push_back(1.0);
            
//             else
//             {
//                 unordered_map<string,int>vis;
//                 double ans=dfs(m,a,b,vis);
//                 v.push_back(ans);
//             }
            
//         }
//         return v;
//     }
};