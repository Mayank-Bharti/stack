import re
from collections import defaultdict, deque

class Grammar:
    def __init__(self, rules):
        self.productions = defaultdict(list)
        self.terminals = set()
        self.non_terminals = set()
        self.start_symbol = ''
        self.augmented_start = ''  # initialize first
        self._parse_rules(rules)
        self.augmented_start = self.start_symbol + "'"
        self.productions[self.augmented_start] = [self.start_symbol]
        self.non_terminals.add(self.augmented_start)


    def _parse_rules(self, rules):
        for rule in rules:
            lhs, rhs = rule.split("→")
            lhs = lhs.strip()
            rhs_alts = [alt.strip() for alt in rhs.strip().split('|')]

            if not self.start_symbol:
                self.start_symbol = lhs

            self.non_terminals.add(lhs)

            for alt in rhs_alts:
                self.productions[lhs].append(alt)
                for symbol in alt:
                    if not symbol.isupper() and symbol != 'ε':
                        self.terminals.add(symbol)
                    elif symbol.isupper():
                        self.non_terminals.add(symbol)

        # Augment the grammar
        self.productions[self.augmented_start] = [self.start_symbol]
        self.non_terminals.add(self.augmented_start)

    def is_terminal(self, symbol):
        return symbol in self.terminals

    def is_non_terminal(self, symbol):
        return symbol in self.non_terminals

class LR0Parser:
    def __init__(self, grammar):
        self.grammar = grammar
        self.states = []
        self.state_map = {}
        self.goto_table = defaultdict(dict)
        self.action_table = defaultdict(dict)
        self._build_dfa()

    def closure(self, items):
        closure_set = set(items)
        added = True
        while added:
            added = False
            new_items = set()
            for head, body, dot_pos in closure_set:
                if dot_pos < len(body):
                    symbol = body[dot_pos]
                    if self.grammar.is_non_terminal(symbol):
                        for prod in self.grammar.productions[symbol]:
                            item = (symbol, prod, 0)
                            if item not in closure_set:
                                new_items.add(item)
                                added = True
            closure_set.update(new_items)
        return frozenset(closure_set)

    def goto(self, state, symbol):
        moved_items = set()
        for head, body, dot in state:
            if dot < len(body) and body[dot] == symbol:
                moved_items.add((head, body, dot + 1))
        return self.closure(moved_items) if moved_items else frozenset()

    def _build_dfa(self):
        start_item = (self.grammar.augmented_start, self.grammar.productions[self.grammar.augmented_start][0], 0)
        start_state = self.closure([start_item])

        queue = deque([start_state])
        self.state_map[start_state] = 0
        self.states.append(start_state)

        while queue:
            current = queue.popleft()
            idx = self.state_map[current]

            symbols = set()
            for head, body, dot in current:
                if dot < len(body):
                    symbols.add(body[dot])

            for sym in symbols:
                next_state = self.goto(current, sym)
                if next_state not in self.state_map:
                    self.state_map[next_state] = len(self.states)
                    self.states.append(next_state)
                    queue.append(next_state)
                self.goto_table[idx][sym] = self.state_map[next_state]

        self._build_parsing_table()

    def _build_parsing_table(self):
        for idx, state in enumerate(self.states):
            for item in state:
                head, body, dot = item
                if dot < len(body):
                    sym = body[dot]
                    if self.grammar.is_terminal(sym):
                        to_state = self.goto_table[idx][sym]
                        if self.action_table[idx].get(sym):
                            self.action_table[idx][sym] = 'conflict'
                        else:
                            self.action_table[idx][sym] = f'shift {to_state}'
                else:
                    if head == self.grammar.augmented_start:
                        self.action_table[idx]['$'] = 'accept'
                    else:
                        for term in self.grammar.terminals.union({'$'}):
                            prod = f'{head} → {body}'
                            if self.action_table[idx].get(term):
                                self.action_table[idx][term] = 'conflict'
                            else:
                                self.action_table[idx][term] = f'reduce {prod}'

            for nt in self.grammar.non_terminals:
                if nt in self.goto_table[idx]:
                    self.action_table[idx][nt] = f'goto {self.goto_table[idx][nt]}'

    def print_dfa(self):
        print("\nDFA States (Closure Items):")
        for i, state in enumerate(self.states):
            print(f"\nState {i}:")
            for head, body, dot in state:
                before = body[:dot]
                after = body[dot:]
                print(f"  {head} → {before}.{after}")

    def print_parsing_table(self):
        print("\nParsing Table:")
        headers = list(self.grammar.terminals) + ['$'] + list(self.grammar.non_terminals - {self.grammar.augmented_start})
        print(f"{'State':<10}" + "".join(f"{h:<15}" for h in headers))
        for i in range(len(self.states)):
            row = f"{i:<10}"
            for h in headers:
                row += f"{self.action_table[i].get(h, ''):<15}"
            print(row)

    def parser_type(self):
        for actions in self.action_table.values():
            for act in actions.values():
                if act == 'conflict':
                    return "Not LR(0) — Might be SLR(1) or needs LR(1)"
        return "Grammar is LR(0)"

# Example run on the first grammar
if __name__ == "__main__":
    grammar_input = [
        "S → A",
        "A → aA | b"
    ]

    grammar = Grammar(grammar_input)
    parser = LR0Parser(grammar)

    print("\n=== Bottom-up Parser Type ===")
    print(parser.parser_type())

    parser.print_dfa()
    parser.print_parsing_table()
