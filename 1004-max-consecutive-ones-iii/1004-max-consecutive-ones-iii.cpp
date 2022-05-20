class Solution {
public:
    int longestOnes(vector<int>& n, int k) {
        int fin=0,count=0;
        int i=0,j=0;
        while(j<n.size())
        {
            
            if(n[j]==0)
            {
                count++;
                while(count>k && i<n.size())
                {
                    if(n[i]==0)
                        count--;
                    i++;
                }  
            }
            
            fin=max(j-i+1,fin);
            j++;
        }
        return fin;
    }
};