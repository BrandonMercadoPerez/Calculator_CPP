#include <iostream>
using namespace std;

int main() {
    int number = 0;
    int input = 1;
    char op = 0;

    int previous[10] = {0};
    int history = 0;
    const int maxHistory = 10;

    while (input) {
        // Prompt user for operator input
        while (true) {
            cout << "Current Number: " << number << endl;
            cout << "Enter an operation (+, -, *, /, ?) or 0 to quit: ";
            cin >> op;

            if (op == '+' || op == '-' || op == '*' || op == '/' || op == '?' || op == '0') {
                break;
            } else {
                cout << "Invalid input. Please use (+, -, *, /, ?)." << endl;
                cin.clear();
                cin.ignore(1024, '\n');
            }
        }

        if (op == '0') {
            break; // Exit the loop
        }

        if (op == '+' || op == '-' || op == '*' || op == '/') {
            cout << "Enter a number: ";
            cin >> input;

            if (cin.fail()) {
                cout << "Invalid number. Try again." << endl;
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }

            cin.ignore(1000, '\n');

            // Update history
            for (int i = maxHistory - 1; i > 0; --i) {
                previous[i] = previous[i - 1];
            }
            previous[0] = number;
            
            // Perform the operation
            switch (op) {
                case '+':
                    number += input;
                    break;
                case '-':
                    number -= input;
                    break;
                case '*':
                    number *= input;
                    break;
                case '/':
                    if (input != 0) {
                        number /= input;
                    } else {
                        cout << "Cannot divide by zero." << endl;
                        continue;
                    }
                    break;
            }

            // Track history length
            history = min(history + 1, maxHistory);
        } else if (op == '?') {
            if (history > 0) {
                number = previous[0];
                for (int i = 0; i < maxHistory - 1; ++i) {
                    previous[i] = previous[i + 1];
                }
                history--;
            } else {
                cout << "No values left in history." << endl;
            }
        }
    }

    cout << "Final Value: " << number << endl;
    return 0;
}

// End of code