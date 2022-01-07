#include <bits/stdc++.h>
using namespace std;

int modularExp(int x, int n, int m) {
	int res = 1;
    while( n > 0)
    {
        if( n & 1)
        {
            res = (1LL * res * (x % m))% m;
        }
        x = (1LL * (x % m) * (x % m)) % m;
        n = n >> 1;
    }
    return res;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << modularExp(a, b, 1000000007) << endl;
    return 0;
}

/* 

Time Complexity: O(Log2(N))
Space Complextiy: O(1)

*/