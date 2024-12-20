/*For any number n, write a program to list all the solutions of the equation x1 + x2 +
#x3 + ...+ xn = C, where C is a constant (C<=10) and x1, x2,x3,...,xn are nonnegative
#integers, using brute force strategy.*/

#include <iostream>
#include <vector>
using namespace std;
int c = 8;

void fun(vector<int> a, int n) {
    int s = 0;
    for (int i = 0; i < a.size(); i++) {
        s += a[i];
    }
    if (n == 1) {
        a.push_back(c - s);
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    } else {
        for (int i = 0; i <= c - s; i++) {
            a.push_back(i);
            fun(a, n - 1);
            a.pop_back();
        }
    }
}

int main() {
    int n = 3;
    vector<int> a;
    fun(a, n);
    return 0;
}
