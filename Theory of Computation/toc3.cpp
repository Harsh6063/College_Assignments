#include <iostream>
#include <string>

using namespace std;

enum State {
    q0, q1, q2, q3, qAccept, qReject
};

bool accepts(const string& input) {
    if (input.length() < 4) {
        return false; // The string length must be at least 4
    }

    // Store the first two and last two characters
    char first_char = input[0];
    char second_char = input[1];
    char last_char_minus_one = input[input.length() - 2];
    char last_char = input[input.length() - 1];

    // Check if the first two characters match the last two characters
    if (first_char == last_char_minus_one && second_char == last_char) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string input;
    cout << "Enter a string over {a, b}: ";
    cin >> input;

    if (accepts(input)) {
        cout << "The string is accepted (first two characters are the same as the last two)." << endl;
    } else {
        cout << "The string is not accepted (first two characters are not the same as the last two)." << endl;
    }

    return 0;
}
