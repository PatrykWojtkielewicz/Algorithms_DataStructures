#include <bits/stdc++.h>

int findMinimumCoins(std::vector<int> coins, int change)
{
    int count = 0;

    for(int i=0; i<coins.size(); ++i)
    {
        while(change>=coins[i])
        {
            change -= coins[i];
            count++;
        }
    }

    return count;
}

int main()
{
    std::vector<int> denominations = {500, 200, 100, 50, 20, 10, 5, 2, 1}; // in cents
    int change = 1761;

    std::cout << "Change given will contain " << findMinimumCoins(denominations, change) << " coins";

    return 0;
}