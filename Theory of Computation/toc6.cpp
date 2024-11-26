#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Union of two languages
set<string> unionLanguages(const set<string>& L1, const set<string>& L2) {
    set<string> result = L1;
    result.insert(L2.begin(), L2.end());
    return result;
}

// Intersection of two languages
set<string> intersectionLanguages(const set<string>& L1, const set<string>& L2) {
    set<string> result;
    for (const string& word : L1) {
        if (L2.find(word) != L2.end()) {
            result.insert(word);
        }
    }
    return result;
}

// Concatenation of two languages
set<string> concatenateLanguages(const set<string>& L1, const set<string>& L2) {
    set<string> result;
    for (const string& word1 : L1) {
        for (const string& word2 : L2) {
            result.insert(word1 + word2);
        }
    }
    return result;
}

// Function to print the language set
void printLanguage(const set<string>& language) {
    for (const string& word : language) {
        cout << word << " ";
    }
    cout << endl;
}

// Function to input a language
set<string> inputLanguage() {
    set<string> language;
    int n;
    cout << "Enter the number of strings in the language: ";
    cin >> n;
    cout << "Enter the strings:\n";
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        language.insert(word);
    }
    return language;
}

int main() {
    cout << "Enter Language L1:" << endl;
    set<string> L1 = inputLanguage();

    cout << "Enter Language L2:" << endl;
    set<string> L2 = inputLanguage();

    // Display the input languages
    cout << "Language L1: ";
    printLanguage(L1);
    cout << "Language L2: ";
    printLanguage(L2);

    // Perform union
    set<string> unionResult = unionLanguages(L1, L2);
    cout << "Union of L1 and L2: ";
    printLanguage(unionResult);

    // Perform intersection
    set<string> intersectionResult = intersectionLanguages(L1, L2);
    cout << "Intersection of L1 and L2: ";
    printLanguage(intersectionResult);

    // Perform concatenation
    set<string> concatenationResult = concatenateLanguages(L1, L2);
    cout << "Concatenation of L1 and L2: ";
    printLanguage(concatenationResult);

    return 0;
}
