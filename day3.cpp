#include <bits/stdc++.h>
using namespace std;

int duplicateNumber(vector<int>&a, int n) {

    int sum = (n * (n + 1)) / 2;

    int s2 = 0;
    for (int i = 0; i <a.size() ; i++) {
        s2 += a[i];
    }
    int duplicate=s2-sum;
    return duplicate;
} 

int main()
{
    int n = 4;
    vector<int> a = {3,1,3,4,2};
    int ans = duplicateNumber(a, n);
    cout << "The duplicate number is: " << ans << endl;
    return 0;
}
