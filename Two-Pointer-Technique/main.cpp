#include <bits/stdc++.h>

// Checks if there are 2 values in given sorted array that summed equal the target
// Time complexity O(n), space complexity O(1)
bool twoSum(std::vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size()-1;

    while(left < right)
    {
        int sum = arr[left]+arr[right];

        if(sum == target)
            return true;
        else if(sum < target)
            left++;
        else
            right--;
    }
    
    return false;
}

int main()
{
    std::vector<int> arr = {-6, -2, 0, 7, 9, 11, 12};
    int target = 7;

    std::cout << (twoSum(arr, target) ? "yes" : "no");

    return 0;
}