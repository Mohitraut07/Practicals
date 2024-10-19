# Define the grammar as a dictionary
grammar = {
    'S': ['A B'],
    'A': ['a A', 'ε'],
    'B': ['b B', 'ε']
}

# First sets
first = {
    'S': {'a', 'b', 'ε'},
    'A': {'a', 'ε'},
    'B': {'b', 'ε'}
}

# Follow sets
follow = {
    'S': {'$'},  # $ is the end of input marker
    'A': {'b', '$'},
    'B': {'$'}
}

# Define parsing table
parsing_table = {
    ('S', 'a'): 'A B',
    ('S', 'b'): 'A B',
    ('S', '$'): None,  # Invalid state
    
    ('A', 'a'): 'a A',
    ('A', 'b'): 'ε',
    ('A', '$'): 'ε',
    
    ('B', 'b'): 'b B',
    ('B', '$'): 'ε',
}

# Parsing function
def parse_input(input_string, parsing_table, grammar):
    # Append end of input symbol ($)
    input_string += '$'
    
    # Initialize stack with start symbol and the end marker
    stack = ['$', 'S']
    
    # Initialize input pointer
    pointer = 0
    success = False

    print(f"{'Stack':<30}{'Input':<15}{'Action'}")
    print('-' * 60)

    # Parsing loop
    while len(stack) > 0:
        top = stack.pop()  # Get the top of the stack
        current_input = input_string[pointer]

        # Convert stack to a string to display properly
        print(f"{' '.join(stack):<30}{input_string[pointer:]:<15}", end='')

        if top == current_input:
            # Terminal matches
            print(f"Matched {current_input}")
            pointer += 1
            if top == '$':
                success = True
                break
        elif top in grammar:
            # Non-terminal: use parsing table
            rule = parsing_table.get((top, current_input))
            if rule is None:
                print(f"Error: No rule for {top} on {current_input}")
                return False

            print(f"Apply rule: {top} → {rule}")

            # Push production onto the stack (in reverse)
            if rule != 'ε':  # Don't push ε
                for symbol in reversed(rule.split()):
                    stack.append(symbol)
        else:
            # Terminal mismatch
            print(f"Error: Unexpected symbol {current_input}")
            return False
    
    if success:
        print("Input successfully parsed.")
        return True
    else:
        print("Error: Parsing failed.")
        return False

# Example usage
input_string = "aabb"
parse_input(input_string, parsing_table, grammar)
