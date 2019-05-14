/*************************************************************************
	> File Name: hasCycle.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 14 May 2019 06:37:39 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


bool hasCycle(ListNode *head) 
{
    bool rel = false;
    int step = 0;
    ListNode* pos=head,*double_pos=head;
    while(pos != NULL && double_pos != NULL) 
    {
        if(pos == double_pos && step!=0)
        {
            rel = true;
            break;
        }
        pos=pos->next;
        double_pos =  double_pos->next != NULL ? double_pos->next->next : NULL;
        ++step;
    }

    return rel;
}

int main(int argc,char** argv)
{
    ListNode * head = NULL,*cur=NULL,*cycle_node=NULL;


    for(int i=0;i<6;++i)
    {
        if(head==NULL)
        {
            head = new ListNode(i);
            cur = head;
        }
        else
        {
            cur->next = new ListNode(i);
            cur = cur->next;
            if(i==1)
            {
                cycle_node = cur;
            }
        }
    }
    //cur->next = cycle_node;

    cout<<"bool="<<hasCycle(head)<<endl;
    return 0;
}
