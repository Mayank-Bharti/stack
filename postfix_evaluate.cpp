#include <iostream>
#include <stack>
#include <sstream>
#include <cstring>

using namespace std;

int main() {
    char input[100];
    stack<int> s1;

    // Read the entire line of input
    cin.getline(input, 100);

    // Use a stringstream to handle spaces
    stringstream ss(input);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            // Convert token to integer and push to stack
            int x = stoi(token);
            s1.push(x);
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (s1.size() < 2) {
                
                return 1;
            }
            int operand2 = s1.top();
            s1.pop();
            int operand1 = s1.top();
            s1.pop();
            int result;

            if (token == "+") {
                result = operand1 + operand2;
            } else if (token == "-") {
                result = operand1 - operand2;
            } else if (token == "*") {
                result = operand1 * operand2;
            } else if (token == "/") {
                result = operand1 / operand2;
            }
            s1.push(result);
        } else {
            cout << token << endl;
            return 1;
        }
    }

    if (s1.size() != 1) {
        return 1;
    }

    cout << s1.top() << endl;
    return 0;
}
