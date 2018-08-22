#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FINAL_STRING_LEN 10000
#define TOKEN_LEN 200
//#define DEBUG

char Vowel[] = {'a','e','i','o','u','A','E','I','O','U'};

int isVowel(char c)
{
	int is_vowel = 0;
	int vowel_len = sizeof(Vowel)/sizeof(char);
	for (int i=0;i<vowel_len;i++) {
		if (c == Vowel[i]) {
			is_vowel = 1;
			break;
		}
	}
	
	return is_vowel;
}

char* toGoatLatin(char* S) {
	char temp[TOKEN_LEN] = "";
	int i = 0, isFirstWord = 1, is_vowel, word_count = 0;
	int j, word_counts_total = 0;
	char *result = (char *) malloc(sizeof(char) * FINAL_STRING_LEN);
	if (result != NULL) {
		while (*S != '\0') {
			//printf("token:%c\n", *S);
			if (*S == ' ') {
#ifdef DEBUG
				printf("words:%s\n", temp);
#endif
				word_count++;

				if (is_vowel == 1) {
#ifdef DEBUG
					printf("temp:%s sizeof temp:%d\n", temp, (int) strlen(temp));
#endif

					char final_word[TOKEN_LEN] = "";
					strcpy(final_word, temp);
					strcat(final_word, "ma");
					for (j=0;j<word_count;j++)
						strcat(final_word, "a");
					strcat(final_word, " ");
#ifdef DEBUG
					printf("%s strlen:%d\n", final_word, (int) strlen(final_word));
#endif

					strcpy(result+word_counts_total, final_word);
					word_counts_total += (int) strlen(final_word);
				}
				else {
#ifdef DEBUG
					printf("temp:%s sizeof temp:%d\n", temp, (int) strlen(temp));
#endif
					char final_word[TOKEN_LEN] = "";
					strcpy(final_word, temp+1);
					final_word[strlen(final_word)] = temp[0];
					strcat(final_word, "ma");
					for (j=0;j<word_count;j++)
						strcat(final_word, "a");
					strcat(final_word, " ");
#ifdef DEBUG
					printf("%s strlen:%d\n", final_word, (int) strlen(final_word));
#endif

					strcpy(result+word_counts_total, final_word);
					word_counts_total += (int) strlen(final_word);
				}

				isFirstWord = 1;
				memset(temp, '\0', sizeof(temp));
				i = 0;
			}
			else {
				temp[i] = *S;
				if (isFirstWord == 1) {
					is_vowel = isVowel(temp[i]);
#ifdef DEBUG
					printf("is_vowel=%d\n", is_vowel);
#endif
					isFirstWord = 0;
				}

				if (*(S+1) == '\0') {
#ifdef DEBUG
					printf("words:%s\n", temp);
#endif
					word_count++;

					if (is_vowel == 1) {
#ifdef DEBUG
						printf("temp:%s sizeof temp:%d\n", temp, (int) strlen(temp));
#endif

						char final_word[TOKEN_LEN] = "";
						strcpy(final_word, temp);
						strcat(final_word, "ma");
						for (j=0;j<word_count;j++)
							strcat(final_word, "a");
						strcat(final_word, " ");
#ifdef DEBUG
						printf("%s strlen:%d\n", final_word, (int) strlen(final_word));
#endif

						strcpy(result+word_counts_total, final_word);
						word_counts_total += (int) strlen(final_word);
					}
					else {
#ifdef DEBUG
						printf("temp:%s sizeof temp:%d\n", temp, (int) strlen(temp));
#endif
						char final_word[TOKEN_LEN] = "";
						strcpy(final_word, temp+1);
						final_word[strlen(final_word)] = temp[0];
						strcat(final_word, "ma");
						for (j=0;j<word_count;j++)
							strcat(final_word, "a");
						strcat(final_word, " ");
#ifdef DEBUG
						printf("%s strlen:%d\n", final_word, (int) strlen(final_word));
#endif

						strcpy(result+word_counts_total, final_word);
						word_counts_total += (int) strlen(final_word);
					}
				}
				
				i++;				
			}
			
			S++;
		}

		//printf("word_counts_total=%d\n", word_counts_total);
		result[word_counts_total-1] = '\0';
		
	}
	
	return result;
}

int main()
{
	//char S[] = "I I I";
	char S[] = "I speak Goat Latin only";
	//char S[] = "The quick brown fox jumped over the lazy dog";
	printf("The input string is:\n%s\n", S);
	
	char *result = toGoatLatin(S);
	printf("result:\n%s\n", result);
	return 0;
}

/*
A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
For example, the word 'apple' becomes 'applema'.
 
If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".
 
Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin. 

 

Example 1:

Input: "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
Example 2:

Input: "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 

Notes:

S contains only uppercase, lowercase and spaces. Exactly one space between each word.
1 <= S.length <= 150.
*/
