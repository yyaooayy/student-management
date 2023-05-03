#include "list.h"

void help()
{
    cout<<"*****************************"<<endl;
    cout<<"help: messege for help      *"<<endl;
    cout<<"insert: insert elements     *"<<endl;
    cout<<"print: print all elements   *"<<endl;
    cout<<"delete: delete elements     *"<<endl;
    cout<<"free: release space         *"<<endl;
    cout<<"search: search th list      *"<<endl;
    cout<<"cls: clear the screen       *"<<endl;
    cout<<"quit: exit the exe          *"<<endl;
    cout<<"*****************************"<<endl;
}
# if 0
// insert through head
STU* insert_list(STU tmp, STU *head)
{
    // tmp.next = head;
    // head = &tmp;
    // return head;
    STU *p = new STU;
    *p = tmp;
    p->next = NULL;

    if(head == NULL)
    {
        head = p;
    }
    else if(head != NULL)
    {
        p->next = head;
        head = p;
    }
    return head;
    delete p;
}
# endif

# if 0
// insert through tail
STU* insert_list(STU tmp, STU *head)
{
    STU *p = new STU;
    *p = tmp;
    p->next = NULL;

    //STU *q = head;

    if(head == NULL)
    {
        head = p;
    }
    else if(head != NULL)
    {
        STU *q = head;
        while(q->next != NULL)
        {
            q = q->next;
        }
        q ->next = p;
    }
    return head;
    delete p;
}
# endif

# if 1
// insert base on sequences
STU* insert_list(STU tmp, STU *head)
{
    STU *present = new STU;
    *present = tmp;
    present->next = NULL;

    //STU *q = head;

    if(head == NULL)
    {
        head = present;
    }
    else if(head != NULL)
    {
        STU *helper1 = head;
        STU *helper2 = head;
        while((helper1->num <= present->num) && (helper1->next != NULL))
        {
            helper2 = helper1;
            helper1 = helper1->next;
        }
        if(helper1->num > present->num)
        {
            if(helper1 == head)
            {
                present->next = helper1;
                head = present;
            }
            else
            {
                present->next = helper1;
                helper2->next = present;
            }
        }
        else
        {
            helper1->next = present;
        }
    }
    return head;
    delete present;
}
# endif

void print_list(STU *head)
{
    if(head == NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    STU *p = head;
    while (p != NULL)
    {
        cout<<p->num<<" "<<p->name<<endl;
        p = p->next;
    }
    return;
}

STU* search_list(char *tmp_name, STU *head)
{
    STU *helper = head;
    if(helper == NULL)
    {
        cout<<"this is an empty list"<<endl;
        return NULL;
    }
    while(helper != NULL)
    {
        if(strcmp(helper->name,tmp_name) == 0)
        {
            return helper;
        }
        else
        {
            helper = helper->next;
        }
    }
    if(helper == NULL)
    {
        cout<<"this name isn't in this list"<<endl;
        return NULL;
    }
}

STU* delete_node(int tmp_num, STU *head)
{
    STU * helper1 = head;
    STU * helper2 = head;
    if(helper1 == NULL)
    {
        cout<<"list is empty"<<endl;
        return head;
    }
    if(head->num == tmp_num)
    {
        head = head->next;
        cout<<"deleted"<<endl;
        return head;
    }
    else
    {
        while (helper1 != NULL)
        {
            if(helper1->num != tmp_num)
            {
                helper2 = helper1;
                helper1 = helper1->next;
            }
            else if(helper1->num == tmp_num)
            {
                helper2->next = helper1->next;
                delete helper1;
                cout<<"deleted"<<endl;
                return head;
            }
        }
        cout<<"this num isn't in this list"<<endl;
        return head;
    }
}

STU* free_list(STU* head)
{
    if(head == NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else
    {
        STU *helper1 = head;
        while(helper1 != NULL)
        {
            head = head->next;
            delete helper1;
            helper1 = head;
        }
        cout<<"list is freed"<<endl;
    }
    return head;
}