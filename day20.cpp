#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &s, int element)
{
    if (s.empty() || s.top() > element)
    {
        s.push(element);
        return;
    }
    int topElement = s.top();
    s.pop();
    sortedInsert(s, element);
    s.push(topElement);
}

void sortStack(stack<int> &stk)
{
    if (stk.empty() || stk.size() == 1)
        return;
    int topElement = stk.top();
    stk.pop();
    sortStack(stk);
    sortedInsert(stk, topElement);
}

int main()
{
    stack<int> stk;
    stk.push(-3);
    stk.push(3);
    stk.push(39);
    stk.push(16);
    stk.push(11);
    sortStack(stk);
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }

    return 0;
}