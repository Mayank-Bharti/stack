#include <bits/stdc++.h>
using namespace std;

map<char, set<char>> first, follow;
map<char, vector<string>> grammar;
map<pair<char, char>, string> parsingTable;
char startSymbol;
set<char> terminals, nonTerminals;

void computeFirst(char);
void computeFollow(char);
void constructParsingTable();
bool validateString(const string &);

void parseGrammar(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open file " << filename << endl;
        exit(1);
    }

    cout << "Reading input from file: " << filename << endl;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        cout << "Processing line: " << line << endl;
        char lhs = line[0];
        string rhs = line.substr(3);
        nonTerminals.insert(lhs);
        stringstream ss(rhs);
        string production;
        while (getline(ss, production, '|')) {
            grammar[lhs].push_back(production);
            cout << "Added rule: " << lhs << " -> " << production << endl;
            for (char ch : production)
                if (!isupper(ch) && ch != 'e')
                    terminals.insert(ch);
        }
    }
    file.close();
    startSymbol = *nonTerminals.begin();
    terminals.insert('$');
}

void computeFirst(char symbol) {
    if (!isupper(symbol)) {
        first[symbol].insert(symbol);
        return;
    }
    if (!first[symbol].empty()) return;

    for (const pair<const char, vector<string>> &entry : grammar) {
        char lhs = entry.first;
        const vector<string> &prods = entry.second;
        for (const auto &prod : prods) {
            bool nullable = true;
            for (char ch : prod) {
                computeFirst(ch);
                first[lhs].insert(first[ch].begin(), first[ch].end());
                if (first[ch].find('e') == first[ch].end()) {
                    nullable = false;
                    break;
                }
            }
            if (nullable)
                first[lhs].insert('e');
        }
    }
}

void computeFollow(char symbol) {
    if (symbol == startSymbol)
        follow[symbol].insert('$');

    for (const pair<const char, vector<string>> &entry : grammar) {
        char lhs = entry.first;
        const vector<string> &prods = entry.second;
        for (const auto &prod : prods) {
            for (size_t i = 0; i < prod.size(); i++) {
                if (prod[i] == symbol) {
                    bool nullable = true;
                    for (size_t j = i + 1; j < prod.size(); j++) {
                        for (char ch : first[prod[j]]) {
                            if (ch != 'e') follow[symbol].insert(ch);
                        }
                        if (first[prod[j]].find('e') == first[prod[j]].end()) {
                            nullable = false;
                            break;
                        }
                    }
                    if (nullable && lhs != symbol) {
                        computeFollow(lhs);
                        follow[symbol].insert(follow[lhs].begin(), follow[lhs].end());
                    }
                }
            }
        }
    }
}

void constructParsingTable() {
    for (const pair<const char, vector<string>> &entry : grammar) {
        char lhs = entry.first;
        const vector<string> &prods = entry.second;
        for (const auto &prod : prods) {
            set<char> firstSet;
            bool nullable = true;
            for (char ch : prod) {
                firstSet.insert(first[ch].begin(), first[ch].end());
                if (first[ch].find('e') == first[ch].end()) {
                    nullable = false;
                    break;
                }
            }
            for (char terminal : firstSet)
                if (terminal != 'e')
                    parsingTable[{lhs, terminal}] = prod;
            if (nullable)
                for (char terminal : follow[lhs])
                    parsingTable[{lhs, terminal}] = "e";
        }
    }
}

bool validateString(const string &input) {
    stack<char> stk;
    stk.push('$');
    stk.push(startSymbol);
    size_t index = 0;

    while (!stk.empty()) {
        char top = stk.top();
        stk.pop();

        cout << "Stack: ";
        stack<char> tempStack = stk;
        while (!tempStack.empty()) {
            cout << tempStack.top() << " ";
            tempStack.pop();
        }
        cout << " | Input: " << input.substr(index) << endl;

        if (top == input[index]) {
            index++;
        } else if (isupper(top)) {
            if (parsingTable.find({top, input[index]}) != parsingTable.end()) {
                string prod = parsingTable[{top, input[index]}];
                for (auto it = prod.rbegin(); it != prod.rend(); ++it)
                    if (*it != 'e')
                        stk.push(*it);
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    return index == input.size();
}

int main() {
    parseGrammar("C:\\Users\\Mayank bharti\\Downloads\\c++\\compilor\\demo.txt");

    for (char nt : nonTerminals)
        computeFirst(nt);
    for (char nt : nonTerminals)
        computeFollow(nt);
    constructParsingTable();

    cout << "\nFirst sets:\n";
    for (const pair<const char, set<char>> &entry : first) {
        char nt = entry.first;
        const set<char> &fset = entry.second;
        cout << nt << ": ";
        for (char ch : fset)
            cout << ch << " ";
        cout << endl;
    }

    cout << "\nFollow sets:\n";
    for (const pair<const char, set<char>> &entry : follow) {
        char nt = entry.first;
        const set<char> &fset = entry.second;
        cout << nt << ": ";
        for (char ch : fset)
            cout << ch << " ";
        cout << endl;
    }

    cout << "\nParsing Table:\n";
    for (const pair<const pair<char, char>, string> &entry : parsingTable) {
        pair<char, char> key = entry.first;
        string prod = entry.second;
        cout << key.first << ", " << key.second << " -> " << prod << endl;
    }

    cout << "\nEnter string to validate: ";
    string input;
    cin >> input;
    input += '$';

    if (validateString(input))
        cout << "String is accepted.\n";
    else
        cout << "String is rejected.\n";

    return 0;
}
