/*************************************************************************
	> File Name: detectCycle.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 14 May 2019 09:27:43 PM CST
    给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
    为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
    说明：不允许修改给定的链表。
 ************************************************************************/

#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

};

ListNode *detectCycle(ListNode *head) {
    int step = 0;
    ListNode* pos=head,*double_pos=head;
    while(double_pos != NULL && double_pos->next != NULL) 
    {
        if(pos == double_pos && step!=0)
        {
            break;
        }
        pos=pos->next;
        double_pos = double_pos->next->next;
        ++step;
    }
    if( pos!= double_pos || step==0 ) return NULL;
    
    pos=head;
    while(pos!=double_pos)
    {
        pos = pos->next;
        double_pos = double_pos->next;
    }
    return pos;
}

int main(int argc,char** argv)
{
    return 0;
}
