#include <bits/stdc++.h>

void bubbleSort(std::vector<int>& numbers)
{
    int n = numbers.size();

    for(size_t i=0; i<n-1; ++i)
    {
        for(size_t j=0; j<n-1-i; ++j)
        {
            if(numbers[j] > numbers[j+1])
            {
                std::swap(numbers[j], numbers[j+1]);
            }
        }
    }
}

int main()
{
    std::vector<int> numbers = {4, 7, 2, 3, 9, 0, 1, 8, 5, 6};

    bubbleSort(numbers);
    
    for(int n: numbers)
        std::cout << n << " ";

    return 0;
}