#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

struct DataItem {
	char *data;
	long long int key;
};

int hashCode(long long int key) {
   return key % 10;
}

struct DataItem* hashArray[200];
struct DataItem* dummyItem;
struct DataItem* item;

struct DataItem *search(long long int key) {
	long long int hashIndex = key;

	while (hashArray[hashIndex] != NULL) {

		if (hashArray[hashIndex]->key == key)
			return hashArray[hashIndex];

		++hashIndex;

		hashIndex %= SIZE;
	}

	return NULL;
}

void insert(long long int key, char *data) {

	struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
	strcpy(item->data, data);
	printf("data = %s\n", item->data);
	item->key = key;

	long long int hashIndex = hashCode(key);

	while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
		++hashIndex;

		hashIndex %= SIZE;
	}

	hashArray[hashIndex] = item;
}

void display() {
	long long int i = 0;

	for (i = 0; i < SIZE; i++) {

		if (hashArray[i] != NULL)
			printf(" %s ", hashArray[i]->data);
		else
			printf(" ~~ ");
	}

	printf("\n");
}



int prime(char x)
{
	if (x == 'a')
		return 2;
	if (x == 'b')
		return 3;
	if (x == 'c')
		return 5;
	if (x == 'd')
		return 7;
	if (x == 'e')
		return 11;
	if (x == 'f')
		return 13;
	if (x == 'g')
		return 17;
	if (x == 'h')
		return 19;
	if (x == 'i')
		return 23;
	if (x == 'j')
		return 29;
	if (x == 'k')
		return 31;
	if (x == 'l')
		return 37;
	if (x == 'm')
		return 41;
	if (x == 'n')
		return 43;
	if (x == 'o')
		return 47;
	if (x == 'p')
		return 53;
	if (x == 'q')
		return 59;
	if (x == 'r')
		return 61;
	if (x == 's')
		return 67;
	if (x == 't')
		return 71;
	if (x == 'u')
		return 73;
	if (x == 'v')
		return 79;
	if (x == 'w')
		return 83;
	if (x == 'x')
		return 89;
	if (x == 'y')
		return 97;
	if (x == 'z')
		return 101;
}

long long int multiply(char *arr)
{
	long long int i, m = 1;
	for (i = 0; i < strlen(arr); i++)
	{
		m = m * prime(arr[i]);
	}
	//printf("%lld\n", m);
	return m;
}

int main(char argc, char *argv[])
{	long long int i = 0, h;

	dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
	dummyItem->data = NULL;
	dummyItem->key = -1;


	char arr[256], a[256];
	if (argc < 2)
	{
		printf("ERROR\n");
		return 0;
	}
	FILE *ptr;
	if ((ptr = fopen(argv[1], "r")) == NULL)
	{
		printf("FILE not there\n");
		return 0;
	}

	long long int n = atoi(argv[2]);
	i = 0;
	while (i < n)
	{	
		fgets(arr, 256, ptr);
		printf("%s", arr);
		h = multiply(arr);
		printf("%lld\n", h);
		h = h%10;
		insert(h, arr);
		i++;
	}
	do
	{
		scanf("%s", a);
		long long int h = multiply(a);
		h = h%10;
		search(h);

	} while (strcmp(a, "q") != 0);



}
