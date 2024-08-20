#include<iostream>
using namespace std;

// Identifier Validation
 
int main()
{
    string input;
    cout << "Enter the your input: " ;
    getline(cin,input,'\n');

    string keyWord[] = {"new", "delete", "this", "true", "false", "null", "bool", "char", "int", "float", "double", "void", "signed", "unsigned", "short", "long", "if", "else", "switch", "case", "default", "while", "do", "for", "break", "continue", "return", "goto", "try", "catch", "throw", "const", "static", "virtual", "class", "struct", "union", "enum", "typedef", "template", "typename", "namespace", "using", "public", "protected", "private", "friend", "operator", "inline", "extern", "volatile", "mutable", "register", "explicit", "export", "asm", "sizeof", "typeid", "dynamic_cast", "static_cast", "const_cast", "reinterpret_cast", "true", "false", "null", "and", "and_eq", "bitand", "bitor", "compl", "not", "not_eq", "or", "or_eq", "xor", "xor_eq"};

    for(int i=0;i < 64 ;i++){
        if(input == keyWord[i]) cout << "INVALID IDENTIFIER";
        return -1;
    }


    cout << "VALID IDENTIFIER";

    return 0;
}