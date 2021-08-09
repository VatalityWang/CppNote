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

static int list_node_val[] = {8, 6, 5, -1, -1, 7, -1, -1, 6, 7, -1, -1, 5, -1, -1};
static int counter = 0;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL)
    {
    }
};

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

 // Definition for an interval.
  struct Interval
  {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

 bool static compare_Interval(const Interval &v1,const Interval &v2){
       if(v1.start>v2.start) return false;
       else return true;
   }

template <typename T>
bool static compare_int( T v1, T v2) {
    stack<int> decompose1,decompose2;
    if(v1==0){
        decompose1.push(0);
    }
    else{
        while(v1){
            decompose1.push(v1%10);
            v1/=10;
        }
    }
    if(v2==0){
        decompose2.push(0);
    }
    else{
        while (v2){
            decompose2.push(v2%10);
            v2/=10;
        }
    }
    while(decompose1.size()&&decompose2.size()){
        int temp1=decompose1.top();
        int temp2=decompose2.top();
        decompose1.pop();
        decompose2.pop();
        if(temp1>temp2)
            return true;
        else if(temp1<temp2)
            return false;
    }
     //剩下的元素都为零
    if(decompose1.size())
        return false;
    else
        return true;
}


template <typename T>
bool static compare(const T &v1,const T &v2){
   if(v1>v2)
    return false;
   else
    return true;
}


bool static compare_string_by_number(const string &v1,const string &v2){
   return v1+v2>v2+v1;
}

struct point{
    int x,y,w;
};

 template<typename T> 
    bool compare_inter_vector(const T &v1,const T &v2){
        return v1[0]<v2[0]?true:false;
    }


/**
 * 按序打印
 * **/
class Foo {
public:
    mutex mutex1,mutex2;
    unique_lock<mutex> lock1,lock2;

    Foo():lock1(mutex1,try_to_lock),lock2(mutex2,try_to_lock){
       
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        lock1.unlock();

    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        lock_guard<mutex> guard(mutex1);
        printSecond();
        mutex2.unlock();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        lock_guard<mutex> guard(mutex2);
        printThird();
             
    } 

   
   
};


/********************************************栈**********************************************************/
/**
 * 用两个栈实现队列
 * **/
class CQueue {
public:
    CQueue() {
       
    }
    
    void appendTail(int value) {
        input.push(value);
    }
    
    int deleteHead() {
        int res;
        if(output.size()){
            res=output.top();
            output.pop();
        }
        else{     
            while(input.size()){
                int top_=input.top();
                output.push(top_);
                input.pop();
            }
            if(output.size()){
                res=output.top();
                output.pop();
            }
            else
                return -1;
        }
        return res;
    }
private:
    stack<int> input;
    stack<int> output;
};

/**
 * 返回最小值的栈
 * **/
class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> elements;

    MinStack() {
        elements.clear();
    }
    
    void push(int val) {
        elements.push_back(val);
    }
    
    void pop() {
        elements.pop_back();
    }
    
    int top() {
        int elem=elements.back();
        return elem;
    }
    
    int getMin() {
        return *std::min_element(elements.begin(),elements.end());
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
/*
* 返回队列最大值
*/
class MaxQueue {
public:

    queue<int> elements;
    deque<int> max_elements;
    MaxQueue() {
        
       
    }
    
    int max_value() {
        if(max_elements.size()){
            int max=max_elements.front();
            //max_elements.pop_front();
            return max;
        }
        else 
            return -1;
    }
    
    void push_back(int value) {
        elements.push(value);
        if(!max_elements.size()){
            max_elements.push_back(value);
        }
        else{
            while(max_elements.size()&&max_elements.back()<value){
                max_elements.pop_back();
            }
            max_elements.push_back(value);
        }
    }
    
    int pop_front() {
        if(elements.size()){
            int element=elements.front();
            elements.pop();
            if(max_elements.size()&&element==max_elements.front())
                max_elements.pop_front();
            return element;
        }
        else
            return -1;
    }
};
struct DListNode{
    DListNode * pre;
    DListNode * next;
    int key,val;
    DListNode(int _key,int _val){key=_key;val=_val;pre=nullptr;next=nullptr;}
    DListNode():key(0),val(0),pre(nullptr),next(nullptr) {}
};


class LRUCache {
public:
    int totalCapacity;
    int size=0;
    map<int,DListNode*> elements;
    DListNode * head;
    DListNode * tail;

    
    void moveToHead(DListNode * node){
      
        node->pre->next=node->next;
        node->next->pre=node->pre;
        node->next=head->next;
        head->next->pre=node;
        node->pre=head;
        head->next=node;
    }

     void addToHead(DListNode * node){
        node->next=head->next;
        head->next->pre=node;
        node->pre=head;
        head->next=node;
    }

    void removeNode(DListNode * node){
        node->pre->next=node->next;
        node->next->pre=node->pre;
    }

    DListNode* removeFromTail(){
        DListNode * temp=tail->pre;
        removeNode(temp);
        return temp;
    }

    LRUCache(int capacity) {
        totalCapacity=capacity;
        head=new DListNode();
        tail=new DListNode();
        head->next=tail;
       
        tail->pre=head;
     
    }

    void printNode(){
        DListNode *p=head->next;
        while(p!=tail){
            cout<<p->val<<"->";
            p=p->next;
        }
        cout<<endl;
    }
    
    int get(int key) {
        //能找到
        if(elements.find(key)!=elements.end()){
            //移动链表节点至表头
           moveToHead(elements[key]);
           return elements[key]->val;
        }
        //不能找到
        else
            return -1;
    }
    
    void put(int key, int value) {
        //能找到,更新value值
        if(elements.find(key)!=elements.end()){
            DListNode *old=elements[key];
            moveToHead(old);
            old->val=value;

        }
        //不能找到
        else{   //增加新的节点至链表头
                if(size<totalCapacity){
                    //cout<<"insert "<<key<<" "<<value<<endl;
                    DListNode * node=new DListNode(key,value);
                    addToHead(node);
                    size++;
                    elements.insert({key,node});
                }
                //容量满了，删除尾部节点,增加新节点至表头
                else if(size==totalCapacity){
                    DListNode * temp= removeFromTail();
                    elements.erase(temp->key);
                    delete temp;

                    DListNode * tempNew=new DListNode(key,value);
                    addToHead(tempNew);
                    elements.insert({key,tempNew});
                }
        } 
        //printNode();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

static int sum=0;
class SumSolution {
public:
    SumSolution(){

    }
    ~SumSolution(){
        sum=0;
        
    }
    SumSolution(int n):num(n){
        sum+=n;
    }

    int sumNums(int n) {
        for(int i=1;i<=n;i++){
          SumSolution*p =new SumSolution(i);
        }
        return sum;
    }
    int num;
};

class Solution
{
public:

    /**
     * 剑指 Offer 34. 二叉树中和为某一值的路径
     * **/
    void dfs_Bt(TreeNode* root, int target,vector<int> &cur,vector<vector<int>> &res){
        if(root){
            //页节点
            if(!root->left&&!root->right){
                if(root->val==target){
                    cur.push_back(root->val);
                    res.push_back(cur);
                    cur.pop_back();
                }
            }
            else{
                cur.push_back(root->val);
                dfs_Bt(root->left,target-root->val,cur,res);
                dfs_Bt(root->right,target-root->val,cur,res);
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> res;
        if(!root)
            return res;
        vector<int> cur;
        dfs_Bt(root,target,cur,res);
        return res;
    }

    /**
    * 剑指 Offer 49. 丑数
    **/
    int nthUglyNumber(int n) {
        vector<int> uglys;
        uglys.push_back(1);
        int p2=0,p3=0,p5=0,curMax;
        while(uglys.size()!=n){
            curMax=min(uglys[p2]*2,min(uglys[p3]*3,uglys[p5]*5));
            if(curMax==uglys[p2]*2)//有可能存在相等的情况
                p2++;
            if(curMax==uglys[p3]*3)
                p3++;
            if(curMax==uglys[p5]*5)
                p5++;
            uglys.push_back(curMax);
        }
        return uglys.back();
    }



    /**
     * 剑指 Offer 35. 复杂链表的复制
     * **/
     int findIndex(vector<Node*>&nodes,Node*node){
        if(!node)
            return -1;
        vector<Node*>::iterator it=find(nodes.begin(),nodes.end(),node);
        return it-nodes.begin();
    }

    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        Node * pwork=head;
        vector<Node*> nodes;
        vector<Node*> newnodes;
        Node * newHead=new Node(0);
        Node * tail=newHead;
        while(pwork){
            //创建新节点
            Node * temp=new Node(pwork->val);
            newnodes.push_back(temp);
            tail->next=temp;
            tail=tail->next;
            nodes.push_back(pwork);
            pwork=pwork->next;
        }
        pwork=head;
        int i=0;
        while(pwork){
            int randIndex=findIndex(nodes,pwork->random);
            if(randIndex==-1)
                newnodes[i]->random=nullptr;
            else
                newnodes[i]->random=newnodes[randIndex];
            pwork=pwork->next;
            i++;
        }
        return newHead->next;
    }   
    /**
    * 611. 有效三角形的个数
    * 
    **/
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)
            return 0;
        int num=0;
        int i,j,k;
        sort(nums.begin(),nums.end());
        for(i=0;i<n-2;i++)
            for(j=i+1;j<n-1;j++){
                int temp=nums[i]+nums[j];
                k=j+1;
                if(k<n){
                // 二分查找第一个比前两个数小的。
                    int left=k,right=n-1,pos=j;
                    while(left<=right){
                        int mid=(left+right)/2;
                        if(nums[mid]>=temp){
                            right=mid-1;
                        }
                        else{
                            pos=mid;
                            left=mid+1;
                        }    
                    }
                    num+=pos-k+1;
                }
            }
        return num;
    }

    /**
     * 82. 删除排序链表中的重复元素 II map
     * **/
    ListNode* deleteDuplicates_map(ListNode* head) {
        if(!head||!head->next)
            return head;
        map<int,int> elements;
        ListNode * pwork=head;
        ListNode * newHead=new ListNode(0);        
        ListNode *tail=newHead;
        while(pwork){
            elements[pwork->val]++;
            pwork=pwork->next;
        }
        map<int,int>::iterator it=elements.begin();
        while(it!=elements.end()){
            if(it->second==1){
                tail->next=new ListNode(it->first);
                tail=tail->next;
            }
            it++;
        }
        return newHead->next;
    }

    /**
     * 82. 删除排序链表中的重复元素 II
     * **/
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode * pre,*pwork,*tail;
        ListNode * newHead=new ListNode(0);
        tail=newHead;
        pre=head;
        pwork=pre->next;
        bool newPre=true;
        while(pwork){
            if(!newPre){
                if(pwork->val!=pre->val){
                    newPre=true;
                    pre=pwork;
                }    
            }
            else{
                if(pwork->val==pre->val){
                    newPre=false;
                }
                else{
                    tail->next=pre;
                    tail=pre;
                    pre=pwork;
                }
            }
            pwork=pwork->next;
        }
        if(newPre)
            tail->next=pre;
        else
            tail->next=nullptr;
        return newHead->next;
    }

    /**
     * 不同路径 II
     * **/
     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        int i,j;
        vector<vector<int>> dp(m,vector<int>(n));
        if(obstacleGrid[0][0]){
            return 0;
        }
        dp[0][0]=1;
        for(j=1;j<n;j++)
            if(obstacleGrid[0][j])
                break;
            else
                dp[0][j]=dp[0][j-1];
        for(i=1;i<m;i++)
            if(obstacleGrid[i][0])
                break;
            else
                dp[i][0]=dp[i-1][0];
        for(i=1;i<m;i++)
            for(j=1;j<n;j++){
                if(!obstacleGrid[i][j]){
                    dp[i][j]=dp[i][j-1]+dp[i-1][j];
                }
            }
        return dp[m-1][n-1];
    }

    /**
     * 乘积最大子数组
     * **/
    int maxProduct(vector<int>& nums) {
        int i,res=nums[0];
        int pre=nums[0];
        if(nums.size()==1)
            return res;
        int max_=pre;
        int min_=pre;
        int tempMax,tempMin;
        for(i=1;i<nums.size();i++){
            tempMax=max_;
            tempMin=min_;
            max_=max(tempMax*nums[i],max(nums[i],tempMin*nums[i]));
            min_=min(tempMin*nums[i],min(nums[i],tempMax*nums[i]));
           
            res=max(max_,res);

        }
        return res;
    }
    /**
     * 合并K个升序链表
     * **/
     ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) 
            return nullptr;
        if(lists.size()==1)
            return lists[0];
        int n=lists.size();
        vector<ListNode *> pwork;
        ListNode * head=new ListNode(0);
        ListNode * min=nullptr;
        ListNode * tail=head;
        int minIndex=-1;

        //初始化头节点
        std::copy(lists.begin(),lists.end(),std::back_inserter(pwork));
       
        //遍历n个链表
        bool flag=true;
        while(flag){
            flag=false;
            min=nullptr;
            minIndex=-1;
            for(int i=0;i<pwork.size();i++){
                if(!min&&pwork[i]){
                    min=pwork[i];
                    minIndex=i;
                    flag|=true;
                }
                else if(pwork[i]&&min->val>pwork[i]->val){
                    minIndex=i;
                    min=pwork[i];
                    flag|=true;
                }
               
            }
            if(minIndex!=-1){
                tail->next=min;
                tail=min;
                pwork[minIndex]=pwork[minIndex]->next;
            }
            else 
                break;
            for(int i=0;i<pwork.size();i++){
                 if(!pwork[i])
                    pwork.erase(pwork.begin()+i);
            }
        }
        return head->next;
    }
    //基于multimap的方法
     ListNode* mergeKLists_(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return nullptr;
        if(lists.size()==1)
            return lists[0];
        int n=lists.size();
        multimap<int,ListNode *> pwork;
        ListNode * head=new ListNode(0);
        ListNode * min=nullptr;
        ListNode * tail=head;
        int minIndex=-1;

        //初始化头节点
        for(int i=0;i<lists.size();i++)
        if(lists[i])
            pwork.insert({lists[i]->val,lists[i]});
      
        while(pwork.size()){
            multimap<int,ListNode *>::iterator it=pwork.begin();
            if(it->second){
                tail->next=it->second;
                tail=tail->next;
                ListNode *temp=it->second;

                pwork.erase(it);

                if(temp->next)
                    pwork.insert({temp->next->val,temp->next});

            }
        }

        return head->next;
    }

    /**
     *  零钱兑换 II(暴力，会超时)
     * **/
    void dfsCoins(int amount,int index,int &num,vector<int>&coins){

        if(index==coins.size())
            return;
        if(amount==0){
            num++;
            return;
        }
        cout<<"amount "<<amount<<endl;
        dfsCoins(amount,index+1,num,coins);
        if(amount-coins[index]>=0){
            dfsCoins(amount-coins[index],index,num,coins);
        }
    }

    int change(int amount, vector<int>& coins) {
        int num=0;
        dfsCoins(amount,0,num,coins);
        
        return num;
    }

    //动态规划解法
    int change_dp(int amount, vector<int>& coins) {
        vector<int> dp(amount+1);
        dp[0]=1;
        for(int j=0;j<coins.size();j++){
            for(int i=coins[j];i<=amount;i++)    
                dp[i]+=dp[i-coins[j]];
        }
        return dp[amount];
    }


    /**
     * 接雨水
     * **/
    int trap(vector<int>& height) {
        //单调栈,index对应高度递减
        stack<int> indexs;
        int i,top,left;
        int volume=0;
        for(i=0;i<height.size();i++){
            while(!indexs.empty()&&height[indexs.top()]<=height[i]){
                top=indexs.top();
                indexs.pop();
                if(!indexs.empty()){
                    left=indexs.top();
                    volume+=min(height[i]-height[top],height[left]-height[top])*(i-left-1);
                }
            }
            indexs.push(i);
        } 
        return volume;
    }

    /**
     * 滑动窗口最大值
     * **/
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n=nums.size();
        if(k==1){
            return nums;
        }
        priority_queue<pair<int,int>> elements;
        int i=0;
        for(i=0;i<k;i++){
            elements.push({nums[i],i});
        }
        res.push_back(elements.top().first);
        //右边的元素
        for(i=k;i<n;i++){
            elements.push({nums[i],i});
            while(elements.top().second<=i-k){
                elements.pop();
            }
            res.push_back(elements.top().first);
        }
        return res;
    }

    /**
     * 戳气球 二维动态规划，行列坐标分别表示数组下标的范围。
     * **/
    int maxCoins(vector<int>& nums) {
        if(nums.size()==1){
            return  nums[0];
        }
        if(nums.size()==2)
            return nums[0]*nums[1]+nums[1];
        
        int n=nums.size();

        vector<vector<int>> dp(n+2,vector<int>(n+2));
        vector<int> val(n+2);
        val[0]=1;
        val[n+1]=1;

        for(int i=1;i<=n;i++){
            val[i]=nums[i-1];
        }
        int i,j,k;
        for(i=n-1;i>=0;i--)
            for(j=i+2;j<n+2;j++)
                for(k=i+1;k<j;k++){
                    int sum=val[i]*val[k]*val[j];
                    sum+=dp[i][k]+dp[k][j];
                    dp[i][j]=max(sum,dp[i][j]);
                }
        return dp[0][n+1];
    }   

    /**
     * 验证二叉搜索树
     * **/
    bool isValidBST(TreeNode* root) {
        if(!root)
            return false;
        stack<TreeNode *> elements;
        int lastElement=INT_MIN;
        TreeNode *p=root;
        while(p||!elements.empty()){
            while(p){
                elements.push(p);
                p=p->left;
            }
            if(!elements.empty()){
                p=elements.top();
                elements.pop();
                if(lastElement>=p->val)
                    return false;
                lastElement=p->val;
                p=p->right;
            }
          
        }
        return true;
    }

    /**
     * 单词拆分
     * **/
     bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for(auto &it:wordDict){
            words.insert(it);
        }
        int n=s.size();
        vector<bool> dp(n+1);
        dp[0]=true;
        int i,j;
        for(i=0;i<=n;i++)
            for(j=0;j<i;j++)
                if(dp[j]&&words.find(s.substr(j,i-j))!=words.end()){
                    dp[i]=true;
                    break;
                }
      
        return dp[n];  
    }

    /**
     * 字符串的排列
     * **/
     void comination(string &s,string &str,set<string>&res,vector<bool> &used){
        if(str.size()==s.size()){
            res.insert(str);
            return;
        }
        for(int i=0;i<used.size();i++){
            if(used[i]==false){
                used[i]=true;
                str+=s[i];
                comination(s,str,res,used);
                str.pop_back();
                used[i]=false;
            }
        }
    }

    vector<string> permutation(string s) {
        set<string> res;
        int n=s.size();
        if(n==1||n==0){
            return {s};
        }
        vector<bool> used(n);
        string str;
        comination(s,str,res,used);
        vector<string> new_res;
        for(auto &it:res)
            new_res.push_back(it);
        return new_res;
    }

  
    

    /**
     *  电话号码的字母组合
     * **/
    void num_dfs(vector<string> &total_str,int index,vector<string> &res,string cur){
        if(cur.size()==total_str.size()){
            res.push_back(cur);
            return;
        }
        if(index<total_str.size()){
            // printf("cur size %d, total_str size %d\n",cur.size(),total_str.size());
           
            for(auto &it:total_str[index]){
                cur+=it;
                // printf("cur %s, %c\n",cur.c_str(),it);
                num_dfs(total_str,index+1,res,cur);
                cur.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> total_str;
        vector<string> res;
        if(digits.empty())
            return  res;
        map<char,string> num2char;
        num2char.insert({'2',"abc"});
        num2char.insert({'3',"def"});
        num2char.insert({'4',"ghi"});
        num2char.insert({'5',"jkl"});
        num2char.insert({'6',"mno"});
        num2char.insert({'7',"pqrs"});
        num2char.insert({'8',"tuv"});   
        num2char.insert({'9',"wxyz"});
        int n=digits.size();
        string cur;
        int i;
        for(i=0;i<n;i++)
            total_str.push_back(num2char[digits[i]]);
    
        num_dfs(total_str,0,res,cur);
    
        return res;
    }

    /**
     * 完全平方数
     * **/
     int numSquares(int n) {
        int i,j;
        vector<int> dp(n+1);
        dp[0]=0;
        for(i=1;i<=n;i++){
            int min_temp=INT_MAX;
            for(j=1;j*j<=i;j++){
                min_temp=min(dp[i-j*j],min_temp);
            }
            dp[i]=min_temp+1;
        }
        return dp[n];
    }

    /**
     * 不同路径
     * **/
        int uniquePaths(int m, int n) {
        int i,j;
        vector<vector<int>> path_num(m,vector<int>(n));
        path_num[0][0]=1;
        if(!m&&!n)
            return path_num[m][n];
        for(i=0;i<m;i++)
            for(j=0;j<n;j++){
                if(i-1>=0&&j-1>=0)
                    path_num[i][j]=path_num[i-1][j]+path_num[i][j-1];
                if(i==0)
                    path_num[i][j]=1; 
                if(j==0)
                    path_num[i][j]=1;
            }
        return path_num[m-1][n-1];
    }

    /**
     * 搜索旋转排序数组
     * **/
    int search_(vector<int>& nums, int target) {
        int n=nums.size();
        if(!n)
            return -1;
        if(n==1){
            return nums[0]==target?0:-1;
        }
        int l,r;
        l=0;
        r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target)
                return mid;
            //左边有序
            if(nums[0]<=nums[mid]){
                if(nums[0]<=target&&target<nums[mid]){
                    r=mid-1;
                }
                else 
                    l=mid+1;
            }
            
            //右边有序 nums[mid]<=nums[r]
            else{
                if(nums[mid]<target&&target<=nums[n-1])
                    l=mid+1;
                else
                    r=mid-1;
            }
        }
        return -1;
    }

    /**
     * 在排序数组中查找元素的第一个和最后一个位置
     * **/
     vector<int> searchRange(vector<int>& nums, int target) {
        int i;
        int n=nums.size();
        int start=-1,end=-1;
        if(n==0)
           return {start,end};
        vector<int> res;
        auto pos=equal_range(nums.begin(),nums.end(),target);
        //返回一个pair{first,second};
        //first指向第一个小于等于target的元素，不存在则指向end,second指向第一个大于target的元素,不存在则指向end。

        //不存在小于等于target的元素
        if(pos.first==nums.end())
            return {start,end};
        //存在target
        else if(*pos.first==target){
            start=pos.first-nums.begin();
            end=pos.second-nums.begin()-1;
            return {start,end};
        }
        //target包含于数组元素范围中，但不存在。
        else{
            return {start,end};
        }
     }

    /**
     * 环形子数组的最大和
     * **/
     int maxSubarraySumCircular(vector<int>& nums) {
        
        int i,j,sum=0;
        int n=nums.size();
        if(n==1)
            return nums[0];
        int pre=0,max_=INT_MIN,min1=INT_MAX,min2=INT_MAX;
        for(auto &it:nums)
            sum+=it;
        pre=0;
        for(i=0;i<n;i++){
            pre=max(nums[i],pre+nums[i]);
            max_=max(max_,pre);
        }
        pre=0;
        for(i=1;i<n;i++){
            pre=min(nums[i],pre+nums[i]);
            min1=min(min1,pre);
        }
        int max_1=sum-min1;
        pre=0;
        for(i=0;i<n-1;i++){
            pre=min(nums[i],pre+nums[i]);
            min2=min(min2,pre);
        }
        int max_2=sum-min2;

        return max(max_,max(max_1,max_2));
    }
    //another solution
      int maxSubarraySumCircular_(vector<int> &A) { 
        if (A.size()==0 || A.size() < 1) {
            return 0;
        }
        int curMax, max_, curMin, min, sum;
        curMax  = max_ = curMin = min = sum = A[0];
        for (int i = 1; i < A.size(); i++) {
            sum += A[i];
            curMax = curMax > 0 ? curMax + A[i] : A[i]; 
            max_ = curMax > max_ ? curMax : max_;
            curMin = curMin < 0 ? curMin + A[i] : A[i];
            min = curMin < min ? curMin : min;
        }
        if (max_ < 0)
            return max_;
        return max(sum - min, max_);
    }
    /**
     * 零钱兑换
     * **/
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
            return 0;
        int i,j;
        int n=coins.size();
      
      
        vector<int> memeory(amount+1,amount+1);
        memeory[0]=0;
        for(i=1;i<=amount;i++){
        
            for(j=0;j<n;j++){
                int temp=i-coins[j];//
                if(temp>=0)
                    memeory[i]=min(memeory[i],memeory[temp]+1);   
            }
        }
        return memeory[amount]>amount?-1:memeory[amount];
    }

    /**
     * 和为K的子数组
     * **/
     int subarraySum(vector<int>& nums, int k) {
        int i,j;
        int num=0;
        int sum=0;
        int n=nums.size();
        int pre;
        unordered_map<int,int> statistic; 
        statistic.insert({0,1});
        for(i=0;i<n;i++){
            sum+=nums[i];
            pre=sum-k;
            if(statistic.find(pre)!=statistic.end()){
                num+=statistic[pre];//可能好几段都是相同的。在前i项中查找是否有等于pre的项，并累加出现pre出现的次数
            } 
            statistic[sum]++;
        }
        return num;
    }
    
    /**
     * 跳跃游戏 II
     * **/
    
     int jump(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        else if(nums.size()==2)
            return 1;
        int i,j,rightmost=nums[0];

        int num=0,max_pos=0,end=0;
        int n=nums.size();
        for(i=0;i<n-1;++i){
            max_pos=max(max_pos,i+nums[i]);
            if(i==end){
                end=max_pos;
                num++;
            }
        }
        return num;
    }

    /**
     * 最大正方形
     * **/
    int Expand_Square(vector<vector<char>> &matrix, int i,int j){
        int m=matrix.size()-1;
        int n=matrix[0].size()-1;
        int max_len=min(m-i,n-j);
        int p=0,q=0;
        for(p=0;p<max_len;p++){
            if(matrix[i+p][j]=='0')
                break;
        }
        for(q=0;q<max_len;q++){
            if(matrix[i][j+q]=='0')
                break;
        }
        int max_boundary=0;
        bool flag=false;
        max_len=min(p,q);
       
        if(matrix[i][j]=='1'){
            max_boundary=1;
            for(p=1;p<=max_len;p++){
                flag=false;
                if(matrix[i+p][j+p]=='0')
                    break;
                for(q=0;q<p;q++){
                    if(matrix[i+p][j+q]=='0'||matrix[i+q][j+p]=='0'){
                        flag=true;
                        break;
                    }
                }
                if(!flag)
                    max_boundary=max(max_boundary,p+1);
                else
                    break;
            }
        }

        return max_boundary*max_boundary;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int i,j;
        int m=matrix.size();
        int n=matrix[0].size();
        int max_=0;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++)
                max_=max(Expand_Square(matrix,i,j),max_);
        }
        return max_;
    }
    //基于动态规划的算法

    /**
     * 搜索二维矩阵 II
     * **/
     bool binary_search(vector<int> &nums,int low,int high,int target){
        if(low>=0&&high<=nums.size()&&low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target)
                return true;
            else if(nums[mid]<target)
                low=mid+1;
            else
                high=mid-1;
            return binary_search(nums,low,high,target);
        }
      
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i,j;
        int m=matrix.size();
        int n=matrix[0].size();
        bool res=false;
        for(i=0;i<m;i++)
             res|=binary_search(matrix[i],0,n-1,target);
        return res;
    }

    //0(m+n) 版本
     bool searchMatrix_(vector<vector<int>>& matrix, int target) {
        int i,j;
        int m=matrix.size();
        int n=matrix[0].size();
        i=m-1;
        j=0;
       while(i>=0&&j<n){
                if(matrix[i][j]>target)
                    i--;
                else if(matrix[i][j]<target)
                    j++;
                else    
                    return true;
            }
        return false;
    }
    /**
     * 最小花费跑楼梯
     * **/
     int minCostClimbingStairs(vector<int>& cost) {
        int i;
        int n=cost.size();
        vector<int> dp(3);
        dp[0]=0;
        dp[1]=0;
        for(i=2;i<=n;i++){
            dp[2]=min(dp[1]+cost[i-1],dp[0]+cost[i-2]);
            dp[0]=dp[1];
            dp[1]=dp[2];
        }
        return dp[2];
    }
    
    /**
     * 目标和
     * **/
    void sumdfs(vector<int> &nums,int index,int target,int sum,int &total){
      
        if(index==nums.size()){
            if(sum==target)
                total++;
        }
        else{
            sumdfs(nums,index+1,target,sum+nums[index],total);
            sumdfs(nums,index+1,target,sum-nums[index],total);
        }
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0,sum=0;
        sumdfs(nums,0,target,sum,total);
        return total;
    }

    //动态规划法
     int findTargetSumWays_(vector<int>& nums, int target) {
        
        int sum=std::accumulate(nums.begin(),nums.end(),0);
        int diff=sum-target;
        if(diff%2)
            return 0;
        int neg=diff/2;
        if(neg<0)
            return 0;
        
        int num=nums.size();
        vector<vector<int>> dp(num+1,vector<int>(neg+1));
        int i,j;
        
        //dp[i][j] 表示在前i个数中选择数存在通过组合等于j的方案数
        for(j=0;j<=neg;j++)
        
            if(j==0)
                dp[0][j]=1;
            else
                dp[0][j]=0;
        for(i=1;i<=num;i++)
            for(j=0;j<=neg;j++){
                if(j<nums[i-1])
                    dp[i][j]=dp[i-1][j];
                else    
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
            }
        return dp[num][neg];
    }


    /**
     * 分割等和子集
     * **/
     bool canPartition(vector<int>& nums) {
        int i,j;
        int sum=0;
        for(i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2)   
            return false;
        sum=sum/2;
        int target=sum;
        bool res=false;
        int max_element=*std::max_element(nums.begin(),nums.end());
        if(max_element>target)
            return false;
        vector<vector<bool>> dp(nums.size(),vector<bool>(target+1));
        for(i=0;i<nums.size();i++)
            dp[i][0]=true;
        dp[0][nums[0]]=true;
        for(i=1;i<nums.size();i++)
            for(j=1;j<=target;j++){
                if(j>=nums[i])
                    dp[i][j]=dp[i-1][j]|dp[i-1][j-nums[i]];
                else
                    dp[i][j]=dp[i-1][j];
            }
        return dp[nums.size()-1][target];
    }


    /*
    *
    * 岛屿数量
    */
    void dfs(int i,int j,int row,int column, vector<vector<char>>&grid){
        if(i<0||i>row-1)   
            return;
        if(j<0||j>column-1)
            return;
        if(grid[i][j]=='0')
            return;
        else{
            grid[i][j]='0';
            dfs(i+1,j,row,column,grid);
            dfs(i-1,j,row,column,grid);
            dfs(i,j+1,row,column,grid);
            dfs(i,j-1,row,column,grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int row=grid.size();
        int column=grid[0].size();
        int i,j,num;
        num=0;
        // vector<vector<int>> visited(row,vector<int>(column));
        for(i=0;i<row;i++)
            for(j=0;j<column;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,row,column,grid);
                    num++;
                }
            }
        return num;
    }


    /**
     *实现 Trie (前缀树)
     * **/
   class Trie {
public:

    vector<string> elements;

    /** Initialize your data structure here. */
    Trie() {
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if(find(elements.begin(),elements.end(),word)==elements.end())
            elements.push_back(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(find(elements.begin(),elements.end(),word)!=elements.end())
            return true;
        else 
            return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto it=find_if(elements.begin(),elements.end(),[prefix] (const string &a){auto im=a.find(prefix);return im==0;});
        if(it==elements.end())
            return false;
        else
            return true;
    }
};


    /**
     * 前 K 个高频元素
     * **/
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<int> num;
        unordered_map<int,int> element2num; 
        unordered_multimap<int,int> num2element; 
        int i;
        for(i=0;i<nums.size();i++){
            element2num[nums[i]]++;
        }



        unordered_map<int,int>::iterator it;
        for(it=element2num.begin();it!=element2num.end();it++){
            num.push(it->second);
            num2element.insert({it->second,it->first});
          
        }
        
        int curnum=-1;
        while(res.size()<k){
            int temp=num.top();
            num.pop();
            if(curnum!=temp){
                curnum=temp;
               
                for(auto pos=num2element.equal_range(curnum);pos.first!=pos.second;++pos.first)
                    res.push_back(pos.first->second);
            }
        }
        return res;
    }

    /**
     * 除自身以外数组的乘积
     * **/
     vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        vector<int> forward(n);
        vector<int> backward(n);
        int product=1;
        int i;

        for(i=0;i<n;i++){
            product*=nums[i];
         
            forward[i]=product;
        }

        product=1;
        for(i=n-1;i>=0;i--){
            product*=nums[i];
           
            backward[i]=product;
        }

        for(i=0;i<n;i++){
            if(i==0)
                res.push_back(backward[i+1]);
            else if(i==n-1)
                res.push_back(forward[i-1]);
            else{
                res.push_back(forward[i-1]*backward[i+1]);
            }
        }

        return res;
    }
    //空间复杂度为o(1)
      vector<int> productExceptSelf_(vector<int>& nums) {
        int n=nums.size();
        vector<int> forward(n);
        int product=1;
        int i;
        forward[0]=1;
        for(i=1;i<n;i++){
        
            forward[i]=nums[i-1]*forward[i-1];
        }
        product=1;
        for(i=n-1;i>=0;i--){
             forward[i]=forward[i]*product;
             product=product*nums[i];
            }
        return forward;
    }

    /**
     * 
     * 旋转图像
     * **/
     void rotate(vector<vector<int>>& matrix) {


        int row=matrix.size();
        int column=matrix[0].size();
       

        for(int i=0;i<row/2;i++)

            for(int j=0;j<column;j++){

                swap(matrix[i][j],matrix[row-i-1][j]);
            }
    
    
        for(int i=0;i<row;i++)

            for(int j=i;j<column;j++){

                swap(matrix[i][j],matrix[j][i]);
            }
    }

    /**
     * 组合总和
     * **/
     void add_elment(vector<int>&candidates,int index,int target,vector<int>&res,vector<vector<int>>&final_res){
       if(index==candidates.size())
            return;
        if(target==0){
            final_res.push_back(res);
            return;
        }
        add_elment(candidates,index+1,target,res,final_res);
        if(target-candidates[index]>=0){
            res.push_back(candidates[index]);
            add_elment(candidates,index,target-candidates[index],res,final_res);
            res.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> final_res;
        vector<int> res;
        int index=0;
        add_elment(candidates,0,target,res,final_res);
    
        return final_res;
    }

    /**
     * 最长递增子序列
     * **/
     int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        for(int i=0;i<nums.size();i++){
            dp[i]=1;
            for(int j=0;j<=i;j++){
                if(nums[j]<nums[i])
                    dp[i]=max(dp[i],dp[j]+1);//动态更新dp[i]
            }
        }
        return *std::max_element(dp.begin(),dp.end());
    }

    /**
     * 从前序与中序遍历序列构造二叉树
     **/
    TreeNode* buildOwnTree(vector<int>& preorder, vector<int>& inorder,int pre_left,int pre_right,int in_left,int in_right,map<int,int>&elements){

        if(pre_left>pre_right)    
            return nullptr;
        
        if(in_left>in_right)
            return nullptr;
    
        TreeNode *p=new TreeNode(preorder[pre_left]);

        int p_index=elements[preorder[pre_left]];

        p->left=buildOwnTree(preorder,inorder,pre_left+1,p_index-in_left+pre_left,in_left,p_index-1,elements);


        p->right=buildOwnTree(preorder,inorder,p_index-in_left+pre_left+1,pre_right,p_index+1,in_right,elements);

        return p;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size())
            return nullptr;
        
        map<int,int> elements;

        for(int i=0;i<inorder.size();i++){
           elements[inorder[i]]=i;
        }

        int pre_left,pre_right,in_left,in_right,p_index;

        pre_left=0;
        pre_right=preorder.size()-1;
        
        p_index=elements[preorder[pre_left]];

        in_left=0;
        in_right=inorder.size()-1;
        
        TreeNode* p=buildOwnTree(preorder,inorder,pre_left,pre_right,in_left,in_right,elements);

        return p;

    }



    /**
     * 寻找重复数(只有一个重复的整数)
     * **/
    int findDuplicate(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int max_bit=31;
        while(!((n-1)>>max_bit)){
            max_bit--;
        }
        for(int i=0;i<=max_bit;i++){
            int x=0,y=0;
            for(int j=0;j<n;j++){
                if(nums[j]&(1<<i))
                    x++;
                if(j>0&&(j&(1<<i)))
                    y++;
            }
            if(x>y)
                ans|=1<<i;
        }
        return ans;
    }


    /**
     *  最短无序连续子数组
     * **/
        int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        int start=-1,end=-1;
        vector<int> nums_;
        std::copy(nums.begin(),nums.end(),std::back_inserter(nums_));
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
            if(nums[i]!=nums_[i]){
                    start=i;
                    break;
                }
        for(int i=nums.size()-1;i>=0;i--)
            if(nums[i]!=nums_[i]){
                end=i;
                break;
            }
        if(start!=-1&&end!=-1)
            return end-start+1;
        return 0;
    }

    /**
     * 字符串解码
     **/
    string GetNum(int &i,string &s){
        string ret="";
        while(isdigit(s[i]))
            ret+=s[i++];
        return ret;
    }

    string GetString(vector<string> &elements){
        string ret="";
        for(int i=0;i<elements.size();i++){
            ret+=elements[i];
        }
        return ret;
    }

    string decodeString(string s) {
        string res="";
        vector<string> temp_str;
        stack<string> elements;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                elements.push(GetNum(i,s));
                i--;
            }
            else if(s[i]=='[')
                elements.push(string(1,s[i]));
            else if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
                elements.push(string(1,s[i]));
            }
            else{
                while(elements.top()!="["){
                    temp_str.push_back(elements.top());
                    elements.pop();
                }
                elements.pop();//出'['
                int num=std::stoi(elements.top());//出重复次数
                elements.pop();
                std::reverse(temp_str.begin(),temp_str.end());
                //重复num次组合成字符串
                string cur=GetString(temp_str);
                string temp="";
                while(num){
                    temp+=cur;
                    num--;
                }
                temp_str.clear();
                elements.push(temp);
            }    
        }
        while(!elements.empty()){
            temp_str.push_back(elements.top());
            elements.pop();
        }
        std::reverse(temp_str.begin(),temp_str.end());
        return GetString(temp_str);
    }


    /**
     * 除法求值(待修正)
     * **/
   unordered_map<string,int> node2num;
    
    double get_query(vector<string> &single_query,vector<vector<pair<int,double>>>&edges){

        double res=-1.0;

        int start,end;
        if(node2num.find(single_query[0])!=node2num.end()&&node2num.find(single_query[1])!=node2num.end()){

            res=1.0;
            start=node2num[single_query[0]];
            end=node2num[single_query[1]];
            if(start==end)
                return res;
            queue<int> points;
            points.push(start);
            vector<double> ratios(edges.size(),-1.0);
            ratios[start]=1.0;
            while(!points.empty()&&ratios[end]<0){
                int curpoint=points.front();
               
                points.pop();
                for(pair<int,double> it: edges[curpoint]){
                    if(ratios[it.first]<0){
                        ratios[it.first]=ratios[curpoint]*it.second;
                        points.push(it.first);
                    }
                }
            }
            res=ratios[end];
        }
        return res;

    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,vector<vector<string>>& queries) {
       
        vector<double> res;
        int num=0;
        int i=0,j=0;

        //字符串隐射到数字
        for(i=0;i<equations.size();i++){
            if(node2num.find(equations[i][0])==node2num.end())
                node2num[equations[i][0]]=num++;
            if(node2num.find(equations[i][1])==node2num.end())
                node2num[equations[i][1]]=num++;
        }

        vector<vector<pair<int,double>>> edges(num);
        //起点和终点及对应边的权值一一对应
        for(i=0;i<equations.size();i++){
            int start=node2num[equations[i][0]];
            int end=node2num[equations[i][1]];
            edges[start].push_back(make_pair(end,values[i]));
            edges[end].push_back(make_pair(start,1.0/values[i]));
        }

        for(j=0;j<queries.size();j++){
            res.push_back(get_query(queries[j],edges));
        }
        return res;
    }

    /**
     * 打家劫舍 
     **/
    struct selectStatus{
        int selected;
        int notSelected;
    };

    struct selectStatus Dfs(TreeNode *root){
        if(!root)    
            return {0,0};
        struct selectStatus left=Dfs(root->left);
        struct selectStatus right=Dfs(root->right);
        int selected=root->val+left.notSelected+right.notSelected;
        int notSelected=max(left.notSelected,left.selected)+max(right.selected,right.notSelected);  
        return {selected,notSelected};
    }

    int rob(TreeNode* root) { 
       struct selectStatus res=Dfs(root);
       return max(res.selected,res.notSelected);
    }

    //数组版本  打家劫舍
     struct choose{
        int selected;
        int notselected;
    };

    struct choose dfs(vector<int>& nums,int index){
        if(index==nums.size())
            return {0,0};
        struct choose res=dfs(nums,index+1);
        int selected=res.notselected+nums[index];
        int notselected=max(res.selected,res.notselected);
        
        return {selected,notselected};
    }

    int rob_(vector<int>& nums) {
        struct choose res=dfs(nums,0);
        return max(res.selected,res.notselected);
    }
    
    /**
     * 打家劫舍 II
     * **/
     int rob_by_scope(vector<int> &nums,int start,int end){
        int fisrt=nums[start],second=max(fisrt,nums[start+1]);
        for(int i=start+2;i<=end;i++){
            int temp=second;
            second=max(nums[i]+fisrt,second);
            fisrt=temp;
        }
        return second;
    }

    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        else if(nums.size()==2)
            return max(nums[0],nums[1]);
        int n=nums.size();
        return max(rob_by_scope(nums,0,n-2),rob_by_scope(nums,1,n-1));
    }

    /**
     * 最近公共祖先节点
     * **/
     vector<TreeNode*> road_path1;
    vector<TreeNode*> road_path2;
    vector<TreeNode*> road_path;

    void TraverseTree(TreeNode * root,TreeNode* p, TreeNode* q){
        if(!root){
          
            return;
        }
        road_path.push_back(root);
        if(root==p&&road_path1.empty()){
            std::copy(road_path.begin(),road_path.end(),std::back_inserter(road_path1));
        }
        if(root==q&&road_path2.empty()){
            std::copy(road_path.begin(),road_path.end(),std::back_inserter(road_path2));
        }
        TraverseTree(root->left,p,q);
        TraverseTree(root->right,p,q);
        if(root)
            road_path.pop_back();
     
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TraverseTree(root,p,q);
        int i=0,j=0;
        int min_len=min(road_path1.size(),road_path2.size());
     
        for(i=0;i<min_len;i++){
            if(road_path1[i]==road_path2[i])
                j=i;
        }
        return road_path1[j];
    }

    /**
     * 二叉树展开为链表
     * **/
    void preorder(TreeNode*root,vector<TreeNode*>&elements){
        if(root)
            elements.push_back(root);
        else 
            return;
        preorder(root->left,elements);
        preorder(root->right,elements);
    }
    void flatten(TreeNode* root) {
        if(!root)
            return;
        vector<TreeNode*> elements;
        preorder(root,elements);
        for(int i=0;i<elements.size()-1;i++){
            elements[i]->right=elements[i+1];
            elements[i]->left=nullptr;
            if(i==elements.size()-1)
                elements[i]->right=nullptr;
        }
    }

    /**
     * 二叉树的直径
     * **/
    int height(TreeNode*root,int &diameter){
        if(!root)
            return 0;
        int left=height(root->left,diameter);
        int right=height(root->right,diameter);
        diameter=max(diameter,left+right);
        return left>right?left+1:right+1;
    }

   

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        height(root,diameter);
        return diameter;
    }



    /**
     * 回文链表
     * **/
    //非递归
    bool isPalindrome(ListNode* head) {
        vector<int> elements;
        ListNode *pwork=head;
        while(pwork){
            elements.push_back(pwork->val);
            pwork=pwork->next;
        }
        for(int i=0,j=elements.size()-1;i<=j;i++,j--)
            if(elements[i]==elements[j])
                continue;
            else
                return false;
        return true;
    }
    //递归
    bool check(ListNode *Node){
        if(Node){
            if(!check(Node->next))
                return false;
            if(frontpointer->val!=Node->val)
                return false;
         
            frontpointer=frontpointer->next;
        } 
        return true;
    }
    bool isPalindrome_(ListNode* head) {
        frontpointer=head;
        return check(head);
    }

    /**
     * 找到所有数组中消失的数字
     * **/
     vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        res.clear();
        int n=nums.size();
        int temp;
        for(int i=0;i<nums.size();i++){
            temp=(nums[i]%n)?(nums[i]%n):n;
            nums[temp-1]+=n;
        }
       
        for(int i=0;i<nums.size();i++)
            if(nums[i]<=n)
                res.push_back(i+1);
        return res;
    }

    /**
     * 最长回文子串
     * **/
    void judge_circle_str(string &s,int left,int right,int &num){
        while(left>=0&&right<s.size()&&s[left]==s[right]){
            left--;
            right++;
            num++;
        }
    }
    int countSubstrings(string s) {
        int i;
        int num=0;
        for(i=0;i<s.size();i++){
            judge_circle_str(s,i,i,num);
            judge_circle_str(s,i,i+1,num);
        }
        return num;
    }

    /**
     * 二叉搜索树与双向链表
     * **/
    

    /**
     * 数组中出现一半的数字
     * **/
    int majorityElement_(vector<int>& nums) {
        int count=0;
        int majority;
        for(int i=0;i<nums.size();i++){
            if(count==0)
                majority=nums[i];
            if(nums[i]==majority)   
                count++;
            else{
                count--;
            }
        }
        return majority;
    }

    /**
     * 连续子数组的最大和
     ***/
     int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        int max_=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                dp[i]=nums[i];
            }
            if(i>0)
                dp[i]=dp[i-1]>0?dp[i-1]+nums[i]:nums[i];
            max_=max(dp[i],max_);
        }
        return max_;
    }

    //非动态规划
     void throughPath(vector<vector<int>>&grid,int i,int j,vector<int>&path_sum,int&cur_path){
        if(i>grid.size())
            return;
        if(j>grid[0].size())
            return;
        cur_path+=grid[i][j];
        if(i==grid.size()-1&&j==grid[0].size()-1){
            path_sum.push_back(cur_path);
            cur_path-=grid[i][j];
            return;
        }
        throughPath(grid,i+1,j,path_sum,cur_path);
        throughPath(grid,i,j+1,path_sum,cur_path);
        cur_path-=grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> path_sum;
        path_sum.clear();
        int cur_path=0;
        throughPath(grid,0,0,path_sum,cur_path);
        return *std::min_element(path_sum.begin(),path_sum.end());
    }
    //动态规划
    int minPathSumDp(vector<vector<int>>& grid) {
         int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> path_sum(m,vector<int>(n));
        int i,j;
        path_sum[0][0]=grid[0][0];
        for(i=1;i<m;i++)
            path_sum[i][0]=path_sum[i-1][0]+grid[i][0];
        for(j=1;j<n;j++)
            path_sum[0][j]=path_sum[0][j-1]+grid[0][j];
        for(i=1;i<m;i++){
            for(j=1;j<n;j++){
                path_sum[i][j]=min(path_sum[i-1][j],path_sum[i][j-1])+grid[i][j];
            }
        }
        return path_sum[m-1][n-1];
    }

    /**
     * 比特位计数
     * **/
     vector<int> countBits(int n) {
        vector<int> res;
        int cur;
        for(int i=0;i<=n;i++){
            if(i==0)
                res.push_back(0);
            else if((i&(i-1))==0){
                cur=i;
                res.push_back(1);
            }
            else{
                res.push_back(res[i-cur]+1);
            }
        }
        return res;
    }

    /**
     * 翻转二叉树
     * **/
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        invertTree(root->left);
        invertTree(root->right);
        if(root->left||root->right)
            swap(root->left,root->right);
        return root;
    }

      /**
       * 排序链表
       * **/
      ListNode* mergeList(ListNode *head1,ListNode *head2){
        
        ListNode*pwork1=head1,*pwork2=head2,*tail=nullptr,*head=nullptr;
        while(pwork1&&pwork2){
            if(pwork1->val<pwork2->val){
                if(!tail){
                    tail=pwork1;
                    head=tail;
                }
                else{
                    tail->next=pwork1;
                    tail=pwork1;
                }
                pwork1=pwork1->next;
            }
            else{
                if(!tail){
                    tail=pwork2;
                    head=tail;
                }
                else{
                    tail->next=pwork2;
                    tail=pwork2;
                }
                pwork2=pwork2->next;
            }
          
        }
        if(!tail){
            return head1?head1:head2;
        }
        else if(pwork1)
           tail->next=pwork1;
        
        else if(pwork2)
            tail->next=pwork2;
       
        return head;
    }
    ListNode* mergeSortList(ListNode *head){
        if(!head)
            return head;
        if(head->next==nullptr){
            return head;
        }
        ListNode *slow=head,*fast=head;
        while(fast->next&&fast->next->next){
           slow=slow->next;
           fast=fast->next->next;
        }
        ListNode *mid=slow;
        slow=slow->next;
        mid->next=nullptr;
       
        return mergeList(mergeSortList(head),mergeSortList(slow));
      
    }
    ListNode* sortList(ListNode* head) {
        return mergeSortList(head);
    }


    /**
     * 下一个排列
     * **/
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1)  
            return;
        int i=0,j=0;
        bool find=false;

        for(i=nums.size()-1;i>=0&&!find;i--){
            for(j=i-1;j>=0&&!find;j--){
                if(nums[j]<nums[i]){
                    find=true;
                    swap(nums[j],nums[i]);
                    
                }
            }
        }
        if(!find)
            sort(nums.begin(),nums.end());
    }
    
    

    /**
     * 盛最多水的容器
     * **/
    int maxArea(vector<int>& height) {
        int water_volume=0;
        int high,width,i,j;
        for(i=0,j=height.size()-1;i<height.size()&&j>=0&&i!=j;){
        
            high=min(height[i],height[j]);
            width=j-i;
            water_volume=water_volume<high*width?high*width:water_volume;
            
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return water_volume;
    }

    /**
     * 课程表
     * **/
    //超时算法
    void vectorDfs(int start,vector<vector<int>>&edges,vector<int> &visited,bool &res){
        visited[start]=1;
        for(auto v:edges[start]){
            if(visited[v]==0){
              vectorDfs(v,edges,visited,res);
              if(!res)
                    return;
                
            }
            else if(visited[v]==1){
                res=false;
                return;
            } 
        }
        visited[start]=2;
    }
    

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        bool res=true;
        vector<int> visited;
        vector<vector<int>> edges;
        edges.resize(numCourses);
        visited.resize(numCourses);
        //统计边
        for(int i=0;i<prerequisites.size();i++){
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);//起点，终点。
        }

        for(int i=0;i<numCourses&&res;i++){
            // printf("start %d,%d->%d\n",prerequisites[i][1],prerequisites[i][1],prerequisites[i][0]);
            if(!visited[i])
                vectorDfs(i,edges,visited,res);
        }
        return res;
    }

    /**
     * 反转链表
     * **/
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return nullptr;
        ListNode * newHead=new ListNode(0);
        ListNode * pwork=head,*temp;
        while(pwork){
            temp=pwork->next;
            pwork->next=newHead->next;
            newHead->next=pwork;
            pwork=temp;
        }
        return newHead->next;
    }

    /**
     * 二叉树的最大深度
     * **/
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        return left>right?left+1:right+1;
    }

    /**
     * 有效的括号
     * **/
    bool isValid(string s) {
        stack<char> statistics;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                statistics.push(s[i]);
            }
            else{
                    if(s[i]==')'){
                        if(statistics.size()&&statistics.top()=='(')
                            statistics.pop();
                        else
                            return false;
                    }
                    else if(s[i]==']'){
                        if(statistics.size()&&statistics.top()=='[')
                            statistics.pop();
                        else
                            return false;
                    } 
                    else if(s[i]=='}'){
                        if(statistics.size()&&statistics.top()=='{')
                            statistics.pop();
                        else
                            return false;
                    }
                }
        }
        if(statistics.size())
            return false;
        else 
            return true;
    }

    
    /**
     * 三色问题
     * **/
    void sortColors(vector<int>& nums) {
         int left=0,right=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                swap(nums[i],nums[left]);
                if(left<right){
                    swap(nums[i],nums[right]);
                }
                left++;
                right++;
            }
            else if(nums[i]==1){
                swap(nums[i],nums[right]);
                right++;
            }
        }

    }

    /**
     * 最长回文子串
     * **/
    pair<int,int> expand(string &s,int left,int right){
        while(right<s.size()&&left>=0&&s[left]==s[right]){
            --left;
            ++right;
        }
        return {left+1,right-1};
    }

    string longestPalindrome(string s) {
        int start=0,end=0;
        for(int i=0;i<s.size();i++){
             pair<int,int> res1=expand(s,i,i);
             pair<int,int> res2=expand(s,i,i+1);
            if(res1.second-res1.first>end-start){
                start=res1.first;
                end=res1.second;
            }
            if(res2.second-res2.first>end-start){
                start=res2.first;
                end=res2.second;
            }
        }
        return s.substr(start,end-start+1);
    }

    /**
     * 多数元素
     * **/
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int majority;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                majority=nums[i];
                count++;
            }
            else{
                if(nums[i]==majority)
                    count++;
                else
                    count--;
            }
        }
        return majority;
    }

    /**
     * 相交链表的第一个节点
     * **/
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=0,len2=0;
        ListNode*pwork1=headA,*pwork2=headB;
        while(pwork1){
            len1++;
            pwork1=pwork1->next;
        }
        while (pwork2){
            len2++;
            pwork2=pwork2->next;
        }
        pwork1=headA;
        pwork2=headB;
        if (len1>len2){
            while(len1>len2){
                pwork1=pwork1->next;
                len1--;
            }
        }
        else {
            while(len1<len2){
                pwork2=pwork2->next;
                len1++;
            }
        }
        while(pwork1&&pwork2){
            if(pwork1==pwork2)
                return pwork1;
            else{
                pwork2=pwork2->next;
                pwork1=pwork1->next;
            }
        }
        return nullptr;
    }

    /**
     * 爬楼梯
     * **/
    int climbStairs(int n) {
        int p=0,q=0,r=1;
        for(int i=1;i<=n;i++){
            p=q;
            q=r;
            r=p+q;
        }
        return r;
    }

    /**
     * 数据流的中位数
     * **/
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums(nums1.size()+nums2.size());
        std::copy(nums1.begin(),nums1.end(),nums.begin());
        std::copy(nums2.begin(),nums2.end(),nums.begin()+nums1.size());
        sort(nums.begin(),nums.end());
        int length=nums.size();
        int mid=length/2;
        if(length%2) 
            return nums[mid];
        else
            return (nums[mid]+nums[mid-1])/2.0;
    }


    /**
     * 不同的二叉搜索树
     * **/
    int numTrees(int n) {
        //长度为n的连续自然数序列能构成的二叉搜索树的种数。
        vector<int> G(n+1,0);
        G[0]=1;
        G[1]=1;
        //长度为n的序列，分别每个节点作根节点。
        for(int i=2;i<=n;i++){
            //以根节点为分割点，分别求左右子树构成的二叉搜索树个数
            for(int j=1;j<=i;j++){
                G[i]+=G[i-1]*G[i-j];
            }
        }
        return G[n];
    }


    /**
     * 判断链表中是否有环
     * **/
    bool hasCycle(ListNode *head) {
        set<ListNode*> ListNodes;
        ListNode* pwork=head;
        while (pwork){
            if(!ListNodes.count(pwork))
                ListNodes.insert(pwork);
            else
                return true;
            pwork=pwork->next;
        }
        return false;
        
    }

    /**
     * 无重复字符的最长字串
     * **/
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1)
            return s.size();
        string sub="";
        unordered_map<char,int> characters;
        unordered_map<char,int>::iterator it,im;
        int max_length=0;
        for(int i=0;i<s.size();i++){
            int index=sub.find(s[i]);
            if(index==string::npos){
                sub+=s[i];
                max_length=sub.size()>max_length?sub.size():max_length;
            }
            else{
                int temp=sub.size()-1-index;
                i-=temp+1;
                
                sub.clear();
            }
        }
        return max_length;
    }

   /**
    * 最小的k个数
    * **/
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        vector<int> res(arr.begin(),arr.begin()+k);
        return res;
    }

    /**
    * 最后一块石头的重量
    **/
    int lastStoneWeight(vector<int>& stones) {
        int a,b;
        priority_queue<int> total_stones;
        for(int i=0;i<stones.size();i++){
            total_stones.push(stones[i]);
        }
        while(total_stones.size()>=2){
            a=total_stones.top();
            total_stones.pop();    
            b=total_stones.top();
            total_stones.pop();
            if(a>b)
                total_stones.push(a-b);
        }
        if(total_stones.size()==1)
            return total_stones.top();
        else    
            return 0;
        
    }

    /**
     * 最长回文子串
     * **/
    int longestPalindrome_(string s) {
        map<char,int> statistic;
        int i;
        int odd_max=0;
        int total=0;
        bool hasSingle=false;
        for(i=0;i<s.size();i++){
            statistic[s[i]]++;
        }
        map<char,int>::iterator it=statistic.begin();
        while(it!=statistic.end()){
            if(it->second)
                total+=it->second/2*2;
            if(it->second%2&&!hasSingle){
                hasSingle=true;
                total++;   
            }
            it++;
        }
        return total;
    }

    void inorderTree(TreeNode*root,vector<int>&res){
        if(!root)
            return;
        if(root->left)
            inorderTree(root->left,res);
        res.push_back(root->val);
        if(root->right)
            inorderTree(root->right,res);
    }

   /**
    * 二叉树的中序遍历
    * **/
   vector<int> inorderTraversal(TreeNode* root){
       vector<int> res;
        inorderTree(root,res);
        return res;

    }

    /**
     * 删除链表节点
     * **/
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *newHead=new ListNode(0);
        newHead->next=head;
        ListNode *pwork=head,*pre=newHead;
        for(;pwork;pwork=pwork->next){
            if(pwork->val==val){
                pre->next=pwork->next;
                
            }
            else{
                pre=pwork;
                
            }
        }
        return newHead->next;
    }

    /**
     * 二叉树的坡度
     * **/
    int get_node_sum(TreeNode *root){
        if(!root)
            return 0;
        return root->val+get_node_sum(root->left)+get_node_sum(root->right);
    }

    void calucate_gradient(TreeNode *root,int&total_grad){
        if(!root)
            return;
        int left=0,right=0;
        if(root->left){
            left=get_node_sum(root->left);
            calucate_gradient(root->left,total_grad);
        }
        if(root->right){
            right=get_node_sum(root->right);
            calucate_gradient(root->right,total_grad);
        }
        total_grad+=abs(left-right);
    }

    int findTilt(TreeNode* root) {
        int total_grad=0;
        calucate_gradient(root,total_grad);
        return total_grad;
    }

    /**
     * 三数之和等于0
     ***/
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        res.clear();
        int i,j,k;
        sort(nums.begin(),nums.end());
        for( i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1])
                continue;
            k=nums.size()-1;
            for( j=i+1;j<nums.size();j++){
                if(j>i+1&&nums[j]==nums[j-1])
                    continue;
                while(j<k&&nums[j]+nums[k]>-nums[i])
                    k--;
                if(k==j)
                    break;
                if(nums[j]+nums[k]==-nums[i]){
                    res.push_back({nums[i],nums[j],nums[k]});
                }
            }
            
        }
        return res;
    }   

    /**
     * 三角形的最大周长
     * **/
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=0;i-=3){
            if(i>=2&&nums[i-1]+nums[i-2]>nums[i])
                return nums[i-1]+nums[i-2]+nums[i];
           

        }
        return 0;
    }

    /**
     * 合并两个有序链表
     **/
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!(l1&&l2)){
            if(!l1&&!l2)
                return l1;
            else
                return l1?l1:l2;
        }
        ListNode *newhead=new ListNode(0);
        ListNode *pwork=newhead;
        ListNode *pwork1=l1,*pwork2=l2;
        while (pwork1||pwork2){
            if(pwork1&&pwork2){

                if(pwork1->val<pwork2->val){
                
                    pwork->next=pwork1;
                    pwork=pwork1;
                    pwork1=pwork1->next;
                }
                else{
                
                    pwork->next=pwork2;
                    pwork=pwork2;
                    pwork2=pwork2->next;
                }
            }
            else{
                if(pwork1){
                    
                    pwork->next=pwork1;
                    pwork=pwork1;
                    pwork1=pwork1->next;
                }
                if(pwork2){
                    pwork->next=pwork2;
                    pwork=pwork2;
                    pwork2=pwork2->next;
                }
            }
        }
        return newhead->next;
    }

    /**
     * 四数之和
     ***/

    //此种方法包含重复元素重复组合
    void judge_sum(vector<int>&cur,vector<vector<int>>&res, vector<int>&used,vector<int>&nums, int target,int num){
        if(cur.size()==num){
            if(std::accumulate(cur.begin(),cur.end(),0)==target)
                res.push_back(cur);
            return;
        }
        for(int i=0;i<used.size();i++){
            if(used[i]==0){
                cur.push_back(nums[i]);
                used[i]=1;
                judge_sum(cur,res,used,nums,target,num);
                cur.pop_back();
                used[i]=0;
            }
        }
    }

    vector<vector<int>> fourSum_(vector<int>& nums, int target) {
        vector<int> used(nums.size(),0);
        vector<int> cur;
        vector<vector<int>> res;
        cur.clear();
        res.clear();
        int num=4;
        judge_sum(cur,res,used,nums,target,num);
        return res;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target){
        int first,second,third,four,total;
        total=nums.size()-1;
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(first=0;first<nums.size();first++){
            if(first>0&&nums[first]==nums[first-1])
                continue;
            for(second=first+1;second<nums.size();second++){
                if(second>first+1&&nums[second-1]==nums[second])
                    continue;
                for(third=second+1;third<nums.size();third++){
                    if(third>second+1&&nums[third-1]==nums[third])
                        continue;
                    four=total;
                    while(four>third&&nums[four]>target-(nums[first]+nums[second]+nums[third]))
                        four--;
                    if(four==third)
                        break;
                    if(nums[four]=target-(nums[first]+nums[second]+nums[third]))
                        res.push_back({nums[first],nums[second],nums[third],nums[four]});
                }
            }
        }
        return res;
    }

    /**
    * 删除链表中倒数第n个节点 
    **/
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pwork1=head,*pwork2=head,*pre=nullptr;
        int i=0;
        while(i<n-1){
            pwork2=pwork2->next;
            i++;
        }
        while(pwork2&&pwork2->next!=nullptr){
            pre=pwork1;
            pwork1=pwork1->next;
            pwork2=pwork2->next;
        }
        if(pre){
            pre->next=pwork1->next;
            pwork1->next=nullptr;
            return head;
        }
        else
            return pwork1->next;
    }

    /**
     * 移除元素
     * **/
    int removeElement(vector<int>& nums, int val) {
        int i,slow=0,fast=0,size=nums.size();
        while(fast<size){
            if(nums[fast]!=val){
                nums[slow++]=nums[fast++];
            }
            else{
                fast++;
            }
        }
        return slow;
    }

    /**
     * 删除有序数组中的重复项
     * **/
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator it,im;
        for(it=nums.begin();it!=nums.end();it++){
            for(im=it+1;im!=nums.end();){
                if(*im==*it){
                    im=nums.erase(im);
                }
                else
                    im++;
            }
        }
        return nums.size();
    }

    /**
     * 交换一次的先前排列 从第二位开始找比最高位数字小的数中的最大者与最高位(处理位)进行交换
     * **/
    vector<int> prevPermOpt1(vector<int>& arr) {
        int i,j,flag,max_index,size=arr.size();
        for(i=size-2;i>=0;i--){
            flag=i;
            max_index=-1;
            for(j=i+1;j<size;j++){
                if(arr[j]<arr[flag]){
                    if(max_index==-1)
                        max_index=j;
                    else{
                        if(arr[j]>arr[max_index])
                            max_index=j;
                    }
                }
            }
            if(max_index!=-1){
                swap(arr[flag],arr[max_index]);
                return arr;
            }
        }
        return arr;
    }

    /**
     * 链表 两数相加
     * **/
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pwork1=l1;
        ListNode *pwork2=l2;
        ListNode *newlist=new ListNode(-1);
        ListNode *ptail=newlist;
        ListNode*p;
        int carry=0;
        int temp=0;
        while(pwork1||pwork2){
            if(pwork2&&pwork1){
                temp=pwork1->val+pwork2->val+carry;
                carry=temp/10;
                if(temp<10){
                    p=new ListNode(temp);
                }
                else{
                    p=new ListNode(temp%10);
                }
                ptail->next=p;
                ptail=p;
                pwork1=pwork1->next;
                pwork2=pwork2->next;
            }
            else{
                if(pwork1){
                    temp=pwork1->val+carry;
                    carry=temp/10;
                    if(temp<10){
                        p=new ListNode(temp);
                    }
                    else{
                        p=new ListNode(temp%10);
                    }
                    ptail->next=p;
                    ptail=p;
                    pwork1=pwork1->next;
                } 
                if(pwork2){
                    temp=pwork2->val+carry;
                    carry=temp/10;
                    if(temp<10){
                        p=new ListNode(temp);
                    }
                    else{
                        p=new ListNode(temp%10);
                    }
                    ptail->next=p;
                    ptail=p;
                    pwork2=pwork2->next;
                }
            }   
        }
        if(carry){
            p=new ListNode(carry);
            ptail->next=p;
            ptail=p;
        }
        return newlist->next;
    }

    /**
     * 存在重复元素
     **/
    int getID(int x, long w) {
        return x < 0 ? (x + 1ll) / w - 1 : x / w;
    }
    /**
     * 官方题解
     * **/
    bool containsNearbyAlmostDuplicate_(vector<int>& nums, int k, int t) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            long x = nums[i];
            int id = getID(x, t + 1ll); //long long 整型的1
            if (mp.count(id)) {
                return true;
            }
            if (mp.count(id - 1) && abs(x - mp[id - 1]) <= t) {
                return true;
            }
            if (mp.count(id + 1) && abs(x - mp[id + 1]) <= t) {
                return true;
            }
            mp[id] = x;
            if (i >= k) {
                mp.erase(getID(nums[i - k], t + 1ll));
            }
        }
        return false;
    }



    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<long,long>> statis;
        int i;
        for(i=0;i<nums.size();i++){
            statis.push_back(make_pair(nums[i],i));
        }
        sort(statis.begin(),statis.end());
        for(int i=0;i<statis.size();i++)
            for(int j=i+1;j<statis.size();j++){
                if(abs(statis[j].first-statis[i].first)<=t&&abs(statis[j].second-statis[i].second)<=k)
                    return true;
                if(abs(statis[j].first-statis[i].first)>t)
                    break;
            }
        return false;
    }

    void collection(vector<vector<int>> &res,vector<int>&cur,vector<int>&nums,int n,vector<int> &used){
        if(cur.size()==n){
            res.push_back(cur);
            return;
        }
        for(int i=0;i<used.size();i++){
            if(used[i]==0){
                cur.push_back(nums[i]);
                used[i]=1;
                collection(res,cur,nums,n,used);
                cur.pop_back();
                used[i]=0;
            }
        }
     
    }
    
    /**
     * 全排列
     * **/
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int len=nums.size();
        vector<int> used(len,0);
        vector<int> cur;
        cur.clear();
        res.clear();
        int pos=-1;
        collection(res,cur,nums,len,used);
        return res;
    }

    /**
     * 二叉树的堂兄弟节点
     * **/

    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode *rLeft=root->left;
        TreeNode *rRight=root->right;
        //保存上一层的节点数
        TreeNode *PxNode=new TreeNode(x);
        TreeNode *PyNode=new TreeNode(y);
        deque<TreeNode*> elements;
        elements.push_back(root);
        while(!elements.empty()){
            int Level_size=elements.size();
            if(Level_size>2){
                deque<TreeNode*>::iterator im=std::find_if(elements.begin(),elements.end(),[&](auto & e){return e->val==PxNode->val;});
                deque<TreeNode*>::iterator in=std::find_if(elements.begin(),elements.end(),[&](auto & e){return e->val==PyNode->val;});
                if(im!=elements.end()&&in!=elements.end() &&abs(im-in)>=1){
                    if(abs(im-in)==1){
                        int distance;
                        if(im>in)
                            distance=im-elements.begin();
                        else
                            distance=in-elements.begin();    
                        if(!(distance%2))
                            return true;
                        else
                            return false;
                    }
                    else
                        return true;
                }
            }
            int i=0;
            while(i<Level_size){
                TreeNode * pNode=elements.front();
                if(pNode->left)
                    elements.push_back(pNode->left);
                else if(pNode->right)
                    elements.push_back(new TreeNode(0));
                if(pNode->right)
                    elements.push_back(pNode->right);
                else if(pNode->left)
                    elements.push_back(new TreeNode(0));
                elements.pop_front();
                i++;
            }
        }
        return false;
    }


    /*
    * 两数之和  哈希
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> statistic;
      
        for(int i=0;i<nums.size();i++){
            map<int,int>::iterator it;
            it=statistic.find(target-nums[i]);
            if(it!=statistic.end()){
                return {it->second,i};
            }
            statistic[nums[i]]=i;
        }
        return {};
    }

    /**
     * 只出现一次的数字
     * **/
    int singleNumber(vector<int>& nums) {

        int i=0;
        map<int,int> statistic;
        for(i=0;i<nums.size();i++){
            statistic[nums[i]]++;
        }
        map<int,int>::iterator it;
        for(it=statistic.begin();it!=statistic.end();it++){
            if(it->second==1)
                return it->first;
        }
        return i;
    }
    /*
    * 基于异或的方法
    */
    int singleNumber_(vector<int>& nums){
        for(int i=1;i<nums.size();i++){
            nums[0]^=nums[i];
        }
        return nums[0];
    }


    
    /**
     * 子集 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
     * **/
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.clear();
        int total=nums.size();
        int auxiliary=pow(2,total)-1;
        for(int i=0;i<=auxiliary;i++){
            vector<int> cur_res;
            cur_res.clear();
            for(int j=0;j<total;j++){
                if(i&&(1<<j))
                    cur_res.push_back(nums[j]);
            }
            res.push_back(cur_res);
        }
        return res;
    }

    /**
     * 删除并获得点数
     * **/
    int rob_delete_num(vector<int>&sum_nums){
        int size=sum_nums.size();
        int first=sum_nums[0],second=max(sum_nums[0],sum_nums[1]);
        for(int i=2;i<size;i++){
            int temp=second;
            second=max(first+sum_nums[i],second);
            first=temp;
        }
        return second;
    }

    int deleteAndEarn(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int max_value=*std::max_element(nums.begin(),nums.end());
        vector<int> sum_nums(max_value+1);
        for(int it:nums){
            cout<<it<<endl;
            sum_nums[it]+=it;
        }
        return rob(sum_nums);
    }




    bool valid(string &char_str){
        int i,balance=0;
        for(i=0;i<char_str.size();i++){
            if(char_str[i]=='('){
                balance++;
            }
            else
                balance--;
            //中间过程不满足就返回
            if(balance<0)
                return false;
        }
        return balance==0;
    }
    

    void add_bracket(vector<string>&res,string &single_res,int n){

        if(single_res.size()==n*2){
            if(valid(single_res)){
                res.push_back(single_res);
            }
            return;
        }

        single_res+='(';
        add_bracket(res,single_res,n);
        single_res.pop_back();
        single_res+=')';
        add_bracket(res,single_res,n);
        single_res.pop_back();  
    }



    /**
     * 括号生成
     * **/
     vector<string> generateParenthesis(int n) {
        //write code here
        vector<string> res;
        res.clear();
        string single_res="";
        add_bracket(res,single_res,n);
        return res;
    }


    /**
     * 子数组的最大累加和 
     * **/
     int maxsumofSubarray(vector<int>& arr) {
        // write code here
        if(arr.size()==1)
            return arr[0];
        int i=0;
        int pre=0,max=arr[0];
        for(i=0;i<arr.size();i++){
            pre=std::max(pre+arr[i],arr[i]);
            max=std::max(pre,max);
        }
        return max;
    }

    /**
     * 买卖股票的最佳时期
     * **/
    int maxProfit_(vector<int>& prices) {
        int minprice=INT_MAX;
        int max_profit=0;
        int i;
        for(i=0;i<prices.size();i++){
            minprice=minprice<prices[i]?minprice:prices[i];
            max_profit=max(max_profit,prices[i]-minprice);
        }
        return max_profit;
    }

    /**
     * 股票(无限次交易)
     * @param prices int整型vector 股票每一天的价格
     * @return int整型
     * 买找最低价,卖找最高价 找波峰和波谷，波谷买入，波峰卖出。
     **/
     int maxProfit(vector<int>& prices) {
        // write code here

        int profit=0;
        if(prices.size()<=1)
            return profit;
        bool descend;
        vector<int>::iterator min_index=prices.begin();
        vector<int>::iterator max_index=prices.begin();
        if(prices[1]>prices[0]){
            descend=false;
            max_index=min_index+1;
        }
        else{
            descend=true;
            min_index=max_index+1;
        }
        vector<int>::iterator it;
        for(it=prices.begin()+2;it!=prices.end();it++){
            if(*it>*(it-1)){
                //由下降转上升，波谷
                if(descend){
                    min_index=it-1;
                }
                descend=false;
            }
            else{
                //由上升转下降,波峰
                if(!descend){
                    max_index=it-1;
                    if(max_index>min_index){
                        profit+=*max_index-*min_index; 
                    }
                }
                descend=true;
            }
        }
        if(!descend)
            return profit+*(it-1)-*min_index;
        else
            return profit;
    }

    bool static comparex(point p1,point p2){
        return p1.x<p2.x;
    }
    bool static comparey(point p1,point p2){
        return p1.y<p2.y;
    }

    /**
     * 带权最小曼哈顿距离
     * n:点个数
     * x:x坐标
     * y:y坐标
     * w:每个点的权值
     * **/
     long long MinimumDistance(int n, vector<int>& x, vector<int>& y, vector<int>& w) {
        // write code here
        long long min=0;
        int i=0,W=0,s=0,x_=0,y_=0;
        // point *p=(point*)malloc(n*sizeof(point));
        point *p=(point*)new point[n];
        for(i=0;i<n;i++){
            p[i].x=x[i];
            p[i].y=y[i];
            p[i].w=w[i];
            W+=w[i];
        }
        W/=2;

        sort(p,p+n,comparex);
        for(i=0;i<n;i++){
            s+=p[i].w;
            if(s>W){
                x_=i;
                break;
            }
        }
        for(i=0;i<n;i++){
            min+=abs(p[i].x-p[x_].x)*p[i].w;
        }

        s=0;
        sort(p,p+n,comparey);
        for(i=0;i<n;i++){
            s+=p[i].w;
            if(s>W){
                y_=i;
                break;
            }
        }
        for(i=0;i<n;i++){
            min+=abs(p[i].y-p[y_].y)*p[i].w;
        }
        delete []p;
        return min;

     }

    /**
     * 牛牛，牛妹仍骰子 抛n次m面的骰子
     * **/

    string Throwdice(int n, int m, vector<int>& a, vector<int>& b) {
        // write code here
        // write code here
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int sum1=0,sum2=0;
        bool flag1=true,flag2=true;
        for(int i=0;i<n &&(flag1||flag2);i++){
            if(a[i]<=sum1+1){
                sum1+=a[i];
            }else{
                flag1=false;
                sum1+=1;
            }
             
            if(b[i]<=sum2+1){
                sum2+=b[i];
            }else{
                sum2+=1;
                flag2=false;
            }
        }
        return sum1>sum2 ? "Happy" : "Sad";

    }

     /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 牛牛拼数
     * 返回这n个数能够组成的最大的数字是多少    
     * @param s string字符串vector 
     * @return string字符串
     */
    string formMaxNumber(vector<string>& s) {
        // write code here
        sort(s.begin(),s.end(),compare_string_by_number);
        string res="";
        for(auto &it:s)
            res+=it;
        return res;

    }



    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回符合牛牛希望的分法中最小的差值是多少
     * @param n int整型 代表共有多少数
     * @param a int整型vector 代表每个数的大小
     * @return int整型
     */
    int splitArray(int n, vector<int>& a) {
        // write code here
        sort(a.begin(),a.end());
        vector<int> diff;
        for(int i=0;i<a.size();i++)
            if(i<a.size()-1)
                diff.push_back(a[i+1]-a[i]);
        return *std::min_element(diff.begin(),diff.end());
    }

    /**
     * 奇怪的排序问题
     * 操场上有n个人排成一队，这n个人身高互不相同，可将他们的身高视为一个1到n的排列。
     * 这时需要把队伍变成升序，也就是从矮到高排序。 
     * 每次可以选择一个人，让这个人和在他身后的人比高矮，如果比对方高，则交换位置并继续下一次比较，直到比对方矮或者已经在队尾。
     * 现在给出数n和一个1到n的排列，求最少的选择次数，使队伍变为升序。
     * **/
    int wwork(int n, vector<int>& a) {
        // write code here
        int i,count=0,order=n;
        for(i=n-1;i>=0;i--){
            if(a[i]>order)
                count++;
            order=min(a[i],order);
        }
        return count;
    }

    /**
     * 栈排序
     * @param a int整型一维数组 描述入栈顺序
     * @param aLen int a数组长度
     * @return int整型vector
     */
    vector<int> solve(int* a, int aLen) {
        // write code here
        vector<int> res;
        stack<int> aux;
        int i=0;
        aux.push(a[i++]);
        while (aux.size()||i<=aLen){
            if(i==aLen){
                while(aux.size()){
                    res.push_back(aux.top());
                    aux.pop();
                }
                i++;
            }
            else{
                if(aux.size()){
                    int top=aux.top();
                    int next_max=*(std::max_element(a+i,a+aLen));
                    while(top>next_max){
                        aux.pop();
                        res.push_back(top);
                        if(aux.size())
                            top=aux.top();
                        else
                            break;
                    }
                }
                aux.push(a[i++]);
            }
        }
        return res;
    }

    /**
     * 
     * 给定一个数组由一些非负整数组成，现需要将他们进行排列并拼接，使得最后的结果最大，返回值需要是string类型 否则可能会溢出。
     * input:[30,1]
     * output:"301"
     * 最大数
     * @param nums int整型vector 
     * @return string字符串
     */
    string solve(vector<int>& nums) {
        // write code here
        string res="";
        int num;
        sort(nums.begin(),nums.end(),compare_int<int>);
        for(int i=0;i<nums.size();i++){
            res+=std::to_string(nums[i]);
        }
        stringstream ss;
        ss<<res;
        ss>>num;
        if(num==0)
            return string("0");
        return res;
    }

    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 链表奇偶节点重排
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* oddEvenList(ListNode* head) {
        // write code here
        if(!head||!head->next)
            return head;
        ListNode*odd,*even,*temp,*work,*evenstart,*oddstart;
        int i=1;
        work=head;
        while(work){
            temp=work->next;
            if(i%2){
                if(i==1)
                    oddstart=work;
                odd=work;
                if(work->next&&work->next->next)
                    odd->next=work->next->next;
                else
                    odd->next=nullptr;
            }
            else{
                if(i==2)
                    evenstart=work;
                even=work;
                if(work->next&&work->next->next)
                    even->next=work->next->next;
                else
                    even->next=nullptr;
            }
            work=temp;
            i++;
        }
        odd->next=evenstart;
        return oddstart;
    }


    /*
    * 合并区间  给出一组区间，请合并所有重叠的区间。请保证合并后的区间按区间起点升序排列。
    * input:[[10,30],[20,60],[80,100],[150,180]]
    * output:[[10,60],[80,100],[150,180]]
    * **/
   //template<typename T>
    //leetcode版
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare_inter_vector<vector<int>>);//传参数的时候，初始化模板实际类型。
        vector<vector<int>>::iterator it,next;
        vector<vector<int>> merged;
        for(it=intervals.begin();it<intervals.end();it++){
            int L=(*it)[0],R=(*it)[1];
            if(!merged.size()||merged.back()[1]<L)
                merged.push_back({L,R});
            else
                merged.back()[1]=max(R,merged.back()[1]);
        }
        return merged;
    }

    //牛客版
    vector<Interval> merge(vector<Interval> &intervals)
    {
        sort(intervals.begin(), intervals.end(), compare_Interval);
        vector<Interval>::iterator it, next;
        for (it = intervals.begin(); it < intervals.end(); it++){
            next = it + 1;
            if (next < intervals.end()){
                //区间内部
                if((*next).start>=(*it).start&&(*next).end<=(*it).end){                  
                    intervals.erase(next);
                    it--;
                }
                //区间重叠
                else{
                    if ((*next).start <=(*it).end){
                        (*it).end = (*next).end;
                         intervals.erase(next);
                         it--;
                    }
                }
            }
        }
        return intervals;
    }

    /*
    * 剪绳子
    * */
    int cutRope(int number) 
    {
        if(number==2)
            return 1;
        else if(number==3)
            return 2;
        else
        {
            int x=number%3;
            int y=number/3;
            if(x==0)
                return pow(3,y);
            else if(x==1)
                return 2*2*pow(3,y-1);
            else 
                return 2*pow(3,y);            

        }
    }

    /**
     * 单词搜索
     * **/
     void match(vector<vector<char>>& board,int i,int j,int index,string word,bool &res,vector<vector<bool>> &memory){
        int m=board.size();
        int n=board[0].size();
        if(i>=0&&i<m&&j>=0&&j<n&&index<=word.size()-1&&!memory[i][j]){
            if(board[i][j]==word[index]){
                if(index==word.size()-1){
                    res|=true;
                    return;
                }
                
                memory[i][j]=true;
                match(board,i+1,j,index+1,word,res,memory);
                match(board,i-1,j,index+1,word,res,memory);
                match(board,i,j+1,index+1,word,res,memory);
                match(board,i,j-1,index+1,word,res,memory);
                memory[i][j]=false;
            }
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        int i,j;
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> memory(m,vector<bool>(n,false));
        bool res=false;
        for(i=0;i<m;i++)
            for(j=0;j<n;j++){
                match(board,i,j,0,word,res,memory);
            }
        return res;
    }


    /*
    * 机器人的运动范围
    * */
    int getnumsum(int num)
    {
        int sum = 0;
        while (num)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    bool judge(int threshold, int row, int col)
    {
        if (getnumsum(row) + getnumsum(col) > threshold)
            return false;
        else
            return true;
    }
    void through_path(int threshold, int *memory, int i, int j, int rows, int cols)
    {
        if (i < 0 || j < 0 || i > rows - 1 || j > cols - 1) //越界
            return;
        int index = i * cols + j;
        if (!judge(threshold, i, j)) //不能走
            return;
        if (memory[index]) //能走但已走过
            return;
        else
            memory[index] = 1;
        through_path(threshold, memory, i - 1, j, rows, cols);
        through_path(threshold, memory, i + 1, j, rows, cols);
        through_path(threshold, memory, i, j + 1, rows, cols);
        through_path(threshold, memory, i, j - 1, rows, cols);
    }

    int movingCount(int threshold, int rows, int cols)
    {
        int count = 0;
        int i, j;
        int total = rows * cols;
        int *memory = new int[total];
        through_path(threshold, memory, 0, 0, rows, cols);
        for (i = 0; i < total; i++)
            if (memory[i])
                count++;
        return count;
    }

    /*
    * 矩阵中的路径
    * */
    bool matrix_path(string matrix, string str, int rows, int cols, int order, int i, int j, int *memory)
    {
        if (order > str.size() - 1) //超过范围
        {
            // printf("order oversize\n");
            return false;
        }
        if (i > rows - 1 || j > cols - 1 || i < 0 || j < 0)
        {
            // printf("axis oversize\n");
            return false;
        }
        // printf("before judge wether through\n");
        // print_memory(memory,8,40);
        int pos = i * cols + j;
        if (memory[pos]==1) //已走过
        {
            // printf("pos %d already through\n",pos);
            return false;
        }
        //没有走过
        if (str[order] == matrix[pos])
        {
            // printf("current pos %d,oerder %d,match char %c\n",pos,order,str[order]);
            memory[pos] = 1;
            if (order == str.size() - 1)
                return true;
            else
            {
                bool res1 = matrix_path(matrix, str, rows, cols, order + 1, i - 1, j, memory);
                if (res1)
                    return true;
                else
                {
                    bool res2 = matrix_path(matrix, str, rows, cols, order + 1, i + 1, j, memory);
                    if (res2)
                        return true;
                    else
                    {
                        bool res3 = matrix_path(matrix, str, rows, cols, order + 1, i, j - 1, memory);
                        if (res3)
                            return true;
                        else
                        {
                            bool res4 = matrix_path(matrix, str, rows, cols, order + 1, i, j + 1, memory);
                            if (res4)
                                return true;
                            else
                                return false;
                        }
                    }
                }
            }
        }
        else
            return false;
    }

    void print_memory(int *memory,int cols,int size)
    {
        for(int i=0;i<size;i++)
        {
            printf("%d ",memory[i]);
            if((i+1)%cols==0)
                printf("\n");

        }
    }

    bool hasPath(string matrix, int rows, int cols, string str)
    {
        int i, j, k;
        bool res = false;
        int *memory = new int[matrix.size()]();

        // int direction[4]={1,2,3,4};   //1,2,3,4分别代表左，上，右，下。
        string path;

        for (k = 0; k < matrix.size(); k++)
        {
            i = k / cols; //行
            j = k % cols; //列
            // printf("k %d\n",k);
            // print_memory(memory,8,40);
            res = matrix_path(matrix, str, rows, cols, 0, i, j, memory);
            if (res)
                return res;
            else
                memset(memory,0,sizeof(int)*matrix.size());
        }
        return res;
    }
    //     if(matrix[k]==str[0])
    //     {

    //         i=k/cols;   //行
    //         j=k%cols;   //列
    //         path+=matrix[k];
    //         for(int m=0;m<4;m++)
    //         {

    //             switch (direction[m])
    //             {
    //             case 1:
    //                 next=(--j)+i*cols;
    //                 if(matrix[next]==str[path.size()])
    //                     path+=matrix[next];
    //                 break;
    //             case 2:
    //                 break;
    //             case 3:
    //                 break;
    //             case 4:
    //                 break;
    //             default:
    //                 break;
    //             }
    //         }
    //     }
    //     else
    //         continue;
    // }

    /*
    *  滑动窗口最大值 
    */
    vector<int> maxInWindows(const vector<int> &num, unsigned int size)
    {
        int start, end, i;
        vector<int> res;
        vector<int> temp;
        temp.clear();
        res.clear();
        start = 0;
        end = start + size - 1;
        while (end < num.size())
        {
            i = start;
            while (i <= end)
            {
                temp.push_back(num[i]);
                i++;
            }
            sort(temp.begin(), temp.end());
            res.push_back(temp[temp.size() - 1]);
            temp.clear();
            start++;
            end++;
        }
        return res;
    }

    /*
    * 数据流中的中位数
    */
    void Insert(int num)
    {
        data.push_back(num);
    }

    double GetMedian()
    {
        sort(data.begin(), data.end());
        int length = data.size();
        if (length % 2)
            return data[length / 2];
        else
            return (data[length / 2] + data[length / 2 - 1]) / 2.0;
    }

    /*
    * 求二叉搜索树第k小的节点
    * **/
    TreeNode *midorder(TreeNode *pRoot, int k, int *num)
    {
        if (!pRoot)
            return NULL;
        TreeNode *left = NULL;
        TreeNode *right = NULL;
        left = midorder(pRoot->left, k, num);
        if (left)
            return left;
        (*num)++;
        if ((*num) == k)
            return pRoot;
        right = midorder(pRoot->right, k, num);
        if (right)
            return right;
        else
            return NULL;
    }

    TreeNode *KthNode(TreeNode *pRoot, int k)
    {
        int m = 0;
        return midorder(pRoot, k, &m);
    }

    /*
    * 序列化二叉树
    **/

    void preorder(TreeNode *root, string &str)
    {
        if (!root)
        {
            str += '#';
            return;
        }
        str += to_string(root->val);
        str += ',';
        preorder(root->left, str);
        preorder(root->right, str);
    }

    char *Serialize(TreeNode *root)
    {
        if (!root)
            return NULL;
        string str;
        preorder(root, str);
        char *serialize_res = new char[str.size() + 1];
        int i = 0;
        while (i < str.size())
        {
            serialize_res[i] = str[i];
            i++;
        }
        serialize_res[i] = '\0';
        return serialize_res;
    }

    TreeNode *deserialize(char **str)
    {
        TreeNode *root = NULL;
        if (**str == '#')
        {
            (*str)++;
            return root;
        }
        int num = 0;
        while (**str != '\0' && **str != ',')
        {
            num = num * 10 + ((**str) - '0');
            (*str)++;
        }
        root = new TreeNode(num);
        if (**str == '\0')
            return root;
        else
            (*str)++;
        root->left = deserialize(str);
        root->right = deserialize(str);
        return root;
    }

    TreeNode *Deserialize(char *str)
    {
        TreeNode *root = NULL;
        if (!str)
            return root;
        root = deserialize(&str);
        return root;
    }

    /*
    * 按行打印二叉树
    * */
    vector<vector<int>> Print_(TreeNode *pRoot)
    {
        vector<vector<int>> res;
        res.clear();
        if (!pRoot)
            return res;
        bool new_floor = true;
        queue<TreeNode *> travserse_tree;
        queue<TreeNode *> aid_tree;
        travserse_tree.push(pRoot);
        while (!travserse_tree.empty() || !aid_tree.empty())
        {
            vector<int> temp;
            temp.clear();
            if (new_floor)
            {

                while (!travserse_tree.empty())
                {

                    TreeNode *tempnode = travserse_tree.front();
                    travserse_tree.pop();
                    temp.push_back(tempnode->val);
                    if (tempnode->left)
                        aid_tree.push(tempnode->right);
                    if (tempnode->right)
                        aid_tree.push(tempnode->right);
                }
                new_floor = false;
            }
            else
            {

                while (!aid_tree.empty())
                {

                    TreeNode *tempnode = aid_tree.front();
                    aid_tree.pop();
                    temp.push_back(tempnode->val);
                    if (tempnode->left)
                        travserse_tree.push(tempnode->left);
                    if (tempnode->right)
                        travserse_tree.push(tempnode->right);
                }
                new_floor = true;
            }
            if (!temp.empty())
                res.push_back(temp);
        }
        return res;
    }


    /*
    * 按之字顺序打印二叉树
    * */
    vector<vector<int>> Print__(TreeNode *pRoot)
    {

        vector<vector<int>> res;
        res.clear();
        if (!pRoot)
            return res;
        bool from_left = true;
        stack<TreeNode *> travserse_tree;
        stack<TreeNode *> aid_tree;
        travserse_tree.push(pRoot);
        while (!travserse_tree.empty() || !aid_tree.empty())
        {
            vector<int> temp;
            temp.clear();
            if (from_left)
            {

                while (!travserse_tree.empty())
                {

                    TreeNode *tempnode = travserse_tree.top();
                    travserse_tree.pop();
                    temp.push_back(tempnode->val);
                    if (tempnode->left)
                        aid_tree.push(tempnode->left);
                    if (tempnode->right)
                        aid_tree.push(tempnode->right);
                }
                from_left = false;
            }
            else
            {

                while (!aid_tree.empty())
                {

                    TreeNode *tempnode = aid_tree.top();
                    aid_tree.pop();
                    temp.push_back(tempnode->val);
                    if (tempnode->left)
                        travserse_tree.push(tempnode->left);
                    if (tempnode->right)
                        travserse_tree.push(tempnode->right);
                }
                from_left = true;
            }
            if (!temp.empty())
                res.push_back(temp);
        }
        return res;
    }
    //leetcode
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<TreeNode *> nodes;
        stack<int> tempNodes;
        vector<int> cur;
        TreeNode * temp;
        bool left2Right=true;
        nodes.push(root);
        while(!nodes.empty()){
            int len=nodes.size();
            for(int i=0;i<len;i++){
                temp=nodes.front();
                nodes.pop();
                if(left2Right){
                    cur.push_back(temp->val);
                }else{
                    tempNodes.push(temp->val);
                }
                if(temp->left)
                    nodes.push(temp->left);
                if(temp->right)    
                    nodes.push(temp->right);
            }
            if(left2Right)
                left2Right=false;
            else{
                while(tempNodes.size()){
                    cur.push_back(tempNodes.top());
                    tempNodes.pop();
                }
                left2Right=true;
            }
            res.push_back(cur);
            cur.clear();
        }
        return res;
    }

    /*
    *  判断而产生误会是否镜像对称
    * */

    bool isSymmetrical(TreeNode *pRoot)
    {
        if (pRoot == NULL)
            return true;

        return f(pRoot->left, pRoot->right);
    }

    bool f(TreeNode *t1, TreeNode *t2)
    {
        if (t1 == NULL && t2 == NULL)
            return true;

        if (t1 != NULL && t2 != NULL)
            return t1->val == t2->val && f(t1->left, t2->right) && f(t1->right, t2->left);

        return false;
    }

    bool isSymmetrical_(TreeNode *pRoot)
    {
        TreeNode *pTemp, *pLeft, *pRight;
        deque<TreeNode *> tree_queue;
        deque<TreeNode *> tree_queue_copy;
        tree_queue.clear();
        tree_queue_copy.clear();
        // deque<TreeNode*> tree_temp;
        if (!pRoot)
            return true;
        if (!pRoot->left && !pRoot->right)
            return true;
        tree_queue.push_front(pRoot);
        while (!tree_queue.empty())
        {
            while (!tree_queue.empty())
            {
                pTemp = tree_queue.front();
                tree_queue.pop_front();
                if (pTemp->left)
                    tree_queue_copy.push_front(pTemp->left);
                if (pTemp->right)
                    tree_queue_copy.push_front(pTemp->right);
            }
            if (!tree_queue_copy.empty())
                std::copy(tree_queue_copy.begin(), tree_queue_copy.end(), std::back_inserter(tree_queue));
            // tree_queue.clear();
            while (!tree_queue_copy.empty())
            {
                pLeft = tree_queue_copy.front();
                pRight = tree_queue_copy.back();
                if (pLeft->val == pRight->val)
                {
                    tree_queue_copy.pop_back();
                    tree_queue_copy.pop_front();
                    continue;
                }
                else
                    return false;
            }
        }
        return true;
    }

    /*
    * 找出中序遍历的下一个节点并返回
    * */
    TreeLinkNode *GetNext(TreeLinkNode *pNode)
    {
        TreeLinkNode *pTemp, *pparent;
        if (!pNode)
            return NULL;
        else if (pNode->right) //右节点不空 ---> 右子树的最左节点
        {
            pTemp = pNode->right;
            while (pTemp->left)
                pTemp = pTemp->left;
            return pTemp;
        }
        else if (pNode->next) //右节点空，父节点不空 ---> 返回父节点
        {
            pTemp = pNode->next;
            if (pTemp->left == pNode) //左子树
                return pTemp;
            else if (pTemp->right == pNode) //右子树
            {
                pparent = pTemp->next;
                if (pparent->right == pTemp)
                    return NULL;
                else
                    return pparent;
            }
            else
                return NULL;
        }
        else
            return NULL;
    }

    /*
    * 删除链表重复结点
    **/
    ListNode *deleteDuplication(ListNode *pHead)
    {
        if (!pHead || pHead->next == NULL)
            return pHead;
        ListNode *ppre, *pre, *pwork, *pnext;
        ppre = (struct ListNode *)malloc(sizeof(struct ListNode));
        ppre->next = pHead;
        pre = ppre;
        pnext = NULL;
        pwork = pHead;
        while (pwork && pwork->next)
        {
            pnext = pwork->next;
            if (pwork->val == pnext->val)
            {

                while (pnext && pnext->val == pwork->val)
                    pnext = pnext->next;
                pre->next = pnext;
                pwork = pnext;
            }

            else
            {
                pre = pwork;
                pwork = pwork->next;
            }
        }

        return ppre->next;
    }

    /*
    * 链表中环的入口地址
    * */

    //leetcode 空间复杂度o(1)版本
    ListNode *detectCycle(ListNode *head) {
        ListNode*slow=head,*fast=head,*ptr=head;
        if(!fast)
            return nullptr;
        while(fast){
            slow=slow->next;
            if(!fast->next)
                return nullptr;
            fast=fast->next->next;
            if(slow==fast){
                while(ptr!=slow){
                    slow=slow->next;
                    ptr=ptr->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }

    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        ListNode *p = pHead;
        if (!pHead)
            return NULL;
        set<ListNode *> node_list;
        set<ListNode *>::iterator it;
        while (p)
        {
            node_list.insert(p);
            it = node_list.find(p->next);
            if (it != node_list.end())
            {
                return p->next;
            }
            else
            {
                p = p->next;
            }
        }
        return NULL;
    }

    /*
    * 字符流中第一个不重复的字符
    * **/

    //Insert one char from stringstream
    void Insert(char ch)
    {
        vector<char>::iterator it = find(char_set.begin(), char_set.end(), ch);
        if (it == char_set.end())
            char_set.push_back(ch);
        if (static_count.find(ch) == static_count.end())
        {
            static_count.insert({ch, 1});
        }
        else
        {
            static_count[ch]++;
        }
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        // vector<int>::iterator it;
        for (auto &it : char_set)
            if (static_count[it] == 1)
                return it;
        return '#';
    }

    /*
    * 表示数值的字符串
    **/
    bool isNumeric(char *string)
    {
        /*
        
        只有一个e/E;                 
        不能出现除E/e以外的任何字符；
        e/E后面跟数字，数字可以有符号,但不能有小数点；
        只有一个小数点；
        正负号只能出现在e/E后面或者首位

        */
        char *pstr = string;
        if (!pstr)
            return false;
        if (!strlen(pstr))
            return false;
        int i, j;
        int decimal_point = 0;
        int character_e = 0;
        int sign = 0;
        for (i = 0; i < strlen(pstr); i++)
        {
            if (pstr[i] == '+' || pstr[i] == '-')
            {
                sign++;

                if (sign > 2)
                    return false;
                if (character_e == 1)
                {
                    if (i != 0 && (pstr[i - 1] != 'e' && pstr[i - 1] != 'E'))
                        return false;
                }
                else
                {
                    if (i != 0) //不出现在首位又没有e/E
                        return false;
                }
            }
            else if (pstr[i] == 'e' || pstr[i] == 'E')
            {
                character_e++;
                if (character_e > 1)
                    return false;
                if (i == 0) //出现在首位
                    return false;
                else
                {
                    if (!(pstr[i - 1] >= '0' && pstr[i - 1] <= '9'))
                        return false;
                    if (i + 1 == strlen(pstr)) //出现在末位
                        return false;
                }
            }
            else if (pstr[i] == '.')
            {
                decimal_point++;
                if (decimal_point > 1)
                    return false;
                if (i == 0)
                    return false;
                else
                {
                    if (i + 1 == strlen(pstr))
                        return false;
                    if (!(pstr[i + 1] >= '0' && pstr[i + 1] <= '9'))
                        return false;
                    if (character_e == 1)
                        return false;
                }
            }
            else if (pstr[i] >= '0' && pstr[i] <= '9')
                continue;
            else
                return false;
        }
        return true;
    }

    /*
    * 正则表达式匹配
    * */
    bool match(char *str, char *pattern)
    {
        int i = 0, j = 0;
        int len1 = strlen(str);
        int len2 = strlen(pattern);
        if (len2 == 0)
        {
            if (!len1)
                return true;
            else
                return false;
        }
        if (pattern[1] == '*')
        {
            if ((str[0] != '\0' && pattern[0] == '.') || str[0] == pattern[0])
                return match(str, pattern + 2) || match(str + 1, pattern);
            else
                return match(str, pattern + 2);
        }
        else
        {
            if ((str[0] != '\0' && pattern[0] == '.') || str[0] == pattern[0])
                return match(str + 1, pattern + 1);
            else
                return false;
        }
    }
    /*
    * 构建乘积数组
    **/
    vector<int> multiply(const vector<int> &A)
    {
        vector<int> res;
        res.clear();
        if (A.size() <= 1)
            return res;
        int MultiplySum = 1;
        int i;
        for (i = 0; i < A.size(); i++)
            if (i == 0)
                res.push_back(MultiplySum);
            else
                res.push_back(MultiplySum *= A[i - 1]);
        for (i = A.size() - 1; i >= 0; i--)
            if (i == A.size() - 1)
                MultiplySum = 1;
            else
            {
                MultiplySum *= A[i + 1];
                res[i] *= MultiplySum;
            }
        return res;
    }
    //leetcode 
    vector<int> constructArr(vector<int>& a) {
        int n=a.size();
        vector<int> res;
        if(!n||n==1) 
            return res;
        res.resize(n);
        vector<int> left(n,1);
        vector<int> right(n,1);
        int i;
        for(i=1;i<n;i++)
            left[i]=left[i-1]*a[i-1];
        for(i=n-2;i>=0;i--)
            right[i]=right[i+1]*a[i+1];
        for(i=0;i<n;i++)
            res[i]=left[i]*right[i];
        return res;
    }


    /*
    * 数组中重复的数字
    * **/
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int *duplication)
    {
        if (length <= 1)
            return false;
        map<int, int> NumCount;
        int i = 0;
        for (i = 0; i < length; i++)
            if (NumCount.find(numbers[i]) == NumCount.end())
                NumCount.insert({numbers[i], 1});
            else
            {
                NumCount[numbers[i]]++;
            }
        for (i = 0; i < length; i++)
            if (NumCount[numbers[i]] > 1)
            {
                *duplication = numbers[i];
                return true;
            }
        return false;
    }

    /*
    * 把字符串转换成整数；输入一个字符串,包括数字字母符号,可以为空；如果是合法的数值表达则返回该数字，否则返回0。
    * **/
    int StrToInt(string str)
    {
        int i, res = 0, carrynum, carry, j;
        carry = 1;
        if (str[0] == '+' || str[0] == '-' || (str[0] >= '0' && str[0] <= '9'))
        {
            for (i = str.size() - 1; i >= 0; i--)
            {
                carrynum = str.size() - 1 - i;
                while (carrynum)
                {
                    carry *= 10;
                    carrynum--;
                }

                if (str[i] >= '0' && str[i] <= '9')
                {
                    res += (str[i] - 48) * carry;
                }
                else if (i != 0)
                {
                    return 0;
                }
                else
                {
                    if (str[i] == '+')
                        return res;
                    else if (str[i] == '-')
                        return -res;
                }
                //    printf("handle %c,carry %d res %d\n",str[i],carry,res);
                carry = 1;
            }
            return res;
        }
        else
        {
            return 0;
        }
    }

    /*
    * 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
    * */
    int Add(int num1, int num2)
    {
        int Add = num1 ^ num2;          //异或 相当于按位相加
        int Carry = (num1 & num2) << 1; //进位
        while (Carry)
        {
            num2 = Add;
            num1 = Carry;
            Add = num1 ^ num2;
            Carry = (num1 & num2) << 1;
        }
        return Add;
    }
    /*
    *  求1+2+3+...+n 要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
    * */

    int Sum_Solution(int n)
    {
        if (n == 1)
            return 1;
        else
        {
            return n + Sum_Solution(n - 1);
        }
    }

    /*
    *  圆圈中最后剩下的数
    */
    int LastRemaining_Solution(int n, int m) //n个人，从第一个开始，第m个出列。返回最后一个剩下的人
    {
        if (n == 1)
            return 0;
        if (n == 0)
            return -1;
        vector<int> People;
        int i, WorkIndex;
        for (i = 0; i < n; i++)
            People.push_back(1);
        int start = 0, countnum, j;
        while (count(People.begin(), People.end(), 1) != 1)
        {
            printf("remain count :%ld\n", count(People.begin(), People.end(), 1));
            j = start;
            countnum = 0;
            while (countnum < m)
            {
                if (People[j])
                {
                    countnum++;
                    if (countnum == m)
                    {
                        People[j] = 0;
                        printf("label %d to zero\n", j);
                    }
                    else
                        j++;
                }
                else
                {
                    j++;
                }
                if (j == People.size())
                    j = 0;
            }
            while (!People[(j + 1) % n])
            {
                j = (j + 1) % n;
            }
            start = (j + 1) % n;
            printf(" the new start is %d\n", start);
        }
        WorkIndex = find(People.begin(), People.end(), 1) - People.begin();
        return WorkIndex;
    }

    /**
    * 扑克牌顺子
    * */
    bool IsContinuous(vector<int> numbers)
    {
        if (numbers.size() == 0)
            return false;
        vector<int> SubNum;
        SubNum.clear();
        int ZeroNum = 0;
        int i;
        sort(numbers.begin(), numbers.end());
        vector<int>::iterator im;
        for (i = 0; i != numbers.size(); i++)
        {
            if (numbers[i] == 0)
                ZeroNum++;
            else if (i > 1 && numbers[i - 1])
            {
                SubNum.push_back(numbers[i] - numbers[i - 1]);
            }
        }
        if (ZeroNum == 4)
            return true;
        else
        {
            if (accumulate(SubNum.begin(), SubNum.end(), 0) - SubNum.size() == ZeroNum)
                return true;
            else
            {
                return false;
            }
        }
    }

    /**
     *  翻转单词顺序列
     **/
    string ReverseSentence(string str)
    {
        stack<string> InternalWords;
        string delimiter = " ";
        string ResStr = "";
        string token;
        size_t pos = 0;
        while ((pos = str.find(delimiter)) != string::npos)
        {
            token = str.substr(0, pos);
            cout << token << endl;
            InternalWords.push(token);
            str.erase(0, pos + delimiter.length());
        }
        cout << str << endl;
        InternalWords.push(str);
        while (!InternalWords.empty())
        {
            ResStr += InternalWords.top();
            InternalWords.pop();
            if (!InternalWords.empty())
                ResStr += " ";
        }
        return ResStr;
    }

    /**
    * 左旋转字符串
    **/
    string LeftRotateString(string str, int n)
    {
        if (str.size() == 0)
            return str;
        if (n == str.size())
            return str;
        else if (n > str.size())
            n = n - str.size();
        string TempStr1 = str.substr(0, n);
        string TempStr2 = str.substr(n, str.size() - n);
        return TempStr2 + TempStr1;
    }
    /**
    *   输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
    * */
    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        vector<vector<int>> TotalResult;
        TotalResult.clear();
        vector<int> Result;
        Result.clear();
        int i, start, end, Temp1, Temp2, Mid, Remainder;
        end = array.size() - 1;
        for (i = 0; i < array.size(); i++)
        {
            start = i + 1;
            // printf("handle the index %d\n ",i);
            Remainder = sum - array[i];
            while (start <= end)
            {

                Mid = (start + end) / 2;
                // printf("current start %d,Mid %d,end %d Remainder %d,array[Mid] %d\n",start,Mid,end,Remainder,array[Mid]);
                if (Remainder > array[Mid])
                {
                    start = Mid + 1;
                }
                else if (Remainder < array[Mid])
                {
                    end = Mid - 1;
                }
                else
                {
                    Result.push_back(array[i]);
                    Result.push_back(array[Mid]);
                    TotalResult.push_back(Result);
                    Result.clear();
                    start = start + 1;
                }
            }
        }
        if (TotalResult.size() == 1)
            return TotalResult[0];
        else if (TotalResult.size() > 1)
        {
            Mid = TotalResult[0][0] + TotalResult[0][1];
            int MinIndex = 0;
            for (i = 1; i < TotalResult.size(); i++)
            {
                if (TotalResult[i][0] + TotalResult[i][1] < Mid)
                    MinIndex = i;
            }
            return TotalResult[MinIndex];
        }
        else
        {
            return Result;
        }
    }
    /*
    *   1-1  输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序 
    */

    vector<vector<int>> FindContinuousSequence(int sum)
    {
        int i, j;
        int tempsum = 0;
        vector<vector<int>> result;
        vector<int> temp_order;
        int num = 0;
        for (i = 1; i <= sum / 2 + 1; i++)
        {
            tempsum += i;
            num += 1;
            if (num >= 2 && tempsum == sum)
            {
                for (j = i - num + 1; j <= i; j++)
                    temp_order.push_back(j);
                result.push_back(temp_order);
                temp_order.clear();
                i = i - num + 1;
                num = 0;
                tempsum = 0;
            }
            if (tempsum > sum)
            {
                i = i - num + 1;
                tempsum = 0;
                num = 0;
            }
        }
        return result;
    }

private:
    map<char, int> static_count;
    vector<char> char_set;
    vector<int> data;
    ListNode * frontpointer;
};

/*
* 输入序列建立二叉树
**/
TreeNode *CreateBTree(TreeNode *bt)
{
    int val = list_node_val[counter++];
    printf("counter %d\n", counter);
    if (counter > 16)
        return NULL;
    // fflush(stdin);
    // printf("please input val:\n");
    // scanf("%d",&val);
    // fflush(stdin);
    if (val != -1)
    {

        bt = new TreeNode(val);
        bt->left = CreateBTree(bt->left);
        bt->right = CreateBTree(bt->right);
        return bt;
    }
    else
        // cout<<"current node pointer "<<bt<<endl;
        return NULL;
}

void travserse_tree(TreeNode *root)
{
    if (root)
    {
        printf("%d\n", root->val);
        travserse_tree(root->left);
        travserse_tree(root->right);
    }
    else
        return;
}


void print_variable_name(){
    string a("hello");
    cout<<typeid(a).name()<<endl;
}

void printMultimap(multimap<int,int>&order){
    multimap<int,int> ::iterator it=order.begin();
    while(it!=order.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    cout<<endl;
}

#if 1

int main()
{

    vector<int> input={1,5,2,8,9,10,11};
    int sum=500;
    Solution slu;

    int res=slu.change_dp(sum,input);
    cout<<res<<endl;
    return 0;

    #if 0
    map<int,int> statistics;
    unordered_map<int,int> que;
    vector<int> input={2,3,4,5,7,6};
    vector<vector<int>> courses;
   
    courses.push_back({1,0});
    courses.push_back({0,2});
    courses.push_back({2,1});


    
    string input_str("aab");
    for(int i=0;i<input.size();i++){
        que[input[i]]=i*2;
        statistics[input[i]]=i*2;
    }

    for(auto &it:que){
        cout<<it.first<<"->"<<it.second<<endl;
    }
    #endif

    //使用substr

    // string str="worldhellotask";
    // string str1="hello";
    // auto it=str.find(str1);
    // cout<<it<<endl;
    // auto endpos=str.size()-1-(it+str1.size()-1)+1;
    // str=str.substr(0,it)+str.substr(it+str1.size(),endpos);
    // cout<<str<<endl;

    //验证priority_queue插入pair是否按第一个元素排序

    // priority_queue<pair<int,int>> elements;
    // vector<int> input{2,3,5,8,1,9,0,7};
    // for(int i=0;i<input.size();i++){
    //     elements.push({input[i],i});
    // }

    // while (!elements.empty()){
    //     auto it=elements.top();
    //     cout<<it.first<<"->"<<it.second<<endl;
    //     elements.pop();
    // }
    
    
    //使用queue

    // for(auto &it:statistics){
    //     cout<<it.first<<"->"<<it.second<<endl;
    // }

    // unordered_map<int,int>::iterator im=que.find(3);

    // deque<int>::iterator im=find(que.begin(),que.end(),10);

    // int distance=std::distance(que.begin(),im);
    // cout<<distance<<endl;


    // Solution slu;
    // bool res=slu.canFinish(3,courses);
    // int len=slu.lengthOfLongestSubstring(input_str);
    // cout<<res<<endl;
    // cout<<profit<<endl;

    // char c='(';
    // cout<<c<<endl;
  
#if 0

    int a[9]={5,8,9,6,7,1,3,2,4};
    int b[9]={1,2,3,4,5,6,7,8,9};
   
    vector<string> input{"321","32","321"};
    string res=slu.formMaxNumber(input);
    cout<<res<<endl;

     //map 插入元素自带排序
    int a[9]={5,8,9,6,7,1,3,2,4};
    int b[9]={1,2,3,4,5,6,7,8,9};
    map<int,int> elements;
    for(int i=0;i<9;i++)
        elements.insert({a[i],b[i]});
    for(auto &it:elements)
        cout<<it.first<<endl;

    /*
    *
    */
    vector<int> res=slu.solve(a,9);
    cout<<"result:"<<endl;
    for(auto &it:res)
        cout<<it<<endl;
    cout<<typeid(res).name()<<endl;
    cout<<res.at[10]<<endl;  //at 如果越界会抛出 out_of_range 异常。

     /*
    * 创建链表
    * */
    int list_node_val[7]={2,1,3,5,6,4,7};
    struct ListNode *ptemp,*ptail,*pHead;
    for(int i=0;i<7;i++)
    {
        ptemp=(struct ListNode*)malloc(sizeof(struct ListNode));
        ptemp->val=list_node_val[i];
        ptemp->next=nullptr;
        if(i==0)
        {
            pHead=ptemp;
            ptail=pHead;
        }
        else
        {
            ptail->next=ptemp;
            ptail=ptemp;
        }
    }
    pHead=slu.oddEvenList(pHead);
    ptemp=pHead;
    while (ptemp)
    {
        cout<<ptemp->val<<endl;
        ptemp=ptemp->next;
    }

     /*
    ABCEHJIG
    SFCSLOPQ
    ADEEMNOE
    ADIDEJFM
    VCEIFGGS
    
    */
    string martix="ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    string str="SGGFIECVAASABCEHJIGQEM";
    Solution solu;
    bool res=solu.hasPath(martix,5,8,str);
    cout<<"res:"<<res<<endl;
    cout<<"hello world"<<endl;


     /*
    * 创建二叉树
    ***/
    int list_node_val[7]={8,6,9,5,7,7,5};
    TreeNode *root=NULL;
    root=CreateBTree(root);
    travserse_tree(root);

    Solution solu;
    bool res=solu.isSymmetrical(root);
    cout<<"isSymmetrical "<<res<<endl;

    int i=0,j=0;
    while(j<20)
    {
        j++;
        cout<<"j "<<j<<endl;
        while(i<10)
        {
            i++;
            if(i<5)
                continue;
            cout<<"i "<<i<<endl;
        }
    }

    /*
    * 调用方法
    * */
    pHead=solu.deleteDuplication(pHead);

    /*
    * 打印链表
    * */
    ptemp=pHead;
    while (ptemp)
    {
        cout<<ptemp->val<<endl;
        ptemp=ptemp->next;
    }

    printf("hello world\n");
    char str[]="1+23";
    Solution solu;
    int res=solu.isNumeric(str);
    cout<<res<<endl;
    cout<<'0'-48<<endl;
    // string ReverseWords=solu.ReverseSentence(words);
    // cout<<ReverseWords<<endl;



     string words="student a am i";
    vector<int> Cards={0,0,1,4,6};
    bool res=solu.IsContinuous(Cards);

    vector<int> array={1,2,4,7,11,16};
    Solution solu;
    vector<int> Result=solu.FindNumbersWithSum(array,17);
    if(Result.size())
    {
        for(auto im:Result)
                cout<<im<<endl;
    }


    vector<vector<int>> res;
    res=solu.FindContinuousSequence(9);
    for(auto it:res)
        for (auto im:it)
            cout<<im<<endl;
#endif
}
#endif