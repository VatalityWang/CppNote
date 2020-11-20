#include<vector>
#include <iostream>
#include<string>
#include<stack>
#include<algorithm>
#include<numeric>
using namespace ::std;
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
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
};


#if 1
int main()
{
    //
    //  1-1
    //

    Solution solu;
    string words="student a am i";
    vector<int> Cards={0,0,1,4,6};
    bool res=solu.IsContinuous(Cards);
    cout<<res<<endl;
    // string ReverseWords=solu.ReverseSentence(words);
    // cout<<ReverseWords<<endl;


    #if 0

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
    return 0;
}
#endif