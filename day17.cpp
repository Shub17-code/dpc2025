#include<bits/stdc++.h>
using namespace std;

vector<int> countPrimes(int n){
    vector<int> Prime(n+1);
    for(int i=2;i<=n;i++){ 
        Prime[i]=1; 
    }
    for(int i=2;i<=n;i++){ 
        if(Prime[i]==1){ 
            for(int j=2*i;j<=n;j+=i){
                Prime[j]=0; 
            }
        }
    }
	vector<int> ans;
    for(int i=2;i<=n;i++){
        if(Prime[i]==1){
            while(n%i==0){
                n=n/i;
                ans.push_back(i);
            }
        }
    }
    return ans;
}
int main(){
    int n=123456;
    vector<int> ans=countPrimes(n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}