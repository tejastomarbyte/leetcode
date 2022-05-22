class Solution {
public:
    void moveZeroes(vector<int>& a) {
         vector<int>v;
         int count=0;
         for(auto it:a)
         {
             if(it)
                 v.push_back(it);
             else
                 count++;
         }
        
         for(int i=0;i<count;i++)v.push_back(0);
        
         for(int i=0;i<a.size();i++)
         {
             a[i]=v[i];
         }
            
            
        }
    
};