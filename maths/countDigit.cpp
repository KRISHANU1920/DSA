#include <bits/stdc++.h>
using namespace std;

int countDig(int n)
{
    double res = 0;
    for(int i=2; i<=n; i++)
    {
        res += log10(i);
    }
    return floor(res)+1;
}
int main()
{
    int n;
    cin >> n;
    cout << countDig(n);
    return 0;
}