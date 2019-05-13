/*************************************************************************
	> File Name: myAtoi.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 13 May 2019 04:05:47 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <cctype>
#include <climits>
#include <vector>
using namespace std;

int myAtoi(string str)
{
    int rel = 0;
    if(str.empty())
    {
        cout<<"输入参数为空字符"<<endl;
        return rel;
    }

    int len = str.length(); 
    //剔除空格
    int pos = 0;
    int symbol_flag = 1;
    int symbol_count = 0;
    int num_count = 0;
    while( 0 != isspace(str[pos]) && pos < len)
    {
        ++pos;
    }
    while(pos < len )
    {
        if( str[pos]>='0' && str[pos]<='9' )
        {
            //判断越界问题
            if( symbol_flag*rel > INT_MAX/10 )
                return INT_MAX;
            
            else if(symbol_flag*rel == INT_MAX/10 &&\
                (str[pos] - '0')>=(INT_MAX-rel *10))
            {
                return  INT_MAX;
            }
            else if( symbol_flag * rel < INT_MIN/10)
                return INT_MIN;
            else if(symbol_flag * rel == INT_MIN/10 &&\
                ('0' - str[pos]) <= (INT_MIN + rel*10))
            {
                return INT_MIN;
            }
            
            rel = rel * 10 - '0' + str[pos];
            ++pos;
            ++num_count;
        }
        else if( str[pos] == '-' || str[pos] == '+')
        {
            if( rel != 0 || num_count != 0 || symbol_count == 1 ) break;
            symbol_flag = str[pos] == '-' ? -1 : 1;
            ++symbol_count;
            ++pos;
        }
        else
        {
            break;
        }
    }

    return symbol_flag*rel;
}

int main(int argc,char** argv)
{
    cout<<"INT_MIN="<<INT_MIN<<" INT_MAX="<<INT_MAX<<endl;
    vector<string> test_arr = {"-42"}; 
    for(string x : test_arr)
    {
        cout<<x<<" = "<<myAtoi(x)<<endl;
    }

    return 0;
}
