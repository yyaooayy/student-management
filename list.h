#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string.h>
using namespace std;

//定义链表节点类型
struct STU
{
    //数据域
    int num;
    char name[32];

    //指针域
    STU *next;
};

extern void help();
extern STU* insert_list(STU tmp, STU *head);
extern void print_list(STU *head);
extern STU* search_list(char *tmp_name, STU *head);
extern STU* delete_node(int tmp_num, STU *head);
extern STU* free_list(STU* head);
#endif //LIST_H