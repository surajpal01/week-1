#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *newNode, *temp, *del;
    int n, i, value, choice, pos;

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

    printf("\n1. Delete from Beginning");
    printf("\n2. Delete from End");
    printf("\n3. Delete from Given Position");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    if(head == NULL) {
        printf("List is empty");
        return 0;
    }

    if(choice == 1) {
        del = head;
        head = head->next;
        free(del);
    }

    else if(choice == 2) {
        if(head->next == NULL) {
            free(head);
            head = NULL;
        } else {
            temp = head;

            while(temp->next->next != NULL)
                temp = temp->next;

            del = temp->next;
            temp->next = NULL;
            free(del);
        }
    }

    else if(choice == 3) {
        printf("Enter position: ");
        scanf("%d", &pos);

        if(pos == 1) {
            del = head;
            head = head->next;
            free(del);
        } else {
            temp = head;

            for(i = 1; i < pos - 1 && temp->next != NULL; i++)
                temp = temp->next;

            if(temp->next == NULL) {
                printf("Invalid position");
                return 0;
            }

            del = temp->next;
            temp->next = del->next;
            free(del);
        }
    }

    else {
        printf("Invalid choice");
        return 0;
    }

    printf("Linked List after deletion:\n");

    temp = head;

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");

    return 0;
}