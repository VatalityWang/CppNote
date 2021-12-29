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



class Solution {
public:

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