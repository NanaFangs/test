#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_max(int a, int b) {
	return (a > b) ? a : b;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	//library function
	//char arr[10] = { 0 };
	//char arr2[20] = "hello world";
	//memset(arr2, 'x', 1);
	//printf("%s\n", arr2); // xello world
	//memset(arr2, 'x', 5);
	//printf("%s\n", arr2); // xxxxx world
	//memset(arr, 'A', sizeof(arr) - 1);
	////printf(sizeof(arr)); // 10
	//arr[9] = '\0'; // Ensure null termination
	//printf("%s\n", arr); // AAAAAAAAAA

	//printf("%d\n", sizeof(arr)-1); // 10

	//maxnum
	/*int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int max = get_max(a, b);
	printf("%d\n", max); */

	//swap two numbers
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("before swap a:%d, b:%d\n", a, b);
	swap(&a, &b);
	printf("after swap a:%d, b:%d\n", a, b);


}