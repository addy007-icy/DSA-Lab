#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

struct DataItem {
   int key;
};

struct DataItem* hashArray[SIZE];
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(int key) {
   return key % SIZE;
}

struct DataItem *search(int key) {
   int hashIndex = hashCode(key);
   int count = 0;
   while (hashArray[hashIndex] != NULL)
   {
      count++;
      if (hashArray[hashIndex]->key == key)
         return hashArray[hashIndex];

      ++hashIndex;

      hashIndex %= SIZE;
      if(count == SIZE)
         break;
   }

   return NULL;
}

void insert(int key) {

   struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   item->key = key;

   int hashIndex = hashCode(key);               //k mod 10

   while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
      ++hashIndex;                              // (k+i) mod 10

      hashIndex %= SIZE;
   }

   hashArray[hashIndex] = item;
}

struct DataItem* delete(struct DataItem* item) {
   int key = item->key;

   int hashIndex = hashCode(key);

   while (hashArray[hashIndex] != NULL) {

      if (hashArray[hashIndex]->key == key) {
         struct DataItem* temp = hashArray[hashIndex];

         hashArray[hashIndex] = dummyItem;
         return temp;
      }

      ++hashIndex;

      hashIndex %= SIZE;
   }

   return NULL;
}

void display() {
   int i = 0;

   for (i = 0; i < SIZE; i++) {

      if (hashArray[i] != NULL && hashArray[i]->key != -1)
         printf(" (%d)", hashArray[i]->key);
      else
         printf(" ~~ ");
   }

   printf("\n");
}

int main() {
   dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
   dummyItem->key = -1;
   int n = 10, ch, key;

   while (1) {
      printf("\n1. Insertion \t2. Deletion\n");
      printf("3. Searching\t 4. Display\t 5. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &ch);
      switch (ch) {
      case 1:
         printf("Enter the key value: ");
         scanf("%d", &key);
         insert(key);;
         break;

      case 2:
         printf("Enter the key to perform deletion: ");
         scanf("%d", &key);
         delete(search(key));
         break;

      case 3:
         printf("Enter the key to search: ");
         scanf("%d", &key);
         item = search(key);

         if (item != NULL) {
            printf("Element found: %d\n", item->key);
         } else {
            printf("Element not found\n");
         }
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
}