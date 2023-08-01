#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
#include<unordered_map>
using namespace std;

template<class K, class V>
using hashmap = std::unordered_map<K, V>;
int main()
{
    hashmap<int,string> m = {{1,"张三"},{2,"李四"},{3,"王五"},{4,"赵六"},{5,"田七"},{6,"王八"},{7,"王九"},{8,"王十"}};
    m.max_load_factor(1);
     for(int i=0;i<m.bucket_count();i++){
        cout<<"第"<<i<<"桶"<<":";
        for(auto it=m.begin(i);it != m.end(i);it++){
            cout<<it->first<<" "<<it->second<<endl;
        }
        cout<<endl;
     }
    cout<<endl;
    return 0;
}
