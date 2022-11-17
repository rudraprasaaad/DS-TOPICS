#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class circularQ{
    int *arr;
    int front;
    int rear; 
    int size;

    public:
        circularQ(int s){
            front = rear = -1;
            size = s;
            arr = new int[s];
        }

        void enQueue(int value);
        int deQueue();
        void displayQueue();
};

void circularQ::enQueue(int value)
{
    if((front == 0 && rear == size - 1) || (rear == (front-1)%(size-1))){
        cout<<"Queue is full";
    }

    else if(front == -1){
        front = rear = 0; 
    }

    else if(rear == size - 1  && front != 0){
        rear = 0;
    }

    else{
        rear++;
    }
    arr[rear] = value;
}

int circularQ::deQueue(){
    if(front == -1){
        cout<<"Queue is Empty";
    }
    
    int data = arr[front];
    arr[front] = -1;
    
    if(front == rear) {
        front = rear = -1;
    }
    else if(front == size - 1){
        front = 0;
    }
    else{
        front++;
    }
    return data;    
}

void circularQ::displayQueue()
{
    if (front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ",arr[i]);
    }
    else
    {
        for (int i = front; i < size; i++)
            printf("%d ", arr[i]);
  
        for (int i = 0; i <= rear; i++)
            printf("%d ", arr[i]);
    }
}

int main(){
    circularQ q(5);
  
    q.enQueue(14);
    q.enQueue(22);
    q.enQueue(13);
    q.enQueue(-6);
  
    q.displayQueue();
  
    printf("\nDeleted value = %d", q.deQueue());
    printf("\nDeleted value = %d", q.deQueue());
  
    q.displayQueue();
  
    q.enQueue(9);
    q.enQueue(20);
    q.enQueue(5);
  
    q.displayQueue();
  
    q.enQueue(20);
    return 0;
}