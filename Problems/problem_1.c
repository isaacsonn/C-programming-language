#include <stdio.h>
#include <stdlib.h>

/* Node structure for singly linked list */
struct Node {
    int data;
    struct Node *next;
};

/* Function to create a new node with given value */
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

/* Insert a new node at the end of the list */
void insertAtEnd(struct Node **head, int value) {
    struct Node *newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

/* Insert a new node at the 4th position */
void insertAtFourth(struct Node **head, int value) {
    struct Node *newNode = createNode(value);

    /* If list is empty, new node becomes the head. */
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    int i;

    /* Move temp to the node at position 3 (before the 4th) */
    for (i = 1; i < 3 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

/* Delete a node at the 3rd position */
void deleteThird(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete 3rd node.\n");
        return;
    }

    struct Node *temp = *head;

    /* If there is only one node */
    if (temp->next == NULL) {
        printf("List has fewer than 3 nodes. No deletion.\n");
        return;
    }

    struct Node *second = temp->next;

    /* If there are exactly two nodes */
    if (second->next == NULL) {
        printf("List has fewer than 3 nodes. No deletion.\n");
        return;
    }

    /* third is the node we want to delete */
    struct Node *third = second->next;
    second->next = third->next;

    printf("Deleting node at 3rd position with value: %d\n", third->data);
    free(third);
}

/* Display all nodes */
void displayList(struct Node *head) {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Help function to free the list */
void freeList(struct Node **head) {
    struct Node *current = *head;
    struct Node *nextNode;

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

    printf("Initial list after inserting at the end:\n");
    displayList(head);

    printf("\nInserting 99 at the 4th position:\n");
    insertAtFourth(&head, 99);
    displayList(head);

    printf("\nDeleting the node at the 3rd position:\n");
    deleteThird(&head);
    displayList(head);

    freeList(&head);

    return 0;
}
