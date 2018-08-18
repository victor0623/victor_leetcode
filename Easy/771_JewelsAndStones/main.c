#include <stdio.h>
#include <string.h>

/* The slowest method: O(n^2)*/
int numJewelsInStones(char* J, char* S) {
    int num_j = 0;
    int i, k;

    if (J == NULL) {
    	printf("NULL pointer for J!\n");
    	return num_j;
    }

    if (S == NULL) {
    	printf("NULL pointer for S!\n");
    	return num_j;
    }

    if (strlen(J) > 50) {
    	printf("number of types for jewels is more than 50!\n");
    	return num_j;
    }

    if (strlen(S) > 50) {
    	printf("number of stones is more than 50!\n");
    	return num_j;
    }

    for (i=0;i<strlen(J);i++) {
    	char jewel_cur = J[i];

    	for (k=0;k<strlen(S);k++) {
    		char stone_cur = S[k];
    		if (stone_cur == jewel_cur)
    			num_j++;
    	}
    }

    return num_j;
}

int main(void)
{
	char J[] = "aAb";
	char S[] = "aAAbbbb";

	//printf("size of J=%d\tstrlen of J=%d\n", sizeof(J), strlen(J));
	//printf("size of S=%d\tstrlen of S=%d\n", sizeof(S), strlen(S));

	printf("J:%s\n", J);
	printf("S:%s\n", S);

	printf("number of jewels in stones is: %d\n", numJewelsInStones(J, S));
	return 0;
}