class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {

        int m=matrix.size(), n=matrix[0].size(), count=0, sum=0;
        vector<vector<int>> prefixSum(m, vector<int>(n,0));
        unordered_map<int, int> mp;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i==0 && j==0) prefixSum[i][j] = matrix[0][0];
                else if(i==0) prefixSum[i][j] = matrix[i][j] + prefixSum[i][j-1];
                else if(j==0) prefixSum[i][j] = matrix[i][j] + prefixSum[i-1][j];
                else {
                    prefixSum[i][j] = matrix[i][j] + prefixSum[i][j-1] + prefixSum[i-1][j] - prefixSum[i-1][j-1];
                }
            }
        }
        
        for(int i=0; i<m; i++) {
            for(int j=i; j<m; j++) {
                mp.clear();
                mp[0]=1;
                
                for(int k=0; k<n; k++) {
                    sum = prefixSum[j][k];
                    if(i>0) {
                        sum -= prefixSum[i-1][k];
                    }
                    
                    count += mp[sum-target]; //if sum-target is not present in mp then the value is zero
                    mp[sum]++;
                }
            }
        }
        
        
        return count;
    }
};