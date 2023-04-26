#include <stdio.h>
#include <stdlib.h>

    struct node { 
        int data; 
        struct node *next;
    };
    struct node* createNode(int dataValue){
        struct node* NewNode = (struct node*)malloc(sizeof(struct node));
        NewNode ->data = dataValue;
        NewNode ->next = NULL;
        return NewNode;
    }
    void addNode(struct node **head, struct node *NewNode){
        if (*head == NULL){
            *head = NewNode;
        }else{
            struct node *current = *head;
            while (current->next != NULL){
                current = current->next;
            }
            current ->next = NewNode;
        }
    }
    void printNode(struct node *head){
        struct node *current = head;
        while (current != NULL){
            printf("%d\n", current->data);
            current = current->next;
        }
    }
    void freeNode(struct node *head){
         struct node *current = head;
         while (current !=NULL){
            struct node *nextnode = current->next;
            free(current);
            current = nextnode;
         }
    }
    struct node *searchNode(struct node *head, int value){
        struct node *current = head;
        while (current != NULL){
            if (current->data == value){
                return current;
            }
            current = current->next;
        }
        return NULL;
    }
    int getSize(struct node *head){
        int size = 0;
        struct node *current = head;
        while (current != NULL){
            size++;   
        }
        return size;
    }
    int main(){
        struct node *begin = NULL;
        struct node *newNode;

        //Valores
        newNode = createNode(3);
        addNode(&begin,newNode);
        newNode = createNode(5);
        addNode(&begin,newNode);
        newNode = createNode(7);
        addNode(&begin,newNode);
        printNode(begin);  
        printf("%d size of the list ", getSize(begin));
        int valorbuscado = 7;
        struct node *searchvalueNode = searchNode(&begin, valorbuscado);
        if (searchvalueNode == NULL){
            printf("no se encuentra");

        }else{
            printf("EL valor %d, se encuentra",valorbuscado);
        }
        return 0;
    }
        