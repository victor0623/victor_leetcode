#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool judgeCircle(char* moves) {
    int x=0, y=0;
    char *m = moves;
	
    while (*m != '\0') {
        printf("Move %c\n", *m);
        switch(*m) {
            case 'R':
                x++;
                break;
            case 'L':
                x--;
                break;
            case 'U':
                y++;
                break;
            case 'D':
                y--;
                break;
            default:
                break;
        }
        m++;
    }

    printf("final position: x=%d y=%d\n", x, y);

    if (x==0 && y==0)
        return true;
    else
        return false;
}

int main(void)
{
    char Input[] = "UDRL";
    if (judgeCircle(Input))
        printf("It's a circle!\n");
    else
        printf("It's not a circle!\n");

    return 0;
}