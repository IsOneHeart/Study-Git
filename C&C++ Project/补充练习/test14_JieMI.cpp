#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main()
{
	char ch = ' ';
	printf("ÇëÊäÈëÃÜÎÄ£º");
	while (ch != '\n') {
		ch = getchar();
		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
			ch = ch - 4;
			if ((ch > 'Z' && ch < 'a') || (ch < 'A'))
				ch = ch + 26;
		}
		printf("%c", ch);
	}
}