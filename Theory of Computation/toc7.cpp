#include <iostream>
#include <stack>
#include <string>

bool simulatePDA(const std::string& input) {
    std::stack<char> pdaStack;
    int i = 0;
    int length = input.size();

    // Step 1: Push 'a's onto the stack
    while (i < length && input[i] == 'a') {
        pdaStack.push('a');
        i++;
    }

    // Step 2: Pop 'a's from the stack for each 'b' in the input
    while (i < length && input[i] == 'b') {
        // If stack is empty before we finish reading 'b's, reject the input
        if (pdaStack.empty()) return false;
        pdaStack.pop();
        i++;
    }

    // Step 3: Check if the input is fully processed and the stack is empty
    return i == length && pdaStack.empty();
}

int main() {
    std::string input;
    std::cout << "Enter a string of the form a^n b^n: ";
    std::cin >> input;

    if (simulatePDA(input)) {
        std::cout << "The string is accepted by the PDA." << std::endl;
    } else {
        std::cout << "The string is rejected by the PDA." << std::endl;
    }

    return 0;
}
