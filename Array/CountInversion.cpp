// Question Link : https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

long long int merge(long long arr[], long long int left, long long int mid, long long int right)
{
    long long int len1 = mid-left+1;
    long long int len2 = right-mid;
    long long int i, inv_count = 0;
    
    // create temp arrays
    long long int *first = new long long int [len1];
    long long int *second = new long long int [len2];

    // copy values to temp arrays
    long long int mainInd = left;
    for(i=0; i<len1; i++)
        first[i] = arr[mainInd++];
    mainInd = mid+1;
    for(i=0; i<len2; i++)
        second[i] = arr[mainInd++];

    // merge two sorted arrays
    mainInd = left;
    long long int ind1=0, ind2=0;
    while(ind1<len1 && ind2<len2)
    {
        if(first[ind1] <= second[ind2])
            arr[mainInd++] = first[ind1++];
        else {
            arr[mainInd++] = second[ind2++];
            inv_count += (len1-ind1);
        }
    }
    while(ind1 < len1)
        arr[mainInd++] = first[ind1++];
    while(ind2 < len2)
        arr[mainInd++] = second[ind2++];
    
    delete [] first;
    delete [] second;
    
    return inv_count;
}

long long int mergeSort(long long arr[], long long int left, long long int right)
{
    long long int inv_count = 0;
    if(left < right)
    {
        long long int mid = left + (right - left)/2;
        // Sorting left side of array
        inv_count += mergeSort(arr, left, mid);
        // Sorting right side of array
        inv_count += mergeSort(arr, mid+1, right);
    
        // merging 
        inv_count += merge(arr, left, mid, right);
    }
    return inv_count;
}
long long int inversionCount(long long arr[], long long N)
{
    return mergeSort(arr, 0, N-1);
}

/*

Time Complexity: O(N.Log(N))
Space Complexity: O(N)

*/