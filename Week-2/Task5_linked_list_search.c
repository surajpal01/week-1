#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *newNode, *temp;
    int n, i, value, key, position = 1, found = 0;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        } else {
            temp = head;

            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    temp = head;

    while(temp != NULL) {
        if(temp->data == key) {
            printf("Element found at position %d", position);
            found = 1;
            break;
        }

        temp = temp->next;
        position++;
    }

    if(found == 0)
        printf("Element not found");

    return 0;
}