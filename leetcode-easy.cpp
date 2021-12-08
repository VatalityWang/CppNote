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
     * 495. 提莫攻击
     * **/
     int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res=0;
        for(int i=0;i<timeSeries.size();i++){
            if(i+1<timeSeries.size()){
                if(timeSeries[i+1]<=timeSeries[i]+duration-1)
                    res+=timeSeries[i+1]-timeSeries[i];
                else
                    res+=duration;
            }
            else
                res+=duration;
        }
        return res;
    }

    /**
     * 13. 罗马数字转整数
     * **/
     int romanToInt(string s) {
        int res=0;
        map<char,int> statistics;
        statistics.insert({'I',1});
        statistics.insert({'V',5});
        statistics.insert({'X',10});
        statistics.insert({'L',50});
        statistics.insert({'C',100});
        statistics.insert({'D',500});
        statistics.insert({'M',1000});

        for(int i=s.size()-1;i>=0;i--){
            if(i>=1){
                if(statistics[s[i]]<=statistics[s[i-1]])
                     res+=statistics[s[i]];
                else{
                    res+=statistics[s[i]]-statistics[s[i-1]];
                    i--;
                }

            }
            else{
                res+=statistics[s[i]];
            }
            
        }
        return res;
    }

    /**
     * 383. 赎金信
     * **/
     bool canConstruct(string ransomNote, string magazine) {
        bool res=true;
        map<int,int> ele1;
        map<int,int> ele2;
        for(int i=0;i<magazine.size();i++)
            ele1[magazine[i]]++;
        for(int i=0;i<ransomNote.size();i++)
            ele2[ransomNote[i]]++;
        for(auto it:ele2){
            if(ele1[it.first]<it.second){
                res=false;
                break;
            }
        }
        return res;
    }

    /**
     * 1005. K 次取反后最大化的数组和
     * **/
      int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int minEle=INT_MAX;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0&&k>0){
                nums[i]=-nums[i];
                k--;
            }
            sum+=nums[i];
            minEle=min(minEle,nums[i]);
        }
        if(k>0&&k%2){
            sum-=2*minEle;
        }
        return sum;
    }


    /**
     * 506. 相对名次
     * **/
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> handle;
        vector<string> res;
        map<int,int> socre2rank;
        std::copy(score.begin(),score.end(),back_inserter(handle));
        sort(handle.begin(),handle.end(),std::greater<int>());
        for(int i=0;i<handle.size();i++)
            socre2rank[handle[i]]=i+1;
        for(int i=0;i<score.size();i++){
            if(socre2rank[score[i]]==1)
                res.push_back("Gold Medal");
            else if(socre2rank[score[i]]==2)
                res.push_back("Silver Medal");
            else if(socre2rank[score[i]]==3)
                res.push_back("Bronze Medal");
            else 
                res.push_back(std::to_string(socre2rank[score[i]]));
        }
        return res;    
    }


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