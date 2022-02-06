#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &str, int i, int j)
{
    // base case
    if(i > j)
        return true;

    if(str[i] != str[j])
        return false;

    // recursive call
    isPalindrome(str, i+1, j-1);
}

int main()
{
    string name;
    cin >> name;
    if(isPalindrome(name, 0, name.size()-1))
        cout << "It is Palindrome\n";
    else
        cout << "It is not Palindrome\n";
    return 0;
}