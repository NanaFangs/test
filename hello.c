#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//#include "Source.c"
//extern int a; 
//extern void test(); 

//#define MAX 100
//#define STR "hello world"

//enum Color {
//	RED,
//	GREEN,
//	BLUE
//};
//enum Sex
//{
//	MALE,
//	FEMALE
//};
//int main() {
//	/*printf("hello world\n");
//	printf("hehe\n");*/
//
//	//printf("%zu\n", sizeof(char)); //1
//	//printf("%zu\n", sizeof(short)); //2
//	//printf("%zu\n", sizeof(int)); //4
//	//printf("%zu\n", sizeof(long)); //4
//	//printf("%zu\n", sizeof(long long));//8
//	//printf("%zu\n", sizeof(float));//4
//	//printf("%zu\n", sizeof(double));//8
//
//	//int num1 = 0;
//	//int num2 = 0;
//	////num1 = 1;
//	////printf("%d\n", num1);
//	//scanf("%d %d", &num1, &num2);
//	//int sum = num1 + num2;
//	//printf("%d\n", sum);
//
//
//	/*test();
//	{
//		printf("a=%d\n", a);
//
//	}
//	printf("main a=%d\n", a);
//	*/
//
//	//const int a = 10;
//	//a = 20; //error: assignment of read-only variable 'a'
//
//	/*printf("%d\n", MAX);
//	printf("%s\n", STR);
//	enum Color c = RED;
//	enum Sex mySex = MALE;*/
//
//	//char arr1[] = "abcdef";//"abcdef\0"
//	////char arr2[] = {'a','b','c','d','e','f'}; String end with \0
//	//char arr3[] = {'a','b','c','d','e','f','\0'};
//
//	//int len = strlen(arr1);
//
//
//	//printf("%s\n", arr1);
//	////printf("%s\n", arr2);
//	//printf("%s\n", arr3);
//	//printf("%d\n", len);//6
//	//printf("%d\n", strlen(arr3));//6
//	
//	return 0;
//}
//
int add(int a, int b) {
	return a + b;
}

struct Student {
	int id;
	int age;
	char name[20];
	int sex;//0 for men, 1 for women
};
void printStu(struct Student* ps) {
	printf("%d\n", ps->id);
	printf("%d\n", ps->age);
	printf("%s\n", ps->name);
	printf("%d\n", ps->sex);
	//same
	printf("%d %d %s %d\n", (*ps).id, (*ps).age, (*ps).name, (*ps).sex);
}
int main() {
	//Control sentences
	/*int input = 0;
	scanf("%d", &input);
	if (input == 0) {
		printf("fw\n");
	}
	else {
		printf("else\n");
	}*/
	
	//function
	/*int num1 = 0;
	int num2 = 0;
	printf("input num1 and num2\n");
	scanf("%d %d", &num1, &num2);
	int sum = add(num1, num2);
	printf("sum = %d\n", sum);*/

	// array
	/*int arr2[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2len = sizeof(arr2) / sizeof(arr2[0]);
	printf("%d\n", arr2len);
	for (int i = 0; i < arr2len; i++) {
		printf("%d\n", arr2[i]);
	}
	int i = 0;*/

	//pointer
	/*int a = 10;
	printf("%d\n", a);
	int* p = &a;
	printf("%p\n", p);
	*p = 20;
	printf("%d\n", a);*/

	//struct
	//struct Student stu1 = {	1,16,"zhangsan",0};
	//struct Student stu2 = { 2,17,"lisi",1 };
	///*printf("%d\n", stu1.id);
	//printf("%d\n", stu1.age);
	//printf("%s\n", stu1.name);
	//if (stu1.sex == 0) {
	//	printf("man\n");
	//}
	//else {
	//	printf("woman\n");
	//}*/
	//printStu(&stu2);

	//switch
	/*int m = 1;
	int n = 2;
	switch (n)
	{
	case 1:
		printf("case 1\n");
		break;
	case 2:
		printf("case 2\n");
		break;
	case 3:	
		printf("case 3\n");
		break;
	default:
		break;
	}*/

	// getchar(), return int, putchar(), print char
	/*int ch = 0;
	while ((ch = getchar()) != EOF) {
		putchar(ch);
	}*/
	char password[20] = { 0 };
	printf("input password\n");
	scanf("%s", password);// scanf can't read space
	int ch = 0;
	while ((ch = getchar()) != '\n' && ch != EOF) {
		
	}
	printf("confirm password(Y/N)\n");
	char confirm = getchar();
	if (confirm == 'Y' || confirm == 'y') {
		printf("password is %s\n", password);
	}
	else if (confirm == 'N' || confirm == 'n') {
		printf("cancel\n");
	}
	else {
		printf("error\n");
	}
	return 0;
}