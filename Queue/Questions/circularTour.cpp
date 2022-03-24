// Question Link : https://practice.geeksforgeeks.org/problems/circular-tour/1#

int tour(petrolPump p[],int n)
{
    int deficit = 0, balance = 0, start = 0;
    for(int i=0; i<n; i++)
    {
        balance += p[i].petrol - p[i].distance;
        
        if(balance < 0)
        {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }
    
    if(deficit + balance >= 0)
        return start;
    else
        return -1;
}

/*

Time Complexity: O(N)
Space Complexity: O(1)

*/