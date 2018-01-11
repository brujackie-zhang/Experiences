#include<string>  
#include<vector>  
#include<stdlib.h>  
#include<iostream>  
  
using namespace std;  
   
typedef struct BiNode  
{  
    char data; 
    struct BiNode * lchild; 
    struct BiNode * rchild;  
}BiNode, * BiTree;  
   
void CreateBiTree(BiTree &t,string pre,string mid) 
{  
   if(pre.length()==0)  
   {  
         t=NULL;  
         return ;  
   }  
   char rootNode=pre[0]; 
   int index=mid.find(rootNode); 
   string lchild_mid=mid.substr(0,index); 
   string rchild_mid=mid.substr(index+1); 
   int lchild_length=lchild_mid.length(); 
   int rchild_length=rchild_mid.length();  
   string lchild_pre=pre.substr(1,lchild_length); 
   string rchild_pre=pre.substr(1+lchild_length);  
  
   t=(BiTree)malloc(sizeof(BiNode));  
   if(t!=NULL)  
   {  
       t->data=rootNode;  
       CreateBiTree(t->lchild,lchild_pre,lchild_mid); 
       CreateBiTree(t->rchild,rchild_pre,rchild_mid); 
   }  
}  
    
void printNodeByLevel(BiTree root)  
{  
    if(root == NULL)  
        return;  
    vector<BiNode *> vec;  
    vec.push_back(root);  
    int cur = 0;  
    int last = 1;  
    while(cur < vec.size()) {  
        last = vec.size();  
        while(cur < last) {  
            cout<<vec[cur]->data << " ";  
            if(vec[cur]->lchild != NULL)  
                vec.push_back(vec[cur]->lchild);  
            if(vec[cur]->rchild != NULL)  
                vec.push_back(vec[cur]->rchild);  
            ++cur;  
        } 
    }  
}
int main()  
{  
    BiTree t;
    int n;
    string pre, mid;
    while (cin >> n) {
        cin >> pre;
        cin >> mid;
        CreateBiTree(t,pre,mid);  
        printNodeByLevel(t); 
    }  
    return 0;  
} 