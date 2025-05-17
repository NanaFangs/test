#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "add.h"
#include "sub.h"

void print(unsigned int n) {
	if (n < 10) {
		printf("%d ", n);
		return;
	}
	print(n / 10);
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
	int n = 0;
	scanf("%d", &n);
	int res = fibonacciDP(n);
	printf("%d th fibnacci number is %d\n",n,res);

	return 0;
}
