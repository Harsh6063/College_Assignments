#include <bits/stdc++.h>
using namespace std;

void printPowerSet(const set<int>& S, set<int>& subset, const set<int>::iterator& index) {
    
    cout << "{ ";
    for (auto itr = subset.begin(); itr != subset.end(); itr++) {
        cout << *itr << " ";
    }
    cout << "}" << endl;

    for (auto i = index; i != S.end(); i++) {
        subset.insert(*i);
        printPowerSet(S, subset, next(i));
        subset.erase(*i);
    }
}

void generatePowerSet(const set<int>& S) {
    set<int> subset;
    auto index = S.begin();
    printPowerSet(S, subset, index);
}

int main() {
    set<int> S = {1, 2, 3, 3, 3, 4, 5, 2, 4};

    cout << "Power Set: " << endl;
    generatePowerSet(S);

    return 0;
}
