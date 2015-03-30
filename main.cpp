#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <windows.h>
using namespace std;

struct List{
    int data;
    List *next;
    };

void Work(List *);//��������

void Input(List *);//�½�һ������

void Ins(List *);//��ĳ���ڵ����һ��Ԫ��

void Del(List *);//ɾ��ĳ���ڵ�

void Output(List *);//��ӡ��������

void Clean(List *);//�������

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
    cout<<"1.�½�����"<<endl;
    cout<<"2.����һ��Ԫ��"<<endl;
    cout<<"3.ɾ��һ��Ԫ��"<<endl;
    cout<<"4.�������"<<endl;
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
    cout<<"����������"<<endl;
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
    cout<<"�������������Ľڵ�λ�ã�";
    int pos;
    cin>>pos;
    cout<<"���������ݣ�";
    int data;
    cin>>data;
    List *insert=head;
    for(int i=1;i<pos;i++){
        if(insert==NULL){
            cout<<"����ʧ�ܣ�Խ��"<<endl;
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
    cout<<"����������ɾ���Ľڵ�λ�ã�";
    int pos;
    cin>>pos;
    List *dele=head;
    for(int i=1;i<pos;i++){
         if(dele==NULL){
            cout<<"ɾ��ʧ�ܣ�Խ��"<<endl;
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
