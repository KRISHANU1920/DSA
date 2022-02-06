#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll power(int a, int b)
{
    // base case
    if(b == 0)
        return 1;
    if(b == 1)
        return a;

    // recursive call
    ll ans = power(a, b/2);

    if(b & 1)
        return a*ans*ans;
    else
        return ans*ans;
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << power(x, y) << endl;
    return 0;
}