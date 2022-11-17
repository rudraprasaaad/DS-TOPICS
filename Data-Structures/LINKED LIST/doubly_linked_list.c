#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node * head = NULL;

void insBeg(int value){
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    if(head==NULL){
        newNode->next = NULL;
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
    printf("\n One node inserted!!");
}

void insEnd(int value){
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL){
        newNode->prev = NULL;
        head = newNode;
    }
    else{
        struct Node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next; 
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("\nOne node is inserted");
}

void insBetween(int value, int loc){
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if(head == NULL){
        newNode->prev = NULL;
        newNode->next = NULL;
    }
    else{
        struct Node * temp = head;
        while(temp->data!=loc){
            if(temp->next == NULL){
               printf("\nNode is not available in the list");     
               return;
            }
            temp =  temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        // newNode->next->prev = newNode;

        if(newNode->next!=NULL){
            newNode->next->prev = newNode;
        }
    }
    printf("\nOne node inserted");
}

void delBegin(){
    if(head == NULL){
        printf("\nList is Empty");
    }
    else{
        struct Node *temp = head;
        if(temp->prev == temp->next){
            head = NULL;
            free(temp);
        }
        else{
            head = temp->next;
            head->prev = NULL;
            free(temp);
        }
    }
    printf("\n One node deleted");
}

void delEnd(){
    if(head == NULL){
        printf("\nList is Empty");
    }
    else{
        struct Node *temp = head;
        if(temp->prev == temp->next){
            head = NULL;
            free(temp);
        }
        else{
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->prev->next = NULL;
            free(temp);
        }
    }
    printf("\n One node deleted");
}

void delPos(int loc){
    if(head == NULL){
       printf("\nList is Empty"); 
    }
    else{
        struct Node *temp = head;
        while(temp->data!=loc){
            if(temp->next == NULL){
                printf("\nNode is not presented in the list");
                return;
            }
            else{
                temp = temp->next;
            }
        }
        if(temp->prev == temp->next){
            head = NULL;
            free(temp);
        }
        else if(temp == head){
            head = head->next;
            head->prev = NULL;
            free(temp);
        }
        else if(temp->next == NULL){
            temp->prev->next = NULL;
            free(temp);
        }
        else{
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
        }
        printf("\n One node deleted!!!");
    }
     
}

void display(){
    if(head == NULL){
        printf("\nList is Empty");
    }
    else{
        struct Node *temp = head;
        while(temp->next!=NULL){
            printf("%d <----> ", temp->data);
            temp = temp->next;
        }
        printf("%d ----> NULL", temp->data);
    }
}



int main(){
    int choice,value,loc1,loc2;
    while(1){
        printf("\n\n*****MENU****\n 1.Insert at Beginning\n 2.Insert at End\n 3.Insert at Between\n 4.Deletion from Begin\n 5.Deletion from End\n 6.Deletion from given position\n 7. Display\n 8. Exit \nEnter your choice: ");
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
                delBegin();
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
                printf("Invaid choice");
        }

    }
}