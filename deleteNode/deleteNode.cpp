/*************************************************************************
	> File Name: deleteNode.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 14 May 2019 07:24:30 PM CST
    删除链表中的节点
    请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点

    链表至少包含两个节点。
    链表中所有节点的值都是唯一的。
    给定的节点为非末尾节点并且一定是链表中的一个有效节点。
    不要从你的函数中返回任何结果。
 ************************************************************************/

#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node)
{
    //链表中至少要有两个节点
    if(node==NULL || node->next==NULL) return ;

    ListNode* next = node->next;
    node->val = next->val;
    node->next = next->next;
    
    delete next;
}


int main(int argc,char** argv)
{
    //这题相对简单，就不写测试程序了，leetcode上已跑过
    
    return 0;

}
