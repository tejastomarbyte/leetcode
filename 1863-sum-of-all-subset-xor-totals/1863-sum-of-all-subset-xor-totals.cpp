class Solution {
public:
    int f(vector<int>&a,int i,int temp)
    {
        if(i==a.size())
        {
            return temp;
        }
        int sum1=f(a,i+1,temp^a[i]);
        int sum2=f(a,i+1,temp);
        return sum1+sum2;
    }
    int subsetXORSum(vector<int>& a) {
        int sum=0,temp=0;
        return f(a,0,temp);
;
    }
};