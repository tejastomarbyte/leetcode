class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        int sum1=0,sum2=0;
        for(auto it:a)
            sum1+=it;
        for(auto it:b)
            sum2+=it;
        int dif=(sum2-sum1)/2;
        int pos1=-1,pos2=-1;
        sort(b.begin(),b.end());
        for(int ii=0;ii<a.size();ii++)
        {
            int key=a[ii]+dif;
            int i=0,j=b.size()-1;
            while(i<=j)
            {
                int mid=i+(j-i)/2;
                if(b[mid]==key)
                {
                    pos2=b[mid];
                    break;
                }
                else if(b[mid]>key)
                    j=mid-1;
                else
                    i=mid+1;
            }
            if(pos2!=-1)
            {
               pos1=a[ii];
                break;
            }
                
        }
        return {pos1,pos2};
    }
};