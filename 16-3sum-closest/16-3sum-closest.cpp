class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int closest = nums[0]+nums[1]+nums[2];
        if(n>=3){
            sort(nums.begin(),nums.end());
            for(int i=0;i<n;i++){
                int rem=target-nums[i];
                int j=i+1;
                int k=n-1;
                while(j<k){
                    int sum=nums[j]+nums[k];
                    if(abs(rem-sum)<abs(target-closest)){
                        closest=sum+nums[i];
                    }
                    if(sum>rem){
                        k--;
                    }
                    else if(sum<rem){
                        j++;
                    }
                    else{
                        return target;
                    }
                }
            }
            return closest;    
        }
        else{
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=nums[i];
            }
            return sum;
        }
    }
};