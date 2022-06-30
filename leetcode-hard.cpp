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

};

int main(){
    return 0;
    printf("hello\n");
}