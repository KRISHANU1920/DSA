//Link: https://www.spoj.com/problems/EKO/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int H[], int N, int M, int mid)
{
    long long sum = 0;
    for(int i=0; i<N; i++)
    {
        if(mid < H[i])
           sum += H[i] - mid;
    }
    if(sum >= M)
        return true;
    else
        return false;
}

int main()
{
    int N, M, maxi = INT_MIN;
    cin >> N >> M;
    int H[N];
    for(int i=0; i<N; i++) {
       cin >> H[i];
       if(maxi < H[i])
          maxi = H[i];
    }
    int low = 0, high = maxi, res = -1;
    while (low <= high)
    {
        int mid = low + (high - low)/2;
        if(isPossible(H, N, M, mid))
        {
            res = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << res << "\n";
    return 0;
}

/*

Time Complexity: O(NlogN)
Space Complexity: O(1)

*/