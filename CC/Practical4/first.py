# Function to compute FIRST of each variable
def compute_first(grammar):
    first = {}
    
    # Initialize FIRST sets as empty for all non-terminals
    for non_terminal in grammar:
        first[non_terminal] = set()
    
    # Helper function to find FIRST of a symbol
    def find_first(symbol):
        # If the symbol is a terminal, return it as a singleton set
        if not symbol.isupper():  # Terminals are lowercase or symbols (non-upper case)
            return {symbol}
        
        # If already computed, return the first set for the non-terminal
        if first[symbol]:
            return first[symbol]
        
        # Compute FIRST for this non-terminal
        for production in grammar[symbol]:
            # If the production starts with a terminal, add it to FIRST
            if production == 'ε':
                first[symbol].add('ε')  # Epsilon production
            else:
                for prod_symbol in production:
                    prod_first = find_first(prod_symbol)
                    first[symbol].update(prod_first - {'ε'})  # Add everything except epsilon
                    
                    # If the current symbol doesn't produce epsilon, stop
                    if 'ε' not in prod_first:
                        break
                else:
                    # If all symbols in the production can lead to epsilon, add epsilon
                    first[symbol].add('ε')
        
        return first[symbol]
    
    # Compute FIRST for all non-terminals
    for non_terminal in grammar:
        find_first(non_terminal)
    
    return first

# Example grammar
grammar = {
    'S': ['AB', 'bC'],
    'A': ['ε', 'a'],
    'B': ['b'],
    'C': ['c']
}

# Compute FIRST sets
first_sets = compute_first(grammar)
print("FIRST sets:")
for nt, f_set in first_sets.items():
    print(f"FIRST({nt}) = {{ {', '.join(f_set)} }}")
