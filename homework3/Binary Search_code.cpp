#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
int n, a[N], cnt;

void BinarySearch(int x) {
	int l=1, r=n, mid,flag=0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] < x)
			l = mid + 1;
		else if (a[mid] > x)
			r = mid-1;
		else {
			cout << mid << endl;
			flag = 1;
			break;
		}
	}
	if (!flag)
		cout << "Not find" << endl;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> cnt;   //查找次数
	while (cnt--) {
		int x;
		cin >> x;   //查找的数
		BinarySearch(x);
	}
} 
