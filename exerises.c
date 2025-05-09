#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int binarySearch(int arr[], int size, int target) {
//	int left = 0;
//	int right = size - 1;
//	while (left <= right) {
//		int mid = left + (right - left) / 2;
//		if (arr[mid] == target) {
//			return mid;
//		}
//		else if (arr[mid] < target) {
//			left = mid + 1;
//		}
//		else {
//			right = mid - 1;
//		}
//	}
//	return -1; // target not found
//}

//void merge(int arr[], int left, int mid, int right) {
//	int n1 = mid - left + 1;
//	int n2 = right - mid;
//	int* L = (int*)malloc(n1 * sizeof(int)); //temp left subarray
//	int* R = (int*)malloc(n2 * sizeof(int)); //temp right subarray
//
//	for (int i = 0; i < n1; i++) {
//		L[i] = arr[left + i];
//	}
//	for (int j = 0; j < n2; j++) {
//		R[j] = arr[mid + 1 + j];
//	}
//	int i = 0; // Initial index of first subarray
//	int j = 0; // Initial index of second subarray
//	int k = left; // Initial index of merged subarray
//	while (i < n1 && j < n2) {
//		if (L[i] <= R[j]) {
//			arr[k] = L[i];
//			i++;
//		}
//		else {
//			arr[k] = R[j];
//			j++;
//		}
//		k++;
//	}
//	
//	while (i < n1) {
//		arr[k] = L[i];
//		i++;
//		k++;
//	}
//
//	while (j < n2) {
//		arr[k] = R[j];
//		j++;
//		k++;
//	}
//	free(L);
//	free(R);
//}

//void mergeSort(int arr[], int left, int right) {
//	/*if (left < right) {
//		int mid = left + (right - left) / 2;
//		mergeSort(arr, left, mid);
//		mergeSort(arr, mid + 1, right);
//		merge(arr, left, mid, right);
//	}*/
//	if (left >= right) return;
//	int mid = left + (right - left) / 2;
//	mergeSort(arr, left, mid);
//	mergeSort(arr, mid + 1, right);
//	merge(arr, left, mid, right);
//}

void menu() {
	printf("1. PLAY\n");
	printf("0. EXIT\n");
}
void game() {
	//1. random number
	//0~32767
	int ret = rand()%100+1;
	//printf("Random number is %d\n", ret);
	//2. guess a number, limit 5 times
	int guess = 0;
	int num = 0;
	while (num<5) {
		printf("Guess a number between 1 and 100: ");
		scanf("%d", &guess);
		if (guess > ret) {
			printf("Too high\n");
			printf("You have %d chances left\n", 4 - num);
		}
		else if (guess < ret) {
			printf("Too low\n");
			printf("You have %d chances left\n", 4 - num);
		}
		else {
			printf("You guessed it!\n");
			break;
		}
		num++;
	}
	
}
int main() {
	//factorial of a number
	/*int n = 0;
	int res = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		res *= i;
	}
	printf("%d! is %d\n",n, res);*/

	//cal 1!+2!+3!+4!+5!+..+10!
	//int res = 0;
	/*for (int i = 1; i <= 10; i++) {
		int sub = 1;
		for (int j = 1; j <= i; j++) {
			sub *= j;
		}
		res += sub;
	}*/
	/*int ret = 1;
	for (int i = 1; i <= 10; i++) {
		ret *= i;
		res += ret;
	}
	printf("1!+2!+3!+4!+5!+..+10! = %d\n", res); */

	//binary search
	/*int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int target = 5;
	int result = binarySearch(arr, size, target);
	if (result != -1) {
		printf("Element found at index %d\n", result);
	}
	else {
		printf("Element not found\n");
	}*/

	//merge sort
	/*int arr[] = { 38, 27, 43, 3, 9, 82, 100 };
	int size = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr, 0, size - 1);
	printf("Sorted array: \n");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");*/

	//Guess number
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("Enter your choice: ");
		scanf("%d", &input);
		switch (input) {
		case 1:
			printf("Guess a number\n");
			game();
			break;
		case 0:
			printf("Exit\n");
			break;
		default:
			printf("Invalid choice\n");
			break;

		}
		
	} while (input);
	

	//goto
	/*char input[20] = { 0 };
again:
	printf("Enter a string: ");
	scanf("%s", input);
	if (strcmp(input, "hello") == 0) {
		printf("Hello, world!\n");
	}
	else {
		goto again;
	}*/
	return 0;
}