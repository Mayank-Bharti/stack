#include <iostream>
#include <cmath>
#include <algorithm>
#include <chrono>


using namespace std;
using namespace std::chrono;


string addLeadingZeros(string str, int n) {
    for (int i = 0; i < n; i++) {
        str = "0" + str;
    }
    return str;
}

// Karatsuba algorithm for multiplication of large numbers
string karatsuba(string x, string y) {
    // Make the lengths of x and y equal
    int len = max(x.size(), y.size());
    if (x.size() < len) x = addLeadingZeros(x, len - x.size());
    if (y.size() < len) y = addLeadingZeros(y, len - y.size());

    // Base case: single-digit multiplication
    if (len == 1) {
        int prod = (x[0] - '0') * (y[0] - '0');
        return to_string(prod);
    }

    int m = len / 2;

    // Divide the input strings
    string x1 = x.substr(0, len - m);
    string x0 = x.substr(len - m);
    string y1 = y.substr(0, len - m);
    string y0 = y.substr(len - m);

    // Recursive multiplications
    string p1 = karatsuba(x1, y1);
    string p2 = karatsuba(x0, y0);
    string p3 = karatsuba(to_string(stoi(x1) + stoi(x0)), to_string(stoi(y1) + stoi(y0)));

    // P4 = P3 - P1 - P2
    string p4 = to_string(stoi(p3) - stoi(p1) - stoi(p2));

    // Combine the results
    string result = to_string(stoi(p1) * pow(10, 2 * m) + stoi(p4) * pow(10, m) + stoi(p2));

    return result;
}

int main() {
    string num1 = "12345";
    string num2 = "98765";

    // Measure time for Karatsuba multiplication
    auto start = high_resolution_clock::now();
    string karatsuba_result = karatsuba(num1, num2);
    auto end = high_resolution_clock::now();
    auto karatsuba_duration = duration_cast<microseconds>(end - start);
    cout << "Karatsuba Result: " << karatsuba_result << endl;
    cout << "Karatsuba Time: " << karatsuba_duration.count() << " microseconds" << endl;

    // Measure time for traditional multiplication
    start = high_resolution_clock::now();
    long long traditional_result = stoll(num1) * stoll(num2);
    end = high_resolution_clock::now();
    auto traditional_duration = duration_cast<microseconds>(end - start);
    cout << "Traditional Multiplication Result: " << traditional_result << endl;
    cout << "Traditional Time: " << traditional_duration.count() << " microseconds" << endl;

    return 0;
}