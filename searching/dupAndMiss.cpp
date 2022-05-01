// Question link : https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

// Approach 1: Linear Space Complexity

int *findTwoElement(int *arr, int n) {
    int temp[n+1] = {0};
    int *ans = new int [2];
    for(int i=0; i<n; i++)
        temp[arr[i]%(n+1)]++;
        
    for(int i=1; i<=n; i++)
    {
        if(temp[i]==2)
            ans[0] = i;
        if(temp[i]==0)
            ans[1] = i;
    }
    return ans;
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

*/


// Approach 2: Constant Space Complexity

int *findTwoElement(int *arr, int n) {
    int *ans = new int [2];
    
    // finding duplicate element
    for (int i = 0; i < n; i++) {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            ans[0] =  abs(arr[i]);
    }

    // finding missing element
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0)
            ans[1] = (i + 1);
    }
    return ans;
}

/*

Time Complexity: O(N)
Space Complexity: O(1)

*/