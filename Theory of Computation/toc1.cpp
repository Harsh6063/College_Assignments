#include <iostream>
#include <string>

using namespace std;

enum State {
    q0, q1, q2, q3
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
                    current_state = q0;
                } else if (ch == '1') {
                    current_state = q2;
                } else {
                    return false; // Invalid character
                }
                break;
            case q2:
                if (ch == '0') {
                    current_state = q0;
                } else if (ch == '1') {
                    current_state = q3;
                } else {
                    return false; // Invalid character
                }
                break;
            case q3:
                // Once in q3, remain in q3 regardless of input
                break;
        }
    }
    
    return current_state == q3;
}

int main() {
    string input;
    cout << "Enter a binary string: ";
    cin >> input;
    
    if (accepts(input)) {
        cout << "The string is accepted (contains three consecutive 1s)." << endl;
    } else {
        cout << "The string is not accepted (does not contain three consecutive 1s)." << endl;
    }
    
    return 0;
}

