#include<bits/stdc++.h>
using namespace std;

//memoization
double fibo(int n,vector<double> &dp){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
}
double fiboTabulation(int n){
    vector<double> dp(n+1,0);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
double fiboSpace_optimization(int n){
    if(n==0) return 0;
    double prev2=0;
    double prev1=1;
    for(int i=2;i<=n;i++){
        double curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
int main(){
    int n=1000;
    vector<double> dp(n+1,-1);
    cout<<fibo(n,dp)<<endl;
    cout<<fiboTabulation(n)<<endl;
    cout<<fiboSpace_optimization(n)<<endl;
    return 0; 
}