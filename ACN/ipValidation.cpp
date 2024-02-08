#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Validation function
char ipClass(vector<int> ip)
{
    if (ip[0] >= 1 && ip[0] <= 126)
    {
        return 'A';
    }
    else if (ip[0] >= 127 && ip[0] <= 191)
    {
        return 'B';
    }
    else if (ip[0] >= 192 && ip[0] <= 223)
    {
        return 'C';
    }
    else if (ip[0] >= 224 && ip[0] <= 239)
    {
        return 'D';
    }
    else
    {
        return 'E';
    }
}

vector<int> splitIp(string s)
{
    vector<int> result;
    int pos = 0;

    while (s.length() >= pos)
    {
        pos = s.find(".");
        result.push_back(stoi(s.substr(0, pos)));
        s.erase(0, pos + 1);
    }
    return result;
}

// Driver code
int main()
{

    
    string ip;
    int size;
    cout << "Enter an IPv4 address: " << endl;
    cin >> ip;

    vector<int> ipSplit;

    // special addresses
    if (ip == "0.0.0.0" || ip == "127.0.0.1" || ip == "169.254.0.0" || ip == "224.0.0.0" || ip == "255.255.255.255")
    {
        cout << "Special IP Address found" << endl
             << "Pls add another IP.";

        return 0;
    }

    //'.' separated only
    for(int i=0;i<ip.length();i++){
        if(ip[i]>'0' && ip[i] <= '9' || ip[i] == '.'){
            continue;
        }
        else{
            cout << "Enter valid ip characters.";
            return 0;
        }

    }
    // No leading '0' check
    if(ip[0] == '0'){
        cout << "No leading zero allowed";
        return 0;
    }

    ipSplit = splitIp(ip);
    // 4 cells only
    if (ipSplit.size() != 4)
    {
        cout << "Invalid size of IP\n";
        return 0;
    }
    if (ipSplit[0] <= 0)
    {
        cout << "Given string is not valid IP\n";
        return 0;
    }

    for (int i = 0; i < ipSplit.size(); i++)
    {
        if (ipSplit[0] < 0 || ipSplit[i] > 255)
        {
            cout << "Invalid IP value" << ipSplit[i] << endl;
            return 0;
        }
    }

    cout << "Class of IP is :" << ipClass(ipSplit) << endl;
    return 0;
}