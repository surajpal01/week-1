#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *newNode, *temp;
    int n, i, value, pos;

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

    printf("Enter position for insertion: ");
    scanf("%d", &pos);

    printf("Enter value: ");
    scanf("%d", &value);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if(pos == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        temp = head;

        for(i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if(temp == NULL) {
            printf("Invalid position");
            return 0;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("Linked List after insertion:\n");

    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");

    return 0;
}