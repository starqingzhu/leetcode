/*************************************************************************
	> File Name: twoSum.cpp
	> Author: sunbin
	> Mail: 1041985719@qq.com
	> Created Time: Sun 05 May 2019 08:46:39 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
using namespace std;


//直接输出值
vector<int> twoSum(const vector<int>& arr,int sum)
{

    vector<int> result;
    map<int,int> hash_arr;

    for(int i=0;i<arr.size();++i)
    {
        if( hash_arr.count(arr[i]) == 0 && hash_arr.count(sum-arr[i]) != 0)
        {
            result.push_back(sum-arr[i]);
            result.push_back(arr[i]);
            return result;
        }

        hash_arr[arr[i]]=i;
        cout<<"add hash_arr["<<arr[i]<<"]="<<i<<endl;
    }

}

int main(int argc,char** argv)
{
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(8);
    arr.push_back(9);
    int sum = 11;
    vector<int> res = twoSum(arr,sum);
    for(int i=0;i<res.size();++i)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;


    return 0;
}
