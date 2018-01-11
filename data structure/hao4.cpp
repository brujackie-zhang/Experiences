#include <iostream>  
#include <list>  
using namespace std;  
list<int> list1;  
void find_factor(int sum,int n)  
{  
    //递归出口  
    if(n<=0||sum<=0)  
        return;  
    //输出找到的数  
    if(sum==n)  
    {  
        list1.reverse();  
        for(list<int>::iterator iter=list1.begin();iter!=list1.end();iter++)  
            cout<<*iter<<"+";  
        cout<<n<<endl;  
        list1.reverse();  
    }  
    list1.push_front(n);  
    find_factor(sum-n,n-1);//n放在里面  
    list1.pop_front();  
    find_factor(sum,n-1);//n不放在里面  
}  
  
int main(void)  
{  
    int sum,n;  
    cin>>sum>>n;  
    cout<<"所有可能的序列，如下："<<endl;  
    find_factor(sum,n);  
    return 0;  
}