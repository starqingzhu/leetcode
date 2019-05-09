/*************************************************************************
	> File Name: addTwoNumbersII.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 09 May 2019 11:07:01 PM CST
  
  
    给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。
    它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。 

     你可以假设除了数字 0 之外，这两个数字都不会以零开头。

     进阶:

     如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。

     示例:

     输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
     输出: 7 -> 8 -> 0 -> 7
 ************************************************************************/

#include<iostream>
#include<vector>
#include <stdlib.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int getListLen(const ListNode* head)
{
    int count = 0;
    while(head != NULL)
    {
        ++count;
        head = head->next;
    }
    
    return count;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    //判空检测
    if( l1==NULL || l2 == NULL )
        return NULL;
    int l1_len = getListLen(l1);
    int l2_len = getListLen(l2);

    int diff_len = abs(l1_len - l2_len);
    if (l1_len < l2_len)
        swap(l1,l2);

    ListNode * head = new ListNode(0),*cur = head ,*high=cur;
    //差别位处理
    while( diff_len > 0 )
    {
        int val = l1->val;
        cur->next = new ListNode(val);
        if (val != 9 )
        {
            high = cur->next;
        }
        cur = cur->next;
        
        l1 = l1->next;
        --diff_len;
    }
    //相同位处理
    while(l1)
    {
        int val = l1->val + l2->val;
        if( val > 9 )
        {
            val %= 10;
            ++high->val;
            while(high->next)
            {
                high->next->val = 0;
                high = high->next;
            }
        }

        cur->next = new ListNode(val);
        if( val != 9 )
        {
            high = cur->next;
        }
        cur = cur->next;

        l1 = l1->next;
        l2 = l2->next;

    }


    return head->val == 0 ? head->next : head;

}

int main(int argc,char** argv)
{
    ListNode* head_l1 = NULL,*cur_l1=NULL;
    ListNode* head_l2 = NULL,*cur_l2=NULL;
    vector<int> v_l1 = {1,2,3,4};
    vector<int> v_l2 = {4,5,6};

    bool create_list_flag = true;
    for(int x : v_l1 )
    {
        if(cur_l1==NULL)
        {
            head_l1 = cur_l1 = new ListNode(x);
        }
        else
        {
            cur_l1->next = new ListNode(x);
            cur_l1 = cur_l1->next;
        }
        create_list_flag = (cur_l1 == NULL ? false: true);
        if (!create_list_flag)
        {
            cout<<" new node fail val="<<x<<endl;
            break;
        }
    }
    cout<<"l1_length="<<getListLen(head_l1)<<endl;
    ListNode* pos_l1 = head_l1;
    while( pos_l1 != NULL )
    {
        cout<<pos_l1->val<<" ";
        pos_l1 = pos_l1->next;
    }
    cout<<endl;

    create_list_flag = true;
    for(int x : v_l2 )
    {
        if(cur_l2==NULL)
        {
            head_l2 = cur_l2 = new ListNode(x);
        }
        else
        {
            cur_l2->next = new ListNode(x);
            cur_l2 = cur_l2->next;
        }
        create_list_flag = (cur_l2 == NULL ? false: true);
        if (!create_list_flag)
        {
            cout<<" new node fail val="<<x<<endl;
            break;
        }
    }
    cout<<"l2_length="<<getListLen(head_l2)<<endl;
    ListNode* pos_l2 = head_l2;
    while( pos_l2 != NULL )
    {
        cout<<pos_l2->val<<" ";
        pos_l2 = pos_l2->next;
    }
    cout<<endl;

    ListNode* rel = addTwoNumbers(head_l1,head_l2);
    while( rel != NULL )
    {
        cout<<rel->val<<" ";
        rel = rel->next;
    }
    cout<<endl;

}
