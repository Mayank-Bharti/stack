#include <bits/stdc++.h>
using namespace std;

bool predicate(int mid, vector<int>& arr) {
    if(arr[mid]>=arr[0]){
       return true;
     }
     else{
       return false;
     }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int l = 0, r = n-1;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        if (predicate(mid, arr)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << arr[r] << endl;
  
    return 0;
}
