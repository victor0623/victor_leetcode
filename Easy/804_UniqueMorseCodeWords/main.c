#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *morse_mapping[26] = {".-","-...","-.-.","-..",".","..-.","--.","....",\
	                     "..",".---","-.-",".-..","--","-.","---",".--.","--.-",\
	                     ".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

//#define DEBUG
#define WORDS_SIZE 100
#define PATTERN_SIZE 50

void print_pattern_list(char ** pattern_list, int size)
{
	int i;
	for (i=0;i<size;i++) {
		printf("pattern[%d]:%s\n", i, pattern_list[i]);
	}
}

void add_pattern(char * pattern, char ** pattern_list, int index)
{
#ifdef DEBUG
	printf("add pattern: %s\tindex is:%d\n", pattern, index);
#endif
	pattern_list[index] = (char *) malloc(sizeof(char) * PATTERN_SIZE);
	strcpy(pattern_list[index], pattern);
	return;
}

int uniqueMorseRepresentations(char** words, int wordsSize) {
    int num = 0;
    int i, j, p;
    int pattern_num = 0;

    char **pattern_list = (char **) malloc(sizeof(char *) * wordsSize);

    for (i=0;i<wordsSize;i++) {
    	int isFound = 0;
    	char current[PATTERN_SIZE] = {'\0'};
#ifdef DEBUG
		printf("%s:", words[i]);
#endif

		for (j=0;j<strlen(words[i]);j++) {
#ifdef DEBUG
			printf("%s", morse_mapping[words[i][j] - 97]);
#endif
			strcat(current, morse_mapping[words[i][j] - 97]);
		}

#ifdef DEBUG
		printf("\n");
		printf("current pattern: %s\n", current);
#endif

		//try to find
		for (p=0;p<pattern_num;p++) {
#ifdef DEBUG
			printf("current:%s\tpattern:%s\n", current, pattern_list[p]);
#endif
			if (!strcmp(current, pattern_list[p])) {
				isFound = 1;
				
				break;
			}
		}

		//no pattern found, add a new one
		if (isFound == 0) {
#ifdef DEBUG
			printf("no pattern found\n");
#endif
			add_pattern(current, pattern_list, pattern_num);
			pattern_num++;
		}

#ifdef DEBUG
		printf("\n");
#endif
    }

#ifdef DEBUG
    print_pattern_list(pattern_list, pattern_num);
#endif

    return pattern_num;
}

int main()
{
	int i;
	//char *words[WORDS_SIZE] = {"gin", "zen", "gig", "msg"};
	char *words[WORDS_SIZE] = {"bedqz","duukz","iqsken","iqsnc","frtsat","frbw","oaikq","tmlkq","xfyy","ddcow","xicow","xurow","lubu","rvbu","vvh","vvii","irues","sbth","sdah","veeah","vvh","vvh","vvh","iruh","vsth","sbns","vvh","rbnz","arfz","rnfz","oaikq","tmlkq","dayvs","btysb","bqbb","tcgw","tnyut","gyeat","qadm","qpem","gyew","qpw","qpw","qezm","gyut","qpw","qegw","qwut","gngw","clmva","caubk","iqsken","iqsnc","qmhup","gohfg","jcmut","wqpw","ygleu","kofht","xfyy","xicow","ddcow","xurow","ayrzs","egqph","fduo","uluo","fbao","fnvo","fbwm","lobzq","lmmvxk","ohlo","ohlo","ixgz","ueagz","fjez","uugz","fjpe","duukz","bedqz","gutjf","zwjue","zwjf","tbmwtf","qmhup","gohfg","mjhij","qzhj","xjiq","xjiq","orsk","mkhk","ohlo","ohlo","xjiq","xjiq","ygleu","kofht","jitgi"};

	printf("the number of different transforms is: %d\n", uniqueMorseRepresentations(words, WORDS_SIZE));

	return 0;
}
