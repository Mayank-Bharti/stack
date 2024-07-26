#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool predicate(long double mid, long long sum) {
     if(mid<=sum/mid){
        return true;
      }
      else{
        return false;
      }
}

bool canBuildSquare(long long sum) {
    long double l = 0;
    long double r = sum;
    long double result = 0;

    while (l+1e-7<r) {
        long double mid = l + (r - l) / 2;
        if (predicate(mid, sum)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout.precision(6); // Set precision for output
    //cout << fixed << l << endl;
    long long side = static_cast<long long>(round(l));
    //cout<<side<<endl;
    return (side * side == sum);
}

int main() {
    long long  t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        vector<long long> arr(n); 
        long long sum = 0;

        // Read the array elements and calculate the sum
        for (long long  i = 0; i < n; ++i) {
            cin >> arr[i];
            sum += arr[i];
        }
        //cout<<"sum is:"<<sum<<endl;
        if (canBuildSquare(sum)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
