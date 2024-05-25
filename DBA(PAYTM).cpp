#include <bits/stdc++.h>

using namespace std;


int lb_predicate(const vector<int>& arr, int q) {
    int l = -1, r = arr.size();
    while (l+1 < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] < q) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (arr[r] == q) {
        return r;
    }
    return -1;
}


int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < q; i++) {
        int query;
        cin >> query;
        int first_occurrence = lb_predicate(arr, query);
 
        cout <<  first_occurrence << endl;
    }

    return 0;
}

