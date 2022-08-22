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

        /*
        * 51. N皇后
        */
        bool judge_place(int row,int column,vector<vector<int>>&exist){
        //当前列是否能放置
        bool c_place=true;
        for(int i=0;i<exist.size();i++){
           
            if(exist[i][column]){
                c_place=false;
                break;
            }
        }
        //正对角线
        for(int i=row-1,j=column-1;i>=0&&j>=0;i--,j--){
            if(exist[i][j]){
               c_place=false;
                break;
            }
        }
        //负对角线
        for(int i=row-1,j=column+1;i>=0&&j<exist.size();i--,j++){
            if(exist[i][j]){
                c_place=false;
                break;
            }
        }
        return c_place;
    }


    void backtrack(vector<vector<string>>&res,vector<string>&cur,int index,vector<vector<int>>&exist,int n){ //index表示处理到的当前行
       
        if(index==n){
            res.push_back(cur);
            return;
        }
        for(int i=0;i<n;i++){//遍历位于index行的各个列是否满足放置条件
            if(judge_place(index,i,exist)){
               exist[index][i]=1;
               string cur_str(n,'.');
               cur_str[i]='Q';
               cur.push_back(cur_str);
               backtrack(res,cur,index+1,exist,n);
               cur.pop_back();
               exist[index][i]=0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> cur;
        vector<vector<int>> exist(n,vector<int>(n,0));
       
        backtrack(res,cur,0,exist,n);
        return res;
    }


        /*
        * 332. 重新安排行程
        */
        bool backtrack(vector<vector<string>>& tickets,vector<string>&res,\
        unordered_map<string,map<string,int>>&statistic){
            if(res.size()==tickets.size()+1){
                return true;
            }
            for(auto &it:statistic[res.back()]){    
                if(it.second){
                    it.second--;
                    res.push_back(it.first);
                    if(!backtrack(tickets,res,statistic)){
                        res.pop_back();
                        it.second++;
                    }
                    else
                        return true;
                }
            }
            return false;
        }


        vector<string> findItinerary(vector<vector<string>>& tickets) {
            vector<string> res;
            unordered_map<string,map<string,int>> statistic;
            for(int i=0;i<tickets.size();i++){
                statistic[tickets[i][0]][tickets[i][1]]++;
            }
            res.push_back("JFK");
            backtrack(tickets,res,statistic);
            return res;
        }
        /**
         * 115. 不同的子序列
         * **/
        int numDistinct(string s, string t) {
            int n1=s.size(),n2=t.size();

            //dp[i][j]: s[0:i-1]中子序列t[0:j-1]的个数
            vector<vector<unsigned long long>> dp(n1+1,vector<unsigned long long>(n2+1));

            //初始化
            dp[0][0]=1;
            for(int i=1;i<=n1;i++)
                    dp[i][0]=1; //任何字符串空字符子串的个数为1
                    
            for(int i=1;i<=n1;i++){
                for(int j=1;j<=n2;j++){
                    if(t[j-1]==s[i-1]){
                        dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                    }else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
            return dp[n1][n2];
        }

        /**
         * 123. 买卖股票的最佳时机 III
         * **/
        int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1)
            return 0;
        //dp[i][0]:第i天不做任何操作；
        //dp[i][1]:第i天第1次买入；
        //dp[i][2]:第i天第1次卖出；
        //dp[i][3]:第i天第2次买入；
        //dp[i][4]:第i天第2次卖出。
        vector<vector<int>> dp(n,vector<int>(5));
        dp[0][1]=-prices[0];
        dp[0][3]=-prices[0];
        for(int i=1;i<n;i++){
            dp[i][0]=dp[i-1][0];
            dp[i][1]=max(dp[i-1][0]-prices[i],dp[i-1][1]);
            dp[i][2]=max(dp[i-1][1]+prices[i],dp[i-1][2]);
            dp[i][3]=max(dp[i-1][2]-prices[i],dp[i-1][3]);
            dp[i][4]=max(dp[i-1][3]+prices[i],dp[i-1][4]);
        }
        return dp[n-1][4];
    }
    /**
     * 188. 买卖股票的最佳时机 IV
     * **/
    int maxProfit(int k, vector<int>& prices) {
        if(k==0||prices.size()<=1)//边界条件
            return 0;
        vector<int> dp(2*k+1,0);//表示没有任何操作，第1次买入，第一次卖出，第i次买入，第i次卖出
        for(int j=1;j<=2*k;j++)
            if(j%2)
                dp[j]=-prices[0];
        for(int i=0;i<prices.size();i++){
            for(int j=1;j<=2*k;j++){
                if(j%2) //买入
                    dp[j]=max(dp[j],dp[j-1]-prices[i]);
                else{ //卖出
                    dp[j]=max(dp[j],dp[j-1]+prices[i]);
                }
            }
        }
        return dp[2*k];
    }

};

int main(){
  
    Solution slu;
    vector<vector<string>> res=slu.solveNQueens(4);
    return 0;
}