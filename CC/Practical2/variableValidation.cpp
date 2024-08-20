#include <iostream>
#include <string>
using namespace std;

int validateVariableName(string input)
{

    string keyWord[] = {"new", "delete", "this", "true", "false", "null", "bool", "char", "int", "float", "double", "void", "signed", "unsigned", "short", "long", "if", "else", "switch", "case", "default", "while", "do", "for", "break", "continue", "return", "goto", "try", "catch", "throw", "const", "static", "virtual", "class", "struct", "union", "enum", "typedef", "template", "typename", "namespace", "using", "public", "protected", "private", "friend", "operator", "inline", "extern", "volatile", "mutable", "register", "explicit", "export", "asm", "sizeof", "typeid", "dynamic_cast", "static_cast", "const_cast", "reinterpret_cast", "true", "false", "null", "and", "and_eq", "bitand", "bitor", "compl", "not", "not_eq", "or", "or_eq", "xor", "xor_eq"};

    if ((input[0] >= '0' && input[0] <= 9) || (input.length() > 31))
    {
        return 0;
    }

    if (!((input[0] >= 'a' && input[0] <= 'z') || (input[0] >= 'A' && input[0] <= 'Z') || (input[0] == '_')))
        return 0;

    for (int i = 0; i < 64; i++)
    {
        if (input == keyWord[i])
            return 0;
    }

    for (int i = 1; i < input.length(); i++)
    {
        if (input[i] == ' ')
            return 0;

        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] == '_'))
            continue;
        else if ((input[i] >= '0' && input[i] <= 9))
            continue;
        else
            return 0;
    }
    return 1;
}

int main()
{
    char input[100];
    cout << "INPUT VARIABLE NAME: ";
    cin.getline(input, 100, '\n');
    if (validateVariableName(input))
        cout << "Variable name is Valid!!";
    else
        cout << "Variable name is Invalid!!";
    return 0;
}