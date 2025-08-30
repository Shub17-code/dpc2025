#include<bits/stdc++.h>
using namespace std;

long long int gcd(long long int a,long long int b){
    while(b!=0){ 
        long long int rem=a%b;
        a=b;
        b=rem;
    }
    return a; 
}

long long int lcm(long long int a,long long int b){
    long long int g = gcd(a, b);
    return (a/g) *b; 
}
int main(){
    long long int a=123456;
    long long int b=789012;
    cout<<lcm(a,b)<<endl;
    return 0;
}