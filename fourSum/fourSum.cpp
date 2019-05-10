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
#define num_count_base 4

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    //过滤长度小于3的数组
    if( nums.size() < num_count_base )
        return {};
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

    vector<vector<int>> result;
    for(int first_num_pos=0;first_num_pos<nums.size()-num_count_base+1;++first_num_pos)
    {
        if(target>=0 ? (nums[first_num_pos] > target) : (nums[first_num_pos] < target) ) break;
        if(first_num_pos>0 && nums[first_num_pos] == nums[first_num_pos-1]) continue;
        
        int threeSum = target - nums[first_num_pos];

        for(int second_num_pos = first_num_pos+1;second_num_pos<nums.size();++second_num_pos)
        {
            if(target>=0 ? (nums[first_num_pos] + nums[second_num_pos] > target) : (nums[first_num_pos]+nums[second_num_pos] < target) ) break;
            if(second_num_pos>first_num_pos+1 && nums[second_num_pos]==nums[second_num_pos-1]) continue;
            
            int twoSum = threeSum - nums[second_num_pos];
            int begin_pos = second_num_pos+1,end_pos=nums.size()-1;
            
            while( begin_pos < end_pos )
            {
                if( twoSum > nums[begin_pos] + nums[end_pos] )
                {
                    ++begin_pos;
                }
                else if(twoSum < nums[begin_pos] + nums[end_pos])
                {
                    --end_pos;
                }
                else
                {
                    //成功组队
                    result.push_back(vector<int>{nums[first_num_pos], nums[second_num_pos],nums[begin_pos],nums[end_pos]});
                    
                    while(begin_pos < end_pos && nums[begin_pos]==nums[begin_pos+1])
                        ++begin_pos;
                    ++begin_pos;
                    --end_pos;

                }
            }
        }

    }
    return result;
}

int main(int argc,char** argv)
{
    vector<int> v_l = {-3,-1,0,2,4,5};
    int target = 0;
    vector<vector<int>> rel = fourSum(v_l,target);
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
