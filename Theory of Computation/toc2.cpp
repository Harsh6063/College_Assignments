#include <iostream>
#include <string>

using namespace std;

enum State {
    q0, q1, q2, q3, q4
};

bool accepts(const string& input) {
    State current_state = q0;
    
    for (char ch : input) {
        switch (current_state) {
            case q0:
                if (ch == '0') {
                    current_state = q0;
                } else if (ch == '1') {
                    current_state = q1;
                } else {
                    return false; // Invalid character
                }
                break;
            case q1:
                if (ch == '0') {
                    current_state = q1;
                } else if (ch == '1') {
                    current_state = q2;
                } else {
                    return false; // Invalid character
                }
                break;
            case q2:
                if (ch == '0') {
                    current_state = q2;
                } else if (ch == '1') {
                    current_state = q3;
                } else {
                    return false; // Invalid character
                }
                break;
            case q3:
                if (ch == '0') {
                    current_state = q3;
                } else if (ch == '1') {
                    current_state = q4;
                } else {
                    return false; // Invalid character
                }
                break;
            case q4:
                // Once in q4 (more than 3 `1`s), remain in q4
                break;
        }
    }
    
    // Accept if the final state is q2 or q3
    return current_state == q2 || current_state == q3;
}

int main() {
    string input;
    cout << "Enter a binary string: ";
    cin >> input;
    
    if (accepts(input)) {
        cout << "The string is accepted (contains exactly two or three 1s)." << endl;
    } else {
        cout << "The string is not accepted (contains other than exactly two or three 1s)." << endl;
    }
    
    return 0;
}

