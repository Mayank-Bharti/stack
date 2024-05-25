#include <iostream>
#include <cmath> // For the abs function
using namespace std;

bool predicate(long double mid, long double N) {
      if(mid<=N/mid){
        return true;
      }
      else{
        return false;
      }
}
int main() {
    long double N;
    cin >> N;
    long double l = 0;
    long double r = N;
    long double result = 0;

    while (l+1e-7<r) {
        long double mid = l + (r - l) / 2;
        if (predicate(mid, N)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout.precision(6); // Set precision for output
    cout << fixed << l << endl;

    return 0;
}
