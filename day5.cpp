#include<bits/stdc++.h>
using namespace std;

vector<int> Leader(vector<int>& arr, int n){
	vector<int> ans;
	if(n == 0){
		return {};
	}
    if(n==1) return {arr[0]};
	ans.push_back(arr[n-1]);
    int maxi=INT_MIN;
	for(int i=n-2;i>=0;i--){
		if(arr[i] > maxi){
			ans.push_back(arr[i]);
		}
         maxi=max(maxi,arr[i]);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main(){
    vector<int> arr={7,10,4,10,6,5,2};
    vector<int> ans= Leader(arr,arr.size());
    cout << "The Leaders array is: " << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "  ";
    }
    return 0;
}