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
class Solution {
public:
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
    return 0;
}