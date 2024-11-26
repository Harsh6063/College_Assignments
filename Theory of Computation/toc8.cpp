#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool simulatePDA(const string& input) {
    stack<char> pdaStack;
    int i = 0;
    int length = input.size();

    // Step 1: Push characters from the first half (w) onto the stack until we reach 'X'
    while (i < length && input[i] != 'X') {
        pdaStack.push(input[i]);
        i++;
    }

    // Step 2: Check if we have encountered 'X' as the middle separator
    if (i == length || input[i] != 'X') {
        return false; // Reject if no 'X' is found
    }
    i++; // Move past 'X'

    // Step 3: For the second half (w^R), pop characters from the stack to match
    while (i < length) {
        // If the stack is empty before finishing input, reject
        if (pdaStack.empty()) return false;

        char top = pdaStack.top();
        pdaStack.pop();

        // The character from the input should match the top of the stack
        if (input[i] != top) {
            return false; // Reject if characters don't match
        }
        i++;
    }

    // Accept if the stack is empty after reading the entire input
    return pdaStack.empty();
}

int main() {
    string input;
    cout << "Enter a string in the form wXw^R (e.g., abXba): ";
    cin >> input;

    if (simulatePDA(input)) {
        cout << "The string is accepted by the PDA." << endl;
    } else {
        cout << "The string is rejected by the PDA." << endl;
    }

    return 0;
}
