#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array:" << endl;
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter values of the array in sorted order:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int l = -1;
    int r = n ;
    bool found = false;

    while (l +1< r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == mid) {
            cout << "Key is found using binary search at index " << mid << endl;
            found = true;
            break;
        } else if (arr[mid] < mid) {
            l = mid ;
        } else {
            r = mid ;
        }
    }

    if (!found) {
        cout << "Key not found in the array." << endl;
    }

    return 0;
}
