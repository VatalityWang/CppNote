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


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

/**
 * Definition for a binary tree node.
 */
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

    /**
     * 1832. 判断句子是否为全字母句
     * **/
     bool checkIfPangram(string sentence) {
        vector<int> exists(26);
        if(sentence.size()<26)
            return false;
        for(int i=0;i<sentence.size();i++){
            exists[sentence[i]-'a']=1;
        }
        int sum=0;
        for(auto it:exists)
            sum+=it;
        return sum==26;
    }

    /**
     * 501. 二叉搜索树中的众数
     * **/
    static bool cmp(const pair<int,int>&left,const pair<int,int>&right){
        return right.second<left.second;
    }

    void traverseTree(TreeNode*root,map<int,int>&eles){
        if(!root)
            return;
        eles[root->val]++;
        traverseTree(root->left,eles);
        traverseTree(root->right,eles);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        map<int,int> eles;
        traverseTree(root,eles);
        vector<pair<int,int>> duplicated(eles.begin(),eles.end());
        sort(duplicated.begin(),duplicated.end(),cmp);
        
        int max_count=duplicated[0].second;
        res.push_back(duplicated[0].first);
        for(int i=1;i<duplicated.size();i++){
            if(duplicated[i].second==max_count){
                res.push_back(duplicated[i].first);
            }
        }
        return res;
    }

    /**
     * 530. 二叉搜索树的最小绝对差
     * 
    */
    void traverse(TreeNode*root,vector<int>&eles){
        if(!root)
            return;
        eles.push_back(root->val);
        traverse(root->left,eles);
        traverse(root->right,eles);
    }

    int getMinimumDifference(TreeNode* root) {
        int res=INT_MAX;
        vector<int>eles;
        traverse(root,eles);
        sort(eles.begin(),eles.end()); 
        for(int i=1;i<eles.size();i++){
            res=min(res,eles[i]-eles[i-1]);
        }
        return res;
    }

    /**
     * 860. 柠檬水找零
     * **/
     bool lemonadeChange(vector<int>& bills) {
        map<int,int> statistic;
        for(int i=0;i<bills.size();i++){
            int leave=bills[i]-5;
            if(leave==5){
                statistic[10]++;
                if(statistic[5]){
                    statistic[5]--;
                }
                else    
                    return false;
            }else if(leave==15){
                statistic[20]++;
                if(statistic[5]&&statistic[10]){
                    statistic[10]--;
                    statistic[5]--;
                }
                else if(statistic[5]>=3){
                    statistic[5]-=3;
                }else{
                    return false;
                }    
            }else if(leave==0){  
                statistic[5]++;
            }
        }
        return true;
    }

    /**
     * 2119. 反转两次的数字
     * **/
    bool isSameAfterReversals(int num) {
        string str_first=std::to_string(num);
        reverse(str_first.begin(),str_first.end());
        int re_num=stoi(str_first);
        string str_sec=std::to_string(re_num);
        reverse(str_sec.begin(),str_sec.end());
        int second_num=stoi(str_sec);
        return second_num==num;
    }

    /**
     * 53. 最大子数组和
     * **/
     vector<int> calucateMaxSubArray(vector<int>&nums,int start,int end){
      //存以左端点为起始点的最大子数组和，存以右端点为起始点的最大子数组和，该区间段的最大子数组和，该区间段的总和。
       
        if(start==end){
            return {nums[start],nums[start],nums[start],nums[start]};
        }
       
        int mid=(start+end)>>1;
        vector<int> leftRes=calucateMaxSubArray(nums,start,mid);
        vector<int> rightRes=calucateMaxSubArray(nums,mid+1,end);
        int lsum=max(leftRes[0],leftRes[3]+rightRes[0]);
        int rsum=max(rightRes[1],leftRes[1]+rightRes[3]);
        int sum=leftRes[3]+rightRes[3];
        int maxSubSum=max(max(leftRes[2],rightRes[2]),leftRes[1]+rightRes[0]);
        return {lsum,rsum,maxSubSum,sum};

    }

    int maxSubArray(vector<int>& nums) {
        vector<int>res=calucateMaxSubArray(nums,0,nums.size()-1);
        return res[2];
    }

    /**
     * 821. 字符的最短距离
     * **/
     vector<int> shortestToChar(string s, char c) {
        vector<int> res;
        int left=-1,right=-1;//距离当前位置左边最近的c字符和右边最近的c字符

        //获取最左和最右位置
        for(int i=0;i<s.size();i++){
           left=i,right=i;
           while(left>=0&&s[left]!=c)
                left--;
           while(right<s.size()&&s[right]!=c)
                right++;
           if(left>=0&&right<s.size()){
                res.push_back(min(abs(left-i),abs(right-i)));
           }
           else{
               if(left>=0)
                    res.push_back(abs(left-i));
                else
                    res.push_back(abs(right-i));
           }
        }
        return res;
    }

    /**
     * 804. 唯一摩尔斯密码词
     * **/
     int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> dicts={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> res;
        string cur;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++)
                cur+=dicts[words[i][j]-'a'];
            res.insert(cur);
            cur="";
        }
        return res.size();
    }

    /**
     * 653. 两数之和 IV - 输入 BST
     * **/

    void inOrderTree(TreeNode*root,map<int,int>&statistic,bool & res,int target){
        if(!root)
            return;
        //找到与当前元素互补的元素
        if(statistic.find(root->val)!=statistic.end()){
            res=true;
            return;
        }
        statistic[target-root->val]=root->val;
        inOrderTree(root->left,statistic,res,target);
        inOrderTree(root->right,statistic,res,target);
    }

    bool findTarget(TreeNode* root, int k) {
        map<int,int> statistic;
        bool res=false;
        inOrderTree(root,statistic,res,k);
        return res;
    }

    /**
     * 205. 同构字符串
     * **/
     bool isIsomorphic(string s, string t) {
        map<char,char> l2r;
        map<char,char> r2l;
        //映射关系要唯一
        for(int i=0;i<s.size();i++){
            if(l2r.find(s[i])==l2r.end())
                l2r[s[i]]=t[i];
            else{
                if(l2r[s[i]]!=t[i])
                    return false;
            }
            if(r2l.find(t[i])==r2l.end())
                r2l[t[i]]=s[i];
            else{
                if(r2l[t[i]]!=s[i])
                    return false;
            }
        }
        return true;
    }

    /**
     * 202. 快乐数
     * **/
     bool isHappy(int n) {

        int ans=0;
        for(int i=0;i<100;i++){
            while(n) {
                ans+=(n%10)*(n%10);
                n/=10;
            }
            n=ans;
            if(n==1)
                return true;
            ans=0;
        }
        return false;
    }
    // 基于集合的方法
     bool isHappy_(int n) {

        int ans=0;
        set<int> eles;
        while(n){
            while(n){
                ans+=(n%10)*(n%10);
                n/=10;
            }
            if(eles.count(ans)){
                if(ans==1)
                    return  true;
                else 
                    return false;
            }
            else
                eles.insert(ans);
            n=ans;
            ans=0;
        }
        return false;
    }
    /**
     * 1078. Bigram 分词
     * */
      vector<string> split(string input,string delimiter){
        vector<string> res;
        size_t pos=0;
        string token;
        while ((pos=input.find(delimiter))!=string::npos){
            token=input.substr(0,pos);
            res.push_back(token);
            input.erase(0,pos+delimiter.length());
        }
    
        res.push_back(input);
        return res;
}

    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        vector<string> words;
        string delimiter=" ";
        words=split(text,delimiter);
        int i=0;
        while(i<words.size()-2){
            if(words[i]==first&&words[i+1]==second){
                res.push_back(words[i+2]);
            }
            i++;
        }
        return res;
    }


    /**
     * 590. N 叉树的后序遍历
     * **/
     void nTreePostorder(Node*root,vector<int>&res){
        if(root){
            if((root->children).size()){
                for(auto it:root->children)
                    nTreePostorder(it,res);
            }
            res.push_back(root->val);
        }
    }

    vector<int> postorder(Node* root) {
        vector<int> res;
        nTreePostorder(root,res);
        return res;
    }

    //非递归方法
      vector<int> postorderNtree(Node* root) {
        vector<int> res;
        if(!root)
            return res;
        stack<Node*> eles;
        eles.push(root);
        while(eles.size()){
            Node * p=eles.top();
            eles.pop();
            res.push_back(p->val);
            int childS=p->children.size();
            if(childS){
                for(int i=0;i<childS;i++){
                    eles.push(p->children[i]);
                }
            }
        }
      
        reverse(res.begin(),res.end());
        return res;
    }

    /**
     * 575. 分糖果
     * **/
     int distributeCandies(vector<int>& candyType) {
      
        return min(unordered_set<int>(candyType.begin(),candyType.end()).size(),candyType.size()/2);
    }

    /**
     * 748. 最短补全词
     * **/
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int board[26]={0};
        int cur[26]={0};
        int res=-1;
        for(int i=0;i<licensePlate.size();i++){
            if(isupper(licensePlate[i]))
                board[tolower(licensePlate[i])-'a']++;
            if(islower(licensePlate[i]))
                board[licensePlate[i]-'a']++;
        }

      
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                if(isupper(words[i][j]))
                    cur[tolower(words[i][j])-'a']++;
                if(islower(words[i][j]))
                    cur[words[i][j]-'a']++;
            }
         
            bool statisfy=true;
            for(int k=0;k<26;k++){
                

               
                
                if(cur[k]&&board[k]&&cur[k]<board[k]){
                    statisfy=false;
                    break;
                }

                if(!cur[k]&&board[k]){
                    statisfy=false;
                    break;
                }

            }

            if(statisfy){
                if(res==-1)
                    res=i;
                else{
                    if(words[i].size()<=words[res].size())
                        res=i;
                }
            }
  
            memset(cur,0,sizeof(cur));
  
        }
        return words[res];
    }

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
    Solution slu;
    string licensePlate="1s3 PSt";
    vector<string> words={"step","steps","stripe","stepple"};
    string res=slu.shortestCompletingWord(licensePlate,words);
    cout<<"res: "<<res<<endl;
    return 0;
}