#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <cctype>  // For isupper() and islower()

using namespace std;

map<char, set<char>> firstSet, followSet;
map<char, vector<string>> productions;
char startSymbol;

// Function prototypes
void computeFirst(char nonTerminal);
void computeFollow();
void readInput(istream &input);

int main() {
    ifstream file("C:\\Users\\Mayank bharti\\Downloads\\c++\\compilor\\demo.txt");

    if (file) {
        cout << "Reading input from file: demo.txt\n";
        readInput(file);  // Read from file
    } else {
        cout << "File not found! Enter grammar manually (end with EOF or Ctrl+Z):\n";
        readInput(cin);  // Read from standard input
    }

    file.close();

    // Compute First sets
    for (auto &p : productions) {
        computeFirst(p.first);
    }

    // Compute Follow sets
    computeFollow();

    // Print First sets
    cout << "\nFirst:\n";
    for (auto &p : firstSet) {
        cout << "Fr(" << p.first << ")={";
        bool first = true;
        for (char ch : p.second) {
            if (!first) cout << ", ";
            cout << (ch == 'e' ? "ϵ" : string(1, ch));
            first = false;
        }
        cout << "}" << endl;
    }

    // Print Follow sets
    cout << "\nFollow:\n";
    for (auto &p : followSet) {
        cout << "Fw(" << p.first << ")={";
        bool first = true;
        for (char ch : p.second) {
            if (!first) cout << ", ";
            cout << ch;
            first = false;
        }
        cout << "}" << endl;
    }

    return 0;
}

// Function to read input from file or standard input
void readInput(istream &input) {
    string line;
    bool firstLine = true;

    while (getline(input, line)) {
        if (line.empty()) continue;
        char nonTerminal = line[0];

        if (firstLine) {
            startSymbol = nonTerminal;  // Store start symbol
            firstLine = false;
        }

        string production = line.substr(3); // Skip "A->"
        stringstream ss(production);
        string rule;

        while (getline(ss, rule, '|')) {
            productions[nonTerminal].push_back(rule);
        }
    }
}

// Compute First set for a given non-terminal
void computeFirst(char nonTerminal) {
    if (!firstSet[nonTerminal].empty()) return;

    for (string rule : productions[nonTerminal]) {
        bool containsEpsilon = true;

        for (char symbol : rule) {
            if (islower(symbol)) {  // Terminal directly in First
                firstSet[nonTerminal].insert(symbol);
                containsEpsilon = false;
                break;
            } else if (symbol == 'e') {  // Rule has epsilon
                firstSet[nonTerminal].insert('e');
                containsEpsilon = true;
                break;
            } else if (isupper(symbol)) {  // Non-terminal: Add First(symbol)
                computeFirst(symbol);

                // Add everything except 'ϵ'
                for (char ch : firstSet[symbol]) {
                    if (ch != 'e') firstSet[nonTerminal].insert(ch);
                }

                // Stop if this symbol doesn't have epsilon
                if (firstSet[symbol].count('e') == 0) {
                    containsEpsilon = false;
                    break;
                }
            }
        }

        // If the whole rule can produce epsilon, add it
        if (containsEpsilon) {
            firstSet[nonTerminal].insert('e');
        }
    }
}

// Compute Follow sets for all non-terminals
void computeFollow() {
    followSet[startSymbol].insert('$'); // Add $ to Follow(startSymbol)

    bool changed = true;
    while (changed) {
        changed = false;
        for (auto &p : productions) {
            char lhs = p.first;
            for (string rule : p.second) {
                int len = rule.size();
                for (int i = 0; i < len; i++) {
                    char symbol = rule[i];

                    if (isupper(symbol)) { // Process only non-terminals
                        bool inheritFollow = false;

                        if (i + 1 < len) { // If there is a next symbol
                            char next = rule[i + 1];

                            if (islower(next)) { // If next is a terminal
                                if (followSet[symbol].insert(next).second) {
                                    changed = true;
                                }
                            } else { // If next is a non-terminal
                                for (char ch : firstSet[next]) {
                                    if (ch != 'e') { // Add all except epsilon
                                        if (followSet[symbol].insert(ch).second) {
                                            changed = true;
                                        }
                                    }
                                }
                                // If epsilon is in First(next), inherit Follow(lhs)
                                if (firstSet[next].count('e')) {
                                    inheritFollow = true;
                                }
                            }
                        } else {
                            inheritFollow = true;  // Last symbol: inherit Follow(lhs)
                        }

                        // If symbol should inherit Follow(lhs)
                        if (inheritFollow) {
                            for (char ch : followSet[lhs]) {
                                if (followSet[symbol].insert(ch).second) {
                                    changed = true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
