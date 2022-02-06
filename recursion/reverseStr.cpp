// Approach 1: Using Two Pointers
#include <bits/stdc++.h>
using namespace std;

void reverse(string &str, int i, int j)
{
    // base case
    if(i > j)
        return;
        
    swap(str[i], str[j]);

    // recursive call
    reverse(str, i+1, j-1);
}

int main()
{
    string name;
    cin >> name;
    reverse(name, 0, name.size()-1);
    cout << name << endl;
    return 0;
}


// Approach 2: Using Single Pointer
#include <bits/stdc++.h>
using namespace std;

void reverse(string &str, int i)
{
    // base case
    if(i > str.size()-i-1)
        return;
        
    swap(str[i], str[str.size()-i-1]);

    // recursive call
    reverse(str, i+1);
}

int main()
{
    string name;
    cin >> name;
    reverse(name, 0);
    cout << name << endl;
    return 0;
}