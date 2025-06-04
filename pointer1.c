#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define N_VALUES 5

int* test() {
	int a = 10;
	return &a; // return the address of a
}

int my_strlen(char* str) {
	// this function calculates the length of a string
	int len = 0;
	while (*str != '\0') { // loop until we reach the null terminator
		len++;
		str++; // move to the next character
	}
	return len; 
}

void test2(int* arr,int size) {
	for (int i = 0; i < size; i++) {
		printf("arr[%d] = %d\n", i, *(arr+i));
	}
}
int main() {
	//int a = 10; //a is a variable, take 4 bytes in memory
	//int* p = &a; //p is a pointer, take 4 bytes in memory, it stores the address of a
	
	//pointer is a variable that stores the address of another variable
	//pointer is addressing operator, it returns the address of a variable
	

	// types of pointers:
	//char* pc = NULL; //pc is a pointer to char, it can store the address of a char variable
	//short* ps = NULL; //ps is a pointer to short, it can store the address of a short variable
	//int* pi = NULL; //pi is a pointer to int, it can store the address of an int variable
	//float* pf = NULL; //pf is a pointer to float, it can store the address of a float variable
	//double* pd = NULL; //pd is a pointer to double, it can store the address of a double variable
	//printf("%zu\n", sizeof(pc));
	//printf("%zu\n", sizeof(ps));
	//printf("%zu\n", sizeof(pi));
	//printf("%zu\n", sizeof(pf));
	//printf("%zu\n", sizeof(pd));
	//int a = 0x11223344;
	//int* p = &a; //p is a pointer to int, it can store the address of an int variable
	//*p = 0; //dereferencing the pointer p, it will change the value of a to 0
	//1. the type of pointer decide how many bytes it will read when dereferencing
	//ex , when here we use char* pc = &a; *pc=0;
	//it will read 1 byte from the address of a, and change the value of a to 0x11223300
	//char* pc = (char*)&a; //pc is a pointer to char, it can store the address of a char variable
	//printf("p = %p\n", p);
	//printf("p + 1 = %p\n", p+1);
	//printf("pc = %p\n", pc);
	//printf("pc + 1 = %p\n", pc+1);
	//2. the type of pointer decide when you add or subtract the pointer, how many bytes it will add or subtract

	//wild pointer: a pointer that is not initialized to point to a valid memory location
	/*int* p;
	*p = 10;*/// this will cause a segmentation fault, because p is not initialized to point to a valid memory location

	//int arr[10] = { 0 };
	//int* pArr = arr; //&arr[0], pArr is a pointer to the first element of the array arr 
	//for (int i = 0; i <= 10; i++) {
	//	*pArr = i;
	//	pArr++; //increment the pointer to point to the next element of the array
	//}

	//int* p = NULL;// p is a pointer to int, it can store the address of an int variable
	//*p = 100; //this will cause a segmentation fault, because p is not initialized to point to a valid memory location

	//int* p = test(); // p now points to the address of a local variable in test()
	//if (p != NULL) {
	//	printf("Value pointed by p: %d\n", *p); // this will print the value of a, but it is undefined behavior
	//}
	//else {
	//	printf("Pointer is NULL\n");
	//}

	//pointer -pointer arithmetic
	//only if two pointers point to a same space/ address 
	/*int arr[10] = { 0 };
	printf("%d\n", &arr[9] - &arr[0]);*/// this will print 9, because it calculates the number of elements between the two addresses

	//printf("Length of string: %d\n", my_strlen("Hello, World!")); // this will print the length of the string

	/*char values[N_VALUES];
	//reminder better use the pointer after the array,m not the one infront of the array
	for (char* vp = &values[N_VALUES]; vp > &values[0];) {
		*--vp = 0;
	}
	for (int i = 0; i < N_VALUES; i++) {
		printf("values[%d] = %d\n", i, values[i]);
	}*/

	//array and pointer
	//int arr[10] = { 0 };
	////arr is the address of the first element of the array, it is equivalent to &arr[0]
	//int* pArr = arr; // pArr is a pointer to the first element of the array arr
	//int size = sizeof(arr) / sizeof(arr[0]); // calculate the size of the array
	//for (int i = 0; i < size; i++) {
	//	*(pArr + i) = i + 1; // assign values to the array using pointer arithmetic
	//}
	//for (int i = 0; i < size; i++) {
	//	printf("arr[%d] = %d = %d =%d\n", i, *(pArr + i),*(arr+i), arr[i]); // print the values of the array using pointer arithmetic
	//}
	//for (int i = 0; i < size; i++) {
	//	printf("%p --- %p \n", &arr[i], pArr+i);
	//}

	//二级指针
	//int** ppa; // ppa is a pointer to a pointer to int, it can store the address of a pointer variable to int
	// type of ppa is int**
	//&pointer is the address of the pointer, it is not the address of the variable it points to
	//int a = 10;
	//int* pa = &a; // pa is a pointer to int, it can store the address of an int variable
	//int** ppa=&pa; // this will give the address of the pointer pa, not the address of a
	//*(*ppa) = 50;
	// this will change the value of a to 50, because we dereference ppa to get pa, and then dereference pa to get a
	//printf("Value of a: %d\n", a); // this will print 50, because we changed the value of a using the pointer ppa
	//*pa = 20;
	//printf("Value of a: %d\n", a); // this will print 20, because we changed the value of a using the pointer pa

	//pointer array
	int a = 10, b = 20, c = 30;
	int* pa = &a; // pa is a pointer to int, it can store the address of an int variable
	int* pb = &b; // pb is a pointer to int, it can store the address of an int variable
	int* pc = &c; // pc is a pointer to int, it can store the address of an int variable

	int arr[10];
	int* parr[10] = {&a,&b,&c}; // parr is an array of pointers to int, it can store the addresses of int variables
	for (int i = 0; i < 3; i++) {
		printf("parr[%d] = %d\n", i, *(parr[i])); // print the values of the variables pointed by the pointers in the array
	}

	int arr1[4] = { 1, 2, 3, 4 };
	int arr2[4] = { 5, 6, 7, 8 };
	int arr3[4] = { 9, 10, 11, 12 };

	int* parr2[3] = { arr1, arr2, arr3 }; // parr2 is an array of pointers to int arrays, it can store the addresses of int arrays
	for (int i = 0; i < 3; i++) {
		printf("parr2[%d] = ", i);
		for (int j = 0; j < 4; j++) {
			//printf("%d ", *(parr2[i] + j)); // print the values of the arrays pointed by the pointers in the array
			printf("%d ", parr2[i][j]); // this is equivalent to *(parr2[i] + j)
		}
		printf("\n");
	}

	return 0;
}