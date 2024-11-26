#include <iostream>
#include <string>

using namespace std;

enum State {
    q0, checkB, checkC, reset, accept, reject
};

bool simulateTuringMachine(string &input) {
    State currentState = q0;
    int head = 0;

    while (currentState != accept && currentState != reject) {
        switch (currentState) {
            case q0:
                // Find and mark the first unmarked 'a'
                if (head < input.length() && input[head] == 'a') {
                    input[head] = 'X';  // Mark as processed
                    currentState = checkB;
                } else if (input[head] == 'Y' || input[head] == 'Z' || input[head] == '\0') {
                    // All characters are processed correctly
                    currentState = accept;
                } else {
                    currentState = reject;
                }
                head++;
                break;

            case checkB:
                // Find and mark the first unmarked 'b'
                while (head < input.length() && input[head] != 'b') head++;
                if (head < input.length() && input[head] == 'b') {
                    input[head] = 'Y';  // Mark as processed
                    currentState = checkC;
                } else {
                    currentState = reject;
                }
                head++;
                break;

            case checkC:
                // Find and mark the first unmarked 'c'
                while (head < input.length() && input[head] != 'c') head++;
                if (head < input.length() && input[head] == 'c') {
                    input[head] = 'Z';  // Mark as processed
                    currentState = reset;
                } else {
                    currentState = reject;
                }
                head++;
                break;

            case reset:
                // Move back to the start to find the next 'a'
                while (head >= 0 && input[head] != 'X') head--;
                currentState = q0;
                head++;
                break;

            default:
                currentState = reject;
                break;
        }
    }

    // Verify all 'a's, 'b's, and 'c's have been marked correctly
    for (char ch : input) {
        if (ch == 'a' || ch == 'b' || ch == 'c') {
            return false;  // Reject if any unmarked character is left
        }
    }

    return currentState == accept;
}

int main() {
    string input;
    cout << "Enter a string over {a, b, c} in the form a^n b^n c^n: ";
    cin >> input;

    if (simulateTuringMachine(input)) {
        cout << "The string is accepted (belongs to {a^n b^n c^n})." << endl;
    } else {
        cout << "The string is not accepted (does not belong to {a^n b^n c^n})." << endl;
    }

    return 0;
}
