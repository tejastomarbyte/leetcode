// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int a[],int n)
{
//Your code here


      int total=0;
      for(int i=0;i<n;i++)
      total+=a[i];
      
      int current=0;
      
      for(int i=0;i<n;i++)
      {
          current+=(a[i]*i);
      }
      int maxi=current,sum;
      for(int i=1;i<n;i++)
      {
          sum=current-(total-a[i-1])+a[i-1]*(n-1);
          
          maxi=max(maxi,sum);
          
          current=sum;
          
      }
      return maxi;
}