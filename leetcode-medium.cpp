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


//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 


class Solution {
public:
    using ll = long long;
    const int mod = 1e9 + 7;
    /**
     * 907. 子数组的最小值之和
     * **/
    //利用l,r两个数组,l存某个位置上元素左边第一个比该位置元素小的位置；r存右边第一个比当前元素小的元素位置;
    //当前位置与两个位置的差即最小数组中该位置元素被选中为最小元素的次数。
    //注意：初始化
     int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<ll> l(n, -1), r(n, n);
        stack<int> st;
        for (int i = 0; i < n; i ++ ) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {//当前位置元素比栈顶位置(以前位置)对应元素大，则利用当前位置更新栈顶位置对应r数组。
                r[st.top()] = i;
                st.pop();
            }
            if (!st.empty()) l[i] = st.top();//用比当前位置元素小且在当前元素左边的第一个元素位置更新l数组
            st.push(i);
        }
        ll ans = 0; 
       
        for (int i = 0; i < n; i ++ ) ans += (i - l[i]) * (r[i] - i) * arr[i] % mod;
        return (ans + mod) % mod;
    }

    /**
     * 97. 交错字符串
     * **/
     bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size();
        int n2=s2.size();
        int n3=s3.size();
        if((n1+n2)!=n3)
            return false;
        vector<vector<bool>> dp(n1+1,vector<bool>(n2+1,false));//dp[i][j]:s1[0:i]和s2[0:j]能否组成s3[0:i+j-2];i,j表示字符串长度
       
        dp[0][0]=true;
       
        for(int i=1;i<=n1;i++)
                dp[i][0]=dp[i-1][0]&&(s1[i-1]==s3[i-1]);
        for(int i=1;i<=n2;i++)
                dp[0][i]=dp[0][i-1]&&(s2[i-1]==s3[i-1]);
        for(int i=1;i<=n1;i++)
            for(int j=1;j<=n2;j++){
                dp[i][j]=dp[i-1][j]&&s1[i-1]==s3[i+j-1]||dp[i][j-1]&&s2[j-1]==s3[i+j-1];
                //错误解法
                /*
                 if(s1[i-1]==s3[i+j-1])
                    dp[i][j]=(dp[i-1][j]);
                
                if(s2[j-1]==s3[i+j-1])
                    dp[i][j]=(dp[i][j-1]);
                */
            }
        
        
        return dp[n1][n2];
    }

    /**
     * 95. 不同的二叉搜索树 II
     * **/
     vector<TreeNode*>generate(int left,int right){
        vector<TreeNode*> allTrees;
        if(left>right){
            allTrees.push_back(nullptr);
            return allTrees;
        }
        for(int i=left;i<=right;i++){
            vector<TreeNode*> left_nodes=generate(left,i-1);
            vector<TreeNode*> right_nodes=generate(i+1,right);
            for(TreeNode*left_node:left_nodes)
                for(TreeNode*right_node:right_nodes){
                    TreeNode*t=new TreeNode(i);
                    t->left=left_node;
                    t->right=right_node;
                    allTrees.push_back(t);
                }
        }
        return allTrees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(n>=1)
            return generate(1,n);
        else
            return vector<TreeNode*>{};

    }

    /**
     * 91. 解码方法
     * **/
     int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1); //dp[i]表示以i下标结束的字符串的可解码组合数
        if(s[0]=='0')
            return 0;
        dp[1]=1; // 首字母成一个组合
        dp[0]=1;
        for(int i=1;i<n;i++){
            string temp(1,s[i-1]);
            if(temp=="0"){
                if(s[i]!='0'){
                    dp[i+1]=dp[i];
                    continue;
                }else{//连续的0则必不能组合
                    return 0;
                }
            }
            temp+=s[i];
            int curnum=stoi(temp);
          
            if(s[i]!='0'){ //不为0
                if(curnum<=26&&curnum>=0) //可与上一位组合成一个26以内的整数，即一个字符
                    dp[i+1]=dp[i-1]+dp[i];
                else
                    dp[i+1]=dp[i];
            }else{ // 当前字符为0单独考虑
                 if(curnum<=26&&curnum>=0) {//可与上一位组合成一个26以内的整数，即一个字符
                    if(i==n-1)//最后的0只能与上一位非零的组合
                        dp[i+1]=dp[i-1];
                    else    
                        dp[i+1]=dp[i-1];
                 }
                 else   
                    return 0;
            }
         
        }
        return dp[n];
    }
    /**
     * 216. 组合总和 III
     * **/
    void combinationSum3Dfs(vector<vector<int>>&res,vector<int>&cur,int k,int n,int index,int &sum){
        if(sum>n)
            return;
        if(cur.size()==k){
            // int sum=std::accumulate(cur.begin(),cur.end(),0);
            if(sum==n)
                res.push_back(cur);
            return;
        }
        
        //增加剪枝操作

        for(int i=index;i<=9-(k-cur.size())+1;i++){
            cur.push_back(i);
            sum+=i;
            combinationSum3Dfs(res,cur,k,n,i+1,sum);
            sum-=i;
            cur.pop_back();
        }
    }

    // 选k个数使和等于n
    vector<vector<int>> combinationSum3(int k, int n) {
        int sum=0;
        vector<vector<int>> res;
        vector<int> cur;
        combinationSum3Dfs(res,cur,k,n,1,sum);
        return res;
    }


    /**
     * 377. 组合总和 Ⅳ
     * **/
     int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1);//dp[i] 装满容量为i的背包的组合数
        dp[0]=1;
        for(int j=1;j<=target;j++){ //先遍历背包容量
            for(int i=0;i<nums.size();i++) //再遍历物品，用容量去遍历物品。则会存在先后关系。即容量小的时候，容量小的物品被装上；容量大的背包，容量大的物品再容量小的物品后面装上，体现的了不同的装入顺序。即一种具有先后顺序的排列关系。
                if(j>=nums[i]&&dp[j]<(INT_MAX-dp[j-nums[i]]))
                    dp[j]+=dp[j-nums[i]]; //dp[4]=dp[1]+dp[2]+dp[3]，装满容量为1的背包然而上容量为3的背包；装满容量为2的背包的组合数然后装上容量为2的物品；装满容量为3的背包然后装上容量为1的物品。
           
        }
        return dp[target];
    }

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