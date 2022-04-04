// { Driver Code Starts
// CPP program to find maximum sum
// by selecting a element from n arrays
#include<bits/stdc++.h>

using namespace std;

// To calculate maximum sum by
// selecting element from each array
int maximumSum( int n,int m, vector<vector<int>> &a);



// Driver program to test maximumSum
int main() {
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<vector<int>> arr(n, vector<int>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            cin>>arr[i][j];
            
        cout << maximumSum(n,m,arr)<<endl;
    
    }
    return 0;

}
// } Driver Code Ends


int maximumSum( int n,int m, vector<vector<int>> &a) {

    // Complete the function
    
    int sum=0,max_pre=INT_MIN,maxi;
    //max_pre stores the max element from the next row
    
    for(int i=n-1;i>=0;i--)
    {   maxi=INT_MIN; 
        if(i==n-1)
        {
            for(int j=0;j<m;j++)
            maxi=max(maxi,a[i][j]);
            max_pre=maxi;
            sum+=maxi;
        }
        else
        {
           for(int j=0;j<m;j++)
            {
                if(a[i][j]<max_pre && maxi<a[i][j]) // largest element in the array just smaller than the element selected from the net array
                 maxi=a[i][j];
            }
            if(maxi==INT_MIN)
              return 0;
            sum+=maxi;  
            max_pre=maxi;
        }
        
    }
    return sum;
}