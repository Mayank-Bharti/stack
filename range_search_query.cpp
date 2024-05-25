#include <bits/stdc++.h>



using namespace std;


int lb_predicate(const vector<int>& arr, int q) {
    int l=-1,r=arr.size();
    while (l+1 < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] < q) {
            l = mid;
        } else {
            r = mid;
        }
    }
   
        return r;
    
}

int ub_predicate(const vector<int>& arr, int q) {
    int l = -1, r = arr.size();
    while (l+1 < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] <= q) {
            l = mid ;
        } else {
            r = mid;
        }
    }
    
        return l;
    
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    for (int i = 0; i < q; i++) {
        int l,r;
        cin >> l>>r;
        int first_occurrence = lb_predicate(arr, l);
        int last_occurrence = ub_predicate(arr, r);
        cout <<  last_occurrence - first_occurrence+1<<" ";
    }

    return 0;
}