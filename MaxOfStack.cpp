#include<iostream>
#include<stack>
using namespace std;
int main(void)
{
    int ele[] = {4,6,7,4,3,4,5,6,6,7,1,9,3};
    int ele_count, now_max;
    stack<int> s_max;
    stack<int> s_ele;

    ele_count = sizeof(ele)/sizeof(int);
    for(int i=0;i<ele_count;i++){
        if(s_ele.empty()){
            now_max = ele[i];
            s_ele.push(ele[i]);
            s_max.push(ele[i]);
            cout<<"push "<<ele[i]<<" now max "<< now_max<<endl;
            continue;
        }
        s_ele.push(ele[i]);
        if(ele[i]>=now_max){
            s_max.push(ele[i]);
            now_max = ele[i];
            cout<<"push "<<ele[i]<<" new max "<< ele[i]<<endl;
        }else{
            cout<<"push "<<ele[i]<<" old max "<< now_max<<endl;
        }
    }
    cout<<"========"<<endl;
    while(!s_ele.empty()){
        now_max = s_max.top();
        if(s_ele.top()==now_max){
            s_max.pop();
        }
        cout<<"pop  "<<s_ele.top()<<" now max "<< now_max<<endl;
        s_ele.pop();
    }
    return 0;
}
