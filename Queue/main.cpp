#include <bits/stdc++.h>

struct Node{
    int data;
    Node* next;
};

class Queue
{
    private:
        Node* front;
        Node* rear;
    
    public:
        Queue() : front(nullptr), rear(nullptr) {}

        void enqueue(int x)
        {
            Node* newNode = new Node {x, nullptr};

            if(rear == nullptr)
                front = rear = newNode;
            else
            {
                rear->next = newNode;
                rear = newNode;
            }
        }

        void dequeue()
        {
            if(front == nullptr)
                return;
            
            Node* temp = front;
            front = front->next;

            if(front == nullptr)
                rear = nullptr;

            delete temp;
        }

        int peek()
        {
            if(!isEmpty())
                return front->data;
            else
                throw std::runtime_error("Queue is empty");
        }

        bool isEmpty()
        {
            return front == nullptr;
        }
};

int main()
{
    Queue q;

    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(9);
    q.enqueue(11);
    q.enqueue(13);

    std::cout << "\nFront element: " << q.peek();
    q.dequeue();
    std::cout << "\nFront element: " << q.peek();
    std::cout << "\nIs the queue empty: " << (q.isEmpty() ? "yes" : "no");

    return 0;
}