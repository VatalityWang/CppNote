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
     * 485. 最大连续 1 的个数
     * **/
     int findMaxConsecutiveOnes(vector<int>& nums) {
       int res=0;
       if(nums.size()==1&&nums[0]==1)
            return 1;
       int l=0,r=l+1;
       while(r<nums.size()){
           while(r<nums.size()&&nums[l]==nums[r]&&nums[l]==1)
                r++;
           if(nums[l]==1&&nums[r-1]==1)
                res=max(r-l,res);
           l=r;
           r=l+1;
       }
        if(l<nums.size()&&r-1<nums.size()&&nums[l]==1&&nums[r-1]==1)
            res=max(r-l,res);
       return res;
    }

    /**
     * 389. 找不同
     * **/
    char findTheDifference(string s, string t) {
        char res;
        map<int,int> eles1;
        map<int,int> eles2;
        for(int i=0;i<s.size();i++)
            eles1[s[i]]++;
        for(int i=0;i<t.size();i++)
            eles2[t[i]]++;
        
        for(auto &it:eles1)
            eles2[it.first]-=eles1[it.first];
        for(auto&it:eles2)
            if(it.second==1){
                res=it.first;
                break;
            }
        return res;
    }
};
int main(){
    return 0;
}