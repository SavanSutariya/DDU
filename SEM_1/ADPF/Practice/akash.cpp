#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s, s1;
    int i;
    cin >> s;
    for (i = 0; i < s.size(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
        {
            s1[i] = s[i];
        }
        else
        {
            continue;
        }
    }
    cout<< s1.size();
    return 0;
}