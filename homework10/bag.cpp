#include<bits/stdc++.h>
using namespace std; 
const int N = 1e5;
int n, c,tmp ;
int w[N];
int main() {
	cin >> n >> c;
	for (int i=0; i<n; i++){
		cin >> w[i];
	}
	tmp = 0;
	sort(w, w+n);
	for (int i=0; i<n && c>=w[i]; i++){
		c -= w[i];
		++tmp;
	}
	cout<<tmp<<endl;
	return 0;
} 
