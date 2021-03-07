#include<vector>
#include<iostream>
using std::vector;
using std::cout;
using std::endl;

class Algorithm
{
    public:
        void  merge(vector<int>&input,int p,int q,int r)
        {
            vector<int> temp;
            temp.clear();
            int i=p,j=q+1;
            while(i<=q&&j<=r)
            {
                if(input[i]>input[j])
                    temp.push_back(input[j++]);
                else
                    temp.push_back(input[i++]);
            }
            while (i<=q)
            {
                temp.push_back(input[i++]);
            }
            while(j<=q)
            {
                temp.push_back(input[j++]);
            }
            i=p,j=0;
            while(j<temp.size())
                input[i++]=temp[j++];
            temp.clear();
            temp.shrink_to_fit();//释放内存
            return;
        }

        void mergesort(vector<int>&input,int low,int high)
        {
            if(low<high)
            {
                int mid=(low+high)/2;
                mergesort(input,low,mid);
                mergesort(input,mid+1,high);
                merge(input,low,mid,high);
            }

        }

        
};


int main()
{
    Algorithm alg;
    vector<int> input;
    for(int i=0;i<10;i++)
    {
        input.push_back(10-i);
    }
     for(int j=0;j<input.size();j++)
        cout<<input[j]<<endl;
    alg.mergesort(input,0,input.size()-1);
    for(int j=0;j<input.size();j++)
        cout<<input[j]<<endl;
    return 0;
    // system("pause");
}