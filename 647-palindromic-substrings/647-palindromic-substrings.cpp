class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length(),finans=0;
        for(int i=0;i<n;i++)
        {
            //for each i calculate the no. of palindromes with middle equal to s[i];
            
            int j=i-1,k=i+1;
            int ans=1;
            while(j>=0 && k<n)
            {
                if(s[j]==s[k])ans++;
                else 
                    break;
                j--,k++;
            }
            
            //now calculate no. of palindromes with s[i] && s[i-1] being middle elements
            
            j=i-1,k=i;
            while(j>=0 && k<n)
            {
                if(s[j]==s[k])ans++;
                else 
                    break;
                j--,k++;
            }
            finans+=ans;
        }
        return finans;
    }
};