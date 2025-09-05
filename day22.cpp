#include<bits/stdc++.h>
using namespace std;

int RepeatElement(vector<int> arr,int n,int k){
    unordered_map<int,int> mpp;
    for(auto it:arr){
        mpp[it]++;
    }
    for(auto it:arr){
        if(mpp[it]==k){
            return it;
        }
    }
    return -1;
}
int main(){
    vector<int> arr={1,1,1,1};
    int n=arr.size();
    int k=1;
    cout<<RepeatElement(arr,n,k);
    return 0; 
}