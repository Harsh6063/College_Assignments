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
                if (ch == 'a') {
                    current_state = q1;
                } else if (ch == 'b') {
                    current_state = q2;
                } else {
                    return false; // Invalid character
                }
                break;

            case q1:
                if (ch == 'a') {
                    current_state = q0;
                } else if (ch == 'b') {
                    current_state = q3;
                } else {
                    return false; // Invalid character
                }
                break;

            case q2:
                if (ch == 'a') {
                    current_state = q3;
                } else if (ch == 'b') {
                    current_state = q0;
                } else {
                    return false; // Invalid character
                }
                break;

            case q3:
                if (ch == 'a') {
                    current_state = q2;
                } else if (ch == 'b') {
                    current_state = q1;
                } else {
                    return false; // Invalid character
                }
                break;
        }
    }

    // Accept if the final state is q0 (both counts are even)
    return current_state == q0;
}

int main() {
    string input;
    cout << "Enter a string over {a, b}: ";
    cin >> input;

    if (accepts(input)) {
        cout << "The string is accepted (number of 'a's and 'b's are both even)." << endl;
    } else {
        cout << "The string is not accepted (number of 'a's and 'b's are not both even)." << endl;
    }

    return 0;
}

