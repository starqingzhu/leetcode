/*************************************************************************
	> File Name: twoSumII.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 08 May 2019 12:03:27 AM CST
    两数之和，数组有序
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


vector<int> twoSumII(const vector<int>& nums, int target) 
{   
    
    vector<int> v_rel;
    int l_index=0,r_index=nums.size()-1;
    //既然是2数之和，那么数组中必然不能小于2
    if( nums.size() <= 1 )
    {
        return v_rel; 
    }
    // 判断是升序还是降序
    int up_flag=0;
    int max_num = nums[l_index] <= nums[r_index] ? (up_flag=1,nums[r_index]) : nums[l_index];
    if( target > 2*max_num )
    {
        return v_rel;
    }
    //满足有序数字且数组中元素在合理范围后进行处理
    while( l_index < r_index )
    {
        int temp_sum = nums[l_index]+nums[r_index];
        if( target > temp_sum )
        {
            up_flag == 1 ? ++l_index : --r_index;
        }
        else if(target == temp_sum )
        {
            v_rel.push_back(l_index+1);
            v_rel.push_back(r_index+1);
            return v_rel;
        }
        else
        {
            up_flag == 1? --r_index : ++l_index;
        }
    }
    return v_rel;
}

//数组中 {1,5,8,10}
int main(int argc,char** argv)
{
    vector<int> v_src = {10,8,5,1};//{1,5,8,10};
    //v_src.push_back(1);
    //v_src.push_back(5);
    //v_src.push_back(8);
    //v_src.push_back(10);


    int target = 15;
    vector<int> v_rel = twoSumII(v_src,target);
    for (int x : v_rel )
    {
        cout<<x<<"  ";
    }
    //for(int i=0;i<v_rel.size();++i)
    //{
    //    cout<<v_rel[i]<<"  ";
    //}
    cout<<endl;
    return 0;
}
