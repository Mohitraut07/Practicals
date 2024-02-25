#include <iostream>
#include <string>
#include <vector>
using namespace std;

int binaryToDecimal(int num)
{
    int dec_value = 0;
    int base = 1;
    int temp = num;
    while (temp)
    {
        int last_digit = temp % 10;
        temp = temp / 10;
        dec_value += last_digit * base;
        base *= 2;
    }
    return dec_value;
}


void ipClassDetails(vector<int> ip)
{
    if (ip[0] >= 1 && ip[0] <= 126)
    {
        cout << "Class A" << endl;
        cout << "Subnet Mask: 255.0.0.0" << endl;
        cout << "Network Id: " << ip[0] << endl;
        cout << "Network Address: " << ip[0] << ".0.0.0" << endl;
        cout << "Host Id: " << ip[1] << '.' << ip[2] << '.' << ip[3] << endl;
        cout << "Host Address: " << ip[1] << '.' << ip[2] << '.' << ip[3] << '.' << "0" << endl;
        cout << "Starting Address: " << ip[0] << ".0.0.0" << endl;
        cout << "Last Address: " << ip[0] << ".255.255.255" << endl;
        cout << "Total Addresses: " << (256 - 0) * (256 - 0) * (256 - 0) << endl;
    }
    else if (ip[0] >= 127 && ip[0] <= 191)
    {
        cout << "Class B" << endl;
        cout << "Subnet Mask: 255.255.0.0" << endl;
        cout << "Network Id: " << ip[0] << "." << ip[1] << endl;
        cout << "Network Address: " << ip[0] << "." << ip[1] << ".0.0" << endl;
        cout << "Host Id: " << ip[2] << '.' << ip[3] << endl;
        cout << "Host Address: " << ip[2] << '.' << ip[3] << '.' << "0" << '.' << "0" << endl;
        cout << "Starting Address: " << ip[0] << "." << ip[1] << ".0.0" << endl;
        cout << "Last Address: " << ip[0] << "." << ip[1] << ".255.255" << endl;
        cout << "Total Addresses: " << (256 - 0) * (256 - 0) << endl;
    }
    else if (ip[0] >= 192 && ip[0] <= 223)
    {
        cout << "Class C" << endl;
        cout << "Subnet Mask: 255.255.255.0" << endl;
        cout << "Network Id: " << ip[0] << "." << ip[1] << "." << ip[2] << endl;
        cout << "Network Address: " << ip[0] << "." << ip[1] << "." << ip[2] << ".0" << endl;
        cout << "Host Id: " << ip[3] << endl;
        cout << "Host Address: " << ip[3] << '.' << '0' << '.' << "0" << '.' << "0" << endl;
        cout << "Starting Address: " << ip[0] << "." << ip[1] << "." << ip[2] << ".0" << endl;
        cout << "Last Address: " << ip[0] << "." << ip[1] << "." << ip[2] << ".255" << endl;
        cout << "Total Addresses: " << (256 - 0) << endl;
    }
    else if (ip[0] >= 224 && ip[0] <= 239)
    {
        cout << "Class D" << endl;
    }
    else
    {
        cout << "Class E" << endl;
    }
}

vector<string> ipSplit(string s)
{
    vector<string> result;
    int pos = 0;

    while (s.length() >= pos)
    {
        pos = s.find('.');
        result.push_back(s.substr(0, pos));
        s.erase(0, pos + 1);
    }
    return result;
}

int main()
{
    int choice;
    cout << "Enter the choice:" << endl;
    cin >> choice;

    string ip;
    vector<string> splitIp;
    vector<int> intIp;

    if (choice == 1)
    {

        int size;
        cout << "Enter an IPv4 address: " << endl;
        cin >> ip;

        // vector<string> splitip;

        //'.' separated only
        for (int i = 0; i < ip.length(); i++)
        {
            if (ip[i] == '1' || ip[i] == '0' || ip[i] == '.')
            {
                continue;
            }
            else
            {
                cout << "Enter valid IP characters.";
                return 0;
            }
        }

        splitIp = ipSplit(ip);
        for (string i : splitIp)
        {
            intIp.push_back(binaryToDecimal(stoi(i)));
        }

        // Leading '0' check
        if (to_string(intIp[0])[0] == '0')
        {
            cout << "No leading zero allowed";
            return 0;
        }

        for (int i : intIp)
        {
            cout << i << " ";
        }
        cout << endl;

        ipClassDetails(intIp);
    }
    if (choice == 2)
    {
        int size;
        cout << "Enter an IPv4 address with subnet mask address: " << endl;
        cin >> ip;

        int pos1 = ip.find('/');
        if (pos1 == string::npos)
        {
            cout << "Invalid input format. Please enter an IPv4 address with subnet mask separated by '/'.";
            return 0;
        }

        string ipAddr = ip.substr(0, pos1);
        string subnetMask = ip.substr(pos1 + 1);
        int sm = stoi(subnetMask);
        // cout << subnetMask << endl;
        string s;
        for (int i = 0; i < 32; i++)
        {
            if (i < sm)
            {
                s += '1';
            }
            else
            {
                s += '0';
            }
        }
        int pos2 = 0;
        vector<string> sresult;
        vector<int> maskadd;
        vector<int> maskadd1;

        // cout << s << endl; 
        while (s.length() >= pos2)
        {
            pos2 =0;
            pos2 += 8;
            sresult.push_back(s.substr(0, pos2));
            s.erase(0, pos2 );
        }

        for (int i = 0; i != 4; i++)
        {
            maskadd.push_back(stoi(sresult[i]));
            maskadd1.push_back(binaryToDecimal(maskadd[i]));
        }
        cout << "Masking value: " << endl;
        cout << maskadd1[0]<<'.'<<maskadd1[1] <<'.'<<maskadd1[2]<<'.'<<maskadd1[3] << endl;
    }
    return 0;
}
