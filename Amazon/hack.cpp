#include <bits/stdc++.h>
using namespace std;

int getMaxPeople(int q, vector<int>& people, vector<char>& status) {
    unordered_set<int> inside;  // to track who is currently inside
    int maxCount = 0;

    for (int i = 0; i < q; i++) {
        int person = people[i];
        if (status[i] == '+') {
            inside.insert(person);
        } else {
            // If the person is not in the set, it means invalid exit
            if (inside.find(person) == inside.end()) {
                return -1;
            }
            inside.erase(person);
        }
        maxCount = max(maxCount, (int)inside.size());
    }
    return maxCount;
}

int main() {
    int q;
    cin >> q;

    vector<int> people(q);
    vector<char> status(q);

    for (int i = 0; i < q; i++) {
        cin >> people[i];
    }

    cout << "Input only + and -" << endl;
    for (int i = 0; i < q; i++) {
        cin >> status[i];
    }

    int result = getMaxPeople(q, people, status);
    cout << result << endl;

    return 0;
}
