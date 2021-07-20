/**
 * 合并表记录
 * **/
#include<iostream>

#include<map>

using namespace std;

int main(){
    map<int, int> iimap;
    int key, value, num;
    cin >> num;
    while (num-- && cin >> key >> value)
        iimap[key] += value; //不存在的时候默认是0，存在则累加
    for (auto beg = iimap.begin(); beg != iimap.end(); ++beg)
        cout << beg->first << " " << beg->second << endl;
    return 0;      
}