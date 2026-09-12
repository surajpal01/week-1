#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create() {
    struct Node *newNode, *temp;
    int n, i, value;

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

    printf("List created successfully.\n");
}

void display() {
    struct Node *temp = head;

    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void insertBeginning() {
    struct Node *newNode;
    int value;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = head;
    head = newNode;

    printf("Node inserted at beginning.\n");
}

void insertEnd() {
    struct Node *newNode, *temp;
    int value;

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

    printf("Node inserted at end.\n");
}

void insertPosition() {
    struct Node *newNode, *temp;
    int value, pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    printf("Enter data: ");
    scanf("%d", &value);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if(pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    temp = head;

    for(i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL) {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted successfully.\n");
}

void deleteBeginning() {
    struct Node *temp;

    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);

    printf("Node deleted from beginning.\n");
}

void deleteEnd() {
    struct Node *temp, *del;

    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if(head->next == NULL) {
        free(head);
        head = NULL;
        printf("Node deleted from end.\n");
        return;
    }

    temp = head;

    while(temp->next->next != NULL)
        temp = temp->next;

    del = temp->next;
    temp->next = NULL;
    free(del);

    printf("Node deleted from end.\n");
}

void deletePosition() {
    struct Node *temp, *del;
    int pos, i;

    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos == 1) {
        del = head;
        head = head->next;
        free(del);
        printf("Node deleted successfully.\n");
        return;
    }

    temp = head;

    for(i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if(temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    del = temp->next;
    temp->next = del->next;
    free(del);

    printf("Node deleted successfully.\n");
}

void search() {
    struct Node *temp = head;
    int key, pos = 1, found = 0;

    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    while(temp != NULL) {
        if(temp->data == key) {
            printf("Element found at position %d.\n", pos);
            found = 1;
            break;
        }

        temp = temp->next;
        pos++;
    }

    if(!found)
        printf("Element not found.\n");
}

void countNodes() {
    struct Node *temp = head;
    int count = 0;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Number of nodes = %d\n", count);
}

void reverse() {
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next;

    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;

    printf("Linked List reversed successfully.\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n===== SINGLY LINKED LIST =====\n");
        printf("1. Create List\n");
        printf("2. Display / Traversal\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Given Position\n");
        printf("6. Delete from Beginning\n");
        printf("7. Delete from End\n");
        printf("8. Delete from Given Position\n");
        printf("9. Search Element\n");
        printf("10. Count Nodes\n");
        printf("11. Reverse List\n");
        printf("12. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create();
                break;

            case 2:
                display();
                break;

            case 3:
                insertBeginning();
                break;

            case 4:
                insertEnd();
                break;

            case 5:
                insertPosition();
                break;

            case 6:
                deleteBeginning();
                break;

            case 7:
                deleteEnd();
                break;

            case 8:
                deletePosition();
                break;

            case 9:
                search();
                break;

            case 10:
                countNodes();
                break;

            case 11:
                reverse();
                break;

            case 12:
                printf("Program ended.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}