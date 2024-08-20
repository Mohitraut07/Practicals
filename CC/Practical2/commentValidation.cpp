#include<iostream>
using namespace std;
 

int main()
{
    string input;
    int end_idx;
    cout << "Enter the your input: " ;
    getline(cin,input,'\n');

    end_idx = input.size();

    if((input[0]=='/' && input[1]=='/') || ((input[0]=='/' && input[1]=='*') && (input[end_idx-1]=='/' && input[end_idx-2]=='*'))){
        cout << "Entered input is a COMMENT.";
    }
    else{
        cout << input << endl;
        cout << "Enter Valid COMMENT!!!";
    }
    return 0;
}