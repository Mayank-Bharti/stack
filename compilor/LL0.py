import queue

class Item:
    def __init__(self, lhs, rhs, dot_pos):
        self.lhs = lhs
        self.rhs = rhs
        self.dot_pos = dot_pos

    def __eq__(self, other):
        return (self.lhs, self.rhs, self.dot_pos) == (other.lhs, other.rhs, other.dot_pos)

    def __hash__(self):
        return hash((self.lhs, self.rhs, self.dot_pos))

    def __str__(self):
        return f"{self.lhs} -> {self.rhs[:self.dot_pos]}.{self.rhs[self.dot_pos:]}"

class State:
    def __init__(self, items):
        self.items = set(items)
        self.transitions = {}

    def __eq__(self, other):
        return self.items == other.items

    def __hash__(self):
        return hash(tuple(sorted(self.items)))

grammar = []

def read_grammar(filename):
    with open(filename, "r") as file:
        for line in file:
            grammar.append(line.strip())

def closure(items):
    closure_set = set(items)
    changed = True
    while changed:
        changed = False
        new_items = set()
        for item in closure_set:
            if item.dot_pos < len(item.rhs):
                symbol = item.rhs[item.dot_pos]
                for rule in grammar:
                    if rule[0] == symbol:
                        new_item = Item(symbol, rule[3:], 0)
                        if new_item not in closure_set:
                            new_items.add(new_item)
                            changed = True
        closure_set.update(new_items)
    return closure_set

def goto(state, symbol):
    next_items = {Item(item.lhs, item.rhs, item.dot_pos + 1) for item in state if item.dot_pos < len(item.rhs) and item.rhs[item.dot_pos] == symbol}
    return closure(next_items)

states = []

def construct_lr0():
    start_state = closure({Item("S'", "S", 0)})
    states.append(State(start_state))
    q = queue.Queue()
    q.put(states[0])

    while not q.empty():
        current_state = q.get()
        symbols = {item.rhs[item.dot_pos] for item in current_state.items if item.dot_pos < len(item.rhs)}

        for symbol in symbols:
            next_items = goto(current_state.items, symbol)
            if next_items:
                new_state = State(next_items)
                if new_state not in states:
                    states.append(new_state)
                    q.put(new_state)
                current_state.transitions[symbol] = states.index(new_state)

def print_dfa():
    for i, state in enumerate(states):
        print(f"State {i}:")
        for item in state.items:
            print(f"  {item}")
        for symbol, target in state.transitions.items():
            print(f"  On '{symbol}' -> State {target}")
        print()

read_grammar("C:\\Users\\Mayank bharti\\Downloads\\c++\\compilor\\demoLR0.txt")
construct_lr0()
print_dfa()