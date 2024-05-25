#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> vec(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> vec[i][j];
        }
    }

    for (int i = 0; i < q; ++i) {
        int target;
        cin >> target;

        int l = -1, r = n * m;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            int element = vec[mid / m][mid % m];
            if (element < target) {
                l = mid;
            } else {
                r = mid;
            }
        }

        if (r < n * m && vec[r / m][r % m] == target) {
            cout << r / m << " " << r % m << "\n";
        } else {
            cout << -1 << " " << -1 << "\n";
        }
    }

    return 0;
}
