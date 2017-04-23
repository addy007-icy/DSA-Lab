#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
struct hash *hashTable = NULL;
int count = 0;

typedef struct Node node;

struct Node {
    int key;
    node *next;
    node *prev;
};
 
struct hash {
    node *head;
    int count;
};
 
node * createNode(int key) {
    node *newnode;
    newnode = (node *) malloc(sizeof(node));
    newnode->key = key;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}
 
void insertToHash(int key) {
    int hashIndex = key % count;
    node *newnode = createNode(key);

    if (!hashTable[hashIndex].head) 
    {
        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count = 1;
        return;
    }

    newnode->next = (hashTable[hashIndex].head);
    hashTable[hashIndex].head->prev = newnode;
    hashTable[hashIndex].head = newnode;
    hashTable[hashIndex].count++;
    return;
}
 
void deleteFromHash(int key) {
    int hashIndex = key % count;
    node *temp, *myNode;
    myNode = hashTable[hashIndex].head;
    if (!myNode) {
        printf("Given data is not present \n");
        return;
    }
    temp = myNode;
    while (myNode != NULL) 
    {
        if (myNode->key == key) 
        {
            if (myNode == hashTable[hashIndex].head)
                hashTable[hashIndex].head = myNode->next;
            else
                temp->next = myNode->next;
 
            hashTable[hashIndex].count--;
            free(myNode);
            break;
        }
        temp = myNode;
        myNode = myNode->next;
    }
   
}
 
void searchInHash(int key) {
    int hashIndex = key % count, flag = 0;
    node *myNode;
    myNode = hashTable[hashIndex].head;
    if (!myNode) 
    {
        printf("Search element unavailable in hash table \n");
        return;
    }
    while (myNode != NULL) {
        if (myNode->key == key) {
            printf("%d\n", myNode->key);
            flag = 1;
            break;
        }
        myNode = myNode->next;
    }
    if (!flag)
        printf("element unavailable \n");
    return;
}
 
void display() {
    node *myNode;
    int i;
    for (i = 0; i < count; i++) 
    {
        if (hashTable[i].count == 0)
            continue;
        myNode = hashTable[i].head;
        if (!myNode)
            continue;
        printf("\nData at index %d in Hash Table: \n", i);
        while (myNode != NULL) {
            printf("%d ", myNode->key);
            myNode = myNode->next;
        }
    }
    return;
}
 
int main() {
    int n=10, ch, key;
    count = n;
    hashTable = (struct hash *)calloc(n, sizeof(struct hash));
    while (1) {
        printf("\n1. Insertion \t2. Deletion\n");
        printf("3. Searching\t 4. Display\t 5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Enter the key value: ");
            scanf("%d", &key);
            insertToHash(key);
            break;
 
        case 2:
            printf("Enter the key to perform deletion: ");
            scanf("%d", &key);
            deleteFromHash(key);
            break;
 
        case 3:
            printf("Enter the key to search: ");
            scanf("%d", &key);
            searchInHash(key);
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("pls enter again \n");
            break;
        }
    }
    return 0;
}