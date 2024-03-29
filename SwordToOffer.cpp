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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL){}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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

class Node_ {
public:
    int val;
    Node_* next;
    Node_* random;
    
    Node_(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
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

 //自定义数据类型存字符及字符出现的次数
 typedef struct charinfo{
        char c; //当前字符
        int freq; //字符出现频率
        charinfo(char c_,int freq_):c(c_),freq(freq_){}
        bool operator<(const charinfo &a) const {
        return freq<a.freq;//较大的优先级低，放在后面
        }
    }charinfo;

    // bool operator<(charinfo a,charinfo b){
    //     return a.freq<b.freq;//较大的优先级高，放在前面
    // }

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

class A{
    virtual void f();
    char a;
    static int * p;
};
/*
struct  int_
{
    int int1:1;
    int  : 0;
    int int2:2;
    int int3:31;
    int int4:5;
};
*/


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


class LFUCache {
public:

    typedef struct Node{
        int key;
        int value;
        int freq;
        struct Node * pre;
        struct Node * next;
        Node(int _key,int _value):key(_key),value(_value),pre(nullptr),next(nullptr){freq=1;}
       
    }Node;


    //freqency-> 双链表,最近使用的插入头部。
    unordered_map<int,Node*> freqNodeList;
    
    // key-> Node
    unordered_map<int,Node*> elements;

    // 存freqNodeList中各个键值对应双链表尾节点
    unordered_map<int,Node*> freqNodeListTail;

   
    int capacity;

    //最少的使用频率
    int minFreq;
    //是当前最少使用频率的节点个数
    int minFreqNum;

    

    //移除双链表某个节点
    void removeNode(Node* pNode,int freq){
        // 尾节点直接移除
        if(!pNode->next){
            //更新尾节点信息
            freqNodeListTail[freq]=pNode->pre;
            if(pNode->pre)
                pNode->pre->next=nullptr;
            
        }else{
            // 不是头节点
            if(pNode->pre)
                pNode->pre->next=pNode->next;
            else
                freqNodeList[freq]=pNode->next;
            pNode->next->pre=pNode->pre;
        }

        
    }

    //增加新节点到双链表头
    void addNode(Node* pNode){
        if(freqNodeList.find(pNode->freq)!=freqNodeList.end()){
            pNode->next=freqNodeList[pNode->freq];
            freqNodeList[pNode->freq]->pre=pNode;
            freqNodeList[pNode->freq]=pNode;
        }
        else
            freqNodeList[pNode->freq]=pNode;
        
    }


    LFUCache(int _capacity) {
        capacity=_capacity;
      
        minFreq=0;
        minFreqNum=0;
    }
    
    int get(int key) {
        
        if(elements.find(key)!=elements.end()){

            Node *cur=elements[key];
            
            //从相应哈希表删除
            removeNode(cur,cur->freq);
            if(cur->freq==minFreq)
                minFreqNum--;
         
            //更新该节点freq
            (cur->freq)++;

            // 更新最少使用节点和数量
            if(!minFreqNum){
                minFreq=cur->freq;
                minFreqNum++;
            }

            //增加至新的哈希表对应双链表中
            addNode(cur);

            return cur->value;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        
         //不存在
        if(elements.find(key)==elements.end()){
            //未满
            Node * p=new Node(key,value);
            if(elements.size()<capacity){
                elements.insert({key,p});
                if(freqNodeList.find(p->freq)!=freqNodeList.end()){
                    addNode(p);
                }
                else{
                    //第一个节点为尾结点
                    freqNodeListTail[p->freq]=p;
                    freqNodeList[p->freq]=p;
                }

            }
            // 已满
            else{
                Node * re=freqNodeListTail[minFreq];
                elements.erase(re->key);
                removeNode(re,re->freq);

                //移除节点需要删除
                delete re;

                addNode(p);
            }
            
           
            if(minFreq==1)
                minFreqNum++;
            else{
                minFreq=1;
                minFreqNum=1;
            }

        }
        else{
            // 存在则更新
            Node *cur=elements[key];
            cur->value=value;

            // 更新最少使用节点和数量
            if(cur->freq==minFreq)
                minFreqNum--;

            (cur->freq)++;

            if(!minFreqNum){
                minFreq=cur->freq;
                minFreqNum=1;
            }
        }

    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


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

bool cmp_(vector<int>&left,vector<int>&right){
    return left[1]<right[1];
}

// Definition for a Node.
class NNode {
public:
    int val;
    vector<NNode*> children;

    NNode() {}

    NNode(int _val) {
        val = _val;
    }

    NNode(int _val, vector<NNode*> _children) {
        val = _val;
        children = _children;
    }
};

string strLow1="qwertyuiop";
string strLow2="asdfghjkl";
string strLow3="zxcvbnm";

string strUp1="QWERTYUIOP";
string strUp2="ASDFGHJKL";
string strUp3="ZXCVBNM";

set<char> strSetlow1(strLow1.begin(),strLow1.end());
set<char> strSetlow2(strLow2.begin(),strLow2.end());
set<char> strSetlow3(strLow3.begin(),strLow3.end());

set<char> strSetUp1(strUp1.begin(),strUp1.end());        
set<char> strSetUp2(strUp2.begin(),strUp2.end());
set<char> strSetUp3(strUp3.begin(),strUp3.end());





class Solution
{
public:
    /**
     * 179. 最大数
     * **/
     static bool comp(int &left,int &right){
        string l=std::to_string(left)+std::to_string(right);
        string r=std::to_string(right)+std::to_string(left);
        return l>r;
    }

    string largestNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(),nums.end(),comp);
        for(auto it:nums){
            res+=std::to_string(it);
        }
        if(res[0]=='0')
            return string(1,'0');
        return res;
    }

    /**
     * 700. 二叉搜索树中的搜索
     * **/
     TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
            return nullptr;
        if(root->val==val)
            return root;
        TreeNode* ll=searchBST(root->left,val);
        if(ll)
            return ll;
        TreeNode *lr=searchBST(root->right,val);
        if(lr)
            return lr;
        return nullptr;
    }


    /**
     * 583. 两个字符串的删除操作
     * **/
      int minDistance(string word1, string word2) {
        //dp[i][j]:以i-1,j-1结尾的两个字符串要相同需要的最少删除次数
        //dp[i][j]=dp[i-1][j-1];if word1[i-1]==word2[j-1];
        //否则为删除word[i-1],或则删除word2[j-1];或则二者都删除后的最小删除次数
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=0;i<=m;i++)
            dp[i][0]=i;
        for(int i=0;i<=n;i++)
            dp[0][i]=i;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+2);
                }
            }
        return dp[m][n];
    }

    /**
     * 112. 路径总和
     * **/
    void dfsTreeNodeSum(TreeNode*root,int&sum,int target,bool&res){
        //减枝
        if(res)
            return;
        if(!root)
            return;
        sum+=root->val;
        //叶子节点
        if(sum==target&&!root->left&&!root->right){
            res|=true;
            return;
        }
        dfsTreeNodeSum(root->left,sum,target,res);
        dfsTreeNodeSum(root->right,sum,target,res);
        sum-=root->val;
        return;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        bool res=false;
        dfsTreeNodeSum(root,sum,targetSum,res);
        return res;
    }

    /**
     * 718. 最长重复子数组
     * **/
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();

        //dp[i][j]:以A[i-1],B[j-1]结尾的两个数组的最长公共子数组长度
        vector<vector<int>> dp(m+1,vector<int>(n+1));

        int res=0;
        for(int i=1;i<=nums1.size();i++)
            for(int j=1;j<=nums2.size();j++){
                    if(nums1[i-1]==nums2[j-1])
                        dp[i][j]=dp[i-1][j-1]+1;
                    res=max(res,dp[i][j]);  
            }
        return res;
    }

    /**
     * 674. 最长连续递增序列
     * **/
     int findLengthOfLCIS(vector<int>& nums) {
        int res=1;
        bool start=false;
        int temp=1;
        for(int i=1;i<nums.size();i++){
            if(!start&&nums[i]>nums[i-1]){
                start=true;
                temp++;
                res=max(res,temp);
            }
            else if(start&&nums[i]>nums[i-1]){
                temp++;
                res=max(res,temp);
            }
            else{
                start=false;
                temp=1;
            }
        }
        return res;
    }

    /**
     * 143. 重排链表
     * **/
     void reorderList(ListNode* head) {
        //单节点
        if(head&&!head->next)
            return;
        //双节点
        if(head&&head->next&&!head->next->next)
            return;
        ListNode*slow=head;
        ListNode*fast=head;    

        //先找到中间节点
        while(fast->next&&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        //逆序中间节点以后的节点
        ListNode*mid=slow;
        ListNode*aux1;
        slow=slow->next;
        mid->next=nullptr;
        while(slow){
            aux1=slow->next;
            slow->next=mid->next;
            mid->next=slow;
            slow=aux1;
        }

      
        //重排节点
        ListNode*aux2;
        slow=head;
        fast=mid->next;
        while(slow!=mid){
            aux1=slow->next;
            slow->next=fast;
            aux2=fast->next;
            fast->next=aux1;
            slow=aux1;
            fast=aux2;
        }

        //偶数个节点,aux2指向最后一个节点
        if(aux2)
            mid->next=aux2;
        //奇数个节点，aux2指向空
        else
            mid->next=nullptr;

    }

    /**
     * 859. 亲密字符串
     * **/
    bool buddyStrings(string s, string goal) {

        if(s.size()!=goal.size())
            return false;
      
        map<char,int> eles1;
        map<char,int> eles2;
        int diff=0;

        //统计字符个数
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i])
                diff++;
            eles1[s[i]]++;
            eles2[goal[i]]++;
        }
        //字符种类数不等
        if(eles1.size()!=eles2.size())
            return false;
        
       
        //可交换位置不为2也不为0
        if(diff!=0&&diff!=2)
            return false;

        auto it=eles1.begin();
        auto im=eles2.begin();
        while(it!=eles1.end()&&im!=eles2.end()){
            if(it->first==im->first&&it->second==im->second){
                //两个字符串完全相同且某一类字符个数大于等于2，则可以交换
                if(diff==0&&it->second>=2){
                    return true;
                }
                it=std::next(it);
                im=std::next(im);
            }
            else
                return false;
        }
        if(diff==0)
            return false;
        else 
            return true;
    }

    /**
     * 559. N 叉树的最大深度
     * **/
    void dfsTree(NNode*root,int num,int&res){
        //到达叶子节点
        if(root->children.size()==0){
            res=max(res,num);
            return;
        }
        else{
            for(int i=0;i<root->children.size();i++){
                dfsTree(root->children[i],num+1,res);
            }
        }
    }


    int maxDepth(NNode* root) {
        int res=-1;
        int num=1;
        if(!root)
            return 0;
        dfsTree(root,num,res);
        return res;
    }

    int maxDepth_(NNode* root) {
        if(!root)   
            return 0;
        else{
            int ans=0;
            for(auto&it:root->children)
                ans=max(ans,maxDepth(it));
            //返回当前节点深度
            return ans+1;
        }
        
    }

    /**
     * 6. Z 字形变换
     * **/
      string convert(string s, int numRows) {
        //行数为1直接返回原来的字符串
        if(numRows==1)
            return s;
        
        vector<string> eles(numRows);
        string res;
        int i=0;

        while(i<s.size()){
            int j=0;
            //累加numRows个字符串
            while(i<s.size()&&j<numRows){
                eles[j]+=s[i];
                j++;
                i++;
                
            }

            //回到倒数第二个字符串
            j=numRows-2;

            //累加到正数第二个字符串
            while(i<s.size()&&j>=1){
                eles[j]+=s[i];
                i++;
                j--;
            }
           
        }

        for(auto &it:eles){
            res+=it;
        }
        return res;
    }

    /**
     * 594. 最长和谐子序列
     * **/
    int findLHS(vector<int>& nums) {
        map<int,int> eles;
        for(int i=0;i<nums.size();i++){
            eles[nums[i]]++;
        }
        
        int res=0;

        for(auto it=eles.begin();it!=eles.end();it++){
             auto  im=std::next(it);
            if(im!=eles.end()){
                if(abs(it->first-im->first)==1){
                    res=max(res,it->second+im->second);
                }
            }
        }
        return res;
    }

    /**
     * 455. 分发饼干
     * **/
     int findContentChildren(vector<int>& g, vector<int>& s) {
        priority_queue<int,std::vector<int>,std::greater<int>> g_;
        priority_queue<int,std::vector<int>,std::greater<int>> s_;
        for(int i=0;i<g.size();i++)
            g_.push(g[i]);
        for(int i=0;i<s.size();i++)
            s_.push(s[i]);
        int res=0;
        while(!g_.empty()){
            int cur=g_.top();
            g_.pop();
            
            while(s_.size()&&s_.top()<cur){
                s_.pop();
            }
            if(s_.size()&&s_.top()>=cur){
                res++;
                s_.pop();
            }
            if(s_.empty())
                break;
        }
        return res;
    }

    /**
     * 111. 二叉树的最小深度
     * **/
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        else{
            int left=minDepth(root->left);
            int right=minDepth(root->right);
            if(left&&right)
                return 1+min(left,right);
            else
                return left?left+1:right+1;
        } 
            
    }

    /**
     * 110. 平衡二叉树
     * **/
     int depthTree(TreeNode*root){
        if(!root)
            return 0;
        else return 1+max(depthTree(root->left),depthTree(root->right));

    }

    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        int leftH=depthTree(root->left);
        int rightH=depthTree(root->right);
        if(abs(rightH-leftH)<=1)
           return isBalanced(root->left)&&isBalanced(root->right);
        return false;
    }

    /**
     * 318. 最大单词长度乘积
     * **/
     int maxProduct_(vector<string>& words) {

        int n=words.size();

        //用位运算判断单词中出现的字符是否相同
        vector<bitset<26>> eles_statics(n);

        bitset<26>  temp;

        for(int i=0;i<words.size();i++){
            for(auto c:words[i])
                eles_statics[i][c-'a']=1;
        }
        
        int res=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                //两个单词没有重复字符
                if((temp=eles_statics[i]&eles_statics[j])==0){
                    int cur=words[i].size()*words[j].size();
                    res=std::max(cur,res);
                }
            }
        }

        return res;
    }

    /**
     * 350. 两个数组的交集 II
     * **/
     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        map<int,int> ele_statics1;
        map<int,int> ele_statics2;
        
        for(int i=0;i<nums1.size();i++) {
            ele_statics1[nums1[i]]++;
        }

        for(int i=0;i<nums2.size();i++){
            //先判断是否存在再减少个数
            if(ele_statics1[nums2[i]]&&ele_statics1[nums2[i]]--){
                res.push_back(nums2[i]);
            }
        }

        return res;

    }

    /**
     * 144. 二叉树的前序遍历 非递归
     * **/
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> eles;
        TreeNode *q;
        if(!root)
            return res;
        eles.push(root);
        while(!eles.empty()){
            q=eles.top();
            eles.pop();
            res.push_back(q->val);
            if(q->right) eles.push(q->right);
            if(q->left) eles.push(q->left);
        }
        return res;
    }

    /**
     * 71. 简化路径
     * **/
     string simplifyPath(string path) {
        stack<string> eles;
        string str;

        for(int i=0;i<path.size();i++){
            if(path[i]=='/'){
                if(str.size()){
                    if(str==".."){
                            if(eles.size())
                                eles.pop();
                    }
                    else{
                        if(str!=".")
                            eles.push(str);
                    }
                }
                str.clear();
            }
            else{
                str+=path[i];
                //不以'/'结尾
                if(i==path.size()-1){
                    if(str==".."){
                            if(eles.size())
                                eles.pop();
                    }
                    else{
                        if(str!=".")
                            eles.push(str);
                    }
                }
            }
        }

        //颠倒顺序
        stack<string> auxEle;
        while(!eles.empty()){
            auxEle.push(eles.top());
            eles.pop();
        }


        //加入"/"
        string res="/";
        while(!auxEle.empty()){
            res+=auxEle.top();
            res+="/";
            auxEle.pop();
        }
        if(res.size()>1)
            return res.substr(0,res.size()-1);
        else
            return res;
    }
    /**
     * 520. 检测大写字母
     * **/
    bool detectCapitalUse(string word) {
        int lowerNum=0;
        int upperNum=0;
        for(int i=0;i<word.size();i++){
            if('a'<=word[i]&&word[i]<='z')
                lowerNum++;
            else
                upperNum++;
        }
        if(lowerNum==word.size())
            return true;
        if(upperNum==word.size())
            return true;
        if(upperNum==1&&'A'<=word[0]&&word[0]<='Z')
            return true;
        return false;
    }

    /**
     * 349. 两个数组的交集
     * **/
     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        set<int> eles(nums1.begin(),nums1.end());
        set<int> eles_;
        for(int i=0;i<nums2.size();i++){
            if(eles.count(nums2[i]))
                eles_.insert(nums2[i]);
        }
        for(auto&it:eles_)
            res.push_back(it);
        return res;
    }
    /***
     * 59. 螺旋矩阵 II
     * 
    */
     void dfsMatrixGenerate(vector<vector<int>>&res,int i, int j,int &cur,int dir,vector<int>&pre){
        
        //不能越界且可以填入
        if(0<=i&&i<res.size()&&0<=j&&j<res.size()&&res[i][j]==0){
            switch(dir){
                case 1:
                    cur++;
                    res[i][j]=cur;
                    dfsMatrixGenerate(res,i,j+1,cur,1,pre);
                    break;
                case 2:
                    cur++;
                    res[i][j]=cur;
                    dfsMatrixGenerate(res,i+1,j,cur,2,pre);
                    break;
                case 3:
                    cur++;
                    res[i][j]=cur;
                    dfsMatrixGenerate(res,i,j-1,cur,3,pre);
                    break;
                case 4:
                    cur++;
                    res[i][j]=cur;
                    dfsMatrixGenerate(res,i-1,j,cur,4,pre);
                    break;
                default:
                    break;
            }
        }
        //越界或者已经填充过
        else{
            switch(dir){
                case 1:
                    pre[0]=i+1;
                    pre[1]=j-1;
                    break;
                case 2:
                    pre[0]=i-1;
                    pre[1]=j-1;
                  
                    break;
                case 3:
                    pre[0]=i-1;
                    pre[1]=j+1;
                    break;
                case 4:
                    pre[0]=i+1;
                    pre[1]=j+1;
                    break;
                default:
                    break;
            }
        }
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int cur=0;
        //越界后下一次遍历的起始位置
        vector<int> pre(2,0);
        while(cur!=n*n){
            
            dfsMatrixGenerate(res,pre[0],pre[1],cur,1,pre);
          
            dfsMatrixGenerate(res,pre[0],pre[1],cur,2,pre);
           
            dfsMatrixGenerate(res,pre[0],pre[1],cur,3,pre);
            
            dfsMatrixGenerate(res,pre[0],pre[1],cur,4,pre);
           
        }
        return res;
    }

    /**
     * 80. 删除有序数组中的重复项 II
     * **/
     int removeDuplicates__(vector<int>& nums) {
        if(nums.size()<=2)
            return nums.size();


        int slow=2,fast=2;
       
        while(fast<nums.size()){
            //当前元素应该被保留
           if(nums[slow-2]!=nums[fast]){
               nums[slow]=nums[fast];
               slow++;
           }
           fast++;

        }
        return slow;
    }

    /**
     * 242. 有效的字母异位词
     * **/
      bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        map<char,int> ele1;
        map<char,int> ele2;

        for(int i=0;i<s.size();i++){
            ele1[s[i]]++;
            ele2[t[i]]++;
        }

        for(auto &it:ele1)
            if(ele1[it.first]!=ele2[it.first])
                return false;

        return true;
    }

    /**
     * 299. 猜数字游戏
     * **/
     string getHint(string secret, string guess) {
        map<char,int> match;
        map<char,int> statistics1;
        map<char,int> statistics2;

        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i])
                match[secret[i]]++;
            statistics1[secret[i]]++;
            statistics2[guess[i]]++;
        }

        int res1=0;
        for(auto &it:match)
            res1+=it.second;
       
        int res2=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]!=guess[i]){
                if(statistics2[secret[i]]&&statistics2[secret[i]]-match[secret[i]]){
                    res2++;
                    statistics2[secret[i]]--;
                }
            }
        }
        
        string res=std::to_string(res1)+"A"+std::to_string(res2)+"B";
        return res;
    }

    //leetcode 官方
    string getHint_(string secret, string guess) {
        int bulls = 0;
        vector<int> cntS(10), cntG(10);
        for (int i = 0; i < secret.length(); ++i) {
            if (secret[i] == guess[i]) {
                ++bulls;
            } else {
                ++cntS[secret[i] - '0'];
                ++cntG[guess[i] - '0'];
            }
        }
        int cows = 0;
        for (int i = 0; i < 10; ++i) {
            cows += min(cntS[i], cntG[i]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }



    /**
     * 598. 范围求和 II
     * **/
     int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minR=m,minC=n;
        if(ops.size()==0)
            return m*n;
        for(int i=0;i<ops.size();i++){
            minR=min(minR,ops[i][0]);
            minC=min(minC,ops[i][1]);
        }
        return minR*minC;
    }

    /**
     * 67. 二进制求和
     * **/
    string addBinary(string a, string b) {
        int i=a.size()-1;
        int j=b.size()-1;
        string res;
        bool carry=false;
        while(i>=0&&j>=0){
            if(a[i]=='1'&&b[j]=='1'){
                if(carry){
                    res+="1";
                    carry=true;
                }
                else{
                    res+="0";
                    carry=true;
                } 
                
            }
            else if(a[i]=='0'&&b[j]=='1'){
                 if(carry){
                    res+="0";
                    carry=true;
                 }
                else{
                    res+="1";
                    carry=false;
                } 
            }
            else if(a[i]=='1'&&b[j]=='0'){
                 if(carry){
                    res+="0";
                    carry=true;
                 }
                else{
                    res+="1";
                    carry=false;

                } 
            }
            else if(a[i]=='0'&&b[j]=='0'){
                 if(carry)
                    res+="1";
                else 
                    res+="0";
                carry=false;
            }
            i--;
            j--;
        }
       
        int k=i>j?i:j;
        if(i>=0){
             while(k>=0){
                if(a[k]=='1'){
                    if(carry){
                        res+="0";
                        carry=true;
                    }
                    else{
                        res+="1";
                        carry=false;
                    }

                }else{
                    if(carry){
                        res+="1";
                        carry=false;
                    }
                    else{
                        res+="0";
                        carry=false;
                    }
                }
                k--;
            }
        }
        else{
             while(k>=0){
                if(b[k]=='1'){
                    if(carry){
                        res+="0";
                        carry=true;
                    }
                    else{
                        res+="1";
                        carry=false;
                    }

                }else{
                    if(carry){
                        res+="1";
                        carry=false;
                    }
                    else{
                        res+="0";
                        carry=false;
                    }
                }
                k--;
            }
        }
        if(carry)
            res+="1";
        reverse(res.begin(),res.end());
        return res;
    }

    /**
     * 1218. 最长定差子序列
     * **/
     int longestSubsequence(vector<int>& arr, int difference) {
        int ans=INT_MIN;
        map<int,int> dp;
        int n=arr.size();
        //dp[i]:以i结尾的数组最长等差子序列长度
        for(auto v:arr){
            dp[v]=dp[v-difference]+1;
            ans=max(dp[v],ans);
        }
        return ans;
    }

    /**
     * 332. 重新安排行程
     * **/
    // 超时算法
      void backTracking(vector<vector<string>>&tickets,string &cur,string &res,vector<bool>&visited,int startIndex){
        
        if(cur.size()==(tickets.size()+1)*3){
           
            if(res.size()==0)
                res=cur;
            else if(cur<res)
                res=cur;
            return;
        }
        
        int curNum=0;
        int i=startIndex;
        while(curNum!=tickets.size()){
             if(cur.size()==0){
                if(tickets[i][0]=="JFK"){
                    cur+=tickets[i][0];
                    cur+=tickets[i][1];
                    visited[i]=true;
                 
                  
                }
            }
            else{
               
                //上一次的地点名
                string lastStr=cur.substr(cur.size()-3,3);
                if(visited[i]==false){
                    if(tickets[i][0]==lastStr)
                        cur+=tickets[i][1];
                    visited[i]=true;
                    backTracking(tickets,cur,res,visited,(i+1)%tickets.size());
                    if(tickets[i][0]==lastStr)
                        cur=cur.substr(0,cur.size()-3);
                    visited[i]=false;
                }
            }
           
            i=(i+1)%tickets.size();
            curNum++;
        }
        
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        vector<bool> visited(tickets.size(),false);
        string cur;
        string toatlRes;
        int startIndex;
        vector<int> startIndexs;
        for(int i=0;i<tickets.size();i++)
            if(tickets[i][0]=="JFK"){
                startIndexs.push_back(i);
            }
        
        for(int i=0;i<startIndexs.size();i++){
          
            backTracking(tickets,cur,toatlRes,visited,startIndexs[i]);
            cur.clear();
            std::fill(visited.begin(),visited.end(),false);
        }
        // cout<<"toatoRes: "<<toatlRes<<endl;
        string temp;
        for(int i=0;i<toatlRes.size();i++){
            temp+=toatlRes[i];
            if((i+1)%3==0){
                res.push_back(temp);
                temp.clear();
            }
        }
        return res;
    }


    /**
    * 237. 删除链表中的节点
    *  
    **/
     void deleteNode(ListNode* node) {
        ListNode *pre=node;
        while(node->next){
            node->val=node->next->val;
            pre=node;
            node=node->next;
        }
        pre->next=NULL;
    }

    /**
     * 500. 键盘行
     * **/
    void checkNum(string word,vector<int>&statistics){
       
        for(auto it:word){
            if(strSetlow1.count(it)||strSetUp1.count(it))
                statistics[0]++;
            else if(strSetlow2.count(it)||strSetUp2.count(it))
                statistics[1]++;
            else if(strSetlow3.count(it)||strSetUp3.count(it))
                statistics[2]++;
        }
    }

    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        vector<int> statistics(3,0);
        for(int i=0;i<words.size();i++){
            checkNum(words[i],statistics);
            if(statistics[0]==words[i].size()||statistics[1]==words[i].size()||statistics[2]==words[i].size())
                res.push_back(words[i]);
            std::fill(statistics.begin(),statistics.end(),0);
          
        }
        return res;
    }
    /**
     * 54. 螺旋矩阵
     * **/
     void dfsMatrixRight(vector<vector<int>>&matrix,int i,int j,vector<int>&res,vector<vector<bool>>&visited,int direction,vector<int>&pos){
        int m=matrix.size();
        int n=matrix[0].size();
        if(0<=i&&i<m&&0<=j&&j<n&&visited[i][j]==false){
            visited[i][j]=true;
            res.push_back(matrix[i][j]);
          
            switch (direction){
                case 1:
                    dfsMatrixRight(matrix,i,j+1,res,visited,direction,pos);
                    break;
                case 2:
                    dfsMatrixRight(matrix,i+1,j,res,visited,direction,pos);
                    break;
                case 3:
                    dfsMatrixRight(matrix,i,j-1,res,visited,direction,pos); 
                    break;
                case 4:
                    dfsMatrixRight(matrix,i-1,j,res,visited,direction,pos);
                    break;
                default:
                    break;
            }            
        }
        else {
            switch(direction){
                case 1:
                   
                    pos[0]=i+1;
                    pos[1]=j-1;
                    break;
                case 2:
                    pos[0]=i-1;
                    pos[1]=j-1;
                    break;
                case 3:
                    pos[0]=i-1;
                    pos[1]=j+1;
                    break;
                case 4:
                  
                    pos[0]=i+1;
                    pos[1]=j+1;
                    break;
                default:
                    break;
            }
        }

    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        vector<int> pos(2,0);
        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        while(res.size()!=m*n){
            dfsMatrixRight(matrix,pos[0],pos[1],res,visited,1,pos);
          
            dfsMatrixRight(matrix,pos[0],pos[1],res,visited,2,pos);
           
            dfsMatrixRight(matrix,pos[0],pos[1],res,visited,3,pos);
          
            dfsMatrixRight(matrix,pos[0],pos[1],res,visited,4,pos);
           
        }
        return res;
    }
    /**
     * 228. 汇总区间
     * **/
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size()==0)
            return res;
        if(nums.size()==1){
            res.push_back(std::to_string(nums[0]));
            return res;
        }

        string  temp;
        int start,j;
        for(int i=0;i<nums.size();i++){
            start=i;
            j=start+1;
            while(i<nums.size()&&j<nums.size()&&nums[j]-1==nums[i]){
                i++;
                j++;
            }
            if(start!=i){
                temp+=std::to_string(nums[start]);
                temp+="->";
                temp+=std::to_string(nums[i]);
                res.push_back(temp);
                temp.clear();
            }
            else
                res.push_back(std::to_string(nums[start]));
           
            i=j;
            //消除for循环里面i++造成的影响
            i--;
        }
        return res;
    }

    /**
     * 260. 只出现一次的数字 III
     * **/
     vector<int> singleNumberIII(vector<int>& nums) {
        map<int,int> eles;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            eles[nums[i]]++;
        }
        
        for(auto it:eles)
            if(it.second==1)
                res.push_back(it.first);

        return res;
    }

    /**
     * 219. 存在重复元素 II
     * **/
     bool containsNearbyDuplicate(vector<int>& nums, int k) {
        bool res=false;
        map<int,int> elements;
        for(int i=0;i<nums.size();i++){
            auto it=elements.find(nums[i]);
            if(it!=elements.end()){
                if(i-it->second<=k){
                    res|=true;
                }
            }
            elements[nums[i]]=i;
        }
        return res;
    }

    /**
     * 869. 重新排序得到 2 的幂
     * **/
     //判断是否是2的幂次方
    bool isExponential(vector<int>cur){
       long num=0;
       for(int i=0;i<cur.size();i++){
            num+=pow(10,cur.size()-1-i)*cur[i];
       }
       return (num&(num-1))==0;
    }

    //划分数字
    void dividNum(int n,vector<int>&div){
        while(n){
            div.push_back(n%10);
            n=n/10;
        }
    }

    //求对应数字组合而成的数字
    void backTrackNum(vector<int>&div,long &num,vector<int>&cur,bool &res,vector<bool> &used){

        if(res)
            return;

        if(cur.size()&&cur[0]==0)
            return;

        if(cur.size()==div.size()){
            if(isExponential(cur))
                res|=true;
            return;
        }


        for(int i=0;i<div.size();i++){
            if(used[i]==false){
                used[i]=true;
                cur.push_back(div[i]);
                backTrackNum(div,num,cur,res,used);
                cur.pop_back();
                used[i]=false;
            }
        }
    }

    bool reorderedPowerOf2(int n) {
        long num=0;
        bool res=false;
        vector<int> div;
        vector<int> cur;
        dividNum(n,div);
        vector<bool> used(div.size(),false);
        backTrackNum(div,num,cur,res,used);
        return res;
    }

     bool reorderedPowerOf2_(int n) {
        string num=std::to_string(n);
        sort(num.begin(),num.end());
        set<string> nums;
        for(long i=0;i<=32;i++){
            long temp=pow(2,i);
            if((temp&(temp-1))==0){
                string numTemp=std::to_string(temp);
                sort(numTemp.begin(),numTemp.end());
                nums.insert(numTemp);
            }
        }
        return nums.count(num)!=0;
    }

    /**
     * 167. 两数之和 II - 输入有序数组
     * **/
     vector<int> twoSumII(vector<int>& numbers, int target) {
        vector<int> res;
        //存 target-nums[i] 和 元素对应的下标
        map<int,int> statistics;
        
        for(int i=0;i<numbers.size();i++){
            auto it=statistics.find(numbers[i]);
            if(it!=statistics.end()){
                res.push_back(it->second+1);
                res.push_back(i+1);
                break;
            }
            else{
                statistics.insert({target-numbers[i],i});
            }
        }

        return res;
    }

    /**
     * 496. 下一个更大元素 I
     * **/
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        map<int,int> ele2pos;
        int k;
        for(int j=0;j<nums2.size();j++)
            ele2pos[nums2[j]]=j;
        
        for(int i=0;i<nums1.size();i++){

            for(k=ele2pos[nums1[i]]+1;k<nums2.size();k++){
                if(nums2[k]>nums1[i]){
                    res.push_back(nums2[k]);
                    break;
                }
            }
           
            if(k==nums2.size())
                res.push_back(-1);
        }
        return res;
    }

    /**
     * 99. 恢复二叉搜索树
     * **/
      void inOrderBst(TreeNode*root,vector<int>&elements,map<int,TreeNode*>&ele2node){
        if(root){
            inOrderBst(root->left,elements,ele2node);
            elements.push_back(root->val);
            ele2node[root->val]=root;
            inOrderBst(root->right,elements,ele2node);
        }
    }

    void recoverTree(TreeNode* root) {
        vector<int> elements;
        map<int,TreeNode*> ele2node;
        inOrderBst(root,elements,ele2node);
      
        int first=-1,second=-1;
        for(int i=0;i<elements.size()-1;i++){
            //存在逆序
            if(elements[i]>elements[i+1]){
                if(first==-1)
                    first=i;  
                else if(second==-1)
                    second=i+1;
                if(first!=-1&&second!=-1)
                    break;
            }
        }

        //相邻元素被交换
        if(second==-1)
            second=first+1;
        
   
        ele2node[elements[first]]->val=elements[second];
        ele2node[elements[second]]->val=elements[first];
        

    }

    /**
     * 66. 加一
     * **/
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int over,temp;
        for(int i=digits.size()-1;i>=0;i--){
            if(i==digits.size()-1){
                temp=digits[i]+1;
            }
            else
                temp=digits[i]+over;
            res.push_back(temp%10);
            over=temp/10;
        }
        if(over>0)
            res.push_back(over);
        reverse(res.begin(),res.end());
        return res;
    }

    /**
     * 229. 求众数 II
     * **/
      vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int num=n/3;
        vector<int> res;
        int vote1=0,vote2=0;
        int num1=0,num2=0;
       
        
        num1=nums[0];
        num2=nums[0];

        for(int i=0;i<n;i++){
           if(vote1&&nums[i]==num1){
                vote1++;
           }
           else if(vote2&&nums[i]==num2){
               vote2++;
           }
           else if(!vote1){
               num1=nums[i];
               vote1=1;
           }else if(!vote2){
               num2=nums[i];
               vote2=1;
           }else{
               vote1--;
               vote2--;
           }

        }
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(vote1&&nums[i]==num1)
                cnt1++;
            if(vote2&&nums[i]==num2)
                cnt2++;
        }

        if(vote1&&cnt1>num)
            res.push_back(num1);
        if(vote2&&cnt2>num)
            res.push_back(num2);
        return res;
    }

    /**
     * 剑指 Offer 51. 数组中的逆序对
     * **/
    //超时算法
     int reversePairs(vector<int>& nums) {
        int i,ans=0;
        int n=nums.size();
        multiset<int> elements;
        for(i=n-1;i>=0;i--){
            elements.insert(nums[i]);

            //找第一个大于等于当前元素所在下标
            auto it=elements.lower_bound(nums[i]);
            if(it!=elements.end()){
                int temp1=std::distance(elements.begin(),it);
               
                ans+=temp1;
            }
            //每找到，则处该元素外所有元素比当前元素小
            else{
                int temp2=elements.size()-1;
               
                ans+=temp2;
            }
        }
        return ans;
    }

    void merge(vector<int>&nums,int start,int end,int mid,int &ans){
        int i=start,j=mid+1;
        vector<int> temp;
        while(i<=mid&&j<=end){
            // 前面的大于后面的,构成一个逆序对
            if(nums[i]>nums[j]){
                temp.push_back(nums[j]);
                //前面一部分构成逆序对的有多少个元素
                ans+=mid-i+1;
                j++;
            }
            //本身已经有序
            else{
                temp.push_back(nums[i]);
                i++;
            }
        }

        while(i<=mid)
            temp.push_back(nums[i++]);

        while(j<=end)
            temp.push_back(nums[j++]);
 
        for(i=start,j=0;i<=end;i++,j++)
            nums[i]=temp[j];
    }

    void mergeSort(vector<int>& nums,int start,int end,int&ans){
        if(start<end){
            int mid=(start+end)>>1;
            mergeSort(nums,start,mid,ans);
            mergeSort(nums,mid+1,end,ans);
            merge(nums,start,end,mid,ans);
        }
    }

    int reversePairs_(vector<int>& nums) {
        int i,ans=0;
        int n=nums.size();
        mergeSort(nums,0,n-1,ans);
        
        return ans;
    }

    /**
     * 1438. 绝对差不超过限制的最长连续子数组
     * **/
    //超时解法
    int longestSubarray(vector<int>& nums, int limit) {

        int ans=0;
        int n=nums.size();

        //dp[i][j]: [i,j]范围内的最大/最小值
        //递归公式：dpMax[i][j]=max(dpMax[i][j-1],nums[j]);
        //         dpMin[i][j]=min(dpMax[i][j-1],nums[j]);
        vector<vector<int>>dpMax(n,vector<int>(n));
        vector<vector<int>>dpMin(n,vector<int>(n));

        int i,j;
        for(i=0;i<n;i++){
            for(j=i;j<n;j++){
                if(j==i){
                    dpMax[i][j]=nums[j];
                    dpMin[i][j]=nums[j];
                }
                else if(j>0){
                    dpMax[i][j]=max(dpMax[i][j-1],nums[j]);
                    dpMin[i][j]=min(dpMin[i][j-1],nums[j]);
                }
                if(dpMax[i][j]-dpMin[i][j]<=limit)
                    ans=max(j-i+1,ans);
            }
        }

        return ans;
    }

    /**
     * 476. 数字的补数
     * **/
    int findComplement(int num) {

        int flag=1;
        //求该数字的二进制最大位数
        int digitNum=0;
        for(int i=0;i<31;i++){
            if(flag&num){
                digitNum=i+1;
            }
            flag<<=1;
        }
        flag=1;
     
        int auxilNum=pow(2,digitNum)-1;
        for(int i=0;i<digitNum;i++){
            int tempNum=auxilNum-pow(2,i);
            //1变0
            if(num&flag){
                num=num&tempNum;
            }
            //0变1
            else{
                num=num|flag;
            }
            flag<<=1;
        }
        return num;
    }

    /**
     * 230. 二叉搜索树中第K小的元素
     * **/
    void inOrder(TreeNode*root,vector<int>&elements,int k){
        if(!root)
            return;
        inOrder(root->left,elements,k);
        elements.push_back(root->val);
        if(elements.size()>k)
            return;
        inOrder(root->right,elements,k);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> elements;
        inOrder(root,elements,k);
        return elements[k-1];
    }
    //基于非递归
    int kthSmallest_(TreeNode* root, int k) {
       int ans;
       stack<TreeNode*> elements;
       vector<int> orders;
       TreeNode *p=root;
       while(!elements.empty()||p){
            while(p){
                elements.push(p);
                p=p->left;
            }   
            p=elements.top();
            elements.pop();
            orders.push_back(p->val);
            if(orders.size()==k){
                ans=orders.back(); 
                break;
            }
            p=p->right;
       }
       return ans;
    }

    /**
     * 282. 给表达式添加运算符
     * **/
    int getNum(string &nums){
        int ans=0;
        int temp=1;
        for(int i=nums.size()-1;i>=0;i--){
            ans+=(nums[i]-'0')*temp;
            temp*=10;
        }
        return ans;
    }


    int getCalucate(string expression,bool &isValid){
        /*
        * 计算表达式字符串如:2*3+2的值
        */
       cout<<expression<<endl;
        stack<char> operators;
        stack<int> nums;
        string temp;
        int top1,top2;
        for(int i=0;i<expression.size();i++){
            //数字
            if('0'<=expression[i]&&expression[i]<='9'){
               temp+=expression[i]; 
            }
            //运算符
            else {
                if(temp.size()){

                    //不合法的数字字符串
                    if(temp[0]=='0'&&temp.size()>1)
                        isValid=false;
                    nums.push(getNum(temp));
                    temp.clear();
                    if(operators.size()&&operators.top()=='*'){
                        top1=nums.top();
                        nums.pop();
                        top2=nums.top();
                        nums.pop();
                        nums.push(top1*top2);
                        operators.pop();
                    }
                }
                operators.push(expression[i]);
            }
        }

        if(temp.size()){
             //不合法的数字字符串
            if(temp[0]=='0'&&temp.size()>1)
                isValid=false;
            nums.push(getNum(temp));
            temp.clear();
            if(operators.size()&&operators.top()=='*'){
                top1=nums.top();
                nums.pop();
                top2=nums.top();
                nums.pop();
                nums.push(top1*top2);
                operators.pop();
            }
        }

        while(operators.size()){
            top1=nums.top();
            nums.pop();
            top2=nums.top();
            nums.pop();
            // cout<<"operator pop..."<<endl;
            if(operators.top()=='+'){
                nums.push(top1+top2);
            }
            else{
                nums.push(top2-top1);
            }
            operators.pop();
        }
        return nums.top();
    }

    vector<string> addOperators_(string num, int target) {
        int n = num.length();
        vector<string> ans;

        function<void(string&, int, long, long)> backtrack = [&](string &expr, int i, long res, long mul) {
            if (i == n) {
                if (res == target) {
                    ans.emplace_back(expr);
                }
                return;
            }
            int signIndex = expr.size();
           
            if (i > 0) {
                expr.push_back(0); // 占位，下面填充符号
            }
            long val = 0;
            // 枚举截取的数字长度（取多少位），注意数字可以是单个 0 但不能有前导零
            for (int j = i; j < n && (j == i || num[i] != '0'); ++j) {
                val = val * 10 + num[j] - '0';
                expr.push_back(num[j]);
                if (i == 0) { // 表达式开头不能添加符号
                    backtrack(expr, j + 1, val, val);
                } else { // 枚举符号
                   
                    expr[signIndex] = '+'; backtrack(expr, j + 1, res + val, val);
                    expr[signIndex] = '-'; backtrack(expr, j + 1, res - val, -val);
                    expr[signIndex] = '*'; backtrack(expr, j + 1, res - mul + mul * val, mul * val);
                }
            }
            expr.resize(signIndex);
        };

        string expr;
        backtrack(expr, 0, 0, 0);
        return ans;
    }

    void getExpressionBacktrack(string&num,string &expr, int i, long res, long mul,int target,vector<string>&ans) {
            if (i == num.size()) {
                if (res == target) {
                    ans.emplace_back(expr);
                }
                return;
            }
            int signIndex = expr.size();
          
            if (i > 0) {
                expr.push_back(0); // 占位，下面填充符号
            }
            long val = 0;
            // 枚举截取的数字长度（取多少位），注意数字可以是单个 0 但不能有前导零
            for (int j = i; j < num.size() && (j == i || num[i] != '0'); ++j) {
                val = val * 10 + num[j] - '0';
                expr.push_back(num[j]);
                if (i == 0) { // 表达式开头不能添加符号
                    getExpressionBacktrack(num,expr, j + 1, val, val,target,ans);
                } else { // 枚举符号
                    
                    expr[signIndex] = '+'; getExpressionBacktrack(num,expr, j + 1, res + val, val,target,ans);
                    expr[signIndex] = '-'; getExpressionBacktrack(num,expr, j + 1, res - val, -val,target,ans);
                    expr[signIndex] = '*'; getExpressionBacktrack(num,expr, j + 1, res - mul + mul * val, mul * val,target,ans);
                }
            }
            expr.resize(signIndex);
        };


    void getExpressions(string &num,int startIndex, vector<string>&expressions,string&cur,int target,long curNumber,long multi){
        /*
        * 回溯求算术表达式字符串
        */
       
        if(startIndex==num.size()){
            
            if(curNumber==target)
            {
                expressions.push_back(cur);
                
            }
            return;
        }
        int curlen=cur.size();
        
        if(startIndex>0)
            cur.push_back(0);
        long val=0;
        for(int i=startIndex;i<num.size()&&(i==startIndex||num[startIndex]!='0');i++){
            val=val*10+num[i]-'0';
            cur.push_back(num[i]);
            //第一个数字字符后不需要添加运算符
            if(startIndex==0)
                getExpressions(num,i+1,expressions,cur,target,val,val);
            else{
               

                cur[curlen]='+';
                getExpressions(num,i+1,expressions,cur,target,curNumber+val,val);
               
            
                cur[curlen]='-';
                getExpressions(num,i+1,expressions,cur,target,curNumber-val,-val);
                

                cur[curlen]='*';
                getExpressions(num,i+1,expressions,cur,target,curNumber-multi+val*multi,val*multi);
                
            }
           
        }
        cur.resize(curlen);
    }

    vector<string> addOperators(string num, int target) {
        vector<string> expressions;
        string cur;
        getExpressions(num,0,expressions,cur,target,0,0);
        // getExpressionBacktrack(num,cur,0,0,0,target,expressions);
        return expressions;
    }

    /**
     * 29. 两数相除 
     * **/
     long count_(long dividend,long divisor){
        if(dividend==divisor)
            return 1;
        else if(dividend<divisor)
            return 0;
        
        long res=1;
        long temp=divisor;
        while(temp*2<dividend){
            res*=2;
            temp*=2;
        }
       
        return res+count_(dividend-temp,divisor);
    }

    int divide__(int dividend, int divisor) {

        int flag=1;

        if(!dividend)
            return 0;
        
        if((dividend>0&&divisor<0)||(dividend<0&&divisor>0))
            flag=-1;

        dividend=long(dividend);
        divisor=long(divisor);

        long absDividend=labs(dividend);

        long absDivisor=labs(divisor);

        if(absDividend<absDivisor){
           
            return 0;
        }
        
        else if(absDividend==absDivisor){
           
            return flag;
        }

        long res=count_(absDividend,absDivisor);

        cout<<"res: "<<res<<endl;
       
       long boundary=INT_MAX+long(1);
      

        //负数越界
        if(flag<0&&res>boundary){
          
            return INT_MAX;
        }
        
        //正数越界
        if(flag>0&&res>=INT_MAX)
            return INT_MAX;
        
        return flag*res;
    }

    /**
     * 401. 二进制手表
     * **/
     void getNumber(int total,int num,int startIndex,vector<int>&cur,vector<string>&nums){
      
        if(cur.size()==num){
            //cout<<"num: "<<num<<endl;
            int temp=0;
            for(auto x:cur)
                temp+=pow(2,x);
            if(total==4&&0<=temp&&temp<=11){
                nums.push_back(std::to_string(temp));
            }
            if(total==6&&0<=temp&&temp<=59){
                if(temp==0){
                    nums.push_back("00");
                }else if(1<=temp&&temp<=9){
                    string str="0";
                    str+=std::to_string(temp);
                    nums.push_back(str);
                }else{
                     nums.push_back(std::to_string(temp));
                }
            }
        }

        if(startIndex==total)
            return;
        for(int i=startIndex;i<total;i++){
            cur.push_back(i);
            getNumber(total,num,i+1,cur,nums);
            cur.pop_back();
        }
        
    }

    void getTime(int hourNum,int minuteNum,vector<string>&res){
        // cout<<"hourNum: "<<hourNum<<" minuteNum: "<<minuteNum<<endl;
        vector<int> hourCur;
        vector<string> hourNums;
        vector<int> minuteCur;
        vector<string> minuteNums;
        getNumber(4,hourNum,0,hourCur,hourNums);
        getNumber(6,minuteNum,0,minuteCur,minuteNums);
        for(int i=0;i<hourNums.size();i++){
            for(int j=0;j<minuteNums.size();j++){
                res.push_back(hourNums[i]+":"+minuteNums[j]);
            }
        }
        
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        string cur;
        for(int i=0;i<=4;i++){
            for(int j=0;j<=6;j++){
                if(i+j==turnedOn)
                    getTime(i,j,res);
            }
        }
        return res;
    }

    int getOneNum(int n){
        int res=0;
        while(n){
            n=n&(n-1);
            res++;
        }
        return res;
    }

    vector<string> readBinaryWatch_(int turnedOn) {

        vector<string> res;
        for(int i=0;i<=11;i++){
            for(int j=0;j<=59;j++){
                if(getOneNum(i)+getOneNum(j)==turnedOn){
                    res.push_back(std::to_string(i)+":"+(j<=9?"0"+std::to_string(j):std::to_string(j)));
                }  
            }
        }
        return res;

    }

    /**
     * 441. 排列硬币
     * **/
    int arrangeCoins_(int n) {
        int ans;
        
        ans=int(sqrt(2*long(n)));

        long multi=long(ans)*(ans+1);

        if(multi>long(n)*2)
            ans-=1;
        
        return ans;
    }

     int arrangeCoins(int n) {
        int i=1;
        long long sum=0;
        int ans;
        while(sum<n){
            sum+=i;
            if(sum>n){
                ans=i-1;
            }
            else if(sum==n)
                ans=i;
            i++;
        }
        return ans;
    }

    /**
     * 491. 递增子序列
     * **/
    void backTrackingSubsequence(vector<int>&nums,vector<int>&cur, vector<vector<int>>&res,int startIndex){
        if(cur.size()>=2)
            res.push_back(cur);
        if(startIndex==nums.size())
            return;
        //对本层元素进行去重
        unordered_set<int> curLevel;

        for(int i=startIndex;i<nums.size();i++){

            //遍历树第一层 
            if(!cur.size()&&curLevel.find(nums[i])==curLevel.end()){
                //if(curLevel.find(nums[i])==curLevel.end()){
                    cur.push_back(nums[i]);
                    curLevel.insert(nums[i]);
                    backTrackingSubsequence(nums,cur,res,i+1);
                    cur.pop_back();
                //}
            }
            else{
                if(nums[i]>=cur.back()&&curLevel.find(nums[i])==curLevel.end()){
                    curLevel.insert(nums[i]);
                    cur.push_back(nums[i]);
                    backTrackingSubsequence(nums,cur,res,i+1);
                    cur.pop_back();
                }
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        backTrackingSubsequence(nums,cur,res,0);
        return res;
    }

    /**
     * 118. 杨辉三角
     * **/
     vector<vector<int>> generate(int numRows) {

        vector<vector<int>> res(numRows);

        if(numRows==1)
            return {{1}};


        res[0].push_back(1);

        for(int i=1;i<numRows;i++){
            res[i].push_back(1);
            for(int j=0;j<res[i-1].size()-1;j++)
                res[i].push_back(res[i-1][j]+res[i-1][j+1]);
            res[i].push_back(1);
        }

        return res;

    }

    /**
     * 187. 重复的DNA序列
     * **/
    vector<string> findRepeatedDnaSequences(string s) {
        int i;
        int end;
        int n=s.size();
        vector<string> res;
        map<string,int> statistics;

        for(i=0;i<n;i++){
            if((end=i+9)<n){
                statistics[s.substr(i,10)]++;
            }
        }

        for(auto&it:statistics){
            if(it.second>1)
                res.push_back(it.first);
        }

        return res;
    }

    /**
     * 434. 字符串中的单词数
     * **/
     int countSegments(string s) {
        int ans=0;

        //统计连续字符串个数
        int i=0;
        int n=s.size();
        while(i<n){
            if(s[i]!=' '){
                ans++;
                while(i<n&&s[i]!=' ')
                    i++;
            }
            else
                i++;
        }
        return ans;
    }

    /**
     * 131. 分割回文串
     * **/
    void backTracking(vector<string> &cur,vector<vector<string>> &res,string&s,int startIndex){
        // startIndex为切割起始位置，起始位置大于字符串总长度，说明已经切割完毕，找到了一种切割方案
        //startIndex=s.size()时，上一次传参必为startIndex=s.size()-1,说明调用backTracking所在循环中的字符串最后一位往前数到某一位(旧的startIndex)之间的字符串是回文字符串，这样才能进入下一次回溯过程。
        if(startIndex>=s.size()){
            res.push_back(cur);
            return;
        }
            
        for(int i=startIndex;i<s.size();i++){

            if(isPlalindrome(s,startIndex,i)){
                string temp=s.substr(startIndex,i-startIndex+1);
                cur.push_back(temp);
                backTracking(cur,res,s,i+1);
                cur.pop_back();
            }

        }
        
    }

    //判断回文子串
    bool isPlalindrome(string&s,int start,int end){
        if(start==end)
            return true;
        int i=start,j=end;
        while(i<=j&&s[i]==s[j]){
            i++;
            j--;
        }
        if(i>j)
            return true;
        else
            return false;
    }

    vector<vector<string>> partition(string s) {
        vector<string> cur;
        vector<vector<string>> res;
        backTracking(cur,res,s,0);
        return res;
    }


    /**
     * 482. 密钥格式化
     * **/
        string licenseKeyFormatting(string s, int k) {
            int i;
            string res;
            int nChar=0;
            int curCharN=0;
            int n=s.size();

            for(i=0;i<n;i++){
                if(s[i]!='-')
                    nChar++;
            }

            //第一个分组字符串长度
            int firstStrN=nChar%k;
            if(!firstStrN)
                firstStrN=k;
            for(i=0;i<n;i++){
                if(s[i]!='-'){
                    //小写转大写
                    if('a'<=s[i]&&s[i]<='z')
                        s[i]-=32;
                    res+=s[i];
                    curCharN++;
                    if(curCharN==firstStrN){
                        res+='-';
                        firstStrN=k;
                        curCharN=0;
                    }
                }
            }
            return res.substr(0,res.size()-1);
        }

    /**
     * 166. 分数到小数
     * **/
    string fractionToDecimal(int numerator, int denominator) {
        string division;
        double res;
        int flag=1;
        map<int,int> remain2pos;//记录余数出现的位置
        map<int,int>::iterator it;
        res=double(numerator)/denominator;
        
        if(res<0)
            flag=-1;
        
        if(flag==-1)
            division.push_back('-');
        
        unsigned long numerator_=abs(numerator);
        unsigned long denominator_=abs(denominator);
        
        long div=numerator_/denominator_;
        division+=std::to_string(div);
        long remainder=numerator_%denominator_;
       
        if(remainder)
            division+=".";

        while(remainder){
            it=remain2pos.find(remainder);
            //出现重复余数，则小数部分会重复
            if(it!=remain2pos.end()){
                int pos=remain2pos[remainder];
                string repetDivision=division.substr(remain2pos[remainder],division.size()-pos);
                division=division.substr(0,pos);
                division+="(";
                division+=repetDivision;
                division+=")";
                return division;
            }
            numerator_=remainder*10;
            div=numerator_/denominator_;
            division+=std::to_string(div);
            remain2pos[remainder]=division.size()-1;
            remainder=numerator_%denominator_;    
        }
        return division;
    }

    /**
     * 36. 有效的数独
     * 
    */
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rowsChar(9);//行
        vector<set<char>> columnsChar(9);//列
        vector<set<char>> internalChar(9);//内部的9*9宫格
        int i,j;
        int m=board.size();
        int n=board[0].size();
        bool res=true;
        for(i=0;res&&i<m;i++){
            for(j=0;res&&j<n;j++){
                if('1'<=board[i][j]&&board[i][j]<='9'){
                    
                    if(rowsChar[i].count(board[i][j])){
                        
                        res=false;
                        break;
                    }
                    else
                        rowsChar[i].insert(board[i][j]); 
                    
                    if(columnsChar[j].count(board[i][j])){
                       
                        res=false;
                        break;
                    }
                    else
                        columnsChar[j].insert(board[i][j]);

                    if(internalChar[i/3*3+j/3].count(board[i][j])){
                       
                        res=false;
                        break;
                    }
                    else
                        internalChar[i/3*3+j/3].insert(board[i][j]);
                }
            }

        }
        return res;
    }

    /*
    * 405. 数字转换为十六进制数
    */
    string toHex(int num) {
        string res;
        if(num==0)
            return "0";
        string hex="0123456789abcdef";
        while(num&&res.size()<8){
            res=hex[num&0xf]+res;
            num>>=4;
        }
        return res;        
    }


    /**
     * 714. 买卖股票的最佳时机含手续费
     * **/
    int maxProfit_dp(vector<int>& prices, int fee) {
        int n=prices.size();
        if(n==1)
            return 0;
        vector<vector<int>> dp(n,vector<int>(2));//持有，不持有
        dp[0][0]=-prices[0];
        dp[0][1]=0;//啥都不干，而不是买入卖出，倒贴手续费
    
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]-prices[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]+prices[i]-fee);

        }
        return max(dp[n-1][1],dp[n-1][0]);
    }

    int maxProfit(vector<int>& prices, int fee) {
        int i;
        int n=prices.size();
       
        int minPrice=prices[0];
        int res=0;
        for(i=0;i<n;i++){

            //更新截至目前的最小价格
            if(minPrice>prices[i])
                minPrice=prices[i];
            // 不会获得收益直接跳过
            if(minPrice<=prices[i]&&prices[i]<=minPrice+fee)
                continue;
            //并不是真的就出手了，只是暂时计算受益，如果后面有更高的价格，还会累计收益。
            // minPrice=prices[i]-fee; 更新后下一次判断时，minPrice+fee=price[j],j在i的前面，然后累加收益。
            else if(minPrice+fee<=prices[i]){
                res+=prices[i]-minPrice-fee;
                minPrice=prices[i]-fee;
            }
                
        }
        return res;
    }

    /**
     * 35. 搜索插入位置
     * **/
    int searchInsert(vector<int>& nums, int target) {
        int mid;
        int n=nums.size();
        int left=0,right=n-1;
       
        while(left<=right){
            mid=(left+right)>>1;
            if(nums[mid]>target){
                right=mid-1;
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            else
                return mid;
        }
        // 分别处理如下四种情况
        // 目标值在数组所有元素之前  [0, -1]
        // 目标值等于数组中某一个元素  return middle;
        // 目标值插入数组中的位置 [left, right]，return  right + 1
        // 目标值在数组所有元素之后的情况 [left, right]， return right + 1
        return right+1;
    }

    /**
     * 435. 无重叠区间
     * **/
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //不重合区间个数
        int res=0;
        int i,preRight;
        auto f=[&](vector<int> &left,vector<int>& right){return left[1]<right[1];};

        sort(intervals.begin(),intervals.end(),f);

        int n=intervals.size();
        if(n==1)
            return res;

        res=1;
        preRight=intervals[0][1];
        for(i=0;i<n;i++){
            //后一个区间左端点>=前一个区间右端点，则计入不重合区间里面，
            //右端点已经有序
            if(i>0&&intervals[i][0]>=preRight){
                res++;
                preRight=intervals[i][1];
            }
            
        }
        //总区间个数-不重合的最大区间个数=需要移除的最小区间个数
        return n-res;
    }

    /**
     * 134. 加油站
     * **/
     int canCompleteCircuit_(vector<int>& gas, vector<int>& cost) {
        /*基于贪心的思路*/
        int curSum=0,totalSum=0;
        int i,start=0;
        int n=gas.size();
        for(i=0;i<n;i++){
            //累加当前剩余油量
            curSum+=gas[i]-cost[i];
            //累加总的剩余油量
            totalSum+=gas[i]-cost[i];

            //当前剩余油量小于0则只能从下一个位置开始继续行驶
            if(curSum<0){
                start=i+1;
                curSum=0;
            }
        }
        if(totalSum<0)
            return -1;
        return start;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i,j;
        int n=gas.size();
        int curGas;
      
        int start;
        int curPos;
        //遍历n个出发点
        for(i=0;i<n;i++){
            start=i;
            curGas=0;
            curPos=start;
            //可以从该位置出发
            if(cost[curPos]<=gas[curPos]){
                curGas+=gas[curPos];
                curGas-=cost[curPos];
                curPos=(curPos+1)%n;
                while(curPos!=start){
                    //获取当前位置油桶里面的汽油
                    curGas+=gas[curPos];
                    //驶往下一站。
                    if(curGas>=cost[curPos]){
                        curGas-=cost[curPos];
                        curPos=(curPos+1)%n;
                    }
                    //不能去下一站
                    else
                        break;
                }
                if(curPos==start)
                    return start;
            }
            else
                continue;
        }
        return -1;   
    }

    /**
     * 40. 组合总和 II
     * **/
     void combinationSum2Dfs(vector<vector<int>> &res,vector<int>& candidates,int index,int sum,vector<int>&cur, vector<bool> &used){
        
        if(sum==0){
            res.push_back(cur);
            return;
        }

        for(int i=index;i<candidates.size()&&sum>=candidates[i];i++){
            
            //candidates[i]==candidates[i-1]&&used[i-1]==false, 表示回溯路径构成的树的同一层：当前选择的和上一次选择一样，则没有选择的必要。candidates[i]==candidates[i-1]&&used[i-1]=true则表示回溯路径构成的树同一条路径上某个节点和上一层节点的值相同，不为同一层，可以继续选择。
            if(i>0&&candidates[i]==candidates[i-1]&&used[i-1]==false)
                continue;
          
            used[i]=true;
            //选当前
            cur.push_back(candidates[i]);
            combinationSum2Dfs(res,candidates,i+1,sum-candidates[i],cur,used);
            //不选当前
            cur.pop_back();
            used[i]=false;
            
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        vector<bool> used(n,false);
        combinationSum2Dfs(res,candidates,0,target,cur,used);
        return res;
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
     * 77. 组合
     * **/
    void dfsCombine_(vector<vector<int>>&res,int index,int n,int k,vector<int>&cur){
        
        
        if(cur.size()==k){
           
            res.push_back(cur);
            return;
        }
        for(int i=index;i<=n;i++){
            cur.push_back(i);
            dfsCombine_(res,i+1,n,k,cur);
            cur.pop_back();
        }
    
    }

    vector<vector<int>> combine(int n,int k) {
        vector<vector<int>> res;
        vector<int> cur;
        dfsCombine_(res,1,n,k,cur);
        return res;
    }

    /**
     * 725. 分隔链表
     * **/
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res;
        vector<ListNode*> cur;
        ListNode* pWork=head;
        ListNode* temp;
        int num=0;

        while(pWork){
            pWork=pWork->next;
            num++;
        }

        //一个节点一部分，剩下的为空
        if(num<k){  
            pWork=head;
            while(pWork){
                temp=pWork->next;
                pWork->next=nullptr;
                res.push_back(pWork);
                pWork=temp;
            }
            while(res.size()!=k){
                res.push_back(nullptr);
            }
            return res;
        }
        else{
            int avg=num/k;
            int leave=num%k;
            int curNum=0;

            cout<<"avg: "<<avg<<" leave: "<<leave<<endl;
            //前leave部分每个含有节点数：avg+1 个
            pWork=head;

            while(pWork){   

                temp=pWork->next;
                res.push_back(pWork);
                cur.push_back(pWork);
                
                //前leave个
                if(res.size()<=(avg+1)*leave){    
                    if(cur.size()==avg+1){
                        pWork->next=nullptr;
                        cur.clear();
                    }
                }
                //剩余的
                else{
                    if(cur.size()==avg){
                        pWork->next=nullptr;
                        cur.clear();
                    }
                }
                pWork=temp;
            }
            return res;
        }

    }

    /**
     * 58. 最后一个单词的长度
     * **/
     int lengthOfLastWord(string s) {

        int i,j;
        int n=s.size();
        if(n==1)
            return n;
        
        //找右边第一个非空字符
        i=n-1;
        while(s[i]==' ') i--;
        j=i;
        
        //找右边非空字符串的第一个空格
        while(j>=0&&s[j]!=' ') j--;
        return i-j;
        
    }

    /**
     * 673. 最长递增子序列的个数
     * **/
    int findNumberOfLIS(vector<int>& nums) {
        int i,j;
        int maxLen=0;
        int n=nums.size();
        if(n==1)
            return n;
        int num=0;
        // 以下标i结尾的最长递增子序列的长度，最后统计所有序列长度,求最大长度的个数就是所求结果
        vector<int> dp(n,1);
        // 以i结尾的最长递增子序列的个数
        vector<int> cnt(n);
        cnt[0]=1;

        for(i=0;i<n;i++){
           
            for(j=0;j<i;j++)
                if(nums[j]<nums[i])
                    dp[i]=max(dp[j]+1,dp[i]);
            maxLen=max(dp[i],maxLen);

            //统计最长子序列的个数
            for(j=0;j<i;j++)
                if(nums[j]<nums[i]&&dp[j]==dp[i]-1)
                    cnt[i]+=cnt[j];
            
            //以i结尾的最长子序列前面没有比其小的元素，则最长子序列为其本身，个数为1
            if(cnt[i]==0)
                cnt[i]=1;
        }
        if(maxLen==1)
            return n;

        //统计个数
        for(i=0;i<n;i++){
            if(dp[i]==maxLen){
               num+=cnt[i];
            }
        }
      
        return num;
    }

    /**
     * 1497. 检查数组对是否可以被 k 整除
     * **/
     bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        
        int i,j;

        // k个桶，n个数分别映射至k个桶
        vector<int> statics(k);
        int index;

        for(i=0;i<n;i++){
            index=arr[i]%k;
            if(index<0)
                index+=k;
            statics[index]++;
        }
    
        for(i=1,j=k-1;i<=j;i++,j--){
            if(statics[i]==statics[j])
                continue;
            else
                return false;
        }

        // 该数本身能被k整除，则需要判断是否两两成对

        if(statics[0]%2)
            return false;
        return true;
    }

    /**
     * 1109. 航班预订统计(差分数组)
     * **/
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        int i,j;
        int size=bookings.size();

        //基于差分数组的思路

        vector<int> diff(n);

        for(i=0;i<size;i++){

            int start=bookings[i][0];
            int end=bookings[i][1];
            int seats=bookings[i][2];
            //变化的下标范围是[start-1:end-1]
            diff[start-1]+=seats;
    
            if(end<n)
                diff[end]-=seats;

        }
        
        for(i=1;i<n;i++){
            diff[i]=diff[i-1]+diff[i];
        }

        return diff;
    }
    /**
     * 451. 根据字符出现频率排序
     * **/
    string frequencySort(string s) {
        string res;
        vector<int> charStatic(128);
        int i;
        int n=s.size();
        //统计各个字符出现次数
        for(i=0;i<n;i++){
            charStatic[int(s[i])]++;
        }
        //存入大顶堆
        priority_queue<charinfo> charQue;
        for(i=0;i<128;i++){
            if(charStatic[i]){
                    charinfo cInfo(char(i),charStatic[i]);
                    charQue.push(cInfo);

                }
            }
        
        //遍历大顶堆，输出相应字符
     
        while(!charQue.empty()){
            charinfo tempC=charQue.top();
          
            string str(tempC.freq,tempC.c);
            res+=str;
            charQue.pop();
        }
        return res;
    }

    /**
     * 147. 对链表进行插入排序
     * **/
      ListNode* insertionSortList(ListNode* head) {

        ListNode * pWork,* pAdjust,*pre,*pAfter;
        if(!head)
            return head;
        if(!head->next)
            return head;
        

        pWork=head->next;
        head->next=nullptr;
        while(pWork){
            pAdjust=head;
            
            //从前往后比较
            while(pAdjust&&pAdjust->val<=pWork->val){
                pre=pAdjust;
                pAdjust=pAdjust->next;
            }

            pAfter=pWork->next;
            //当前元素插入头节点之后
            if(pAdjust!=head){

                //先存工作指针后续节点
                //插入节点
                pWork->next=pre->next;
                pre->next=pWork;

                //插入节点为尾节点
             
            }
            //当前元素比头节点小
            else{
                pWork->next=pAdjust;
                head=pWork;
            }
            pWork=pAfter;
        }
        return head;

    }

    /**
     * 392. 判断子序列 基于最小编辑距离的算法
     * **/
    bool isSubsequence__(string s, string t) {
        int ns=s.size();
        int nt=t.size();
        int i,j;
        if(ns>nt)
            return false;
        
        //dp[i][j]:s[0:i-1] t[0:j-1] 的子串长度，不是子串则长度为0。 i,j表示s,t中子串的长度。
        vector<vector<int>> dp(ns+1,vector<int>(nt+1));

        //初始化 空串是是任何字符串的子串 且长度为0
        for(i=0;i<=ns;i++)
            dp[i][0]=0;
        for(j=0;j<=nt;j++)
            dp[0][j]=0;
        
        for(i=1;i<=ns;i++)
            for(j=1;j<=nt;j++){
                //相等：则子串长度加1
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                //不相等则复用上一个状态,t删除一个字符，看当前子串长度
                else
                    dp[i][j]=dp[i][j-1];
            }
        return dp[ns][nt]==ns?true:false;
    }

    bool isSubsequence_(string s, string t) {
        int ns=s.size();
        int nt=t.size();
        int i,j;
        if(ns>nt)
            return false;
        
        //dp[i][j]:s[0:i-1] 是否是t[0:j-1] 的子串。 i,j表示s,t中子串的长度。
        vector<vector<int>> dp(ns+1,vector<int>(nt+1));

        //初始化 空串是是任何字符串的子串 i,j表示长度
        for(i=0;i<=ns;i++)
            dp[i][0]=i;
        for(j=0;j<=nt;j++)
            dp[0][j]=j;
        
        for(i=1;i<=ns;i++)
            for(j=1;j<=nt;j++){
                //相等：则判断借用以前的状态
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                //不相等则t减少一个或者s增加一个，或者替换
                else
                    dp[i][j]=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
            }
        //理论上最小编辑距离为二者长度之差
        return dp[ns][nt]==nt-ns?true:false;
    }

    /**
     * 392. 判断子序列
     * **/
    bool isSubsequence(string s, string t) {
        int ns=s.size();
        int nt=t.size();
        int i,j;
        if(ns>nt)
            return false;

        //双指针法
        for(i=0,j=0;i<nt&&j<ns;)
            if(t[i]==s[j]){
                i++;
                j++;
            }
            else
                i++;
        
        if(j!=ns)
            return false;
        else 
            return true;
    }

    /**
     * 209. 长度最小的子数组
     * **/
    // 超时算法
     int minSubArrayLen(int target, vector<int>& nums) {

        int n=nums.size();
        int i,j;
        int minDis=INT_MAX;

        //存以下标开始到当前下标元素的总和
        vector<int> aux=nums;

        for(i=0;i<n;i++){
            for(j=0;j<i;j++){
                aux[j]+=nums[i];
                if(aux[j]>=target)
                    minDis=min(minDis,i-j+1);
            }
            if(nums[i]>=target)
                return 1;
        }
        if(minDis==INT_MAX)
            return 0;
        else
            return minDis;
    }
    // 优化
    int minSubArrayLen_(int target, vector<int>& nums) {

        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum >= target) {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;

    }
    // 二分
     int minSubArrayLen__(int target, vector<int>& nums) {

        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        //求前缀和
        vector<int> sum(n+1);

        for(int k=1;k<=n;k++)
            sum[k]=sum[k-1]+nums[k-1];
        
        int ans = INT_MAX;

        for (int i = 1; i <= n; i++) {
            int s=target+sum[i-1];
            //在所有前缀和里面找 前缀和>=前i-1个元素和+target。找到的第一个满足条件的前缀和-前i-1个元素和>=target. 二者的下标范围即是最小连续子数组的长度。

            auto it=lower_bound(sum.begin(),sum.end(),s);//不小于目标值的第一个元素
            // it-sum.begin() 第一个满足条件的下标
            if(it!=sum.end())            
                ans=min(ans,static_cast<int>(it-sum.begin()-i+1));

        }
        return ans == INT_MAX ? 0 : ans;

    }

    /**
     * 14. 最长公共前缀
     * **/
     string longestCommonPrefix(vector<string>& strs) {
        string res;
        int n=strs.size();
        int i,j;
        if(n==1)
            return strs[0];
        for(i=0;i<strs[0].size();i++){

          
            //遍历剩余字符串,从第二个开始匹配
            for(j=1;j<n;j++){
                if(i<strs[j].size()&&strs[j][i]==strs[0][i])
                    continue;
                else
                    break;
            }

            //第j个字符串的比较结果
            if(j==n)
                res+=strs[0][i];
            else
                break;

        }
        return res;
    }

    /**
     * 9. 回文数
     * **/
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        else if(x==0){
            return true;
        }
        else{
            int i,j,n;
            string num=std::to_string(x);
            n=num.size();
            for(i=0,j=n-1;i<j;i++,j--)
                if(num[i]==num[j])
                    continue;
                else
                    return false;
            return true;
        }
    }

    /**
     * 210. 课程表 II 
     * **/
     // 超时算法
      void dfsGraph_(vector<vector<int>>&graph,vector<int>&res){
        int n=graph.size();
        int i,j;

        // 当前节点入度
        int inputNum;

        // 是否存在无前趋的顶点
        bool preExist=true;

        vector<bool> visited(n,false);

        while(res.size()!=n){
            preExist=false;
            for(i=0;i<n;i++){
                if(!visited[i]){
                    inputNum=0;
                    for(j=0;j<n;j++){
                        inputNum+=graph[j][i];
                    }

                    // 当前节点入读为0
                    if(!inputNum){
                        preExist=true;
                        visited[i]=true;
                        res.push_back(i);
                        // 删除以该节点为起点的边
                        for(j=0;j<n;j++)
                            if(graph[i][j])
                                graph[i][j]=0;
                    }

                }
            }
            //不存在无前驱节点，即存在环
            if(!preExist){
                res.clear();
                return;
            }
        }
    }

    vector<int> findOrder_(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses,vector<int>(numCourses));

        vector<int> res;

        //初始化图
        int i;
        for(i=0;i<prerequisites.size();i++)
            graph[prerequisites[i][1]][prerequisites[i][0]]=1;
        
        dfsGraph_(graph,res);

        return res;
    }

    //基于邻接表

     void dfsGraph(vector<vector<int>>&graph,vector<int>&res,vector<int> &inputG){
        int n=graph.size();
        int i,j;

        stack<int> topOrder;
        // 入度为0的顶点入栈
        for(i=0;i<n;i++){
            if(inputG[i]==0)
                topOrder.push(i);
        }

        while(!topOrder.empty()){
            int top=topOrder.top();
            res.push_back(top);
            topOrder.pop();
            //更新以该顶点为起始点的边的尾节点的入度
            for(j=0;j<graph[top].size();j++)
                if(--inputG[graph[top][j]]==0) topOrder.push(graph[top][j]);
        }

     

        if(res.size()!=n){
            res.clear();
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);

        vector<int> res;

        // 统计每个节点入度
        vector<int> inputG(numCourses);

        //初始化图 邻接表形式
        int i;
        for(i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inputG[prerequisites[i][0]]++;
        }
        
      

        

        dfsGraph(graph,res,inputG);

        return res;
    }

    /**
     * 802. 找到最终的安全状态
     * **/
    // dfs 超时
     void dfsGragh(vector<vector<int>>& graph,int index,vector<bool>&visited,bool &canFinish){
        if(!visited[index]){
            visited[index]=true;
            int i;
            for(i=0;i<graph[index].size();i++){
                dfsGragh(graph,graph[index][i],visited,canFinish);
            }
            visited[index]=false;
        }
        //回到某个已经访问过的节点，构成了环
        else{
            canFinish=false;
            return;
        }
    }


    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n=graph.size();

        vector<bool> visited(n,false);

        vector<int> res;

        //是否能深度优先遍历完成
        bool canFinish=true;

        int i;
        for(i=0;i<n;i++){
            dfsGragh(graph,i,visited,canFinish);
            if(canFinish)
                res.push_back(i);
            canFinish=true;
        }
        return res;
    }

    // 基于链式前向星的方法
    vector<int> eventualSafeNodes_(vector<vector<int>>& graph) {
        
        //边的数量

        int N=1e4;

        int M=4*1e4;

        int edgeIndex=0,i,j;

        int n=graph.size();

        vector<bool> visited(n,false);

        vector<int> res;

        //存每个节点的入度
        vector<int> inDegree(N,0);

        // 反转图：由存图的出度节点改为存图的入度节点

        //存节点链表 某个点对应的边表的第一条边
        vector<int> head(n,-1);

        //某一条边指向的节点
        vector<int> edgeEnd(M);

        //某个边对应的下一条边节点
        vector<int> nextEdge(M); 

        // 添加边
        //[&] 表示基于引用的捕获方式
        //[&] 采用值捕获方式
        //为空则不捕获
        auto addEdge=[&](int a,int b){
            edgeEnd[edgeIndex]=b;
            nextEdge[edgeIndex]=head[a]; //该边下一条边对应的头节点
            head[a]= edgeIndex++;
        };

        
        //反向构建
        for(i=0;i<n;i++)
            for(j=0;j<graph[i].size();j++){
                addEdge(graph[i][j],i);
                inDegree[i]++;
            }

        /*
        cout<<"head: ";
        for(i=0;i<n;i++)
            cout<<head[i]<<" ";
        cout<<endl;

        cout<<"endEdge: ";
        for(i=0;i<edgeIndex;i++)
            cout<<edgeEnd[i]<<" ";
        cout<<endl;

        cout<<"nextEdge: ";
        for(i=0;i<edgeIndex;i++)
            cout<<nextEdge[i]<<" ";
        cout<<endl;
        */

        //BFS 求反向图的拓扑序列
        queue<int> points;
        for(i=0;i<n;i++){
            //该节点入度为0
            if(inDegree[i]==0){
                points.push(i);
            }
        }

        while(!points.empty()){
            // 
            int top=points.front();
            points.pop();
            for(i=head[top];i!=-1;i=nextEdge[i]){
                //i为top节点对应的边编号
                j=edgeEnd[i];// 该边对应尾节点
                if((--inDegree[j])==0) points.push(j);
            }
        }

        for(i=0;i<n;i++)
            if(inDegree[i]==0)
                res.push_back(i);

        return res;
    }

    /**
     * 257. 二叉树的所有路径
     * **/
     void dfsTreePaths(TreeNode* root, vector<string>&res,string curPath){
        curPath+=std::to_string(root->val);
       if(!root->left&&!root->right){
            res.push_back(curPath);
            return;
        }
        //保证传入节点不为空
        if(root->left)
            dfsTreePaths(root->left,res,curPath+"->");
        if(root->right)
            dfsTreePaths(root->right,res,curPath+"->");
        
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root)
            return res;
        string curPath;
        dfsTreePaths(root,res,curPath);
        return res;
    }

    /**
     * 7. 整数反转
     * **/
    int reverse__(int x) {
        
        if(x==INT_MIN)
            return 0;
        if(x==INT_MAX)
            return 0;
        int flag;

        if(x>0)
            flag=1;

        else{
            flag=-1;
            x=-x;
        }
       
        string res=std::to_string(x);
        ::reverse(res.begin(),res.end());
    
        int n=res.size();
        
        //越界
        if(res[0]-'0'>3&&n>=10)
            return 0;
       
        int i;
        long num=0;
        long negMin=2147483648;
        long posMax=2147483647;
       
        for(i=0;i<n;i++){
            num+=(res[i]-'0')*pow(10,n-1-i);
            if(flag>0&&num>posMax)
                return 0;
            if(flag<0&&num>negMin)
                return 0;
        }
        return num*flag;
        
    }
    //simple
    int reverse_(int x)
    {
        long n = 0;
        while (x)
        {
            n = n * 10 + x % 10;
            x /= 10;
        }
        return n > INT_MAX || n < INT_MIN ? 0 : n;
    }

    /**
     * 43. 字符串相乘
     * **/
    string add(string str1,string str2){
        int n1=str1.size();
        int n2=str2.size();

        int nMin=min(n1,n2);
        int nMax=max(n1,n2);

        string res;
        int j,plus=0,sum;
         for(j=0;j<nMin;j++){
                sum=(str1[j]-'0')+(str2[j]-'0')+plus;
                plus=sum/10;
                sum=sum%10;
                res+=std::to_string(sum);
        }
        for(;j<nMax;j++){
            if(n1==nMax)
                sum=(str1[j]-'0')+plus;
            else
                sum=(str2[j]-'0')+plus;
            plus=sum/10;
            sum=sum%10;
            res+=std::to_string(sum);
        }
        if(plus)
            res+=std::to_string(plus);
        
        return res;
    }

    // 每次计算两个数，递归计算用字符串表示的总和
    string addStr(vector<string> &midStr,int index){

        if(index==midStr.size()-1)
            return midStr[index];
        else{
            return add(midStr[index],addStr(midStr,index+1));
        }
    }

    string multiply(string num1, string num2) {

        string res;

        int n1=num1.size();
        int n2=num2.size();
        int nMax=max(n1,n2);

        vector<string> midStr;

        //判空
        if(n1==0||n2==0)
            return "0";
        //判0
        if(n1&&n2){
            if(num1[0]=='0'||num2[0]=='0')
                return "0";
        }


        int i,j,k;
        int nMin=min(n1,n2);

        int plus=0,multi;

        for(i=n1-1;i>=0;i--){

            k=0;
            while(k<n1-1-i){
               res.push_back('0');
               k++;
            }

            for(j=n2-1;j>=0;j--){
                multi=(num1[i]-'0')*(num2[j]-'0')+plus;
                plus=multi/10;
                multi=multi%10;
                res+=std::to_string(multi);
            }
            if(plus)
                res+=std::to_string(plus);
            midStr.push_back(res);
            plus=0;
            res="";
        }
        

        res=addStr(midStr,0);
    
        reverse(res.begin(),res.end());

        return res;
    }       

    /**
     * 73. 矩阵置零
     * **/
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int column=matrix[0].size();
        int i,j,k;

        //存下0元素所在的行列值
        set<int> emptyRows;
        set<int> emptyColumns;
        for(i=0;i<row;i++)
            for(j=0;j<column;j++){
                if(!matrix[i][j]){
                    emptyRows.insert(i);
                    emptyColumns.insert(j);
                }
            }
        
        // 修改对应行列值的零元素
        set<int>::iterator it;
        it=emptyRows.begin();
        while(it!=emptyRows.end()){
            for(i=0;i<column;i++)
                matrix[*it][i]=0;
            it++;
        }
        it=emptyColumns.begin();
        while(it!=emptyColumns.end()){
            for(i=0;i<row;i++)
                matrix[i][*it]=0;
            it++;
        }
    }
    // 常数复杂度
    void setZeroes_(vector<vector<int>>& matrix) {

        int row=matrix.size();
        int column=matrix[0].size();
        int i,j,k;

        //第一行是否存在0
        bool firstRow=false;

        //第一列是否存在0
        bool firstColumn=false;

        for(j=0;j<column;j++)
            if(!matrix[0][j])
                firstRow=true;
        
         for(i=0;i<row;i++)
            if(!matrix[i][0])
                firstColumn=true;

        //存下0元素所在的行列值
        for(i=0;i<row;i++)
            for(j=0;j<column;j++){

                if(!matrix[i][j]){
                    if(i&&j){
                        matrix[i][0]=0;
                        matrix[0][j]=0;
                    }
                }
            }

        for(i=0;i<row;i++){
            //除第一行外的行
            if(i>=1&&!matrix[i][0]){
                for(j=0;j<column;j++)
                    matrix[i][j]=0;
            }
        }

        for(i=0;i<column;i++){
            //除第一列外的列
            if(i>=1&&!matrix[0][i]){
                for(j=0;j<row;j++)
                    matrix[j][i]=0;
            }
        }

        if(firstColumn){
            for(i=0;i<row;i++)
                matrix[i][0]=0;
        }

        if(firstRow){
            for(j=0;j<column;j++)
                matrix[0][j]=0;
        }

    }

    /**
     * 162. 寻找峰值
     * **/
      int findPeakElement(vector<int>& nums,int low,int high){

        if(abs(low-high)>=2){
            int mid=(low+high)/2;
            if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1])
                return mid;
            
            int left=findPeakElement(nums,low,mid);
            // 提前结束
            if(left!=-1)
                return left;
            // 无论是否找到都返回
            int right=findPeakElement(nums,mid,high);
            return right;
        }
        return -1;
    }

    int findPeakElement(vector<int>& nums) {

    //中间元素比相邻元素都大，则必为峰值

    int n=nums.size();
    //边界
    if(n==1)
        return 0;
    if(n==2)
        return nums[0]>nums[1]?0:1;

    int res=findPeakElement(nums,0,n-1);
    if(res!=-1)
        return res;
    //单减或者单增
    if(nums[0]>nums[n-1])
        return 0;
    else 
        return n-1;
    }

    //leetcode answer
     int findPeakElement_(vector<int>& nums,int low,int high){

        if(low==high)
            return low;

    
        int mid=(low+high)/2;
        if(nums[mid]>nums[mid+1])
            return findPeakElement(nums,low,mid);
        
        return findPeakElement(nums,mid+1,high);

    }

    int findPeakElement_(vector<int>& nums) {

    //中间元素比相邻元素都大，则必为峰值

    int n=nums.size();
    //边界
    if(n==1)
        return 0;
    if(n==2)
        return nums[0]>nums[1]?0:1;

    return findPeakElement_(nums,0,n-1);
   
    }

    /**
     * 222. 完全二叉树的节点个数
     * **/
     int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        else if(!root->left&&!root->right)
            return 1;
        else{
            return 1+countNodes(root->left)+countNodes(root->right);
        }
    }
    //非递归
     int countNodes_(TreeNode* root) {
        int num=0;
        if(!root)
            return 0;
        else if(!root->left&&!root->right)
            return 1;
        else{
           //求高度
           int height=0;
           TreeNode *p=root;
           while(p){
               height++;
               p=p->left;
           }

           queue<TreeNode*> elements;
           elements.push(root);

           //当前队列中存第几层的数据 
           int level=1;
           while(!elements.empty()){
               int n=elements.size();
               for(int i=0;i<n;i++){
                    p=elements.front();
                    elements.pop();
                    
                    if(p->left)
                            elements.push(p->left);
                    if(p->right)
                            elements.push(p->right);
               }
        
               if(level==height-1){
                   num=pow(2,height-1)-1+elements.size();
                   break;
               }
               level++;
           }
        }
        return num;
    }
    /**
     * 109. 有序链表转换二叉搜索树
     * **/
     TreeNode* sortedListToBST(ListNode* head) {

        if(!head)
            return nullptr;
        else if(!head->next){
            return new TreeNode(head->val);
        }

        ListNode *first=head,*second=head,*pre=nullptr;

       // 快慢指针找到中间节点
        while(second&&second->next){
            pre=first;
            first=first->next;
            second=second->next->next;
        
        }
        
        //分离链表
        second=first->next;
        pre->next=nullptr;

        // 中间节点为根节点
        TreeNode * p=new TreeNode(first->val);

        //递归建树
        p->left=sortedListToBST(head);
        p->right=sortedListToBST(second);
        return p;
    }

    /**
     * 120. 三角形最小路径和
     * **/
      int minimumTotal(vector<vector<int>>& triangle) {

        //总的层数
        int n=triangle.size();
         
        if(n==1)
            return triangle[0][0];
        
        int i,j;

        //自底向上,原地修改
        for(i=n-2;i>=0;i--){
            for(j=0;j<triangle[i].size();j++)
                triangle[i][j]+=min(triangle[i+1][j+1],triangle[i+1][j]);
        }

        return triangle[0][0];
    }

    //不原地修改的方法
    int minimumTotal_(vector<vector<int>>& triangle) {

        //总的层数
        int n=triangle.size();
        if(n==1)
            return triangle[0][0];
        int i,j;
        vector<int> dp;
        //初始化为最后一层节点的值
        dp=triangle[n-1];

        //自底向上，从倒数第二层开始
        for(i=n-2;i>=0;i--){
            for(j=0;j<triangle[i].size();j++)
                dp[j]=min(dp[j],dp[j+1])+triangle[i][j];
           
        }

        return dp[0];
    }

    /**
     * 61. 旋转链表
     * **/
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head)
            return head;
        else if(!head->next)
            return head;
        if(!k)
            return head;

       ListNode * pWork=head,*tail,*pre;
       int num=0;
       //统计链表节点个数
       while(pWork) {
           num++;
           if(pWork)
                tail=pWork;
           pWork=pWork->next;
        
       }
       if(num<=k){
           //完整旋转
           if(k%num==0){
               return head;
           }
           else{
               k=k%num;
           }
       }
       
       //原链表旋转k(k<num)次，倒数第k个节点，正数num-k+1为头节点
       int i=1;
       pWork=head;
       //前驱
       pre=pWork;
       //找新表头，表头前面是新表尾。
       while(i<num-k+1){
           pre=pWork;
           pWork=pWork->next;
           i++;
       }
      
       pre->next=nullptr;
       tail->next=head;
       return pWork;
    }

    /**
     * 29. 两数相除
     * **/
    long divide_(long dividend, long divisor){

        if(dividend==divisor)
            return 1;
        else if(dividend<divisor)
            return 0;
        else{
            long count=1;
            long temp=divisor;
            //循环减少递归栈空间
            while(temp+temp<dividend){
                temp=temp+temp;
                count=count+count;
            }
            return count+divide_(dividend-temp,divisor);
        }  

    }

    int divide(int dividend, int divisor) {

        int flag;
        if((dividend>0&&divisor>0)||(dividend<0&&divisor<0))
            flag=1;
        else
            flag=-1;
        long a=abs(dividend);
        long b=abs(divisor);
       
        if(a<b)
            return 0;
        if(a==b)
            return flag*1;
        if(a>=abs(INT_MIN)&&b==1){
            if(flag>0)
                return INT_MAX;
            else
                return INT_MIN;
        }
        int res=divide_(a,b);
        if(res>=INT_MAX)
            return INT_MAX;
        return flag*res;

    }


    /**
     * 24. 两两交换链表中的节点
     * **/
    ListNode* swapPairs(ListNode* head) {

        //空
        if(!head)
            return head;
        
        //一个节点
        if(!head->next)
            return head;
        
        ListNode * first, *second, *three, *newHead=nullptr, *tail;

        //至少有两个节点
        first=head;
        second=first->next;
        newHead=second;
        three=second->next;

        //只有两个节点
        if(!three){
            second->next=first;
            first->next=nullptr;
            return newHead;
        }
            
        tail=new ListNode();

        while(three){

            tail->next=second;
            second->next=first;
            first->next=three;

            //更新tail
            tail=first;

            //更新first
            first=three;
            
            if(first->next){
                second=first->next;
                three=second->next;
            }
            //three是最后一个节点
            else
                break;
        }

        //剩余两个节点
        if(!three){
            tail->next=second;
            second->next=first;
            first->next=nullptr;
        }else
            tail->next=three;
        
        return newHead;
    }

    /**
     * 135. 分发糖果
     * **/
      int candy(vector<int>& ratings) {

        int i,j,k;
        int n=ratings.size();
        vector<int> left(n);
        int res=0;

        int right=0;

        //两趟扫描思路
        for(i=0;i<n;i++){
            // 后者大于前者
            if(i>0&&ratings[i]>ratings[i-1])
                left[i]=left[i-1]+1;
            else    
                left[i]=1;
        }

        for(i=n-1;i>=0;i--){
            // 前者大于后者
            if(i<n-1&&ratings[i]>ratings[i+1])
                right++;
            else
                right=1;

            res+=max(left[i],right);
        }

        return res;
    }

    /**
     * 1347. 制造字母异位词的最小步骤数
     * **/
     int minSteps(string s, string t) {

        int i;
        int n=s.size();
        int res=0;
        //统计字符串的字符信息
        vector<int> statistic(26);

        for(i=0;i<n;i++){
            statistic[s[i]-'a']++;
        }

        for(i=0;i<n;i++){
            //t中有相同字符串则抵消
            if(statistic[t[i]-'a'])
                statistic[t[i]-'a']--;
        }
        // 统计不相同的字符个数
        for(i=0;i<26;i++)
            res+=abs(statistic[i]);

        return res;
    }


    /**
     * 49. 字母异位词分组
     * **/
     vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> statistic;
     
        vector<vector<string>> res;
       
        for(auto &it:strs){
            string temp=it;
            sort(temp.begin(),temp.end());
            statistic[temp].emplace_back(it);
        }
       
        for(auto it=statistic.begin();it!=statistic.end();it++){
            res.emplace_back(it->second);
        }
        return res;
    }

    /**
     * 1769. 移动所有球到每个盒子所需的最小操作数
     * **/
    //暴力
    vector<int> minOperations(string boxes) {

        int i,j,k,cur;
        int n=boxes.size();

        vector<int> res;    
        for(i=0;i<n;i++){
            cur=0;
            for(j=i-1,k=i+1;j>=0||k<n;j--,k++){
                if(j>=0&&boxes[j]=='1'){
                    cur+=(i-j);
                }
                if(k<n&&boxes[k]=='1'){
                    cur+=(k-i);
                }
            }
            res.push_back(cur);
        }
        return res;
    }

    //o(n)
    vector<int> minOperations_(string boxes) {

        int i,j,k,cur;
        int n=boxes.size();

        // leftToRight[i]:移动i左边所以1到i需要的移动次数
        vector<int> leftToRight(n);

        // rightToLight[i]:移动i右5边所以1到i需要的移动次数
        vector<int> rightToLeft(n);
        vector<int> res;    

        //leftToRight[i]等于所有'1'移动到上一个位置的移动次数加上i左边'1'的个数(下标增加后所有'1'需要再多移动一次)，rightToLight于此同理。

        if(boxes[0]=='1')
            cur=1;
        else
            cur=0;
      
        for(i=1;i<n;i++){
            leftToRight[i]=cur+leftToRight[i-1];
            if(boxes[i]=='1')
                cur++;
        }

        if(boxes[n-1]=='1')
            cur=1;
        else
            cur=0;
      
        for(i=n-2;i>=0;i--){
            rightToLeft[i]=cur+rightToLeft[i+1];
            if(boxes[i]=='1')
                cur++;
        }

        for(i=0;i<n;i++){
            res.push_back(leftToRight[i]+rightToLeft[i]);
        }
        return res;
    }

    /*
    * 215. 数组中的第K个最大元素 基于优先队列
    */
    int findKthLargest(vector<int>& nums, int k) {
       
        priority_queue<int> elements;
        int i=0,n=nums.size();
        for(i=0;i<n;i++){
            elements.push(nums[i]);
        }
        i=0;
        while(i!=k-1){
            elements.pop();
            i++;
        }
        return elements.top();
    }

    /**
     * 剑指 Offer II 038. 每日温度
     * **/
     vector<int> dailyTemperatures(vector<int>& temperatures) {
        //核心思路：维持一个单调递减栈，存下标便于计算等待天数。
        //入栈之间判断是否小于栈顶元素，不小于则调整栈元素
        stack<int> indexs;
        int n=temperatures.size();
        vector<int> res(n);
        int i;
        for(i=0;i<n;i++){
    
            while(!indexs.empty()&&temperatures[i]>temperatures[indexs.top()]){
                res[indexs.top()]=i-indexs.top();
                indexs.pop();

            }
            
            indexs.push(i);
        }
        return res;
    }

    /**
     * 345. 反转字符串中的元音字母
     * **/
     //判断元音
   bool isVowels(char c){
       if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
            return true;
        else 
            return false;
   }

    string reverseVowels(string s) {

        int i=0,j=s.size()-1;
        while(i<j){
            //从左往右找左边的元音
            while(i<j&&!isVowels(s[i]))
               i++;
            //从右往左找右边的元音
            while(i<j&&!isVowels(s[j]))
               j--;
            if(i<j){
                swap(s[i++],s[j--]);
            }
        }

        return s;
    }
    
    /**
     * 654. 最大二叉树
     * **/
    //找到最大元素所在下标然后递归构建
    TreeNode * buildMaxBT(vector<int> &nums,int start,int end){
        if(start<=end){
           
            //下标越界
            if(start==end){
                if(end==nums.size())
                    return nullptr;
            }
            //总个数
            int n=end-start+1;
            //注意下标范围[start:start+n]
            int maxIndex=std::max_element(nums.begin()+start,nums.begin()+start+n)-nums.begin();
            TreeNode * p=new TreeNode(nums[maxIndex]);
            p->left=buildMaxBT(nums,start,maxIndex-1);
            p->right=buildMaxBT(nums,maxIndex+1,end);
            return p;
        }
        return nullptr;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        //传入下标范围
        return buildMaxBT(nums,0,n-1);
    }

    /**
     * 1689. 十-二进制数的最少数目
     * **/
    int minPartitions(string n) {
        int len=n.size();
        char maxChar=n[0];
        if(len==1)
            return maxChar-'0';
        int i=1;
        while(i<len){
            maxChar=max(maxChar,n[i]);
            i++;
        }
        return maxChar-'0';
    }

    /**
     * 1382. 将二叉搜索树变平衡
     * **/
    //中序遍历按序存储节点
    void inorder(TreeNode * root,vector<int> & elements){
        if(!root)
            return;
        else{
            inorder(root->left,elements);
            elements.push_back(root->val);
            inorder(root->right,elements);
        }
    }

    TreeNode * buildBST(vector<int> &elements,int left, int right){
        if(left<=right){
            int mid=(left+right)/2;
            TreeNode * p=new TreeNode(elements[mid]);
            p->left=buildBST(elements,left,mid-1);
            p->right=buildBST(elements,mid+1,right);
            return p;
        }
        return nullptr;
    }

    TreeNode* balanceBST(TreeNode* root) {
        //边界
        if(!root)
            return root;
        vector<int> elements;
        inorder(root,elements);

        //递归二分建立平衡二叉搜索树
        return buildBST(elements,0,elements.size()-1);
    }

    /**
     * 
     * 763. 划分字母区间
     * **/

     //查找更新右区间后是否加入的新的元素，如果加入新元素，右边界可能继续扩大
    int newCharJoin(string s,int start,int pos, set<char>&occurs){
        int i,k;
        //start:pos之间的所有元素
        for(k=start+1;k<pos;k++)
            occurs.insert(s[k]);
        for(i=s.size()-1;i>pos;i--){
            if(occurs.count(s[i]))
                return i;
        }
        return pos;
    }


    vector<int> partitionLabels(string s) {
        //存储处理区间内已出现的元素
        set<char> occurs;
        vector<int> res;
        int n=s.size();
        //起止,终止，新终止，区间临时起点
        int i,pos,newPos,start;
        for(i=0;i<n;i++){
            pos=i;
            occurs.insert(s[i]);
            newPos=pos;
            start=i;
            while((newPos=newCharJoin(s,start,pos,occurs))!=pos){
                    start=pos;
                    pos=newPos;
                }
            res.push_back(newPos-i+1);
            occurs.clear();
            i=newPos;
        }
        return res;
    }
    //once again
     vector<int> partitionLabels__(string s) {
        vector<int> res;
        //存每一个字符出现的最大的位置(最后一次出现)
        map<char,int> char2pos;
        int i,j;
      
        for(i=0;i<s.size();i++)
            char2pos[s[i]]=i;

        for(i=0;i<s.size();i++){
            int start=i;
            int end=char2pos[s[start]];
            for(j=start+1;j<end;j++){
             
                //更新字符区间尾位置
                if(char2pos[s[j]]>end){
                    end=char2pos[s[j]];
                    
                }

            }
            res.push_back(end-start+1);
            i=end;
        }
        return res;
    }
    /**
     * 1877. 数组中最大数对和的最小值
     * **/
    int minPairSum(vector<int>& nums) {
        //排序
        sort(nums.begin(),nums.end());
        //左右指针
        int i=0,j=nums.size()-1;
        int res=INT_MIN;
        //选最大
        while(i<j){
            res=max(nums[i]+nums[j],res);
            i++;
            j--;
        }
        return res;
    }

    /**
     *  实现 strStr()
     * **/
    int strStr(string haystack, string needle) {
        if(needle.size()==0)
            return 0;
        int n=haystack.size();
        int m=needle.size();
        int i,j,k;
        int pos=-1;
        for(i=0;i<n;i++){
            if(haystack[i]==needle[0]){
                for(j=1;j<=m-1;j++){
                    if(haystack[i+j]==needle[j])
                        continue;
                    else
                        break;
                }
                if(j==m){
                    pos=i;
                    return pos;
                }
            }
        }
        return pos;
    }

     //kmp求下一个比较的位置
    vector<int> nextPos(string s){
        int n=s.size();

        //子串中相应位置匹配失败时从何处重新开始匹配,极端情况：
        // 最后一个匹配失败 
        // 第一个就匹配失败
        vector<int> pos(n,-1);
        int j=0,k=-1;
        while(j+1<n){
            //k==-1表示字符需要从头(0)开始匹配。
            if(k==-1||s[j]==s[k]){
                ++k;++j; pos[j]=k;
            }
            else
                k=pos[k];   
        }
        return pos;
    }

    int strStrKmp(string haystack, string needle) {
        if(needle.size()==0)
            return 0;

        vector<int> Pos=nextPos(needle);
        
        int n=haystack.size();
        int m=needle.size();
        int i=0,j=0;
        while(i<n){
            //j==-1,i后移一步,j从0开始。
            if(j==-1||haystack[i]==needle[j]){
                ++i;++j;
            }
            else
                //子串中下一个开始匹配的位置
                j=Pos[j];
            // 已经匹配完所有字符，下标超过子串下标范围
            if(j==m)
                return i-j;
        }
        return -1;
    }


    bool isNumber(string s) {
        int n=s.size();
        int i=0;

        //最后一位为字母或者符号
        if(('a'<=s[n-1]&&s[n-1]<='z')||('A'<=s[n-1]&&s[n-1]<='Z')||(s[n-1]=='-')||s[n-1]=='+')
            return false;

        //优先判断第一位,第一位为字母
        if(('a'<=s[i]&&s[i]<='z')||('A'<=s[i]&&s[i]<='Z'))
            return false;

        bool pointExist=false;
        bool eExist=false;
        int sign=0;

        bool digitExist=false;

        //跳过前面的空格
        while(i<n&&s[i]==' ') i++;
        int start=i;
        while(i<n){
            if(('a'<=s[i]&&s[i]<='z')||('A'<=s[i]&&s[i]<='Z')){
                //出现e/E
                if(s[i]=='e'||s[i]=='E'){
                    //只能包含一个e
                    if(eExist)
                        return false;
                    else{
                        eExist=true;
                        // 出现e/E 时从未出现数字，如 +e
                        if(!digitExist)
                            return false;
                    }
                    //出现e后下一位不能有空格或者小数点
                    if(i+1<n&&(s[i+1]==' '||s[i+1]=='.'))
                        return false;
                }
                //出现除e/E以外的
                else 
                    return false;
            }
            //第一位非空格,非字母字符的符号位
            else if((s[i]=='+')||(s[i]=='-')){
               sign++;
               if(sign>2)
                    return false;
                if(eExist){
                    //e/E已出现但+,-前一位不为e/E
                    if(i&&s[i-1]!='e'&&s[i-1]!='E')
                        return false;
                    //符号出现在最后一位
                    if(i==n-1)
                        return false;
                }else{
                    //不出现在开始位置
                    if(i!=start)
                        return false;
                }
            }    
            //非空格字符为数字
            else if(s[i]=='.'){
                // e之后只能出现整数
                if(eExist)
                    return false;
                //只能包含一个小数点
                if(pointExist)
                    return false;
                else
                    pointExist=true;

            }
            //空格
            else if(s[i]==' '){
                int j=i;
                while(j<n&&s[j]==' ')
                    j++;
                //只是中间出现空格
                if(j<=n-1)
                    return false;
            }
            //非空格字符为数字
            else{
                digitExist=true;
            }
            i++;
        }
        if(digitExist)
            return true;
        else
            return false;
    }

    /**
     * 剑指 Offer 44. 数字序列中某一位的数字
     * **/
    int findNthDigit(int n) {
        if(!n)
            return 0;

        //求n所在数字的位数//

        //对应数字位数
        int digit=1;
        //对用数位有多少个数字
        long count=9;
        //对应数位的开始数字
        long start=1;
       
        while(n>count){
            n-=count;
            start*=10;
            digit++;
            count=9*start*digit;
        }

        //求该数位对应的数字//

        unsigned int num=start+(n-1)/digit;

        //求对应数位上的数字//

        string numStr=std::to_string(num);    
        

        char res=numStr[(n-1)%digit];

        return res-'0';
    }

    /**
     * 剑指 Offer 16. 数值的整数次方
     * **/
    double myPow(double x, int n) {
       //x为0
        if(abs(x-0.0)<1e-6)
            return x;
        double start=1.0;
        //n为0
        if(!n)
            return start;
        double negStart=-1.0;
        long i;

        //x为1
        if(abs(x-start)<1e-6)
            return start;
        //x为-1
        if(abs(x-negStart)<1e-6)
            return n%2?negStart:start;
        
         //防止n过大
        long absN=abs(long(n));
        
        for(i=1;i<=absN;i++){
            start*=x;
            if(i+i<absN){
                start*=start;
                i+=i;
            }
        }

        return n>=0?start:1.0/start;
    }
    

    /**
     * 剑指 Offer II 092. 翻转字符
     *
     * **/
    int minFlipsMonoIncr(string s) {
        
        int n=s.size();
        if(n==1)
            return 0;
        int ans=INT_MAX;
        //统计1的个数
        vector<int> oneNum(n+1);
        int i;
        //分割成左右两部分，左边需要有多少个1需要反转，右边有多少个0需要反转。
        //最终把左右需要反转的个数相加。
       
        for(i=1;i<=n;i++){
            oneNum[i]=oneNum[i-1]+(s[i-1]=='1');
        }

        //从0开始，考虑n个字符中的1全都需要反转的情况
        for(i=0;i<=n;i++)    
            ans=min(ans,oneNum[i]+n-i-(oneNum[n]-oneNum[i]));
        return ans;
        
    }

    /**
     * 剑指 Offer II 079. 所有子集
     * **/
    void dfsSubset(vector<int>& nums,int index,vector<int>&cur,vector<vector<int>>&res){
        if(index==nums.size()){
                res.push_back(cur);
            return;
        }
        //选当前
        cur.push_back(nums[index]);
        dfsSubset(nums,index+1,cur,res);
        //不选当前
        cur.pop_back();
        dfsSubset(nums,index+1,cur,res);
    }

    //基于回溯
    vector<vector<int>> subsets_(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        if(!n)
            return {{}};
        vector<int> cur;
        dfsSubset(nums,0,cur,res);
        return res;
    }

    /**
     * 1584. 连接所有点的最小费用(Prime超时算法)
     * **/
    int distance(vector<int> &start,vector<int> &end){
        return abs(start[0]-end[0])+abs(start[1]-end[1]);
    }

    

    int minCostConnectPoints_(vector<vector<int>>& points) {
        int i;
        int minPrice=0;
        int minDis=INT_MAX;
        int n=points.size();
        if(n==1)
            return minPrice;

        //已选择节点
        vector<vector<int>> choose;
        //当前距离最小节点
        vector<vector<int>>::iterator minDisPoint;

        //选择第一个节点作为起始节点
        vector<int> start(points[0].begin(),points[0].end());
        choose.push_back(start);
        //删除第一个节点
        vector<vector<int>>::iterator it=points.begin();
        points.erase(it);
       

        vector<vector<int>>::iterator im=choose.begin();

        while(choose.size()!=n){
            for(im=choose.begin();im!=choose.end();im++){
                    for(it=points.begin();it!=points.end();it++){
                        int curDis=distance(*im,*it);
                        if(curDis<minDis){
                            minDisPoint=it;
                            minDis=curDis;
                        }
                        //break;
                    }
            }
            choose.push_back({*minDisPoint});
            points.erase(minDisPoint);
            minPrice+=minDis;
            minDis=INT_MAX;
            //break;
        }
        return minPrice;
    }
    //primer + 邻接矩阵
     int prime(vector<vector<int>>&G,int n){
       int minPrice=0;
       int i,j,k;
    
     
       vector<int> visited(n,0);

       //初始化图中到每个点的到已选点的最短距离，刚开始已选点为空，一次为INT_MAX，后面去更新最短距离
       vector<int> distance(n,INT_MAX);
       distance[0]=0;

       //n次选点
       for(i=0;i<n;i++){
           //选择一个到已选点中距离最小的点加入其中构成最小生成树
           int curPoint=-1,minDis=INT_MAX;
           for(j=0;j<n;j++){
               if(!visited[j]&&distance[j]<minDis){
                   curPoint=j;
                   minDis=distance[j];
               }
           }

           visited[curPoint]=1;
           distance[curPoint]=minDis;
           minPrice+=minDis;
           
           for(k=0;k<n;k++){
               //当前节点未被加入生成树，从本次已选点到当前点有路径，且该路径长度小于以前到当前点的最小距离，则更新最小距离，便于下次选取。
               if(!visited[k]&&G[curPoint][k]!=0&&G[curPoint][k]<distance[k]){
                   distance[k]=G[curPoint][k];
               }
           }
       
       }
       return minPrice;
   }



    int minCostConnectPoints(vector<vector<int>>& points) {
        int i,j;
        int n=points.size();

        //邻接矩阵
        vector<vector<int>> edge(n,vector<int>(n,0));

        for(i=0;i<n;i++)
            for(j=0;j<i;j++){
                int dis=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edge[i][j]=edge[j][i]=dis;
            }
        return prime(edge,n);
    }

    /**
     * 剑指 Offer 67. 把字符串转换成整数
     * **/
     int strToInt(string str) {
        bool charContinue=true;
        stack<int> elements;
        int i=0;
        int n=str.size();
        int flag=1;
        long long res=0;
        for(i=0;str[i]==' ';i++);
        if(str[i]=='-'||str[i]=='+'||'0'<=str[i]&&str[i]<='9'){
            if(str[i]=='-'||str[i]=='+'){
                if(str[i]=='-')
                    flag=-1;
                for(i=i+1;str[i]=='0';i++);
            }
            else{
                 for(;str[i]=='0';i++);
            }
            for(;charContinue&&i<n;i++){
                if('0'<=str[i]&&str[i]<='9'){
                    elements.push(str[i]-'0');
                }
                else
                    charContinue=false;
            }
            long long scale=1;
            while(elements.size()){
                res+=elements.top()*scale;
                if(res>INT_MAX){
                    if(flag==1){
                        return INT_MAX;
                    }
                    else{
                        return INT_MIN;
                    }    
                }
                scale*=10;
                elements.pop();
                if(elements.size()&&scale>INT_MAX){
                   if(flag==1){
                        return INT_MAX;
                    }
                    else{
                        return INT_MIN;
                    }    
                }
            }
            res*=flag;
        }
        return res;
    }

    /**
     * 剑指 Offer 46. 把数字翻译成字符串
     * **/
     int translateNum(int num) {
        string strnum=std::to_string(num);

        int n=strnum.size();

        if(n==1)
            return 1;
        else if(n==2){
            if(num<=25)
                return 2;
            else    
                return 1;
        }
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        int i;
        string tempStr;
        tempStr+=strnum[0];
        for(i=2;i<=n;i++){
            tempStr+=strnum[i-1];
            int tempNum=std::stoi(tempStr);
            if(10<=tempNum&&tempNum<=25)
                dp[i]=dp[i-2]+dp[i-1];
            else
                dp[i]=dp[i-1];
            tempStr=tempStr.substr(1,1);
        }
        return dp[n];
    }

    /**
     * 剑指 Offer 33. 二叉搜索树的后序遍历序列
     * **/
     bool verifyPostorder(vector<int>&postorder,int start,int end){
        
        if(start>=end)
            return true;
        int i,divide;
        //左子树
        for(i=start;i<end&&postorder[i]<postorder[end];i++);
        divide=i;
        //右子树
        for(;i<end&&postorder[i]>postorder[end];i++);
        if(i<end)
            return false;
        else{
            return verifyPostorder(postorder,start,divide-1)&&verifyPostorder(postorder,divide,end-1);
        }
    }

    bool verifyPostorder(vector<int>& postorder) {
       return verifyPostorder(postorder,0,postorder.size()-1);
    }
    /**
     * 
     * 剑指 Offer 60. n个骰子的点数
     * **/
    vector<double> dicesProbability(int n) {
        vector<double> res;
        int i,j,k;
       //dp[n][i]:n个骰子出现点数和为i的次数
        vector<vector<double>> dp(n+1,vector<double>(6*n+1));
        for(i=1;i<=6;i++)
            dp[1][i]=1;
        for(i=2;i<=n;i++)
            for(j=i;j<=6*n;j++){
                    for(k=1;k<=6&&j-k>0;k++){
                        dp[i][j]+=dp[i-1][j-k];
                    }
        }
        //总情况数 n个骰子，每个骰子出现六个情况，每个独立投6次总的情况数
        int all=pow(6,n);
        for(i=n;i<=6*n;i++)
            res.push_back(dp[n][i]*1.0/all);
        return res;
    }
    // 从后往前更新
     vector<double> dicesProbability_(int n) {
        vector<double> res;
        int i,j,k;
        vector<int> dp(6*n+1);
        for(i=1;i<=6;i++)
            dp[i]=1;
        //遍历骰子
        for(i=2;i<=n;i++)
            //遍历该骰子数对应的点数
            for(j=6*n;j>=i;j--){
                dp[j]=0;
                //累加和当前总点数相关的骰子点数和出现的次数
                //比如当前总点数和为7,与之相关的骰子点数和为：6,5,4,3,2,1. (当前骰子数为i,前面的骰子点数和最少为i-1)
                for(k=1;j-k>=i-1&&k<=6;k++)
                    dp[j]+=dp[j-k];
            }
        int all=pow(6,n);
        for(i=n;i<=6*n;i++)
            res.push_back(dp[i]*1.0/all);
        return res;
    }


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
     int findIndex(vector<Node_*>&nodes,Node_*node){
        if(!node)
            return -1;
        vector<Node_*>::iterator it=find(nodes.begin(),nodes.end(),node);
        return it-nodes.begin();
    }

    Node_* copyRandomList(Node_* head) {
        if(!head)
            return head;
        Node_ * pwork=head;
        vector<Node_*> nodes;
        vector<Node_*> newnodes;
        Node_ * newHead=new Node_(0);
        Node_ * tail=newHead;
        while(pwork){
            //创建新节点
            Node_ * temp=new Node_(pwork->val);
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
     * 83. 删除排序链表中的重复元素
     * **/
    ListNode* deleteDuplicates_(ListNode* head) {
        ListNode * pre, *pwork;

        //为空
        if(!head)
            return head;
        //只有一个节点
        if(!head->next)
            return head;

        pre=head;
        pwork=pre->next;

        while(pwork){

            while(pwork&&pwork->val==pre->val)
                pwork=pwork->next;
        
            pre->next=pwork;
            pre=pwork;    
            
        }
        return head;
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
      
        // 总额为1~amount对应的最少硬币数
        vector<int> memeory(amount+1,amount+1);
        memeory[0]=0;

        //遍历总额
        for(i=1;i<=amount;i++){

            //遍历硬币面额
            for(j=0;j<n;j++){

                // 计算放入当前硬币的剩余总额
                int temp=i-coins[j];

                //剩余总额大于等于0，选择当前硬币，更新当前总额对应的最少硬币数
                if(temp>=0)
                    memeory[i]=min(memeory[i],memeory[temp]+1);   
                
                //不选择则无任何操作

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

        //初始化和为0的子数组个数
        statistic.insert({0,1});

        for(i=0;i<n;i++){
            sum+=nums[i];
            pre=sum-k;
            if(statistic.find(pre)!=statistic.end()){
                num+=statistic[pre];                    //可能好几段都是相同的。在前i项中查找是否有等于pre的项，并累加出现pre出现的次数
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
            sumdfs(nums,index+1,target,sum+nums[index],total); //选这个元素
            sumdfs(nums,index+1,target,sum-nums[index],total); //不选这个元素
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

     int findTargetSumWays__(vector<int>& nums, int target) {
       /*转化为01背包问题 */
       
       int sum=std::accumulate(nums.begin(),nums.end(),0);
       if(abs(sum)<abs(target))
            return 0;
        
        int i,j,n;
        n=nums.size();
     
        /*
        * left-right=target; left+right=sum; left=(sum+target)/2;
        */
        int temp=sum+target;
        if(temp%2)
            return 0;
        int s=(temp)/2; 

        //定义dp[i]: 装满容量为i的背包的总装法。
        vector<int> dp(s+1);
        dp[0]=1; //容量为0的背包 啥都不装  一种装法

        //遍历物品
        for(i=0;i<n;i++){
            //遍历背包
            for(j=s;j>=nums[i];j--)
                dp[j]+=dp[j-nums[i]];
                
        }

        return dp[s];

    }

    //更快解法
    int findTargetSumWays___(vector<int>& nums, int S) {
       /*转化为01背包问题 */
       int sum = 0;
       for (int i = 0; i < nums.size(); i++)
           sum += nums[i];
       if (abs(S) > abs(sum))
           return 0; // 此时没有⽅案
       if ((S + sum) % 2 == 1)
           return 0; // 此时没有⽅案
       int bagSize = (S + sum) / 2;
       vector<int> dp(bagSize + 1, 0);
       dp[0] = 1;
       for (int i = 0; i < nums.size(); i++)
       {
           for (int j = bagSize; j >= nums[i]; j--)
           {
               dp[j] += dp[j - nums[i]];
           }
       }
       return dp[bagSize];
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

    // 一维 0 1 背包
      bool canPartition_(vector<int>& nums) {
        int n=nums.size();
        int sum=std::accumulate(nums.begin(),nums.end(),0);

        if(sum%2)
            return false;
        int target=sum/2;

        //转化为0，1背包问题，target为当前背包容量
        int i,j;
        vector<int> dp(target+1);// dp[i] 表示容量为i的背包所获得的价值为dp[i]

        //遍历物品
        for(i=0;i<n;i++){
            //遍历背包容量
            for(j=target;j>=0;j--)
                if(j-nums[i]>=0)
                    dp[j]=max(dp[j],dp[j-nums[i]]+nums[i]);
            
            // 打印dp数组
            // for(auto &it:dp)
            //     cout<<it<<" ";
            // cout<<endl;
        }

        if(dp[target]==target)      
            return true;
        else
            return false;
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
                //equal_range返回一个key为curnum的表示迭代器范围的pair,两个迭代器分别指向第一个key为curnum的第一个迭代器和key为curnum的最后一个迭代器的下一个迭代器
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

    //另一种解法
     void backtrack(vector<vector<int>>&res,vector<int>& candidates,vector<int>&cur,int sum,int index,int target){
        if(index==candidates.size())//越界
            return;
        if(sum>target)
            return;
        if(sum==target){
            res.push_back(cur);
            return;
        }   
        for(int i=index;i<candidates.size();i++){
            cur.push_back(candidates[i]);
            sum+=candidates[i];
            backtrack(res,candidates,cur,sum,i,target);
            sum-=candidates[i];
            cur.pop_back();
        }
       
    }

    vector<vector<int>> combinationSumPlus(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(res,candidates,cur,0,0,target);
        return res;
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
    //优化
     int lengthOfLIS_(vector<int>& nums) {
        int res=1;
        int n=nums.size();
        if(n==1)
            return 1;
        vector<int> dp(n+1,1);   //dp[i]长度为i的数组的最长递增子序列
        for(int i=1;i<=n;i++){ //长度
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i-1]){
                    dp[i]=max(dp[j+1]+1,dp[i]);
                }
            }
           res=max(dp[i],res);
        }
        return res;
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
    // 二刷
    TreeNode * buildTree(vector<int>&preorder,vector<int>& inorder,int preLeft,int preRight,int inLeft,int inRight){

        if(preLeft<=preRight){
            TreeNode *root=new TreeNode(preorder[preLeft]);
             //初始化前序，中序遍历节点的左右边界
       
            //求中序中根节点下标
            int inRoot=inLeft;
            while(inorder[inRoot]!=preorder[preLeft]){
                inRoot++;
            }
            //左子树节点数
            int lenLeft=inRoot-inLeft;
            //右子树节点数
            int lenRight=inRight-inRoot;
             //建立左子树
            TreeNode *left=nullptr;
            if(lenLeft)
                left=buildTree(preorder,inorder,preLeft+1,preLeft+lenLeft,inLeft,inRoot-1);
            //建立右子树
            TreeNode *right=nullptr;
            if(lenRight)
                right=buildTree(preorder,inorder,preRight-lenRight+1,preRight,inRoot+1,inRight);
              //给根节点左右节点赋值并返回根节点
            root->left=left;
            root->right=right;
            return root;
        }
        else
            return nullptr;
    }


    /**
     * 106. 从中序与后序遍历序列构造二叉树
     * **/
    TreeNode* buildTree__(vector<int>& inorder, int inStart,int inEnd,vector<int>& postorder,int posStart, int posEnd) {
        //后序遍历的最后一个节点为根，在中序遍历中找到根，并计算左右子树长度。
        if(posStart<=posEnd){
            int root=postorder[posEnd];
            TreeNode *p=new TreeNode(root);

            //找中序中根节点下标
            int rootIndex=inStart;
            while(inorder[rootIndex]!=root) rootIndex++;

            int lenLeft=rootIndex-inStart;
            int lenRight=inEnd-rootIndex;

            //左子树
            p->left=buildTree__(inorder,inStart,rootIndex-1,postorder,posStart,posStart+lenLeft-1);

            //右子树
            p->right=buildTree__(inorder,rootIndex+1,inEnd,postorder,posEnd-lenRight,posEnd-1);

            return p;
        }
        return nullptr;
    }

    TreeNode* buildTreeP(vector<int>& inorder, vector<int>& postorder) {

        int n=inorder.size();
        return buildTree__(inorder,0,n-1,postorder,0,n-1);

    }

    /**
     * 1008. 前序遍历构造二叉搜索树
     * **/
     //传入先序遍历序列和范围
    TreeNode * bstFromPreorder(vector<int>&preorder,int leftPos,int rightPos){

        if(leftPos<=rightPos){
            TreeNode * root=new TreeNode(preorder[leftPos]);
            
            //找右子树起点
            int index=leftPos+1;
            while(index<=rightPos&&preorder[index]<preorder[leftPos])
                index++;
            
            //传入左右��树下标范围
            root->left=bstFromPreorder(preorder,leftPos+1,index-1);
            root->right=bstFromPreorder(preorder,index,rightPos);
            return root;
        }
        return nullptr;
    }


    TreeNode* bstFromPreorder(vector<int>& preorder) {
    
    //递归建树
    return bstFromPreorder(preorder,0,preorder.size()-1);

    }


    TreeNode* buildTree_(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size())
            return nullptr;
        
        //初始化前序，中序遍历节点的左右边界
        int preLeft=0,preRight=preorder.size()-1;
        int inLeft=0,inRight=inorder.size()-1;

        return buildTree(preorder,inorder,preLeft,preRight,inLeft,inRight);
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

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
    vector<vector<string>>& queries) {
       
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
     * 利用二叉搜索树性质的解法
     * **/
     TreeNode* lowestCommonAncestor_(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode*pWork=root;
        TreeNode *res=root;
        while(pWork){
            if(pWork->val>p->val&&pWork->val>q->val)
                pWork=pWork->left;
            else if(pWork->val<p->val&&pWork->val<q->val)
                pWork=pWork->right;
            else{
                res=pWork;
                break;
            } 
        }
        return res;
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
     * 回文子串
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

    // another solution  dynamic programme
    int countSubstrings_(string s) {

        int i,j;
        int num=0;
        int n=s.size();

        //dp[i][j]: s[i:j]是否为回文串
        
        vector<vector<bool>> dp(n,vector<bool>(n,false));

        for(i=0;i<n;i++)
            dp[i][i]=true;

        //从下往上遍历
        for(i=n-1;i>=0;i--){

            // 从左往右
            for(j=i;j<n;j++){
                if(s[i]==s[j]){
                    // 相差不超过1，子串长度为1或者2
                    if(j-i<=1){
                        dp[i][j]=true;
                        num++;
                    // 长度超过2
                    }else if(dp[i+1][j-1]){
                        num++;
                        dp[i][j]=true;
                    }
                }
            }
        }

        return num;
    }
    

    /**
     * 二叉搜索树与双向链表
     * **/
     Node* treeToDoublyList(Node* root) {
        if(!root)
            return root;
        Node * first=nullptr;
        Node * last=nullptr;
        Node * pNode=root;
        stack<Node*> Tree_nodes;
        while(!Tree_nodes.empty()||pNode){
            while(pNode){
                Tree_nodes.push(pNode);
                pNode=pNode->left;
            }
            if(!Tree_nodes.empty()){
                pNode=Tree_nodes.top();
                Tree_nodes.pop();
                if(last){
                    last->right=pNode;
                    pNode->left=last;
                }
                if(!first)
                    first=pNode;
                last=pNode;
                pNode=pNode->right;
            }
        }
        first->left=last;
        last->right=first;
        return first;
    }

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
         int n=nums.size();
        if(n==1)  
            return;
        int i=n-2;
        int j;
        //把左边一个较小的和右边一个较大的交换，同时左边较小的尽可能靠右，右边较大的尽可能小。
        //从右往左找第一个逆序对---左边较小的尽可能靠右
        while(i>=0&&nums[i]>=nums[i+1])
            i--;
        //找到后在左边较小的那个数右边的降序数字中找尽可能小的较大数
        if(i>=0){
            j=n-1;
            while(j>=i+1&&nums[j]<=nums[i])  
                j--;
            //找到后交换左边的较大数和右边的较小数
            swap(nums[j],nums[i]);
        }
        //从左到右为降序，则直接反转/
        reverse(nums.begin()+i+1,nums.end());
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
     * 一种比较好理解的解法
     * **/
    void sortColors_(vector<int>& nums) {
        int left=0,right=nums.size()-1,i=left;
    
        while(i<=right){
            //0 与左边界交换后，左边界增加
            if(nums[i]==0){
                swap(nums[i],nums[left++]);
                // 如果左边界本身为0，则i后移
                if(nums[i]==0)
                    i++;
            // 1直接跳过
            }else if(nums[i]==1)
                i++;
            else
            //交换后i不增加,防止交换后的是0
                swap(nums[i],nums[right--]);
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
     * 516. 最长回文子序列 1 遍历序列问题 2 字符相等与否的条件判断
     * **/
     int longestPalindromeSubseq(string s) {
        if(s.size()==1)
            return 1;
        int i,j;
        int size=s.size();
        // dp[i][j]: s[i:j]之间的最长子序列长度。
        vector<vector<int>> dp(size,vector<int>(size));

        // 从后往前遍历
        for(i=size-1;i>=0;i--){
            dp[i][i]=1;

            // 对于新的字符串依次与之前已经确定好的比较，确定dp[i][j]
            for(j=i+1;j<size;j++){

                //相等 子序列+2
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1]+2;
                
                //不相等，则缩小范围注意i是向右，j是向左。
                }else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][size-1];
    }

    /**
     * 多数元素
     * **/
    int majorityElement__(vector<int>& nums) {
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
     * 基于完全背包的方法
     * **/
     int climbStairs_(int n) {
        vector<int> dp(n+1); //dp[i]:装满容量为i的背包的方法数（爬楼梯数）,物品有2种可任意多次选择，直到装满背包---> 完全背包
        dp[0]=1;
        for(int j=1;j<=n;j++){ //遍历背包容量
            for(int i=1;i<=2;i++){ //遍历物品
                if(j>=i)
                    dp[j]+=dp[j-i];
            }  
        }
        return dp[n];
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
     * 无重复字符的最长子串
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
    //另外一个版本
     int lengthOfLongestSubstring_(string s) {
        if(s.size()<=1)
            return s.size();
        
        int ans=INT_MIN;
        int i=-1,j;
        int n=s.size();
        
        //存某一个字符距离当前遍历下标最近的下标
        map<char,int> occurs;
        int lastLen=1,curLen;
        occurs.insert({s[0],0});
        map<char,int>::iterator it;
        for(j=1;j<n;j++){
            it=occurs.find(s[j]);
            //找到
            if(it!=occurs.end()){
                i=occurs[s[j]];
                if(j-i<=lastLen)
                    curLen=j-i;
                else
                    curLen=lastLen+1;
            }
            else{
                curLen=lastLen+1;
            }
            //更新出现的下标
            lastLen=curLen;
            occurs[s[j]]=j;
            ans=max(ans,curLen);
        }

        return ans;
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

    //二刷
    //求二叉树所有节点的和
    int TreeNodeSum(TreeNode*root){
        if(!root)
            return 0;
        else return root->val+TreeNodeSum(root->left)+TreeNodeSum(root->right);
    }

    void findTilt(TreeNode*root,int &res){
        if(!root)
            return;
        int left=TreeNodeSum(root->left);
        int right=TreeNodeSum(root->right);
        res+=abs(left-right);
        findTilt(root->left,res);
        findTilt(root->right,res);
    }

    int findTilt(TreeNode* root) {
        int res=0;
        findTilt(root,res);
        return res;
    }

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

    int findTilt_(TreeNode* root) {
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
     * 16. 最接近的三数之和
     * **/
     int threeSumClosest(vector<int>& nums, int target) {

        //排序
        sort(nums.begin(),nums.end());

        int n=nums.size();

        int best=1e7;

        int i,left,right,sum,k;  

        //更新best
        auto update=[&](int cur){
            if(abs(cur-target)<abs(best-target))
                best=cur;
        };

        for(i=0;i<n;i++){
            left=i+1;
            right=n-1;
            while(left<right){
                sum=nums[i]+nums[left]+nums[right];
                update(sum);
                if(sum>target){
                    //过滤重复元素，去除多余比较    
                    k=right-1;
                    while(k>left&&nums[k]==nums[k+1])
                        k--;
                    right=k;

                }
                else if(sum<target){
                    //过滤重复元素，去除多余比较
                    k=left+1;
                    while(k<right&&nums[k]==nums[k-1])
                        k++;
                    left=k;
                }
                else 
                    return sum;
            }
        }
        return best;
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
    //通用解法
    int work(vector<int>& nums, int k) {
        int len = 0;
        for(auto num : nums)
            if(len < k || nums[len-k] != num)
                nums[len++] = num;
        return len;
    }
    int removeDuplicates_(vector<int>& nums) {
        return work(nums, 1);
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

    //len表示当前子集的大小
    void backTrackingSubsets(vector<vector<int>>&res,vector<int>&cur,int len,int startIndex,vector<int>&nums){
        if(cur.size()==len){
            res.push_back(cur);
            return;
        }
        if(startIndex==nums.size())
            return;
        for(int i=startIndex;i<nums.size();i++){
            cur.push_back(nums[i]);
            backTrackingSubsets(res,cur,len,i+1,nums);
            cur.pop_back();
        }
    }

    vector<vector<int>> subsets__(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        int i;
        for(i=0;i<=nums.size();i++){
            backTrackingSubsets(res,cur,i,0,nums);
        }
        return res;
    }


   
    //遍历整棵树
    void backTrackingAllTree(vector<vector<int>>&res,vector<int>&cur,int startIndex,vector<int>&nums){
        res.push_back(cur);
        if(startIndex==nums.size())
            return;
        for(int i=startIndex;i<nums.size();i++){
            cur.push_back(nums[i]);
            backTrackingAllTree(res,cur,i+1,nums);
            cur.pop_back();
        }
    }

    vector<vector<int>> subsets___(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur; 
        backTrackingAllTree(res,cur,0,nums);
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
     * 121. 买卖股票的最佳时机
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

    // 基于动态规划的算法
    int maxProfit__(vector<int>& prices) {
        
        //基于动态规划的算法
        int n=prices.size();
        if(n==1)
            return 0;
        //dp[n][0]: 第i天持有股票所获得的收益；dp[n][1]:第i天不持有股票所获得的收益
        vector<vector<int>> dp(2,vector<int>(2));
        dp[0][0]=-prices[0];
        dp[0][1]=0;
        for(int i=1;i<n;i++){

            // 第i天持有：max(第i-1天持有；第i-1天不持有，第i天买入);
            dp[1][0]=max(dp[0][0],-prices[i]);
            dp[0][0]=dp[1][0];

            // 第i天不持有：max(第i-1天不持有;第i-1天持有，第i天卖出)
            dp[1][1]=max(dp[0][1],dp[0][0]+prices[i]);
            dp[0][1]=dp[1][1];
        }
        return max(dp[1][0],dp[1][1]);
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


    /**
     * 57. 插入区间
     * **/
     

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        vector<vector<int>> merged=merge(intervals);
        return merged;
    }

    /**
     * 剑指 Offer 14- II. 剪绳子 II
     * **/
     int cuttingRope_II(int n) {
        if(n<=3)
            return n-1;

        long long res=1;
        int temp=1e9+7;
        while(n>4){
            res*=3;
            res=res%temp;
            n-=3;
        }
        return res*n%temp;
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
    //leetcode
    int cuttingRope(int n) {
        vector<int> dp(n+1);  
        dp[1]=1;
        dp[2]=1;
        if(n<=2)
            return dp[n];
        else{
            for(int i=3;i<=n;i++){
                for(int j=2;j<i;j++){
                    //剪下长度为j的，剩下的长度为i-j,可以选择继续剪dp[i-j]或者不剪(i-j)
                    dp[i]=max(dp[i],max(dp[i-j]*j,j*(i-j)));
                }
            }
        }
        return dp[n];
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

    //"20 000 000 000 000 000 000"
    //"-91 283 472 332"
    //1 283 472 332
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

    int movingCount_(int threshold, int rows, int cols)
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

    int getCoordinateSum(int x){
       int sum=0;
       while(x){
           sum+=x%10;
           x/=10;
       }
       return sum;
   }


    void movingCount(int i,int j,int &count,int m,int n,vector<vector<int>>&visited,int k){
         if(0<=i&&i<m&&0<=j&&j<n&&!visited[i][j]){
            visited[i][j]=1;
            //当前能走，才能继续往下走
            if((getCoordinateSum(i)+getCoordinateSum(j))<=k){
                count++;
                movingCount(i+1,j,count,m,n,visited,k);
                movingCount(i-1,j,count,m,n,visited,k);
                movingCount(i,j-1,count,m,n,visited,k);
                movingCount(i,j+1,count,m,n,visited,k);
            }
            else
                return;
        }
    }

    int movingCount(int m, int n, int k) {
        int count=0;
        vector<vector<int>> visited(m,vector<int>(n));
        movingCount(0,0,count,m,n,visited,k);
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

    //leetcode 
      bool dfsMatrix(vector<vector<char>>& board,int i,int j,int cur,string &word){
        int row=board.size();
        int column=board[0].size();
        if(i<0||j<0||i>=row||j>=column||board[i][j]!=word[cur])
            return false;
        if(cur==word.size()-1){
            return true;
        }
      
        board[i][j]='\0';
        bool res=dfsMatrix(board,i+1,j,cur+1,word)||dfsMatrix(board,i-1,j,cur+1,word)||dfsMatrix(board,i,j+1,cur+1,word)||dfsMatrix(board,i,j-1,cur+1,word);
        board[i][j]=word[cur];
        return res;
    }
    

    bool exist_(vector<vector<char>>& board, string word) {
        int row=board.size();
        int column=board[0].size();

        int i,j;
        for(i=0;i<row;i++)
            for(j=0;j<column;j++){
                if(dfsMatrix(board,i,j,0,word))
                    return true;
            }
        return false;
    }

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



//设定4字节对齐
#pragma pack(push)
#pragma pack(4)

struct test{
    char m1;
    double m4;
    int m3;
};



//测试类的public成员类外可访问可改变
class PublicClass{
    public:

        PublicClass(int a_,int b_,int c_):a(a_),b(b_),c(c_){}
        int a;
        int b;

    private:
        int c;
};




int main()
{
    Solution slu;    
    int i=1;
    for(int j=0;j<10;j++)  
        cout<<rand()%(i+1)<<endl;
    typedef char MacBytes[6];

    cout<<"sizeof(MacBytes)"<<sizeof(MacBytes)<<endl;

    return 0;
}

#pragma pack(pop)

    /*  
    cout<<"sizeof(int): "<<sizeof(int)<<endl;
    cout<<sizeof(struct int_)<<endl;*、
    /*
    int a[10];
    for(int i=0;i<10;i++)
        a[i]=10-i;
    //最后一个元素的下一个位置
    sort(a,a+10);
    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    */
    /**
     * 分割链表
     * **/

    /**
     * 77. 组合
     * **/
    /*
    Solution slu;
    int n=10;
    int k=5;
    vector<vector<int>> res=slu.combine(n,k);
    cout<<"size: "<<res.size()<<endl;
    cout<<endl;
    */
   /**
    * 测试字符转整数
    * **/
   /*char c='a';
   cout<<int(c)<<endl;*/
    // cout<<"哈哈哈"<<endl;


    /**
     * 字符串常量
     * **/
    // char * a="abc";
    // printf("%s\n",a);
    // a[1]='b';

    /**
     * 类的大小
     * **/
    // cout<<sizeof(A)<<endl;

    /**
     * 列表初始化
     * **/
    /*
    vector<int> input={1,3,5,6,7,8};
    for(auto &it:input)
        cout<<it<<endl;
    */


    /**
     * LFU 使用
     * **/
    /*
    LFUCache* obj=nullptr;
    vector<string> operation{"LFUCache","put","put","get","put","get","get","put","get","get","get"};
    vector<string> input{"[2]","[1,1]","[2,2]","[1]","[3,3]","[2]","[3]","[4,4]","[1]","[3]","[4]"};
    for(int i=0;i<operation.size();i++){
       if(operation[i]=="LFUCache"){
            int len=input[i].length();
            int capacity=std::stoi(input[0].substr(1,len-2));
            cout<<"capacity: "<<capacity<<endl;
            obj= new LFUCache(capacity);
       }
       else if(operation[i]=="put"){
           int len=input[i].size();
           std::size_t delimiter=input[i].find(',');
           int key=std::stoi(input[i].substr(1,delimiter-1));
           int value=std::stoi(input[i].substr(delimiter+1,len-delimiter-1));
           cout<<"put: "<<key<<" "<<value<<endl;
           obj->put(key,value);

           for(auto&it:obj->freqNodeList){
                cout<<"freq: "<<it.first;
                for( LFUCache::Node * h=it.second;h;h=h->next)
                    cout<<" value: "<<h->value;
                cout<<endl;
           }
           for(auto &it:obj->freqNodeListTail){
                cout<<"freq: "<<it.first;
                cout<<" NodeAdderss: "<<it.second<<endl;
           }

       }
       else{
            int len=input[i].length();
            int key=std::stoi(input[i].substr(1,len-2));
            cout<<"get: "<<key<<endl;
            int value=obj->get(key);
            cout<<"value: "<<value<<endl;
       }
    }
    */

    // string input="0";
    // string input2="00";
    // string input3="123";
    // for(int i=0;i<input3.size();i++){
    //     input3[i]-=2;
    // }
    // cout<<input3<<endl;
    // bool res=(input2=="0");
    // cout<<res<<endl;

    // char input[]={'0','e',' '};
    // Solution slu;
    // bool res=slu.isNumber(input);
    // cout<<res<<endl;

    // cout<<sizeof(long)<<endl;
    // cout<<sizeof(int)<<endl;



    /*
    vector<vector<int>> input={{1,2},{2,3},{5},{0},{5},{},{}};
     Solution slu;
    vector<int> res=slu.eventualSafeNodes_(input);
    for(auto &it:res)
        cout<<it<<endl;
    */
    
    // int n=input.size();
    // cout<<*(input.begin()+n-1)<<endl;
    // int sum=500;

    // int res=slu.movingCount(16,8,4);
    
    // cout<<res<<endl;

    // set<int> test;

    // test.insert(1);
    // test.insert(2);
    // test.insert(3);
    // set<int>::iterator it=test.begin();
    // cout<<*it<<endl;


    // int a=-123;
    // string str=std::to_string(a);
    // cout<<str<<endl;

    

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

