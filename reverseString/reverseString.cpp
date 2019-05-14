/*************************************************************************
	> File Name: reverseString.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 14 May 2019 06:16:59 PM CST
    反转字符串
    编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。

    不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

    你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


void reverseString(vector<char>& s) 
{
    if(s.size()<=1) return ;
    
    int left_pos=0,right_pos=s.size()-1;
    while(left_pos<right_pos)
    {
        swap(s[left_pos++],s[right_pos--]);
    }
    return;
}

int main(int argc,char** argv)
{
    vector<vector<char>> arr = {{'a','b','c'},{'e','f','g'}};
    for(vector<char> v_x : arr)
    {
        cout<<"v_x=";
        for(auto x : v_x)
        {
            cout<<x;
        }
        cout<<" reverse_x=";
        reverseString(v_x);
        for(auto x : v_x)
        {
            cout<<x;
        }
        cout<<endl;
    }
    return 0;
}
