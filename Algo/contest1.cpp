

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> arr(n, vector<char>(n));  // 2D array to store the beatmap
        vector<int> v;  // To store the columns with '#'

        // Input the beatmap
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> arr[i][j];
            }
        }

        // Process from bottom to top
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                if (arr[i][j] == '#') {
                    v.push_back(j + 1);  // Store 1-based index
                    // break;  // Only one '#' per row
                }
            }
        }

        // Output the result for this test case
        for (int i = 0; i < v.size(); ++i) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
