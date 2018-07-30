#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* toLowerCase(char* str) {
	if (str == NULL) {
		printf("Input string is NULL!\n");
		return NULL;
	}

    char *result = (char *) malloc(sizeof(char) * (strlen(str)+1));
    strncpy(result, str, strlen(str));

    char *r = result;

    while (*r != '\0') {
    	if (*r >= 65 && *r <= 90)
    		*r += 32;
    	r++;
    }

    return result;
}

int main(void)
{
	char Input[] = "ABCD";
	char *Output = toLowerCase(Input);

    printf("input:%s\n", Input);
    printf("output:%s\n", Output);

	return 0;
}