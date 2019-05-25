/*************************************************************************
	> File Name: LRUCache.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 25 May 2019 10:30:01 PM CST
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;


struct Node
{
    Node(int key,int value):m_key(key),m_value(value)
    {

    }

    int m_key;
    int m_value;
    Node* pre;
    Node* next;

};

class doubleList
{
public:
    doubleList():m_size(0),head(NULL),tail(NULL)
    {

    }

    void print()
    {
        Node* cur = getHead();
        cout<<"列表中元素:"<<endl;
        while(cur != NULL)
        {
            cout<<cur->m_value<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }

    Node* getTail()const {
        return tail;
    }

    Node* getHead()const{
        return head;
    }

    const Node* addNodeTail(Node* node)
    {
        if(node == NULL) return NULL;

        ++m_size;
        if(tail == NULL)
        {
            head=tail=node;
            return node;
        }

        
        tail->next = node;
        node->pre = tail;
        node->next = NULL;

        tail = node;

        return node;
    }
    const Node* addNodeHead(Node* node)
    {
        if(node == NULL ) return NULL;

        ++m_size;
        if(head==NULL)
        {
            head=tail=node;
            return node;
        }

        head->pre = node;
        node->next = head;
        node->pre = NULL;

        head = node;
        return node;
    }



    void unlink(Node* node)
    {
        if(node == NULL) return;

        --m_size;
        if(node->pre != NULL)
        {
            node->pre->next = node->next;
        }
        if(node->next != NULL)
        {
            node->next->pre = node->pre;
        }
        
        if(head == node ) 
        {
            head = node->next;
        }
        if(tail == node )
        {
            tail = node->pre;
        }
    }

    void delNode(Node* node)
    {
        if(node != NULL)
        {
            delete node;
        }
    }

    int size()const{
        return m_size;
    }

private:
    int m_size;
    Node* head,*tail;

};

class LRUCache {
private:
    int m_capacity;
    map<int,Node*> m_map;
    doubleList m_list;
public:
    LRUCache(int capacity):m_capacity(capacity)
    {
        
    }

    ~LRUCache()
    {
        m_map.clear();
        Node* cur = NULL;
        while((cur=m_list.getHead())!= NULL )
        {
            m_list.unlink(cur);
            m_list.delNode(cur);
        }
    }
        
    int get(int key) {
        if(m_map.find(key) == m_map.end())
        {
            return -1;
        }

        cout<<"get前:key="<<key<<endl;
        m_list.print();

        m_list.unlink(m_map[key]);
        m_list.addNodeHead(m_map[key]);

        cout<<"get后:key="<<key<<endl;
        m_list.print();
        return m_map[key]->m_value;    
    }
        
    void put(int key, int value) {
        cout<<"put前:(key:value)=("<<key<<","<<value<<")"<<endl;
        m_list.print();
        
        Node* node = NULL;
        if(m_map.find(key) == m_map.end())
        {
            node = new Node(key,value);
            m_map[key] = node;

            m_list.addNodeHead(node);

            if(m_list.size() > m_capacity)
            {
                Node* tail = m_list.getTail();
                m_list.unlink(tail);
                m_map.erase(tail->m_key);

                m_list.delNode(tail);
            }
        }
        else
        {
            node = m_map[key];
            node->m_value = value;

            m_list.unlink(node);
            m_list.addNodeHead(node);
        }
        cout<<"put后:(key:value)=("<<key<<","<<value<<")"<<endl;
        m_list.print();
        

    }

};

int main(int argc,char** argv)
{
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       
    cache.put(3, 3);    
    cache.get(2);       
    cache.put(4, 4);    
    cache.get(1);       
    cache.get(3);       
    cache.get(4);  
    return 0;
}
