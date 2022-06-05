// Question Link : https://leetcode.com/problems/permutation-sequence/

// Naive Approach:  Using Recursion find all the permutations, then sort the list of permutations
//                 finally return the (K-1)th sequence from the list of permutations.




// Optimized approach: (TC-O(N^2) and SC-O(N))
string getPermutation(int n, int k) 
{
    string ans = "";
    vector<int> num;
    int fact = 1;
    
    for(int i=1; i<n; i++)
    {
        num.push_back(i);
        fact *= i;
    }
    
    num.push_back(n);
    k -= 1;
    
    while(1)
    {
        ans += to_string(num[k/fact]);
        num.erase(num.begin() + k/fact);
        
        if(num.size() == 0)
            break;
        
        k = k % fact;
        fact = fact/num.size();
    }
    return ans;
}