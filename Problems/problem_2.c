#include <stdio.h>
#include <stdlib.h>

/* Circular linked list function */
struct Node {
    int data;
    struct Node *next;
};

/* Create a new node */
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* Insert a new node at the end of the circular linked list */
void insertAtEnd(struct Node **head, int value) {
    struct Node *newNode = createNode(value);

    if (*head == NULL) {
        /* First node: points to itself to form a circle */
        *head = newNode;
        newNode->next = newNode;
        return;
    }

    struct Node *temp = *head;

    /* Traverse until the last node */
    while (temp->next != *head) {
        temp = temp->next;
    }

    /* Insert newNode after last node and point it back to head */
    temp->next = newNode;
    newNode->next = *head;
}

/* Display elements of the circular list starting from head */
void displayCircular(struct Node *head) {
    if (head == NULL) {
        printf("Circular list is empty.\n");
        return;
    }

    struct Node *temp = head;

    printf("Circular list from head: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

void freeCircularList(struct Node **head) {
    if (*head == NULL) {
        return;
    }

    struct Node *current = *head;
    struct Node *nextNode;

    struct Node *last = *head;
    while (last->next != *head) {
        last = last->next;
    }
    last->next = NULL; 

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    *head = NULL;
}

int main() {
    struct Node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    displayCircular(head);

    freeCircularList(&head);

    return 0;
}
