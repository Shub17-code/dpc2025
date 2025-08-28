#include<bits/stdc++.h>
using namespace std;

int DistinctKChar(string &s,int k){
    int n = s.size();
    int l=0,r=0;
    int cnt=0;
    unordered_map<char,int> mp; 
    while(r<n){
        mp[s[r]]++;
        while(mp.size()>k){
            mp[s[l]]--;
            if(mp[s[l]]==0){
                mp.erase(s[l]);
            }
            l++;
        }
        cnt+=r-l+1; 
        r++;
    }
    return cnt;
}
int substringCount(string &s,int k){
    int n=s.size();
    if(k<0) return 0;
    if(k>n) return 0;
    int lessthanK=DistinctKChar(s,k); 
    int lessthanK1=DistinctKChar(s,k-1); 
    return lessthanK - lessthanK1;
}
int main(){
    string s="pqpqs";
    int k=2;
    cout<<substringCount(s,k);
    return 0;
}