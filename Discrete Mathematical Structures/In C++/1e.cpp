#include <bits/stdc++.h>
using namespace std;

set<int> complement(const set<int>& S1, const set<int>& universalSet) {
    set<int> complementSet;

    for (const auto& x : universalSet) {
        if (S1.count(x) == 0) {
            complementSet.insert(x);
        }
    }

    return complementSet;
}

int main() {
    set<int> universalSet, S1;
    int universalSetSize, S1Size;

    cout << "Enter the size of the universal set: ";
    cin >> universalSetSize;

    cout << "Enter the elements of the universal set(separated by spaces): ";
    for (int i = 0; i < universalSetSize; i++) {
        int element;
        cin >> element;
        universalSet.insert(element);
    }

    cout << "Enter the size of the set: ";
    cin >> S1Size;

    cout << "Enter the elements of the set(separated by spaces): ";
    for (int i = 0; i < S1Size; i++) {
        int element;
        cin >> element;
        S1.insert(element);
    }

    set<int> complementSet = complement(S1, universalSet);
    cout << "Complement Set: ";
    for (const auto& element : complementSet) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
