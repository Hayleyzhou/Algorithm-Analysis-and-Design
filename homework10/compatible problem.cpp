#include<bits/stdc++.h> 
using namespace std;
const int maxn = 1000;

struct node{
	int s, f;
}t[maxn],ans[maxn];//t����洢��ʼʱ�䣬ans�洢ʹ���������ʱ�䰲��

int cmp(const node& a, const node& b) {
	return a.f < b.f;
}

int main() {
	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	for (int i = 1; i <= n; i++)
		cin>>t[i].s>>t[i].f;

	sort(t + 1, t + 1 + n, cmp);//����ֹʱ������
	int k = 0;//���Ļ����
	ans[++k] = t[1];
	for (int i = 2; i <= n; i++) {
		if (t[i].s >= ans[k].f)
			ans[++k] = t[i];
	}

	cout << "�������Ϊ��" << k << endl;
	cout << "���ŵĻ����ʼ�ͽ�ֹʱ�����£�\n";
	for (int i = 1; i <= k; i++)
		cout << ans[i].s << " " << ans[i].f << endl;
}
