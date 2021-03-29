#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
int n, a[N],cnt;

void sequenSearch(int x) {
	int i=0;
	for (i = 1;i<=n;i++) {
		if (a[i]==x) {
			cout <<i<< endl;
			break;
		}
	}
	if (i==n+1)
		cout << "Not find" << endl;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> cnt;  //查找次数 

	while (cnt--) {
		int x;
		cin >> x;   //查找的数
		sequenSearch(x);
	}
} 
