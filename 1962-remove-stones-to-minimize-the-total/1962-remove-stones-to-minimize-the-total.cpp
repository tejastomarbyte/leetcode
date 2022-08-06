class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>q;
        
        for(int i=0;i<piles.size();i++)
            q.push(piles[i]);
        
        while(k)
        {
            int temp=q.top();
            q.pop();
            
            if(temp%2)
            {
                q.push(temp/2+1);
            }
            else
                q.push(temp/2);
            k--;
        }
        
        int ans=0;
        while(!q.empty())
        {
            ans+=q.top();
            q.pop();
        }
        
        return ans;
    }
};