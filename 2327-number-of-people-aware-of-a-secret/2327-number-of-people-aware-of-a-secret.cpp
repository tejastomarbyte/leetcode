class Solution {
public:
    const int mod=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        deque<int> q1,q2;
        q1.push_back(1);
        q2.push_back(1);
        int i=2;
        
        int ans=1,share=0;
        while(--n > 0)
        {
            if(q1.size()>=delay)
            {
                share=(share+q1.front())%mod;
                q1.pop_front();
            }
            if(q2.size()>=forget)
            {
                share=(mod+share-q2.front())%mod;
                q2.pop_front();
            }
            
            q1.push_back(share);           
            q2.push_back(share);

        }
        return (share+accumulate(begin(q1),end(q1),0LL))%mod;

    }
};