#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data; //variable that actually holds the value of node
    struct Node *next; //pointer that actual stores the address of next node in sequence
};

struct Node *head = NULL;

void insBeg(int value){
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    
    if(head==NULL){ //check the condition when head is NULL
        newNode->next = NULL;
        head = newNode;
    }
    else{
        newNode->next=head;
        head = newNode;
    }
    printf("\n One node is inserted!!");
}

void insEnd(int value){
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }
    else{
        struct Node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next=newNode;
    }
    printf("\n One node is inserted!!");
}

void insBetween(int value, int loc1){
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if(head == NULL){
        newNode->next = NULL;
        head = newNode;
    }
    else{
        struct Node* temp = head;
        while(temp->data!=loc1){
            if(temp->next == NULL){
                printf("\nNode is not presented in the list");
                return;
            }
            temp = temp->next;
        }
        newNode->next=temp->next;
        temp->next = newNode;
    }
    printf("\nOne node is inserted!!");
}

void delBeg(){
    if(head==NULL){
        printf("\nList is Empty");
    }
    else{
        struct Node *temp = head;
        if(head->next == NULL){
            head = NULL;
            free(temp);
        }
        else{
            head = temp->next;
            free(temp);
            printf("\nOne node deleted!!!");
        }
    }
}

void delEnd(){
    if(head==NULL){
        printf("\nList is Empty");
    }
    else{
        struct Node *temp1 = head,*temp2; 
        if(head->next == NULL){
            head = NULL;
        }
        else{
            while(temp1->next!=NULL){
                temp2 = temp1;
                temp1 = temp1->next;
            }
            temp2->next = NULL; 
        }
        free(temp1);
        printf("\nOne node deleted!!");
    }
}

void delPos(int value){
    if(head == NULL){
        printf("\nList is empty");
    }
   
    else{
        struct Node *temp1 = head, *temp2;
        while(temp1->data != value){
             if(temp1->next == NULL){
                printf("\nNode is not present in the list!!");
                return;
            }
            temp2 = temp1;
            temp1 = temp1->next;
        }
        if(head->next == NULL){
            head = NULL;
            free(temp1);
        }
        else if(temp1 == head){
            head = head->next;
            free(temp1);
        }
        else if(temp1->next == NULL){
            temp2->next = NULL;
            free(temp1);
        }
        else{
            temp2->next = temp1->next;
        free(temp1);
        }
        printf("\n One node deleted!!");
    }
}

void display(){
    if(head == NULL){
        printf("\nNode is not present in the list!!");
    }
    else{
        struct Node* temp = head;
        while(temp->next != NULL){
            printf("%d ----> ", temp->data);
            temp = temp->next;
        }
        printf("%d ----> NULL", temp->data);
    }
}


int main(){
    int choice,value,loc1,loc2;
    while(1){
        printf("\n\n*****MENU****\n 1.Insert at Beginning\n 2.Insert at End\n 3. Insert at Between\n 4. Delete at First\n 5. Delete at End\n 6. Deletion at specific position\n 7. Display\n 8. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the value to be insert: ");
            scanf("%d",&value);
            insBeg(value);
            break;

            case 2:
            printf("Enter the value to be insert: ");
            scanf("%d",&value);
            insEnd(value);
            break;

            case 3:
            printf("Enter the value to be insert: ");
            scanf("%d",&value);
            printf("Enter the values where you want to insert: ");
            scanf("%d",&loc1);
            insBetween(value,loc1);
            break;

            case 4:
            delBeg();
            break;

            case 5:
            delEnd();
            break;

            case 6:
            printf("Enter the values of where you want to delete: ");
            scanf("%d",&loc2);
            delPos(loc2);
            break;

            case 7:
            display();
            break;

            case 8:
            exit(0);
            break;

            default:
            printf("\nyou inputed a invalid choice");
        }     
    }
    return 0;
}