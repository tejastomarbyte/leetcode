class Solution {
public:
   

// int answer_dp(vector<int> &nums, vector<int> &multi, int i, int l, int r){

// 	if(i==multi.size())
// 		return 0;

// 	if(dp[l][i]!=-1)
// 		return dp[l][i];

// 	int first = multi[i]*nums[l] + answer_dp(nums, multi, i+1, l+1, r);
// 	int last = multi[i]*nums[r] + answer_dp(nums, multi, i+1, l, r-1);

// 	dp[l][i] = max(first, last);

// 	return dp[l][i];
// }
int maximumScore(vector<int>& v, vector<int>& m) {

	vector<vector<int>> dp(m.size()+1, vector<int>(m.size()+1));
        for(int i = 0; i < dp.size(); i++){
            dp[i][dp[0].size()-1] = 0;
            dp.back()[i] = 0;
        }
        for(int i = dp.size()-2; i >= 0; i--) {
            for(int j = dp[0].size()-2; j >=0; j--) {
                dp[i][j] = max(m[i]*v[j] + dp[i+1][j+1],
                                    m[i]*v[v.size()-1-(abs(i-j))] + dp[i+1][j]);
            }
        }
        return dp[0][0];
}
};