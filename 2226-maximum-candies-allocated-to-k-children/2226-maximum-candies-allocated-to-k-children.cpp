class Solution {
public:
   bool isPoss(int cur,vector<int>& arr, long long k){
    long long c = 0;
    for(int i = 0; i < arr.size(); i++){
        
		      c += (arr[i]/cur);
		
    }
    return (c < k?0:1);
}

int maximumCandies(vector<int>& arr, long long k) {
    int l = 1,h;
    for(int& x: arr)h = max(h,x);
    
    int ans = 0;
    while(l <= h){
        int m = l+(h-l)/2;
        if(isPoss(m,arr,k)){
            ans = m;
            l = m+1;
        }
        else h = m-1;
    }
    return ans;
}
};