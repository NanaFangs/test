#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct definition
// 
//struct tag {
//	member-list
//} variable-list;



struct Peo {
	char name[20];
	char tele[12];
	char sex[10];
	int age;
	float height;
}p1,p2;
// p1, p2 are variables of type struct Peo
//these are not necessary to define the struct, but they are instances of the struct

struct student {
	struct Peo info; // struct Peo is a member of struct student
	float score;
};
// better use print method to print struct members
// print method is a function that takes a pointer to struct Peo and prints its members
// it will save the memory when passing the struct to the function
void print(struct Peo* p) {
	printf("Name: %s, tele: %s, sex: %s,age: %d, height:%f\n", p->name,p->tele,p->sex,p->age,p->height);
}

void print2(struct Peo p) {
	printf("Name: %s, tele: %s, sex: %s,age: %d, height:%f\n", p.name, p.tele, p.sex, p.age, p.height);
}
int main() {
	//struct
	struct Peo p1 = { "Fang","15190478968","male",22,178 };
	printf("Name: %s, tele: %s, sex: %s,age: %d, height:%f\n", p1.name,p1.tele,p1.sex,p1.age,p1.height);


	struct student stu1 = { {"zhangsan","13739132456","female",55,168},100};
	
	printf("%s %s %s %d %f %f\n",stu1.info.name,stu1.info.tele,stu1.info.sex,stu1.info.age,stu1.info.height,stu1.score);
	printf("change value in p1\n");
	p1.age = 30;
	strcpy(p1.name, "Lisi");
	print(&p1);
	print2(p1);

	return 0;
}