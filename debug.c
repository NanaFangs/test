#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int add(int x, int y) {
	return x + y;
}
int main() {
	int a = 10;
	int b = 20;
	int c = add(a, b);
	printf("The sum of %d and %d is %d\n", a, b, c);
	return 0;
}