#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
int nodeCount = 0;

// Funkcje listy
int insertFront(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return 1;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    nodeCount++;
    return 0;
}

int insertBack(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return 1;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
    nodeCount++;
    return 0;
}

int deleteFront() {
    if (head == NULL) return 1;
    Node* temp = head;
    head = head->next;
    free(temp);
    nodeCount--;
    return 0;
}

int deleteBack() {
    if (head == NULL) return 1;
    if (head->next == NULL) return deleteFront();

    Node* prev = NULL;
    Node* curr = head;
    while (curr->next) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    free(curr);
    nodeCount--;
    return 0;
}

void printList() {
    Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void clearList() {
    while (head) deleteFront();
}

int isEmpty() {
    return head == NULL;
}
