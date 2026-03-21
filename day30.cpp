#include<bits/stdc++.h>
using namespace std;

int minElementUntil(vector<int> &coins,int ind,int amount,vector<vector<int>> &dp){
    if(ind==0){
        if(amount%coins[0]==0){
            return amount/coins[0];
        }
        else{
            return 1e9;
        }
    }
    if(dp[ind][amount]!=-1){
        return dp[ind][amount];
    }
    int notTaken = minElementUntil(coins,ind-1,amount,dp);
    int taken=1e9;
    if(coins[ind]<=amount){
        taken = 1+ minElementUntil(coins,ind,amount-coins[ind],dp);
    }
    return dp[ind][amount] = min(taken,notTaken);
}
int minElement(vector<int> &coins,int amount){
    int n=coins.size();
    vector<vector<int>> dp(n,vector<int> (amount+1,-1));
    int ans=minElementUntil(coins,n-1,amount,dp);
    if(ans>=1e9) return -1;
    return ans;
}

//tabulation
int minElementTabulation(vector<int> &coins,int amount){
    int n=coins.size();
    vector<vector<int>> dp(n,vector<int> (amount+1,0));
    for(int i=0;i<=amount;i++){
        if(i%coins[0]==0){
            dp[0][i]= i/coins[0];
        }
        else{
            dp[0][i]= 1e9;
        }
    }
    for(int ind=1;ind<n;ind++){
        for(int target=0;target<=amount;target++){
            int notTaken = dp[ind-1][target];
            int taken=1e9;
            if(coins[ind]<=target){
                taken = 1+ dp[ind][target-coins[ind]];
            }
            dp[ind][target] = min(taken,notTaken);
        }
    }
    int ans=dp[n-1][amount];
    if(ans>=1e9) return -1;
    return ans;
}
int minElementSpace_optimization(vector<int> &coins,int amount){
    int n=coins.size();
    vector<int> prev(amount+1,0);
    vector<int> curr(amount+1,0);
    for(int i=0;i<=amount;i++){
        if(i%coins[0]==0){
            prev[i]= i/coins[0];
        }
        else{
            prev[i]= 1e9;
        }
    }
    for(int ind=1;ind<n;ind++){
        for(int target=0;target<=amount;target++){
            int notTaken = prev[target];
            int taken=1e9;
            if(coins[ind]<=target){
                taken = 1+ curr[target-coins[ind]];
            }
            curr[target] = min(taken,notTaken);
        }
        prev=curr;
    }
    int ans=prev[amount];
    if(ans>=1e9) return -1;
    return ans;
}
int main(){
    vector<int> coins = {1,2,5};
    int amount=11;
    cout<<minElement(coins,amount)<<endl;
    cout<<minElementTabulation(coins,amount)<<endl;
    cout<<minElementSpace_optimization(coins,amount)<<endl;
    return 0;
}