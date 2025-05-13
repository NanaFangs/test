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

int binary_search(int arr[],int target,int size) {
	int left = 0;
	int right = size - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == target) {
			return mid;
		}
		else if (arr[mid] > target) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return -1;
}
void self_add(int* a) {
	(*a)++;
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
	/*int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("before swap a:%d, b:%d\n", a, b);
	swap(&a, &b);
	printf("after swap a:%d, b:%d\n", a, b);*/

	//binary search
	/*int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int target = 5;
	int result = binary_search(arr, target, size);
	if (result != -1) {
		printf("Element found at index: %d\n", result);
	}
	else {
		printf("Element not found\n");
	}*/

	//self add number
	//int num = 0;
	//self_add(&num);
	//printf("%d\n", num); // 1
	//self_add(&num);
	//printf("%d\n", num);//2
	//self_add(&num);
	//printf("%d\n", num);//3
	//self_add(&num);
	//printf("%d\n", num);//4

	//nested function

}