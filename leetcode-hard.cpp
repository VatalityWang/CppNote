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
    return 0;
}