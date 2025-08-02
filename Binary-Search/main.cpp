#include <bits/stdc++.h>

int getElementIndex(std::vector<int>& arr, int key)
{
    int low = 0;
    int high = arr.size()-1;

    while(low <= high)
    {
        int mid = low+(high-low)/2;

        if(arr[mid] == key)
            return mid;

        if(arr[mid] < key) // ignore left half of array
            low = mid+1;
        else               // ignore right half of array
            high = mid-1;
    }

    // In case we don't find the element
    return -1;
}

int main()
{
    std::vector<int> array = {1, 3, 7, 9, 10, 11, 11, 46, 290};

    std::cout << "Index of \"46\" is " << getElementIndex(array, 46);

    return 0;
}