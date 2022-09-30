#include <stdio.h>

//Represent a node of the singly linked list
struct Node {
    int data;
    struct Node *next;
};

//Hold the linkedlist object
struct SinglyLinkedList {
    struct Node *head;
    struct Node *tail;
};

//addNode() will add a new node to the list
void addNode(int data, struct SinglyLinkedList *SLL);

//display() will display all nodes currently in the list
void display(struct SinglyLinkedList SLL);

int main() {

    struct SinglyLinkedList sList;
    sList.head = NULL;
    sList.tail = NULL;

    display(sList);

    addNode(1, &sList);
    addNode(2, &sList);
    addNode(7, &sList);
    addNode(15, &sList);

    display(sList);
}

void display(struct SinglyLinkedList SLL) {
    if(SLL.head == NULL) {
        printf("The list is empty.\n");
    }
    else {
        printf("Nodes of singly linked list: ");
        struct Node current = *SLL.head;
        while(current.next != NULL) {
            printf("%i ->", current.data);
            current = *current.next;
        }
        printf("\n");
    }
}

//addNode() will add a new node to the list
void addNode(int data, struct SinglyLinkedList *SLL) {
    //Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    //Check if the list is empty
    if(SLL->head == NULL) {
        //If the list is empty point both head and tail at the new node
        SLL->head = newNode;
        SLL->tail = newNode;
    }
    else {
        //Otherwise the tail is moved to reflect the new node
        SLL->tail->next = newNode;
        SLL->tail = newNode;
    }

}