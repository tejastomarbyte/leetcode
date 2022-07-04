class RangeFreqQuery {
public:
    vector<int>t;
    map<int,vector<int>>m;
    RangeFreqQuery(vector<int>& arr) {
        t=arr;
        for(int i=0;i<t.size();i++)
        {
            m[arr[i]].push_back(i);
        }
    }
    
int query(int left, int right, int val) {
    return upper_bound(m[val].begin(),m[val].end(),right)-lower_bound(m[val].begin(),m[val].end(),left);
        
         
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */