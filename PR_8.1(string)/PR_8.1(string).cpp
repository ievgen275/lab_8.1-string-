#include <iostream>
#include <string>
using namespace std;

int Count(const string s)
{
    int k = 0;
    size_t pos = 0;
    while ((pos = s.find("SQ", pos)) != string::npos || (pos = s.find("QS", pos)) != string::npos)
    {
        k++;
        pos += 2;
    }
    return k;
}

string Change(string& s)
{
    size_t pos = 0;
    while (true)
    {
        size_t posSQ = s.find("SQ", pos);
        size_t posQS = s.find("QS", pos);
        if (posSQ == string::npos && posQS == string::npos) break;
        if (posSQ != string::npos && (posQS == string::npos || posSQ < posQS))
        {
            s.replace(posSQ, 2, "***"); 
            pos = posSQ + 3;
        }
        else if (posQS != string::npos && (posSQ == string::npos || posQS < posSQ))
        {
            s.replace(posQS, 2, "***"); 
            pos = posQS + 3;
        }
    }
    return s;
}


int main()
{
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);
    cout << "String contained " << Count(str) << " groups of 'SQ' or 'QS'" << endl;
    string dest = Change(str);
    cout << "Modified string (result): " << dest << endl;
    return 0;
}
