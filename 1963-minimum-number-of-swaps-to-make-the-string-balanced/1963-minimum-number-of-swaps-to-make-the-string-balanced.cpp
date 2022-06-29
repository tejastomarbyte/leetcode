class Solution {
public:
    int minSwaps(string s) {
        int st=0,count=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='[')
                st++;
            else
            {
                if(st>0)
                    st--;
                else
                    count++;
                    
            }
        }
        return (count+1)/2;
    }
};