#include <iostream>
#include <string>

using namespace std;

enum State {
    q0, qCarry, qWrite1, qAccept
};

void simulateTuringMachine(string &input) {
    State currentState = q0;
    int head = input.length() - 1;  // Start from the rightmost end of the binary number

    while (currentState != qAccept) {
        switch (currentState) {
            case q0:
                // Start from the last character and determine if we have a carry
                if (input[head] == '0') {
                    input[head] = '1';
                    currentState = qAccept;  // No carry needed, so accept
                } else if (input[head] == '1') {
                    input[head] = '0';  // Set to '0' and carry 1 to the next bit
                    currentState = qCarry;
                } else {
                    currentState = qAccept;
                }
                head--;
                break;

            case qCarry:
                // Move left to handle the carry
                if (head < 0) {
                    // We've reached the beginning of the string, so add a '1' to the start
                    input = "1" + input;
                    currentState = qAccept;
                } else if (input[head] == '0') {
                    input[head] = '1';  // Resolve the carry
                    currentState = qAccept;
                } else if (input[head] == '1') {
                    input[head] = '0';  // Keep the carry and move left
                }
                head--;
                break;

            default:
                currentState = qAccept;
                break;
        }
    }
}

int main() {
    string input;
    cout << "Enter a binary number: ";
    cin >> input;

    simulateTuringMachine(input);
    
    cout << "Incremented binary number: " << input << endl;

    return 0;
}
