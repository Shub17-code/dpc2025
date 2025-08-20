#include <bits/stdc++.h>
using namespace std;

void Subarray(vector<int> arr, int n) {
    unordered_map<int, vector<int>> mpp;
    int sum = 0;
    vector<pair<int,int>> ans; 
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == 0) ans.push_back({0, i});
        if (mpp.find(sum) != mpp.end()) {
            vector<int> v = mpp[sum];
            for (auto it : v) {
                ans.push_back({it + 1, i});
            }
        }
        mpp[sum].push_back(i);
    }
    cout << "The Subarrays are:\n";
    if (ans.empty()) {
        cout << "[ ]\n";
    } else {
        for (auto &p : ans) {
            cout << "[ " << p.first << " " << p.second << " ]\n";
        }
    }
}

int main() {
    vector<int> arr = {1,2,3,4};
    Subarray(arr, arr.size());
    return 0;
}
