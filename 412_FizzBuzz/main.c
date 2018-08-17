#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LEN 10

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
	int i;
	char **result = (char **) malloc(sizeof(char *) * n);
	if (result != NULL) {
		for (i=0;i<n;i++)
			*(result+i) = malloc(sizeof(char) * STRING_LEN);

		for (i=0;i<n;i++) {
			char temp[STRING_LEN] = "";

			if (((i+1) % 15) == 0) {
				snprintf(temp, sizeof(temp), "FizzBuzz");
			} else if (((i+1) % 3) == 0) {
				snprintf(temp, sizeof(temp), "Fizz");
			} else if (((i+1) % 5) == 0) {
				snprintf(temp, sizeof(temp), "Buzz");
			} else {
				snprintf(temp, sizeof(temp), "%d", (i+1));
			}

			strcpy(*(result+i), temp);
		}
	}
	
	*returnSize = n;

    return result;
}

int main(void)
{
	int n = 30;
	int returnSize;

	printf("n = %d\n", n);
	char **result = fizzBuzz(n, &returnSize);

	printf("Result is:\n");
	for (int i=0;i<returnSize;i++)
		printf("%s\n", *(result+i));

	return 0;
}

/*
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
*/