#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    stack<int> s;
    int n, a;

    // Read the number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    // Push elements onto the stack
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a;
        s.push(a);
    }

    // Determine the middle index
    int mid = n / 2;
    vector<int> ans;

    // Remove elements until the middle element
    for (int i = 0; i < mid; i++) {
        ans.push_back(s.top());
        s.pop();
    }

    // Remove the middle element
    if (!s.empty()) {
        s.pop();
    }

    // Push the remaining elements back into the stack
    for (int i = ans.size() - 1; i >= 0; i--) {
        s.push(ans[i]);
    }

    // Print the remaining elements in the stack
    stack<int> tempStack;
    cout << "Elements in the stack after deleting the middle element: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        tempStack.push(s.top());
        s.pop();
    }
    cout << endl;

    // Restore the original stack state (optional)
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }

    return 0;
}
