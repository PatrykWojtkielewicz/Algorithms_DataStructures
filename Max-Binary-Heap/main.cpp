#include <bits/stdc++.h>

class Heap
{
    private:
        int* arr;
        int maxSize;
        int heapSize;
    
    public:
        Heap(int maxSize);

        // Heapifies a sub-tree with argument as root
        void heapify(int);

        // Returns index of the parent of the element
        int getParent(int i)
        {
            return (i-1)/2;
        }

        // Returns index of the left child of the element
        int getLeftChild(int i)
        {
            return (2*i)+1;
        }

        // Returns index of the right child of the element
        int getRightChild(int i)
        {
            return (2*i)+2;
        }

        // Returns value of largest element
        int getMaxValue()
        {
            return arr[0];
        }

        // Returns size of heap
        int getSize()
        {
            return heapSize;
        }
};

Heap::Heap(int size)
{
    heapSize = 0;
    maxSize = size;
    arr = new int[size];
}

void Heap::heapify(int i)
{
    int left = getLeftChild(i);
    int right = getRightChild(i);
    int largest = i;

    if(left < heapSize && arr[left] > arr[i])
        largest = left;
    
    if(right < heapSize && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        std::swap(arr[i], arr[largest]);
        heapify(largest);
    }
}

int main()
{
    Heap h(30);
    


    return 0;
}