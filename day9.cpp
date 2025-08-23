#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string ans="";
    for(int i=0;i<strs[0].length();i++){
        char ch=strs[0][i];
        bool match=true;
        for(int j=0;j<strs.size();j++){
            if(strs[j].size()<i || ch!=strs[j][i]){
                match=false;
                break;
            }
        }
        if(match==false){
            break;
        }
        else{
            ans.push_back(ch);
        }
    }
    return ans;
}
int main(){
    vector<string> s={{"flower"},{"flow"},{"flight"}};
    int n= s.size();
    if(n==0) cout<<"";
	string ans = longestCommonPrefix(s);
    if(ans.size()==0) cout<<"";
    else cout<<ans;
    return 0;
}