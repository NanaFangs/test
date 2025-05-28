#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "add.h"
#include "sub.h"

//recursion version
void printNum(unsigned int n) {
	if (n < 10) {
		printf("%d ", n);
		return;
	}
	printNum(n / 10);
	printf("%d ", n % 10);
}


//non-recursion version
int my_strLen(char* s) {
	int count = 0;
	while (*s != '\0') {
		count++;
		s++;
	}
	return count;
}
//recursion version
int my_strLenR(char* s) {
	if (*s == '\0') {
		return 0;
	}
	else {
		return 1 + my_strLenR(s + 1);
	}
}

int factorial(int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}
//non-recursion version
int factorialN(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}
//fibnacci series ex: 0 1 1 2 3 5 8 13 21
int fibonacci(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}
// dynamic programming version
int fibonacciDP(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		int a = 0;
		int b = 1;
		int c = 0;
		for (int i = 2; i <= n; i++) {
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
}

//reverse String
//recursion version
void reverseString(char* str, int start, int end) {
	if (start >= end) {
		return;
	}
	
	char temp = str[start];
	str[start] = str[end];
	str[end] = temp;
	reverseString(str, start + 1, end - 1);
}
//a b c d e f g \0
//g b c d e f \0-a
//g f c d e \0-b a
//g f e d \0-c b a
void reverse(char* str) {

	char tmp = *str;
	int len = strlen(str);
	*str = *(str + len - 1);
	*(str + len - 1) = '\0'; // null terminate the string
	if (strlen(str + 1) >= 2) {
		reverse(str + 1);
	}
	*(str + len - 1) = tmp; // restore the last character

}
//recursion 
//ex : 1729 =1 + 7 + 2 + 9 = 19
int digitSum(unsigned int n) {
	if (n == 0) {
		return 0;
	}
	else {
		return (n % 10) + digitSum(n / 10);
	}
	
}
//power(n, k)
//n^k = n * n * n * n * n
double power(int n, int k) {
	if (k > 0) {
		return n * power(n, k - 1);
	}
	else if(k==0){
		return 1;
	}
	else {
		return 1.0 / power(n, -k);
	}
}
long long power2(int a, int b) {
	if (b == 0) {
		return 1;
	}
	if (a == 0) {
		return 0;
	}

	long long half = power2(a, b / 2);

	if (b % 2 == 0) {
		return half * half;
	}
	else {
		return a * half * half;
	}
}
int main() {
	/*int a = 0;
	int b = 0;
	scanf("%d %d", &a,&b);
	int sum = Add(a, b);
	printf("%d\n", sum);
	int diff = Sub(a, b);
	printf("%d\n", diff);*/
	//recursion

	//input a number ex:1234 ouput : 1 2 3 4
	/*unsigned int n = 0;
	scanf("%d", &n);
	print(n);*/
	
	//write a funcion to get the length of string
	//input : "hello world" output : 11
	/*char s[] = "hello world";
	int len = my_strLen(s);
	printf("%d\n", len);*/

	//fibnacci series
	/*int n = 0;
	scanf("%d", &n);
	int res = fibonacciDP(n);
	printf("%d th fibnacci number is %d\n",n,res);*/

	//reverse string
	//char str[] = "hello world";//[h e l l o  w o r l d]
	//int left = 0;
	//int size = sizeof(str) / sizeof(str[0]);//currently 12, need to -1 because of null terminator'\0', so actullay size is 11
	//int right = size - 2; // -2 to ignore the null terminator
	//reverseString(str, left, right);
	//printf("string size: % d\n", size);
	//printf("left : %d\n", left);
	//printf("right : %d\n", right);

	//char str[] = "abcdefg";// [a b c d e f g \0]
	char str[] = "abcdef"; // [a b c d e f g \0]
	reverse(str);
	printf("reversed string is : %s\n", str);

	// digit sum
	/*unsigned int n = 1729;
	int sum = digitSum(n);
	printf("digit sum of %d is %d\n", n, sum);*/

	//power
	/*int n = 2;
	int k = 3;
	double res = power(n, k);*/
	


	return 0;
}
