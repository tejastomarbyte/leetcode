// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdbool.h>


 // } Driver Code Ends
//User function Template for C

// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int a[], int size)
{
        
    // your code here
    int x=a[0],count=1;
    for(int i=1;i<size;i++)
    {
        if(a[i]==x)
        count++;
        else
        {
            if(count>1)
            count--;
            else
            x=a[i];
        }
    }
     
    int m=0;
    if(count>=1)
    {
        for(int i=0;i<size;i++)
        {
            if(x==a[i])
            m++;
        }
    }
    
    if(m>=(size/2+1))
    return x;
    return -1;
}

// { Driver Code Starts.

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        
        for(int i = 0;i<n;i++){
            scanf("%d", &arr[i]);
        }
        printf("%d\n", majorityElement(arr, n));
    }

    return 0;
}
  // } Driver Code Ends