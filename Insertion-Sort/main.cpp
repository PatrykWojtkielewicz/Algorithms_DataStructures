#include <bits/stdc++.h>

void insertionSort(std::vector<int>& numbers)
{
    int n = numbers.size();

    for(size_t i=1; i<n; ++i)
    {
        int key = numbers[i];
        size_t j = i-1;

        while(j>=0 && numbers[j]>key)
        {
            numbers[j+1] = numbers[j];
            j--;
        }
        
        numbers[j+1] = key;
    }
}

int main()
{
    std::vector<int> numbers = {4, 7, 2, 3, 9, 0, 1, 8, 5, 6};

    insertionSort(numbers);
    
    for(int n: numbers)
        std::cout << n << " ";

    return 0;
}