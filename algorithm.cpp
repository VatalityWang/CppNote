#include<vector>
#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
using std::vector;
using std::cout;
using std::endl;

class Algorithm
{
    public:

        //调整堆
        void buildMinHeap(vector<int>&elements,int i){
            int smaller;
            int l=2*i;
            int r=2*i+1;
            int n=elements.size();
            
            if(l<n&&elements[i]>elements[l]){
               smaller=l;
            }
            else
                smaller=i;
            if(r<n&&elements[r]<elements[smaller]){
                smaller=r;
            }
            if(smaller!=i){
                swap(elements[i],elements[smaller]);
                buildMinHeap(elements,smaller);
            }
        }

        //堆排序
        vector<int> heapSort(vector<int>&input){
            vector<int> res;
            int n=input.size();
            int i;
            for(i=n/2;i>=0;i--){
                buildMinHeap(input,i);
            }
            for(i=input.size()-1;i>=0;i--){
                res.push_back(input[0]);
                swap(input[0],input[i]);
                input.erase(input.end()-1);
                buildMinHeap(input,0);
            }
            return res;
        }

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

        int position(vector<int> &input,int i,int j){
                int divide=input[j];
                int low=i,high=j-1;
                while(low<=high){
                    while(high>=low&&input[high]>=divide){high--;}
                    while(low<=high&&input[low]<=divide){low++;}
                    if(low<high)
                        swap(input[high],input[low]);
                }
                swap(input[low],input[j]);
                printf("divide pos %d\n",low);
                return low; 
        }

        //双轴
        void quick_sort(vector<int>& input,int low,int high){
            if(low<high){
                int div=position(input,low,high);
                printf("after divide\n");
                for(int j=0;j<input.size();j++)
                    cout<<input[j]<<" ";
                cout<<endl;
                quick_sort(input,low,div-1);
                quick_sort(input,div+1,high);
            }
        }
        
};


int main()
{
    Algorithm alg;
    vector<int> input{7,3,2,10,8,1,9,9,5,4,6};

    for(int j=0;j<input.size();j++)
        cout<<input[j]<<" ";
    cout<<endl;
    
   vector<int> res=alg.heapSort(input);
    
    for(auto &it:res)
        cout<<it<<" ";
    cout<<endl;
    // alg.mergesort(input,0,input.size()-1);


    /**
     * 快速排序
     * **/
    /*alg.quick_sort(input,0,input.size()-1);
    for(int j=0;j<input.size();j++)
        cout<<input[j]<<" ";
    cout<<endl;
    */
    return 0;
    // system("pause");
}