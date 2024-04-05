#include <bits/stdc++.h>
using namespace std;

void printUnion(const set<int>& S1, const set<int>& S2) {
    set<int> unionSet;
    
    for (const auto& element : S1) {
        unionSet.insert(element);
    }
    for (const auto& element : S2) {
        unionSet.insert(element);
    }
    
    cout << "Union Set: ";
    for (const auto& element : unionSet) {
        cout << element << " ";
    }
    cout << endl;
    

}

void printIntersection(const set<int>& S1, const set<int>& S2) {
    set<int> intersectionSet;

    for (const auto& element : S1) {
        if (S2.count(element) > 0) {
            intersectionSet.insert(element);
        }
    }
    
    cout << "Intersection Set: ";
    for (const auto& element : intersectionSet) {
        cout << element << " ";
    }
}
int main() {
    
    set<int> S1 = {1, 2, 3, 4, 5};
    set<int> S2 = {0, 1, 3, 6};
    
    printUnion(S1, S2);
    printIntersection(S1, S2);
    
    
    return 0;
}
