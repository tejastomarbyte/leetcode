//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        stack<int>st;
        int n=arr.size();
        int i=0;
        while(i<n)
        {
            if(st.empty() or (st.top()>=0 and arr[i]>=0 ) or (st.top()<0 and arr[i]<0))
            {
                st.push(arr[i]);
                
            }
            else
            st.pop();
            i++;
        }
        vector<int>a;
        while(!st.empty())
        {
            a.push_back(st.top());
            // cout<<st.top()<<" ";
            st.pop();
            
        }
        reverse(a.begin(),a.end());
        return a;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends