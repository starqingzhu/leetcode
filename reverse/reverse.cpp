/*************************************************************************
	> File Name: reverse.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 14 May 2019 05:49:22 PM CST
     整数反转
     给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 ************************************************************************/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int reverse(int x)
{
    if(x==INT_MIN) return 0;
    int rel = 0;

    int in_temp = x,out_temp=0;
    while(in_temp !=0 )
    {
        int low_num = in_temp%10;
        if((out_temp>INT_MAX/10) || (out_temp < INT_MIN/10)) return 0;
        else if((out_temp==INT_MAX/10) && (low_num > INT_MAX%10)) return 0;
        else if((out_temp==INT_MIN/10) && (low_num< INT_MIN%10)) return 0;
        else
        {
            out_temp = out_temp*10 + low_num;
            in_temp /= 10;
        }
    }

    return out_temp;
}

int main(int argc,char** argv)
{
    vector<int> arr={12,13,-23,-34};
    for(int x : arr)
    {
        cout<<"x="<<x<<"    reserve_x="<<reverse(x)<<endl;
    }
    
    return 0;
}
