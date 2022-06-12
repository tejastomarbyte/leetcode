class Solution {
public:
    vector<int> singleNumber(vector<int>& a) {
        long long int x=a[0],n=a.size();
        for(int i=1;i<n;i++)
        {
            x=x^a[i];
        }
        //x stores a^b
        
        long long int p=(x&(x-1))^x; //to find the last bit where a differs from b
        int b=0,c=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]&p) b^=a[i];
            else
                c^=a[i];
        }
        return vector<int>{b,c};
    }
};