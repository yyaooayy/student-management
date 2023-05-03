#include <iostream>
#include "list.h"
#include <string.h>
using namespace std;

STU *head;
int main()
{
    help();

    while(1)
    {
        char cmd[64] = "";
        cout<<"please type in command: ";
        cin>>cmd;

        if(strcmp(cmd, "help") == 0)
        {
            help();
        }
        else if(strcmp(cmd, "insert") == 0)
        {
            cout<<"please input the new number and new name: ";
            STU tmp;
            cin>>tmp.num>>tmp.name;
            head = insert_list(tmp, head);
        }
        else if(strcmp(cmd, "print") == 0)
        {
            print_list(head);
        }
        else if(strcmp(cmd, "delete") == 0)
        {
            cout<<"please input the number you want to delete: ";
            int tmp_num = 0;
            cin>>tmp_num;
            head = delete_node(tmp_num, head);
        }
        else if(strcmp(cmd, "free") == 0)
        {
            head = free_list(head);
        }
        else if(strcmp(cmd, "search") == 0)
        {
            cout<<"please input the name that you want to search: ";
            char tmp_name[32];
            cin>>tmp_name;
            STU *helper1;
            helper1 = search_list(tmp_name, head);
            if(helper1 != NULL)
            {
                cout<<helper1->num<<" "<<helper1->name<<endl;
            }
        }
        else if(strcmp(cmd, "cls") == 0)
        {
            system("cls");
        }
        else if(strcmp(cmd, "quit") == 0)
        {
            head = free_list(head);
            exit(-1);
        }
    }
    return 0;
}