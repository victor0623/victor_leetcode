#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool backspaceCompare(char* S, char* T) {
	int top_S = -1, top_T = -1;

	int i = 0, j = 0;
	while (S[i] != '\0' || T[j]) {

		if (S[i] == '#') {
			if (top_S >= 0) {
				top_S--;
			}
		}
		else {
			top_S++;
			S[top_S] = S[i];
		}

		if (T[j] == '#') {
			if (top_T >= 0) {
				top_T--;
			}
		}
		else {
			top_T++;
			T[top_T] = T[j];
		}

		if (S[i] != '\0')
			i++;
		
		if (T[j] != '\0')
			j++;
	}

	printf("top_S:%d top_T:%d\n", top_S, top_T);

	

	*(S+top_S+1) = '\0';
	printf("new S:%s\n", S);

	*(T+top_T+1) = '\0';
	printf("new T:%s\n", T);

	if (!strcmp(S, T))
		return true;
	else
		return false;
}

int main(void)
{
	char S[] = "ab#c";
	char T[] = "ad#c";

	printf("The input is:\n");
	printf("S:%s  T:%s\n", S, T);

	bool result = backspaceCompare(S, T);
	if (result)
		printf("true!\n");
	else
		printf("false!\n");

	return 0;
}

/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
*/