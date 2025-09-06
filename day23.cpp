#include <bits/stdc++.h>
using namespace std;

void fun(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> ans;
    int l = 0, maxi = 0;
    for (int r = 0; r < n; r++)
    {
        if (arr[r] > arr[maxi])
        {
            maxi = r;
        }
        while (r - l + 1 > k)
        {
            if (maxi == l)
            {
                maxi = l + 1;
            }
            l++;
        }
        if (arr[r] > arr[maxi])
        {
            maxi = r;
        }
        if (r - l + 1 == k)
            ans.push_back(arr[maxi]);
    }
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
}

int main()
{

    vector<int> arr = {7};
    int k = 1;
    fun(arr, k);
}