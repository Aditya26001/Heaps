//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long solve(long long A[],long long k , long long n){
        priority_queue<long long>maxh;
        
        for(int i=0;i<n;i++){
            maxh.push(A[i]);
            if(maxh.size()>k) maxh.pop();
        }
        
        return maxh.top();
    }
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        long long first = solve(A,K1,N);
        long long second = solve(A,K2,N);
        
        long long ans = 0;
        for(int i=0;i<N;i++){
            if(A[i]>first && A[i]<second){
                ans+=A[i];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends