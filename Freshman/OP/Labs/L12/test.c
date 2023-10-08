#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LINE_LEN 2048


int main() {
    char line[15] = {'4','6','d','\0','3'};
	char t[15] = {'4','k','d','\0','3'};
	printf("%d\n", strcmp(t, line));
}

