#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <numeric>
#include <map>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include<cmath>
#include<sstream>
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
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
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



class Solution
{
public:


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
    vector<vector<int>> Print(TreeNode *pRoot)
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

#if 1

int main()
{

   
    // vector<int> input={30,0};
    int a[9]={5,8,9,6,7,1,3,2,4};
    int b[9]={1,2,3,4,5,6,7,8,9};
   


    Solution slu;
    vector<string> input{"321","32","321"};
    string res=slu.formMaxNumber(input);
    cout<<res<<endl;
    return 0;

#if 0


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