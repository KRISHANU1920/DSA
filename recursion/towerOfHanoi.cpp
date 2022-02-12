// Question Link : 

void solve(int N, int from, int to, int aux, long long& count)
{
    // base case
    if(N == 1) {
        cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
        count++;
        return ;
    }
    // moves N-1 discs from source to auxillary peg
    solve(N-1, from, aux, to, count);
    
    // move Nth disc from source to destination peg
    cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
    count++;
    
    // moves N-1 discs from auxillary to destination peg
    solve(N-1, aux, to, from, count);
}

long long toh(int N, int from, int to, int aux) 
{    
    long long count = 0;
    solve(N, from, to , aux, count);
    return count;
}

/*

Time Complexity: O(2^N)
Space Complexity: O(N)

*/