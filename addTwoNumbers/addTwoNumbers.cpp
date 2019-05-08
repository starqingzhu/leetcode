/*************************************************************************
	> File Name: addTwoNumbers.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 08 May 2019 09:47:02 PM CST
    两个非负正数相加，正数逆序存储在链表中
    返回一个新链表
    
    需要注意两点:
    1.空链表 异常捕获
 ************************************************************************/

#include<iostream>
#include<climits>
#include<cmath>


#define bit_cout  10
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    //判断链表是否为空
    if(l1 == NULL || l2 == NULL)
    {
        cout<<"参数链表为空"<<endl;
        return NULL;
    }
    //正常逻辑
    unsigned int carry = 0;
    unsigned int temp = 0;

    ListNode* rel = NULL;
    ListNode* head = rel;

    while( l1 != NULL || l2 != NULL || carry != 0)
    {
        int l1_cur_val = l1 != NULL ? l1->val : 0;
        int l2_cur_val = l2 != NULL ? l2->val : 0;

        temp =  l1_cur_val + l2_cur_val + carry;
        if( head == NULL )
        {
            rel = new ListNode(temp%10);
            head = rel;
        }
        else
        {
            rel->next = new ListNode(temp%10);
            rel = rel->next;
        }

        carry = temp/10;

        l1 = l1 != NULL ? l1->next : NULL;
        l2 = l2 != NULL ? l2->next : NULL;
    }
    return head;
}

int main(int argc,char** argv)
{
    auto l1 = {9};
    auto l2 = {1,9,9,9,9,9,9,9,9,9};

    ListNode* l1_head = NULL;
    ListNode* l1_cur = l1_head;
    for( auto x : l1 )
    {
        if( l1_head == NULL )
        {
            l1_head = new ListNode(x);
            l1_cur = l1_head;
        }
        else
        {
            l1_cur->next = new ListNode(x);
            l1_cur = l1_cur->next;
        }   
    }
    //打印
    ListNode* print_cur1 = l1_head;
    cout<<"l1=";
    while(print_cur1 != NULL)
    {
        cout<<print_cur1->val;
        print_cur1 = print_cur1->next;
    }
    cout<<endl;

    ListNode* l2_head = NULL;
    ListNode* l2_cur = l2_head;
    for( auto x : l2 )
    {
        if( l2_head == NULL )
        {
            l2_head = new ListNode(x);
            l2_cur = l2_head;
        }
        else
        {
            l2_cur->next = new ListNode(x);
            l2_cur = l2_cur->next;
        }   
    }
    //打印
    ListNode* print_cur2 = l2_head;
    cout<<"l2=";
    while(print_cur2 != NULL)
    {
        cout<<print_cur2->val;
        print_cur2 = print_cur2->next;
    }
    cout<<endl;
    ListNode* rel = addTwoNumbers(l1_head,l2_head);
    cout<<"rel=";
    for(;rel!=NULL;)
    {
        cout<<rel->val;
        rel = rel->next;
    }
    cout<<endl;

}
