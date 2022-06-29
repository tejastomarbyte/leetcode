class Solution {
public:
    void f(int &result,string s,int i)
    {
        result++;
        
        for(int j=i;j<s.length();j++)
        {
            if(j!=i && s[j]==s[i])continue;
            swap(s[i],s[j]);
            f(result,s,i+1);
            
        }
        
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        int result=-1;
        f(result,tiles,0);
        return result;
    }
};