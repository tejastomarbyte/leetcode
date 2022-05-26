class Solution {
    private:
    bool isf(int mid,vector<int> & w,int days){
        int day=1;int ans=0;
        for(int i=0;i<w.size();i++){
            if(w[i]>mid) return false;
            else if(ans+w[i]>mid) {
                day++;
                ans=w[i];
            }
            else{
                ans+=w[i];
            }
        }return day<=days;
    }
public:
    int shipWithinDays(vector<int>& w, int days) {
        int i=*max_element(w.begin(),w.end());
        int j=accumulate(w.begin(),w.end(),0);
        int ans=j;
        while(i<=j){
            int mid=(i+j)/2;
            if(isf(mid,w,days)){
                ans=mid;
                j=mid-1;
            }else i=mid+1;
        }return ans;
    }

};