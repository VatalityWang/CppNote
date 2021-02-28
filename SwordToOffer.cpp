#include<vector>
#include <iostream>
#include<string>
#include<stack>
#include<algorithm>
#include<numeric>
#include<map>
#include<cstring>
#include<set>
#include<queue>
#include<deque>
using namespace ::std;
using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::string;

static int list_node_val[]={8,6,5,-1,-1,7,-1,-1,6,7,-1,-1,5,-1,-1};
static int counter=0;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};



struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
    }
};


class Solution {
public:

    /*
    * 机器人的运动范围
    * */
   int getnumsum(int num)
   {
       int sum=0;
       while (num)
       {
           sum+=num%10;
           num/=10;
       }
       return sum;
   }

    bool judge(int threshold,int row,int col)
    {
        if(getnumsum(row)+getnumsum(col)>threshold)
            return false;
        else
            return true;
    }
    void through_path(int threshold,int *memory,int i,int j,int rows,int cols)
    {
        if(i<0||j<0||i>rows-1||j>cols-1)//越界
            return;
        int index=i*cols+j;
        if(!judge(threshold,i,j)) //不能走
            return;
        if(memory[index]) //能走但已走过
            return;
        else
            memory[index]=1;
        through_path(threshold,memory,i-1,j,rows,cols);
        through_path(threshold,memory,i+1,j,rows,cols);
        through_path(threshold,memory,i,j+1,rows,cols);
        through_path(threshold,memory,i,j-1,rows,cols);
    }

    int movingCount(int threshold, int rows, int cols) 
    {
        int count=0;
        int i,j;
        int total=rows*cols;
        int* memory=new int[total];
        through_path(threshold,memory,0,0,rows,cols);
        for(i=0;i<total;i++)
            if(memory[i])
                count++;
        return count;
    }


    /*
    * 矩阵中的路径
    * */
    void  matrix(string )
    {

    }

    bool hasPath(string matrix, int rows, int cols, string str) 
    {
        int i,j,k,next;
        int direction[4]={1,2,3,4};   //1,2,3,4分别代表左，上，右，下。
        string path;
      
        for(k=0;k<matrix.size();k++)
        {
            if(matrix[k]==str[0])
            {

                i=k/cols;   //行
                j=k%cols;   //列
                path+=matrix[k];
                for(int m=0;m<4;m++)
                {
                    
                    switch (direction[m])
                    {
                    case 1:
                        next=(--j)+i*cols;
                        if(matrix[next]==str[path.size()])
                            path+=matrix[next];
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    default:
                        break;
                    }
                }
            }
            else
                continue;
            

            
        }
        
                
    }

    /*
    *  滑动窗口最大值 
    */
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) 
    {
        int start,end,i;
        vector<int> res;
        vector<int> temp;
        temp.clear();
        res.clear();
        start=0;
        end=start+size-1;
        while(end<num.size())
        {
            i=start;
            while(i<=end)
            {
                temp.push_back(num[i]);
                i++;
            }
            sort(temp.begin(),temp.end());
            res.push_back(temp[temp.size()-1]);
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
        sort(data.begin(),data.end());
        int length=data.size();
        if(length%2)
            return data[length/2];
        else
            return (data[length/2]+data[length/2-1])/2.0;
    }


    /*
    * 求二叉搜索树第k小的节点
    * **/
    TreeNode* midorder(TreeNode*pRoot,int k,int *num)
    {
        if(!pRoot)
            return NULL;
        TreeNode*left=NULL;
        TreeNode*right=NULL;
        left=midorder(pRoot->left,k,num);
        if(left)
            return left;
        (*num)++;
        if((*num)==k)
            return pRoot;
        right=midorder(pRoot->right,k,num);
        if(right)
            return right;
        else 
            return NULL;
    }

     TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        int m=0;
        return midorder(pRoot,k,&m);
        
    }


    /*
    * 序列化二叉树
    **/

   void preorder(TreeNode*root,string&str)
   {
       if(!root)
       {
            str+='#';
            return;
       }
       str+=to_string(root->val);
       str+=',';
       preorder(root->left,str);
       preorder(root->right,str);

   }

   char* Serialize(TreeNode *root) 
    {    
        if(!root)
            return NULL;
        string str;
        preorder(root,str);
        char * serialize_res=new char[str.size()+1];
        int i=0;
        while(i<str.size())
        {
            serialize_res[i]=str[i];
            i++;
        }
        serialize_res[i]='\0';
        return serialize_res;
    }


    TreeNode* deserialize(char **str)
    {
        TreeNode*root=NULL;
        if(**str=='#')
        {
            (*str)++;
            return root;
        }
        int num=0;
        while(**str!='\0'&&**str!=',')
        {
            num=num*10+((**str)-'0');
            (*str)++;
        }
        root=new TreeNode(num);
        if(**str=='\0')
            return root;
        else
            (*str)++;
        root->left=deserialize(str);
        root->right=deserialize(str);
        return root;
    }

    TreeNode* Deserialize(char *str) 
    {
        TreeNode*root=NULL;
        if(!str)
            return root;
        root= deserialize(&str);
        return root;
    }



    /*
    * 按行打印二叉树
    * */
    vector<vector<int> > Print(TreeNode* pRoot) 
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

   bool isSymmetrical(TreeNode *pRoot) {
		if (pRoot == NULL) 
			return true;

		return f(pRoot->left,pRoot->right);
	}
	
	bool f(TreeNode *t1, TreeNode *t2) {
		if (t1 == NULL && t2 == NULL) 
			return true;
		
		if (t1 != NULL && t2 != NULL) 
			return t1->val == t2->val && f(t1->left,t2->right) && f(t1->right, t2->left);
		
		return false;
	}



    bool isSymmetrical_(TreeNode* pRoot)
    {
        TreeNode*pTemp,*pLeft,*pRight;
        deque<TreeNode*> tree_queue;
        deque<TreeNode*> tree_queue_copy;
        tree_queue.clear();
        tree_queue_copy.clear();
        // deque<TreeNode*> tree_temp;
        if(!pRoot)
            return true;
        if(!pRoot->left&&!pRoot->right)
            return true;
        tree_queue.push_front(pRoot);
        while(!tree_queue.empty())
        {
            while(!tree_queue.empty())
            {
                pTemp=tree_queue.front();
                tree_queue.pop_front();
                if(pTemp->left)
                    tree_queue_copy.push_front(pTemp->left);
                if(pTemp->right)
                    tree_queue_copy.push_front(pTemp->right);
            }
            if(!tree_queue_copy.empty())
            std::copy(tree_queue_copy.begin(),tree_queue_copy.end(),std::back_inserter(tree_queue));
            // tree_queue.clear();
            while(!tree_queue_copy.empty())
            {
                pLeft=tree_queue_copy.front();
                pRight=tree_queue_copy.back();
                if(pLeft->val==pRight->val)
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
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
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
     ListNode* deleteDuplication(ListNode* pHead)
    {
       if(!pHead||pHead->next==NULL)
            return pHead;
       ListNode*ppre,*pre,*pwork,*pnext;
       ppre= (struct ListNode *)malloc(sizeof(struct ListNode));
       ppre->next=pHead;
       pre=ppre;
       pnext=NULL;
       pwork=pHead;
       while (pwork&&pwork->next)
       {
           pnext=pwork->next;
           if(pwork->val==pnext->val)
           {

           while(pnext&&pnext->val==pwork->val)
                pnext=pnext->next;
            pre->next=pnext;
            pwork=pnext;
           }
           
           else
           {
               pre=pwork;
               pwork=pwork->next;
           }
            
       }

       return ppre->next;
      
    }

    /*
    * 链表中环的入口地址
    * */
     ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode*p=pHead;
        if(!pHead)
            return NULL;
        set<ListNode*> node_list;
        set<ListNode*>::iterator it;
        while(p)
        {
            node_list.insert(p);
            it=node_list.find(p->next);
            if(it!=node_list.end())
            {
                return p->next;
            }
            else
            {
                p=p->next;
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
        vector<char>::iterator it=find(char_set.begin(),char_set.end(),ch);
        if(it==char_set.end())
            char_set.push_back(ch);
        if(static_count.find(ch)==static_count.end())
        {
            static_count.insert({ch,1});   
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
        for(auto &it:char_set)
            if(static_count[it]==1)
                return it;
        return '#';
    }



    /*
    * 表示数值的字符串
    **/
     bool isNumeric(char* string)
    {
        /*
        
        只有一个e/E;                 
        不能出现除E/e以外的任何字符；
        e/E后面跟数字，数字可以有符号,但不能有小数点；
        只有一个小数点；
        正负号只能出现在e/E后面或者首位

        */
        char *pstr=string;
        if(!pstr)
            return false;
        if(!strlen(pstr))
            return false;
        int i,j;
        int decimal_point=0;
        int character_e=0;
        int sign=0;
        for(i=0;i<strlen(pstr);i++)
        {
            if(pstr[i]=='+'||pstr[i]=='-')
            {
                sign++;

                if(sign>2)
                    return false;
                if(character_e==1)
                {
                    if(i!=0&&(pstr[i-1]!='e'&&pstr[i-1]!='E'))
                        return false;
                }
                else
                {
                    if(i!=0)//不出现在首位又没有e/E
                        return false;
                }
                
              
                
                
            }
            else if(pstr[i]=='e'||pstr[i]=='E')
            {
                character_e++;
                if(character_e>1)
                    return false;
                if(i==0)  //出现在首位
                    return false;
                else
                {
                    if(!(pstr[i-1]>='0'&&pstr[i-1]<='9'))
                        return false;
                    if(i+1==strlen(pstr))  //出现在末位
                        return false;
                }
            }
            else if(pstr[i]=='.')
            {
                decimal_point++;
                if(decimal_point>1)
                    return false;
                if(i==0)
                    return false;
                else
                {
                    if(i+1==strlen(pstr))
                        return false;
                    if(!(pstr[i+1]>='0'&&pstr[i+1]<='9'))
                        return false;
                    if (character_e==1)
                        return false;
                }
            }
            else if(pstr[i]>='0'&&pstr[i]<='9')
                continue;
            else 
                return false;
        }
        return true;
    }


    
    /*
    * 正则表达式匹配
    * */
     bool match(char* str, char* pattern)
    {
        int i=0,j=0;
        int len1=strlen(str);
        int len2=strlen(pattern);
        if(len2==0)
        {
            if(!len1)
                return true;
            else
                return false;
        }
        if(pattern[1]=='*')
        {
            if((str[0]!='\0'&&pattern[0]=='.')||str[0]==pattern[0])
                return match(str,pattern+2)||match(str+1,pattern);
            else
                return match(str,pattern+2);
        }
        else
        {
            if((str[0]!='\0'&&pattern[0]=='.')||str[0]==pattern[0])
                return match(str+1,pattern+1);
            else
                return false;
            
        }
    }
    /*
    * 构建乘积数组
    **/
     vector<int> multiply(const vector<int>& A)
    {
        vector<int> res;
        res.clear();
        if(A.size()<=1)
            return res;
        int MultiplySum=1;
        int i;
        for(i=0;i<A.size();i++)
        if(i==0)
            res.push_back(MultiplySum);
        else
            res.push_back(MultiplySum*=A[i-1]);
        for(i=A.size()-1;i>=0;i--)
        if(i==A.size()-1)
            MultiplySum=1;
        else
        {
            MultiplySum*=A[i+1];
            res[i]*=MultiplySum;
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
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length<=1)
            return false;
        map<int,int>NumCount;
        int i=0;
        for(i=0;i<length;i++)
            if(NumCount.find(numbers[i])==NumCount.end())
                NumCount.insert({numbers[i],1});
            else
            {
                NumCount[numbers[i]]++;
            }
           for(i=0;i<length;i++)
                if(NumCount[numbers[i]]>1)
                {
                    *duplication=numbers[i];
                    return true;
                }
        return false;
    }

    /*
    * 把字符串转换成整数；输入一个字符串,包括数字字母符号,可以为空；如果是合法的数值表达则返回该数字，否则返回0。
    * **/
   int StrToInt(string str) 
   {
       int i,res=0,carrynum,carry,j;
       carry=1;
       if(str[0]=='+'||str[0]=='-'||(str[0]>='0'&&str[0]<='9'))
       {
           for(i=str.size()-1;i>=0;i--)
           {
               carrynum=str.size()-1-i;
               while(carrynum)
               {
                   carry*=10;
                   carrynum--;
               }
               
               if(str[i]>='0'&&str[i]<='9')
               {
                   res+=(str[i]-48)*carry;
               }
               else if(i!=0)
               {
                   return 0;
               }
               else 
               {
                   if(str[i]=='+')
                        return res;
                    else if(str[i]=='-')
                        return -res;
               }
            //    printf("handle %c,carry %d res %d\n",str[i],carry,res);
               carry=1;
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
        int Add=num1^num2;  //异或 相当于按位相加
        int Carry=(num1&num2)<<1; //进位
        while (Carry)
        {
             num2=Add;
             num1=Carry;
             Add=num1^num2;
             Carry=(num1&num2)<<1;

        }
        return Add;
    }
    /*
    *  求1+2+3+...+n 要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
    * */

    int Sum_Solution(int n) {
        if(n==1)
         return  1;
        else
        {
            return n+Sum_Solution(n-1);
        }
        
    }

    /*
    *  圆圈中最后剩下的数
    */
    int LastRemaining_Solution(int n, int m)  //n个人，从第一个开始，第m个出列。返回最后一个剩下的人
    {
        if (n==1)
            return 0;
        if(n==0)
            return -1;
        vector<int> People;
        int i,WorkIndex;
        for(i=0;i<n;i++)
            People.push_back(1);
        int start=0,countnum,j;
        while(count(People.begin(),People.end(),1)!=1)
        {
            printf("remain count :%ld\n",count(People.begin(),People.end(),1));
            j=start;
            countnum=0;
            while( countnum<m)
            {
                if(People[j])
                {
                    countnum++;
                    if(countnum==m)
                    {
                        People[j]=0;
                        printf("label %d to zero\n",j);
                    }
                    else
                        j++;
                }
                else
                {
                    j++;
                }
                if(j==People.size())
                    j=0;
            }
            while (!People[(j+1)%n])
            {
                j=(j+1)%n;
            }
            start=(j+1)%n;
            printf(" the new start is %d\n",start);
        }
        WorkIndex=find(People.begin(),People.end(),1)-People.begin();
        return WorkIndex;
    }

    /**
    * 扑克牌顺子
    * */
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.size()==0)
            return false;
        vector<int> SubNum;
        SubNum.clear();
        int ZeroNum=0;
        int i;
        sort(numbers.begin(),numbers.end());
        vector<int>::iterator im;
        for(i=0;i!=numbers.size();i++)
        {
            if (numbers[i]==0)
                ZeroNum++;
            else if(i>1&&numbers[i-1])
            {
               SubNum.push_back(numbers[i]-numbers[i-1]);
            }
        }
        if(ZeroNum==4)
            return true;
        else
        {
            if(accumulate(SubNum.begin(),SubNum.end(),0)-SubNum.size()==ZeroNum)
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
      string ReverseSentence(string str) {
        stack <string> InternalWords;
        string delimiter=" ";
        string ResStr="";
        string token;
        size_t pos=0;
        while ((pos=str.find(delimiter))!=string::npos)
        {
            token=str.substr(0,pos);
            cout<<token<<endl;
            InternalWords.push(token);
            str.erase(0,pos+delimiter.length());
        }
        cout<<str<<endl;
        InternalWords.push(str);
        while(!InternalWords.empty())
        {
            ResStr+=InternalWords.top();
            InternalWords.pop();
            if(!InternalWords.empty())
                ResStr+=" ";
        }
        return ResStr;
    }

    /**
    * 左旋转字符串
    **/
   string LeftRotateString(string str, int n)
    {
        if(str.size()==0)
            return  str;
        if(n==str.size())     
            return str;
        else if(n>str.size())
            n=n-str.size();
        string TempStr1=str.substr(0,n);
        string TempStr2=str.substr(n,str.size()-n);
        return TempStr2+TempStr1;
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
        int i,start,end,Temp1,Temp2,Mid,Remainder;
        end=array.size()-1;
         for(i=0;i<array.size();i++)
         {
            start=i+1;
            // printf("handle the index %d\n ",i);
            Remainder=sum-array[i];
            while(start<=end)
            {
                
                Mid=(start+end)/2;
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
                    start=start+1;
                }
            }
        }
        if (TotalResult.size() == 1)
            return TotalResult[0];
        else if(TotalResult.size()>1)
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
        int i,j;
        int tempsum=0;
        vector<vector<int>> result;
        vector<int> temp_order;
        int num=0;
        for(i=1;i<=sum/2+1;i++)
        {
           tempsum+=i;
           num+=1;
           if(num>=2&&tempsum==sum)
           {
               for(j=i-num+1;j<=i;j++)
                   temp_order.push_back(j);
               result.push_back(temp_order);
               temp_order.clear();
               i=i-num+1;
               num=0;
               tempsum=0;
           }
           if(tempsum>sum)
           {
               i=i-num+1;
               tempsum=0;
               num=0;
           }
        }
        return result;
    }

private:
    map<char,int> static_count;
    vector<char> char_set;
    vector<int> data;
};

/*
* 输入序列建立二叉树
**/
TreeNode* CreateBTree(TreeNode *bt)
{
    int val=list_node_val[counter++];
    printf("counter %d\n",counter);
    if(counter>16)
        return NULL;
    // fflush(stdin);
    // printf("please input val:\n");
    // scanf("%d",&val);
    // fflush(stdin);
    if(val!=-1)
    {
      
        bt=new TreeNode(val);
        bt->left=CreateBTree(bt->left);
        bt->right=CreateBTree(bt->right);
        return bt;
    }
    else
    // cout<<"current node pointer "<<bt<<endl;
        return NULL;
}

void travserse_tree(TreeNode *root)
{
    if(root)
    {
        printf("%d\n",root->val);
        travserse_tree(root->left);
        travserse_tree(root->right);
    }
    else
        return;
    
}

#if 1

int main()
{

    /*
    * 创建二叉树
    ***/
    // int list_node_val[7]={8,6,9,5,7,7,5};
    // TreeNode *root=NULL;
    // root=CreateBTree(root);
    // travserse_tree(root);

  

    // Solution solu;
    // bool res=solu.isSymmetrical(root);
    // cout<<"isSymmetrical "<<res<<endl; 

    // int i=0,j=0;
    // while(j<20)
    // {
    //     j++;
    //     cout<<"j "<<j<<endl;
    //     while(i<10)
    //     {
    //         i++;
    //         if(i<5)
    //             continue;
    //         cout<<"i "<<i<<endl;
    //     }
    // }

    return 0;
    
    




    #if 0
    /*
    * 创建链表
    * */
    int list_node_val[8]={1,2,3,3,4,4,5};
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