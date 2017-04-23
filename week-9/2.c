#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define NO_OF_CHARS 256

void longestUniqueSubsttr(char *str) {

	int charArray[256] = {0};
	int len = 0, maxlen = 0, startIndex = 0;
	int i;

	for (i = 0; *(str + i); i++) {

		if (charArray[*(str + i)] == 0) 
		{
			len++;
			charArray[*(str + i)]++;
		}
		else 
		{

			if (len > maxlen) {
				maxlen = len;
				startIndex = i - maxlen;
				i--;
			}
			memset(charArray, 0, 256 * sizeof(int));
			len = 0;
		}
	}

	if (len > maxlen) 
	{
		maxlen = len;
		startIndex = i - maxlen;
		i--;
	}

	printf("longestUniqueSubsttr leng = %d", maxlen);

	str += startIndex;
	char *string = (char*)malloc((maxlen + 1) * sizeof(char));
	memcpy(string, str, maxlen);

	printf("\nSub string = %s", string);
}

int main()
{
	char str[100];
	scanf("%s", str);
	printf("The input string is %s \n", str);
	longestUniqueSubsttr(str);
	return 0;
}