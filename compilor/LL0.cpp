#include <bits/stdc++.h>
using namespace std;

struct Item {
    string lhs, rhs;
    int dotPos;

    Item(string l, string r, int d) : lhs(l), rhs(r), dotPos(d) {}

    bool operator==(const Item &other) const {
        return lhs == other.lhs && rhs == other.rhs && dotPos == other.dotPos;
    }

    bool operator<(const Item &other) const {
        return tie(lhs, rhs, dotPos) < tie(other.lhs, other.rhs, other.dotPos);
    }

    string toString() const {
        return lhs + " -> " + rhs.substr(0, dotPos) + "." + rhs.substr(dotPos);
    }
};

struct State {
    set<Item> items;
    map<char, int> transitions;

    bool operator==(const State &other) const {
        return items == other.items;
    }
};

vector<string> grammar;
vector<State> states;

void readGrammar(const string &filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        grammar.push_back(line);
    }
    file.close();
}

set<Item> closure(set<Item> items) {
    set<Item> closureSet = items;
    bool changed;
    do {
        changed = false;
        set<Item> newItems;
        for (const Item &item : closureSet) {
            if (item.dotPos < item.rhs.length()) {
                char symbol = item.rhs[item.dotPos];
                for (const string &rule : grammar) {
                    if (rule[0] == symbol) {
                        string rhs = rule.substr(3);
                        Item newItem(string(1, symbol), rhs, 0);
                        if (closureSet.find(newItem) == closureSet.end()) {
                            newItems.insert(newItem);
                            changed = true;
                        }
                    }
                }
            }
        }
        closureSet.insert(newItems.begin(), newItems.end());
    } while (changed);
    return closureSet;
}

set<Item> gotoFunction(const set<Item> &state, char symbol) {
    set<Item> nextState;
    for (const Item &item : state) {
        if (item.dotPos < item.rhs.length() && item.rhs[item.dotPos] == symbol) {
            nextState.insert(Item(item.lhs, item.rhs, item.dotPos + 1));
        }
    }
    return closure(nextState);
}

void constructLR0() {
    set<Item> startState = closure({Item("S'", "S", 0)});
    states.push_back({startState, {}});

    queue<int> queue;
    queue.push(0);

    while (!queue.empty()) {
        int currentIndex = queue.front();
        queue.pop();

        set<char> symbols;
        for (const Item &item : states[currentIndex].items) {
            if (item.dotPos < item.rhs.length()) {
                symbols.insert(item.rhs[item.dotPos]);
            }
        }

        for (char symbol : symbols) {
            set<Item> nextStateItems = gotoFunction(states[currentIndex].items, symbol);
            if (!nextStateItems.empty()) {
                State nextState = {nextStateItems, {}};
                auto it = find(states.begin(), states.end(), nextState);
                int nextIndex;
                if (it == states.end()) {
                    states.push_back(nextState);
                    nextIndex = states.size() - 1;
                    queue.push(nextIndex);
                } else {
                    nextIndex = distance(states.begin(), it);
                }
                states[currentIndex].transitions[symbol] = nextIndex;
            }
        }
    }
}

void printDFA() {
    for (size_t i = 0; i < states.size(); i++) {
        cout << "State " << i << ":\n";
        for (const Item &item : states[i].items) {
            cout << "  " << item.toString() << "\n";
        }
        for (const auto &[symbol, nextIndex] : states[i].transitions) {
            cout << "  On '" << symbol << "' -> State " << nextIndex << "\n";
        }
        cout << "\n";
    }
}

int main() {
    readGrammar("C:\\Users\\Mayank bharti\\Downloads\\c++\\compilor\\demoLR0.txt");
    constructLR0();
    printDFA();
    return 0;
}