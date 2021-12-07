#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <numeric>
#include <map>
#include<unordered_map>
#include <cstring>
#include <set>
#include<unordered_set>
#include <queue>
#include <deque>
#include<cmath>
#include<sstream>
#include<bitset>
#include<mutex>
#include<functional>
#include<climits>
// #include<math>
using namespace ::std;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;


class Solution {
public:

    /**
     * 81. 搜索旋转排序数组 II
     * **/

    bool search(vector<int>& nums, int target) {

        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            //处理两头的重复数字
            while(low<high&&nums[high]==nums[high-1]) --high;
            while(low<high&&nums[low]==nums[low+1])  ++low;
            int mid=(low+high)/2;
            if(nums[mid]==target)
                return true;
            //判断区间的顺序情况
            else{
                //左边有序
                if(nums[mid]>=nums[low]){
                    //在有序区间里面
                    if(target<nums[mid]&&target>=nums[low])
                        high=mid-1;
                    else
                        low=mid+1;
                }
                //右边有序
                else{
                    //在有序区间里面
                    if(nums[mid]<target&&target<=nums[high])
                        low=mid+1;
                    else
                        high=mid-1;
                } 
            } 
        }
        return false;
    }
};

int main(){
    
    return 0;
}