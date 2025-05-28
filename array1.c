#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(int arr[], int size);
void bubbleSort2(int* arr, int size);
int main() {
	// array declaration
	// type_t arr_name[const_size];
	//1-D array
	//int arr[5]; // array of 5 integers
	//char ch[10]; // array of 10 characters
	//double d[5]; // array of 5 doubles

	////only in machine support C99 standard
	////int n = 10;
	////int arr2[n]; // array of n integers

	//int arr2[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; //1,2,3,4,5,6,7,8,9,10
	//int arr3[10] = { 1,2,3 }; // 1,2,3,0,0,0,0,0,0
	//int arr4[] = { 1,2,3 }; // 1,2,3

	//int size = sizeof(arr2) / sizeof(arr2[0]); // size of array
	//for (int i = 0; i < size; i++) {
	//	printf("%d ", arr2[i]);
	//}
	//// print address of array
	//for (int i = 0; i < size; i++) {
	//	printf("&arr2[%d]= %p\n",i,&arr2[i]);
	//}

	//char ch1[10] = { 'a', 'b', 'c' }; // 'a','b','c','\0','\0','\0','\0','\0','\0','\0
	//char ch2[10] = "abc"; // 'a','b','c','\0','\0','\0','\0','\0','\0','\0
	//char ch3[] = "abc"; // 'a','b','c','\0'
	//char ch4[] = { 'a', 'b', 'c' }; // 'a','b','c'

	//2-D array
	//int arr[3][4]; // 2-D array of 3 rows and 4 columns
	////2-D array initialization
	//int arr2[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
	//int arr3[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 }; // same as arr2
	//int arr4[][4] = { {1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } }; // can ignore row size,but not column size
	//int rowsize = sizeof(arr2) / sizeof(arr2[0]); // row of array
	//int colsize = sizeof(arr2[0]) / sizeof(arr2[0][0]); // col of array
	//printf("row size = %d\n", rowsize);
	//printf("col size = %d\n", colsize);
	//for (int i = 0; i < rowsize; i++) {
	//	for (int j = 0; j < colsize; j++) {
	//		printf("%d ", arr2[i][j]);
	//	}
	//	printf("\n");
	//}
	//for (int i = 0; i < rowsize; i++) {
	//	for (int j = 0; j < colsize; j++) {
	//		printf("&arr[%d][%d]= %p ",i,j,&arr2[i][j]);
	//	}
	//	printf("\n");
	//}

	//array name in 1-D array
	//int arr[] = { 9,8,7,6,5,4,3,2,1 };
	//array name is the pointer of the first element of the array
	//but there are two example:
	//1. sizeof(arrname) will return the size of the array
	//2/ &arrname will return the address of the array
	//printf("%p \n", arr);// arr i s the address of the first element of the array
	//printf("%p \n", arr + 1);// arr+1 is the address of the second element of the array
	//printf("-----------\n");
	//printf("%p \n", &arr[0]);// &arr[0] is the address of the first element of the array
	//printf("%p \n", &arr[0] + 1);// &arr[0]+1 is the address of the second element of the array
	//printf("-----------\n");
	//printf("%p \n", &arr);// &arr is the address of the array
	//printf("%p \n", &arr + 1);// &arr+1 is the address of the end of array

	//array name in 2-D array
	int arr2[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
	int size = sizeof(arr2);
	printf("%d \n", size);// 48
	printf("%p \n", arr2);// arr2 is the address of the first element of the 2-D array which is the address of the first row
	printf("%p \n", arr2 + 1);// arr2+1 is the address of the second row of the 2-D array
	int rowsize = sizeof(arr2) / sizeof(arr2[0]); // row of array
	int colsize = sizeof(arr2[0]) / sizeof(arr2[0][0]); // col of array
	int numElements = sizeof(arr2) / sizeof(arr2[0][0]); // number of elements in the array
	printf("row size = %d\n", rowsize);
	printf("col size = %d\n", colsize);
	printf("numElements = %d\n", numElements);


	// array as parameter of function
	//bubble sort
	/*int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}*/

	return 0;
}
//directly use array as parameter of function
void bubbleSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
//use pointer as parameter of function
void bubbleSort2(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (*(arr + j) > *(arr + j + 1)) {
				int tmp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = tmp;
			}
		}
	}
}