#include <stdio.h>
#include <stdlib.h>

//#define DEBUG

int binaryGap(int N) {
	int temp = N, mod_temp;
	int curr_max_dist = 0, isEmpty = 1, bindex = 0;
	int curr_one_index, previous_one_index, temp_dist;

	while(temp != 0) {
#ifdef DEBUG
		printf("temp:%d\n", temp);
#endif
		mod_temp = temp % 2;
#ifdef DEBUG
		printf("poped_binary:%d\n", mod_temp);
#endif

		if (mod_temp == 1) {
			if (isEmpty) {
				curr_one_index = bindex;
				isEmpty = 0;
			}
			else {
				previous_one_index = curr_one_index;
				curr_one_index = bindex;
				temp_dist = curr_one_index - previous_one_index;
				if (temp_dist > curr_max_dist) 
					curr_max_dist = temp_dist;

#ifdef DEBUG
				printf("curr_max_dist=%d\n", curr_max_dist);
#endif
			}
		}

		temp /= 2;
		bindex++;
	}

    return curr_max_dist;
}

int main(void)
{
	int Input = 22;
	printf("Input:%d\n", Input);
	int Output = binaryGap(Input);
	printf("Output=%d\n", Output);
	return 0;
}

/*
Given a positive integer N, find and return the longest distance between two consecutive 1's in the binary representation of N.

If there aren't two consecutive 1's, return 0.

 

Example 1:

Input: 22
Output: 2
Explanation: 
22 in binary is 0b10110.
In the binary representation of 22, there are three ones, and two consecutive pairs of 1's.
The first consecutive pair of 1's have distance 2.
The second consecutive pair of 1's have distance 1.
The answer is the largest of these two distances, which is 2.
Example 2:

Input: 5
Output: 2
Explanation: 
5 in binary is 0b101.
Example 3:

Input: 6
Output: 1
Explanation: 
6 in binary is 0b110.
Example 4:

Input: 8
Output: 0
Explanation: 
8 in binary is 0b1000.
There aren't any consecutive pairs of 1's in the binary representation of 8, so we return 0.
*/