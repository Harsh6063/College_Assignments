#include <bits/stdc++.h>
using namespace std;
void printCartesianSet(const set<int>& S1, const set<int>& S2) {
    
    cout << "Cartesian Product Sets: " << endl;
    
    for (const auto& x : S1) {
        for (const auto& y : S2) {
            cout << x << " " << y << endl;
        }
    }
    cout << endl;
    
}   

int main() {
    
    set<int> S1 = {1, 2, 3, 4, 5};
    set<int> S2 = {0, 1, 3, 6};
    
    printCartesianSet(S1,S2);
    
    return 0;
}
