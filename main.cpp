#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <windows.h>
using namespace std;

struct List{
    int data;
    List *next;
    };

void Work(List *);//工作界面

void Input(List *);//新建一个链表

void Ins(List *);//在某个节点插入一个元素

void Del(List *);//删除某个节点

void Output(List *);//打印整个链表

void Clean(List *);//清空链表

int main()
{
    List *head,*now;
    head=(List *) malloc(sizeof(List));
    now=head;
    Work(head);
    return 0;
}


void Work(List *head){
    system("cls");
    cout<<"1.新建链表"<<endl;
    cout<<"2.插入一个元素"<<endl;
    cout<<"3.删除一个元素"<<endl;
    cout<<"4.清空链表"<<endl;
    int choice;
    cin>>choice;
    switch (choice){
        case 1:Input(head);break;
        case 2:Ins(head);break;
        case 3:Del(head);break;
        case 4:Clean(head);break;
        }
    Output(head);
    system("pause");
    Work(head);

}

void Input(List *head){
  //  system("cls");
    cout<<"请输入数据"<<endl;
    int num;
    cin>>num;
    List *now=head;
    while(num!=-1){
        List *temp;
        temp=new(List);
        now->next=temp;
        temp->data=num;
        now=temp;
        cin>>num;
        }
    now->next=NULL;
    }

void Ins(List *head){
    system("cls");
    cout<<"请输入您想插入的节点位置：";
    int pos;
    cin>>pos;
    cout<<"请输入数据：";
    int data;
    cin>>data;
    List *insert=head;
    for(int i=1;i<pos;i++){
        if(insert==NULL){
            cout<<"插入失败，越界"<<endl;
            return ;
            }
        insert=insert->next;
        }
    List *temp;
    temp=(List *)malloc(sizeof(List));
    temp->data=data;
    temp->next=insert->next;
    insert->next=temp;
    }

void Del(List *head){
    system("cls");
    cout<<"请输入您想删除的节点位置：";
    int pos;
    cin>>pos;
    List *dele=head;
    for(int i=1;i<pos;i++){
         if(dele==NULL){
            cout<<"删除失败，越界"<<endl;
            return ;
            }
        dele=dele->next;
        }
    dele->next=dele->next->next;
    }

void Clean(List *head){
    List *now;
    while(head->next!=NULL){
        now=head;
        head=head->next;
        free(now);
        }
    }

void Output(List *head){
    List *temp=head->next;
    while(temp!=NULL){
        cout<<temp->data<<' ';
        temp=temp->next;
        }
    }
