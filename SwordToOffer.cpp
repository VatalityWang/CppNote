#include<vector>
#include <iostream>
using namespace ::std;
using std::cout;
using std::endl;
using std::vector;
/*
*1-1  输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序 
*/

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum)
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
int main()
{
    //
    //  1-1
    //
    Solution solu;
    vector<vector<int>> res;
    res=solu.FindContinuousSequence(9);
    for(auto it:res)
        for (auto im:it)
            cout<<im<<endl;
    return 0;
}