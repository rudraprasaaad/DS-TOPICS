#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data; 
    struct Node *next;
};

struct Node *top = NULL; // top pointer to represent the top stack


void push(int value){  // Simply inserting element at the beggining of the linked list
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if(top == NULL){
        newNode->next = NULL;
    }
    else{
        newNode -> next = top;
    }
    top = newNode;
    printf("\nOne Node is inserted");
}

int pop(){
    if(top == NULL){
        printf("\nStack is underflow!!");
    }
    else{
        struct Node *temp = top;
        int tempData = top->data;
        top = top->next;
        free(temp);
        return tempData;
    }
}

void display(){
    if(top == NULL){
        printf("\nStack is underflow!!");
    }
    else{
        struct Node * temp = top;
        while(temp->next!=NULL){
            printf("%d ----> ", temp->data);
            temp = temp->next;
        }
        printf("%d ----> NULL", temp->data);
    }
}


int main(){
    int choice, value;
    while(1){
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice:");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter the value:");
                scanf("%d",&value);
                push(value);
            break;

            case 2:
                printf("\nPopped Element is : %d", pop());
            break;

            case 3:
                display();
            break;

            case 4:
                exit(0);
            break;

            default:
                printf("\nInvalid choice!!!");
        }
    }
    return 0;
}