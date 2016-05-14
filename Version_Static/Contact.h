#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <windows.h>

#ifndef __CONTACT_H__
#define __CONTACT_H__

enum OP
{
	EXIT,
	ADD,
	DEL,
	MODIFY,
	SEARCH,
	DISPLAY,
	SORT,
	CLEAR,
};

#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 25
#define MAX 1000

typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char address[ADDR_MAX];
}PeoInfo;//每一个人的信息用一个结构来接收，包括姓名，性别，年龄，电话，地址

typedef struct Contact
{
	PeoInfo data[MAX];//将通讯录和人员计数也声明在结构体里
	int size;
}Contact,*Pcon;

void _init_contact(Pcon pcon);
void _add_contact(Pcon pcon);
void _del_contact(Pcon pcon);
void _modify_contact(Pcon pcon);
void _search_contact(Pcon pcon);
void _display_contact(Pcon pcon);
void _sort_contact(Pcon pcon);
void _clear_contact(Pcon pcon);

#endif //__CONTACT_H__
