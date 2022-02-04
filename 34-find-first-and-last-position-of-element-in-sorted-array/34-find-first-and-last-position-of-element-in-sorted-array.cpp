class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
       
        
        int i=0,j=a.size()-1,mini=-1,maxi=-1;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(a[mid]==target)
            {
                mini=mid;
                i=mid+1;
            }
            else if(a[mid]>target)
                j=mid-1;
            else
                i=mid+1;    
        }
        i=0;
        j=a.size()-1;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(a[mid]==target)
            {
                maxi=mid;
                j=mid-1;
            }
            else if(a[mid]>target)
                j=mid-1;
            else
                i=mid+1;    
        }
        vector<int> v;
        v.push_back(maxi);
        v.push_back(mini);
        return v;
           
        
    }
};