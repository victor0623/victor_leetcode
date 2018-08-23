#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define DEBUG

int lengthOfLongestSubstring(char* s) {
	int s_len = strlen(s);
#ifdef DEBUG
	printf("s_len:%d\n", s_len);
#endif

	if (s_len == 1)
		return 1;

	int temp_byte_num = s_len+1;
	char *temp = (char *) malloc(sizeof(char) * temp_byte_num);
	char *temp_max_str = (char *) malloc(sizeof(char) * temp_byte_num);;
	
	if (temp != NULL)
		memset(temp, '\0', (unsigned int) temp_byte_num);

	if (temp_max_str != NULL)
		memset(temp_max_str, '\0', (unsigned int) temp_byte_num);

#ifdef DEBUG
	printf("sizeof temp:%d\n", (int) (s_len+1));
#endif

	int i, j, max_len = 0;
	int index = 0;

	for (i=0;i<s_len;) {
#ifdef DEBUG
		printf("i:%d\n", i);
#endif
		int rest_num = s_len - i + 1 -1;
#ifdef DEBUG
		printf("rest_num=%d\n", rest_num);
#endif
		if (max_len >= rest_num)
			break;
		
#ifdef DEBUG
		printf("---->%c\n", s[i]);
#endif
		memset(temp, '\0', (unsigned int) temp_byte_num);
		index = 0;
		for (j=i;j<s_len;j++) {
			char *pch = strchr(temp, s[j]);
			if (pch == NULL) {
#ifdef DEBUG
				//printf("not found!\n");
#endif
				temp[index] = s[j];
			}
			else {
#ifdef DEBUG
				printf("found!");
				printf("dump temp:%s len:%d\n", temp, (int) strlen(temp));
#endif
				if (index > max_len) {
					max_len = index;
					memset(temp_max_str, '\0', (unsigned int) temp_byte_num);
					strcpy(temp_max_str, temp);
				}
				memset(temp, '\0', (unsigned int) temp_byte_num);
				index = 0;
				temp[index] = s[j];
			}
			index++;
		}

		int final_temp_len = (int) strlen(temp);
		if (final_temp_len > max_len) {
			max_len = final_temp_len;
			strcpy(temp_max_str, temp);
		}

#ifdef DEBUG
		printf("temp_max_str:%s\n", temp_max_str);
#endif

		char *pstr = strstr (s+i,temp_max_str);
		int last_index = 0, shift_count = 0, shift = 0;
		while (pstr != NULL) {
			//printf("last_index=%d\n", last_index);
			shift = (int) (pstr - s - i);
			if ((shift > 0) && (shift % strlen(temp_max_str)) == 0)
				shift_count++;
			//printf("shift:%d\n", shift);
			//printf("pstr:%s\n", pstr);
			/*
			if (shift == strlen(temp_max_str)) {
				shift_total += shift;
			}
			*/
			pstr = strstr (pstr+1,temp_max_str);
			//last_index += shift;
			//printf("last_index=%d\n", last_index);
		}

#ifdef DEBUG
		printf("shift:%d shift_count=%d\n", shift, shift_count);
#endif

		if (shift_count >=2 && (shift != 0)) {
			i += shift;
		}
		else {
			i++;
		}
	}

	free(temp);
	free(temp_max_str);

	return max_len;
}

int main(void)
{
	char Input[] = "abcabcbb";
	//char Input[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ ";

	printf("Input string is:\n%s\n", Input);
	
	int result = lengthOfLongestSubstring(Input);
	printf("Max length is:%d\n", result);
	return 0;
}

/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", which the length is 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
