#include <bits/stdc++.h>

class Stack
{
    private:
        int *arr;
        int top;
        int capacity;

    public:
        Stack(int size)
        {
            arr = new int[size];
            capacity = size;
            top = -1;
        }

        ~Stack()
        {
            delete[] arr;
        }

        void push(int e)
        {
            if(top == capacity-1)
                throw std::overflow_error("Stack overflow");
            
            arr[++top] = e;
        }

        int pop()
        {
            if(top == -1)
            {
                throw std::underflow_error("Stack underflow");
            }

            return arr[top--];
        }

        int peek()
        {
            if(top == -1)
            {
                throw std::runtime_error("Stack is empty");
            }

            return arr[top];
        }

        bool isEmpty()
        {
            return top == -1;
        }
};

int main()
{
    Stack numbers(10);

    try
    {
        numbers.push(5);
        numbers.push(7);
        numbers.push(9);

        std::cout << "Top element: " << numbers.peek() << "\n";
        numbers.pop();
        std::cout << "Top element after pop: " << numbers.peek() << "\n";

        std::cout << "Is stack empty: " << (numbers.isEmpty() ? "yes" : "no") << "\n"; 
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception thrown: " << e.what() << "\n";
    }

    return 0;
}