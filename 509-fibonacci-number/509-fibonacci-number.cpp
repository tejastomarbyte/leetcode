class Solution {
public:
    int fib(int n) {
        static int a[100]={0};
        if(n==0)
            return 0;
        else if(n==1)
            return 1;
        else if(a[n]!=0)
            return a[n]; 
        else 
        {
            a[n]=fib(n-1)+fib(n-2);
            return a[n];
        }
            
    }
};