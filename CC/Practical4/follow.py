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

# Function to compute FOLLOW of each variable
def compute_follow(grammar, start_symbol):
    # First we need the FIRST sets
    first = compute_first(grammar)
    
    follow = {}
    
    # Initialize FOLLOW sets as empty for all non-terminals
    for non_terminal in grammar:
        follow[non_terminal] = set()
    
    # Start symbol gets the end of input symbol ($)
    follow[start_symbol].add('$')
    
    # A flag to check if something has changed in FOLLOW sets
    updated = True
    
    while updated:
        updated = False
        # Iterate over each production rule A -> α
        for A in grammar:
            for production in grammar[A]:
                trailer = follow[A].copy()  # Initially, the trailer is FOLLOW(A)
                
                # Process the production in reverse order
                for i in range(len(production) - 1, -1, -1):
                    B = production[i]
                    
                    if B.isupper():  # If B is a non-terminal
                        # Add trailer to FOLLOW(B)
                        if trailer.difference(follow[B]):
                            follow[B].update(trailer)
                            updated = True
                        
                        # Update trailer
                        if 'ε' in first[B]:
                            trailer.update(first[B] - {'ε'})
                        else:
                            trailer = first[B]
                    else:
                        # If B is a terminal, reset trailer to {B}
                        trailer = {B}
    
    return follow

# Example grammar
grammar = {
    'S': ['AB', 'bC'],
    'A': ['ε', 'a'],
    'B': ['b'],
    'C': ['c']
}

# Compute FOLLOW sets
start_symbol = 'S'
follow_sets = compute_follow(grammar, start_symbol)

# Print FOLLOW sets
print("\nFOLLOW sets:")
for nt, f_set in follow_sets.items():
    print(f"FOLLOW({nt}) = {{ {', '.join(f_set)} }}")
