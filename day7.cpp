#include<bits/stdc++.h>
using namespace std;

int TrappedWater(vector<int> &arr, int n) {
    int ans=0;
    vector<int> prefix(n);
    vector<int> suffix(n);
    prefix[0]=arr[0];
    suffix[n-1]=arr[n-1];
    for(int i=1;i<n;i++){
        prefix[i]=max(prefix[i-1],arr[i]);
    }
    for(int i=n-2;i>=0;i--){
        suffix[i]=max(suffix[i+1],arr[i]);
    }
    for(int i=0;i<n;i++){
        ans+=min(prefix[i],suffix[i])-arr[i];
    }
    return ans;
}

int main(){
    vector<int> arr={0,1,0,2,1,0,1,3,2,1,2,1};
    int n=arr.size();
    cout << "Trapped Water: "<<TrappedWater(arr,n);
}