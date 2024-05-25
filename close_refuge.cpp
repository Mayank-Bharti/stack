#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int missingNumber(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int missing = 1; // Initialize the missing number to 1
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == missing) {
            missing++; // Increment the missing number if found in the array
        } else if (arr[i] > missing) {
            return missing; // If the missing number is greater than the current element, return it
        }
    }
    return missing; // Return the missing number if it's not found in the array
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << missingNumber(arr) << endl;

    return 0;
}
