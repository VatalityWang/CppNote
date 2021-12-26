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