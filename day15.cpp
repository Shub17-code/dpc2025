#include <bits/stdc++.h>
using namespace std;

int fun(string &s)
{
    int n = s.size();
    unordered_map<char, int> mpp;
    int ans = 0;
    int l = 0;
    for (int r = 0; r < n; r++)
    {
        mpp[s[r]]++;
        while (mpp[s[r]] > 1)
        {
            mpp[s[l]]--;
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}

int main()
{

    string s;
    s = "abcabcbb";
    cout << fun(s)<<endl; 
}