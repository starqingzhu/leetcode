/*************************************************************************
	> File Name: threeSumClosest.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 12 May 2019 04:47:42 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include <stdlib.h>
#include <climits>
using namespace std;

int threeSumClosest(vector<int>& nums, int target)
{
    int sum_colsest = 0,sum=0,distance=INT_MAX;
    
    if( nums.size()<3 ) return sum;

    sort(nums.begin(),nums.end());
    cout<<"----排序后数组变为--------"<<endl;
    for(int x:nums)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    for(int i=0;i<nums.size()-2;++i)
    {
        if(i>0 && nums[i] == nums[i-1]) continue;

        int left =  i+1,right = nums.size()-1;
        while(left < right)
        {
            sum = nums[i] + nums[left] + nums[right];
            distance = (distance >= abs(sum-target)) ?( sum_colsest = sum, abs(sum-target) ) : distance;
            if(target == sum) 
            {
                return  sum_colsest;
            }
            else if( target < sum )
            {
                if(right<nums.size()-1 && nums[right] == nums[right+1])
                {
                    --right;
                }
                --right;
            }
            else
            {
                if( left > i+1 && nums[left] == nums[left-1] )
                {
                    ++left;
                }
                ++left;
            }

        }

    }

    return sum_colsest;
}

int main(int argc,char** argv)
{
    vector<int> arr = {1,1,1,0};
    int target = 100;
    cout<<"sum="<< threeSumClosest(arr,target)<<endl;
    return 0;
}
