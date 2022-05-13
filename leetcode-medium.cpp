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
/**
 * Definition for singly-linked list.
 */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
*380. O(1) 时间插入、删除和获取随机元素
*/
class RandomizedSet {
public:

    map<int,int> elesTable; // 元素---元素下标
    vector<int> eles; // 存元素

    RandomizedSet() {

    }
    
    bool insert(int val) {
        // 该元素已存在
        if(elesTable.find(val)!=elesTable.end())
            return false;
        eles.push_back(val);
        int index=eles.size()-1;
        elesTable[val]=index;
        return true;
    }
    
    bool remove(int val) {
        // 没有该元素
        if(elesTable.find(val)==elesTable.end())
            return false;
        int last=eles.back();
        int index=elesTable[val];
        eles[index]=last;
        //更新最后一个元素对应下标新下标
        elesTable[last]=index;
        elesTable.erase(val);
        eles.pop_back();
        return true;
    }
    
    int getRandom() {
        int rand_index=rand()%eles.size();
        return eles[rand_index];
    }
};

class Solution {
public:

    /**
     * 1049. 最后一块石头的重量 II
     * **/
    int lastStoneWeightII(vector<int>& stones) {
        int sum=std::accumulate(stones.begin(),stones.end(),0);
        int volume=sum/2;
        vector<int> dp(volume+1);// 背包最大容量,装满容量为i的背包所获得的最大价值
        for(int i=0;i<stones.size();i++){ //遍历物品
            for(int j=volume;j>=stones[i];j--) //遍历背包，从大到小，每个物品只装一次
                dp[j]=max(dp[j],dp[j-stones[i]]+stones[i]);
        }
        return sum-2*dp[volume];
    }

    /**
     * 698. 划分为k个相等的子集
     * **/
     bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=std::accumulate(nums.begin(),nums.end(),0);
        if(sum%k)
            return false;
        int avg=sum/k;

        for(auto it:nums){
            // 大于均分k份的和
            if(it>avg)
                return false;
        }

        // 创建用于状态压缩的dp数组
        int n=nums.size();
        vector<int> dp((1<<16)+2,-1); // 表示16个位置的数字选或者不选的状态，dp[i]表示当前状态求和之后整除target的余数，余数为0，则表示存在满足题意条件的划分。
        // 状态转移方程：如果第i位没有选择，选择第i位。dp[mask|1<<i]=dp[mask]+nums[i]
        dp[0]=0;
        for(int mask=0;mask<(1<<n);mask++){
            if(dp[mask]==-1) continue;
            for(int i=0;i<n;i++){
                //当前位置未被选择，更新选择以后的状态
                if(!(mask&(1<<i))&&(dp[mask]+nums[i]<=avg))
                    dp[mask|(1<<i)]=(dp[mask]+nums[i])%avg;
            }
        }

        return dp[(1<<n)-1]==0;
       
    }

    /**
     * 357. 统计各位数字都不同的数字个数
     * **/
    int count(int n){
        int res=9;
        int start=9;
        for(int i=0;i<n-1;i++){
            res*=start;
            start--;
        }
        return res;
    }

    int countNumbersWithUniqueDigits(int n) {
        if(n==0)
            return 1;
        else if(n==1)
            return 10;
        else{
            return count(n)+countNumbersWithUniqueDigits(n-1);
        }
    }

    /**
     * 38. 外观数列
     * **/
     string countAndSay(int n) {

            string cur="";
            string pre="1";
            string res;

            int cur_count=1;
            char cur_char=pre[0];

            for(int j=1;j<n;j++){
                cur="";
                cur_char=pre[0];
                cur_count=1;
                for(int i=1;i<pre.size();i++){
                    if(pre[i]==pre[i-1]){
                        cur_count++;
                    }else{
                        cur+=std::to_string(cur_count);
                        cur+=cur_char;
                        cur_char=pre[i];
                        cur_count=1;
                    }
                }
                cur+=std::to_string(cur_count);
                cur+=cur_char;        
                pre=cur;
              

            }
          
            return pre;
    }


    /**
     * 86. 分隔链表
     * **/
     ListNode* partition(ListNode* head, int x) {
        
        ListNode * min_tail=nullptr;
        ListNode * max_tail=nullptr;
        ListNode * newHead=nullptr;
        ListNode * maxHead=nullptr;
        ListNode * pwork=head;

        while(pwork){
            if(pwork->val<x){
                if(!min_tail)
                    min_tail=pwork;
                else{
                    min_tail->next=pwork;
                    min_tail=pwork;
                }
                if(!newHead)
                    newHead=min_tail;
            }else{
                if(!max_tail)
                    max_tail=pwork;
                else{
                    max_tail->next=pwork;
                    max_tail=pwork;
                }
                if(!maxHead)
                    maxHead=pwork;
            }
            pwork=pwork->next;
           
        }
        // 尾指针置空
        if(max_tail)
            max_tail->next=nullptr;
        //存在小于x的节点
        if(min_tail)
            min_tail->next=maxHead;
        //不存在小于x的节点
        if(!newHead)
            newHead=maxHead;
        return newHead;
    }

    /**
     * 1414. 和为 K 的最少斐波那契数字数目
     * **/
    int findMinFibonacciNumbers(int k) {

        int a=1,b=1,c=a+b;
        vector<int> eles{1,1};

        while(c<=k){
            eles.push_back(c);
            a=b;
            b=c;
            c=a+b;
        }

        int num=0;
        while(k){

            if(eles.back()<=k){
                k=k-eles.back();
                num++;
            }
            else
                eles.pop_back();    
        }
        return num;
    }

    /**
     * 153. 寻找旋转排序数组中的最小值
     * **/
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            
            if(nums[low]<=nums[high])
                return nums[low];
            int mid=(low+high)>>1;
            //右半部分有序，最小值在左半部分，包括mid所指元素
            if(nums[mid]<nums[high])
                high=mid;
            //左半部分有序，最小值在右半部分，不包括mid下标所指元素，因为nums[mid]>nums[high],nums[mid]不可能为最小元素
            else
                low=mid+1;

        }
        return 0;
    }

    /**
     * 137. 只出现一次的数字 II
     * */
     int singleNumber(vector<int>& nums) {
        int a=0,b=0;
        for(int i=0;i<nums.size();i++){
            a=(a^nums[i])&~b;
            b=(b^nums[i])&~a;
        }
        return a;
    }


    /**
     * 12. 整数转罗马数字
     * **/
    string intToRoman(int num) {
        map<int,char> dict;
        dict.insert({1,'I'});
        dict.insert({5,'V'});
        dict.insert({10,'X'});
        dict.insert({50,'L'});
        dict.insert({100,'C'});
        dict.insert({500,'D'});
        dict.insert({1000,'M'});
        vector<string> midStr;
        string strnum;
        int cur=1;
        while(num){
            int remain=num%10;
            int curNum=remain*cur;
            if(remain){
                if(dict.find(curNum)!=dict.end()){
                    midStr.push_back(string(1,dict[curNum]));
                }
                else{
                    switch(cur){
                        case 1:
                            if(remain==4)
                                midStr.push_back("IV");
                            else if(remain==9){
                                midStr.push_back("IX");
                            }else if(remain<4){
                                midStr.push_back(string(remain,'I'));
                            }
                            else{
                                midStr.push_back("V"+string(remain-5,'I'));
                            }
                            break;
                        case 10:
                            if(remain==4)
                                midStr.push_back("XL");
                            else if(remain==9){
                                midStr.push_back("XC");
                            }else if(remain<4){
                                midStr.push_back(string(remain,'X'));
                            }
                            else{
                                midStr.push_back("L"+string(remain-5,'X'));
                            }
                            break;
                        case 100:
                            if(remain==4)
                                midStr.push_back("CD");
                            else if(remain==9){
                                midStr.push_back("CM");
                            }else if(remain<4){
                                midStr.push_back(string(remain,'C'));
                            }
                            else{
                                midStr.push_back("D"+string(remain-5,'C'));
                            }
                            break;
                        case 1000:
                            midStr.push_back(string(remain,'M'));
                            break;
                        default:
                            break;
                    }
                }
               
            }
            cur*=10;
            num/=10;
        }
        string res;
        reverse(midStr.begin(),midStr.end());
        for(auto it:midStr)
            res+=it;
        return res;
    }

    /**
     * 130. 被围绕的区域
     * **/

    void dfsFind(vector<vector<char>>& board,int i,int j,vector<vector<int>>&memory,vector<vector<int>>&visited){
       
        int m=board.size();
        int n=board[0].size();
        //超出范围
        if(i<0||i>=m||j<0||j>=n)
            return;
        if(visited[i][j]==0&&board[i][j]=='O'){
            memory[i][j]=1;
            visited[i][j]=1;
            dfsFind(board,i+1,j,memory,visited);
            dfsFind(board,i-1,j,memory,visited);
            dfsFind(board,i,j+1,memory,visited);
            dfsFind(board,i,j-1,memory,visited);
        }
    }

    void solve(vector<vector<char>>& board) {
        //找某个'O'是否有边界的'O'与之相连，如果有则该区域不被'X'包围
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>memory(m,vector<int>(n,0));
         vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if((i==0||i==m-1||j==0||j==n-1)&&board[i][j]=='O'){
                    dfsFind(board,i+1,j,memory,visited);
                    dfsFind(board,i-1,j,memory,visited);
                    dfsFind(board,i,j+1,memory,visited);
                    dfsFind(board,i,j-1,memory,visited);
                }
            }
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if((i!=0&&i!=m-1&&j!=0&&j!=n-1)&&memory[i][j]==0&&board[i][j]=='O')
                        board[i][j]='X';
            }
    }

    /**
     * 316. 去除重复字母
     * **/
   string removeDuplicateLetters(string s) {
        int eles[26]={0};
        for(int i=0;i<s.size();i++){
            eles[s[i]-'a']++;
        }
        stack<char> work;  //单调递减栈
        set<char> contain; //记录已插入的字符
        for(int i=0;i<s.size();i++){
            if(work.size()==0){
                work.push(s[i]);
                contain.insert(s[i]);
                eles[s[i]-'a']--;
                continue;
            }
           if(contain.count(s[i])!=0){
                eles[s[i]-'a']--;
                continue;
           }
        
            //比栈顶元素小且栈顶后面还存在
            while(work.size()&&s[i]<work.top()&&eles[work.top()-'a']){
                contain.erase(work.top());
                work.pop();
            }
          
            work.push(s[i]);
            contain.insert(s[i]);
            eles[s[i]-'a']--;
        }
        string res;
        while(work.size()){
            res+=work.top();
            work.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }


    /**
     * 90. 子集 II
     * **/
     void dfsSubSetsWithDup(vector<int>&nums,int startIndex,vector<vector<int>>&res,int curLen,vector<int>&cur){
        if(cur.size()==curLen){
            res.push_back(cur);
            return;
        }
        //用于当前层去重
        set<int> curEles;
        for(int i=startIndex;i<nums.size();i++){
            if(curEles.count(nums[i])==0){
                curEles.insert(nums[i]);
                cur.push_back(nums[i]);
                dfsSubSetsWithDup(nums,i+1,res,curLen,cur);
                cur.pop_back();
            }
        }
        curEles.clear();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            dfsSubSetsWithDup(nums,0,res,i,cur);
            cur.clear();
        }
        //加入原始数组
        res.push_back(nums);
        return res;
    }


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

typedef std::string AddressLines[4];  //每个人的地址有4行，每行是一个string.

int main(){
    vector<vector<char>> input={{'O','O'},{'O','O'}};
    Solution slu;
    slu.solve(input);
    for(auto it:input){
        for(auto im:it){
            cout<<im<<" ";
        }
        cout<<endl;
    }  
    return 0;
}