#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &St, int num) {
    if (St.empty()) {
        St.push(num);
        return;
    }
    
    int n = St.top();
    St.pop();
    
    insertAtBottom(St, num);
    
    St.push(n);
}

void reverse(stack<int> &St) {
    if (St.empty()) {
        return;
    }
    int num = St.top();
    St.pop();

    reverse(St);
    
    insertAtBottom(St, num);
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reverse(s);

    cout << "Reversed stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
