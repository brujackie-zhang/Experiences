// #include<iostream>
// #include<string>
// #include<cstdlib>
// using namespace std;

// int len;

// int f(int n, int m, int *flag)
// {
// 	if (n < 1 || m < 1) {
// 		return 0;
// 	}
// 	if (n > m) {
// 		n = m;
// 	}
// 	if (n == m) {
// 		flag[n - 1] = 1;
// 		for (int i = 0; i < len; i ++) {
// 			if (flag[i] == 1) {
// 				cout << i + 1 << " ";
// 			}
// 		}
// 		cout << endl;
// 		flag[n - 1] = 0;
// 	}
// 	flag[n - 1] = 1;
// 	f(n - 1, m - n, flag);
// 	flag[n - 1] = 0;
// 	f(n - 1, m, flag);
// 	return 0;
// }

// int main()
// {
// 	int n,m;
// 	while (cin >> n >> m) {
// 		len = n;
// 		int *flag = (int *)malloc(len * sizeof(int));
// 		f(n, m, flag);
// 		free(flag);
// 	}
// 	return 0;
// }

#include<iostream>
#include<vector>
using namespace std;
const int maxn =1111;
int used[maxn];
int n,m;
vector<int>mg;
void dfs(int now,int sum)
{
    if(sum<0){
        return ;
    }
    if(sum==0){
        for(int i=0;i<mg.size();i++)
            if(i!=mg.size()-1)cout<<mg[i]<<" ";
            else cout<<mg[i]<<endl;
    }
    for(int i=now;i<=n;i++){
        mg.push_back(i);
        dfs(i+1,sum-i);
        mg.pop_back();
    }
}
int main()
{
    cin>>n>>m;
    dfs(1,m);
}