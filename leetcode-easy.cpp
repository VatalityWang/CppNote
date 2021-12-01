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
     * 1446. 连续字符
     * **/
     int maxPower(string s) {
        int cur=1;
        int res=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1])
                cur++;
            else
                cur=1;
            res=max(cur,res);
        }
        return res;
    }
    /**
     * 485. 最大连续 1 的个数
     * **/
     int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)
                count++;
            else{
                res=max(res,count);
                count=0;
            }
        }
        res=max(res,count);
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