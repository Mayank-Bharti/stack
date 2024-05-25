#include <bits/stdc++.h>
using namespace std;


long long int findMinDiff(vector<long long int>& arr, long long int n, long long int sum1, long long int sum2) {
    if (n == 0) {
        return abs(sum1 - sum2);
    }

   long long int include = findMinDiff(arr, n - 1, sum1 + arr[n - 1], sum2);
   long long int exclude = findMinDiff(arr, n - 1, sum1, sum2 + arr[n - 1]);

    return min(include, exclude);
}

int main() {
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << findMinDiff(arr, n, 0, 0) << endl;
    return 0;
}