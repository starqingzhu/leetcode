/*************************************************************************
	> File Name: threeSum.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 10 May 2019 03:19:26 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define num_count_base 3

vector<vector<int>> threeSum(vector<int>& nums) 
{
    //数组排序
    //降序
    //::sort(nums.begin(),nums.end(),[](int a,int b){ return a>b; });
    //升序
    ::sort(nums.begin(),nums.end());
    //排序后
    for( int x : nums )
    {
        cout<<x<<" ";
    }
    cout<<endl;

    //过滤长度小于3的数组
    if( nums.empty() || nums.front()>0 || nums.back()<0)
        return {};


    vector<vector<int>> result;
    for(int first_num_pos=0;first_num_pos<nums.size();++first_num_pos)
    {
        int second_num_begin=first_num_pos+1;
        int begin_pos = second_num_begin,end_pos=nums.size()-1;

        if( nums[first_num_pos] >0 ) break;
        if( nums[first_num_pos]==nums[first_num_pos-1] ) continue;

        while( begin_pos < end_pos )
        {
            if( 0 > nums[first_num_pos] + nums[begin_pos] + nums[end_pos] )
            {
                ++begin_pos;
            }
            else if(0 < nums[first_num_pos] + nums[begin_pos] + nums[end_pos])
            {
                --end_pos;
            }
            else
            {
                //成功组队
                result.push_back(vector<int>{nums[first_num_pos], nums[begin_pos],nums[end_pos]});
                
                while(begin_pos < end_pos && nums[begin_pos]==nums[begin_pos+1])
                    ++begin_pos;
                ++begin_pos;
                --end_pos;

            }
        }
    }
    return result;
}

int main(int argc,char** argv)
{
    vector<int> v_l = {-1,0,1,2,-1,-4};
    vector<vector<int>> rel = threeSum(v_l);
    for(auto v_val : rel)
    {
        for(auto val : v_val)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }

    
    return 0;
}
