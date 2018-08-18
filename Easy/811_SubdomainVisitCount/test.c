#include <stdio.h>

int main(void)
{
	int val = 43981;
	int *p = &val;
	p++;

	printf("val = 0x%x[%d]\n", val, val);
	printf("output = 0x%x\n", *((unsigned char *) &val));
	return 0;
}
