#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

void toh(int n, int s, int mid, int e, vector<tuple<int, int, int>>& moves) {
    if (n == 0) {
        return;
    }
    toh(n-1, s, e, mid, moves);
    moves.push_back(make_tuple(n, s, e));
    toh(n-1, mid, s, e, moves);
}

int main() {
    int n;
    cin >> n;
    
    vector<tuple<int, int, int>> moves;
    toh(n, 1, 3, 2, moves);
    
    cout << "no of moves: "<<moves.size() << endl;
    for (int i = 0; i < moves.size(); ++i) {
        cout << get<0>(moves[i]) << " " << get<1>(moves[i]) << " " << get<2>(moves[i]) << endl;
    }
    
    return 0;
}
