#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>&a, int n) {

    int sum = (n * (n + 1)) / 2;

    int s2 = 0;
    for (int i = 0; i < n - 1; i++) {
        s2 += a[i];
    }

    int missingNum = sum - s2;
    return missingNum;
} 

int main()
{
    int n = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, n);
    cout << "The missing number is: " << ans << endl;
    return 0;
}
