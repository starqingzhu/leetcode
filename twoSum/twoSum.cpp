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
vector<int> twoSum(const vector<int>& nums,int target)
{
    map<int,int> hash_nums;
    int i = 0;
    while(i < nums.size())
    {
        if(hash_nums.find(target-nums[i]) != hash_nums.end())
        {
            return {hash_nums[target-nums[i]],i};
        }

        hash_nums[nums[i]]=i;
        ++i;
    }
    return {};

}

int main(int argc,char** argv)
{
    vector<int> nums = {3,3};
    int sum = 6;
    vector<int> res = twoSum(nums,sum);
    for(int i=0;i<res.size();++i)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;


    return 0;
}
