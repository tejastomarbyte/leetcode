// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    
    void f(int a[],string v[],vector<string>&ans,string s,int n,int i)
    {
        
        if(i>=n)
        {
            ans.push_back(s);
            return;
        }
        
        int p=a[i];
        string x=v[p];
        for(int j=0;j<x.length();j++)
        {
            s.push_back(x[j]);
            f(a,v,ans,s,n,i+1);
            s.pop_back();
        }
    }
    vector<string> possibleWords(int a[], int n)
    {
        //Your code here
        string v[10]={
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
        };
        vector<string> ans;
        string s="";
        int i=0;
        f(a,v,ans,s,n,i);
        return ans;
        
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends