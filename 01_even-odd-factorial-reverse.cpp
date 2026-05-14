/*
Problem: Basic Number Operations
Tasks:
1) Check if a number is even or odd.
2) Compute factorial of a number.
3) Reverse digits of a number.

Example:
n = 5 → Odd, factorial = 120
num = 123 → reverse = 321
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;

    // Even/Odd
    cout << (n % 2 == 0 ? "Even\n" : "Odd\n");

    // Factorial
    int fact = 1;
    for(int i = 1; i <= n; i++) fact *= i;
    cout << fact << endl;

    // Reverse number
    int num = 123, rev = 0;
    while(num) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    cout << rev;
}