/*
Problem: GCD & LCM

Input:
a = 12, b = 18

Output:
GCD = 6, LCM = 36
*/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main(){
    int a=12,b=18;
    int g=gcd(a,b);
    int l=(a*b)/g;
    cout<<g<<" "<<l;
}