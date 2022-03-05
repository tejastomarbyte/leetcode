class Solution {
public:
    bool validPalindrome(string s) {
        bool check=1;
        int l=0;
        int r=s.length()-1;
     
        while(l<=r){
            if(s[l]==s[r]){
                l++;r--;
            }
            else{
    
                bool a=1;
                int i=l;
                int j=r-1;
                while(i<=j){
                    if(s[i]==s[j]){
                        i++;j--;
                    }
                    else{
                        a=0;
                        break;
                    }
                }
            
                bool b=1;
                i=l+1;
                j=r;
                while(i<=j){
                    if(s[i]==s[j]){
                        i++;j--;
                    }
                    else{
                        b=0;
                        break;
                    }
                }
                    return a||b;
            }
       
        }
        
        return true;
    
    }
};