#include<iostream>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if(a>0&&b>0&&c>0){
		if((a+b>c)&&(a+c>b)&&(b+c>a)){
			if(a==b||a==c||b==c){
				cout<<"等腰三角形"<<endl;
			}else if(a==b&&b==c){
				cout<<"等边三角形"<<endl;
			}else{
				cout<<"一般三角形"<<endl;
			}
		}else{
			cout<<"不能构成三角形"<<endl;
		}
	}else
		cout<<"数字输入不合法！"<<endl;
	return 0;
}
