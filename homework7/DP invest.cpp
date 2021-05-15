#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100;


int main() {
	int m, n,sum;
	int f[N][N],dp[N][N],inv[N][N];
	
	scanf("%d %d", &m,&n);
	for (int i = 0; i <= m; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &f[j][i]);

	//��̬�滮
	for (int k = 1; k <= n; k++) //��k����Ŀ 
		for (int x = 1; x <= m; x++)  //����k��Ŀʱ���������Ǯ 
			for (int i = 0; i <= x; i++) // ��Ŀk�������Ǯ 
				if (dp[k - 1][x - i] + f[k][i] >= dp[k][x]) {
					dp[k][x] = dp[k - 1][x - i] + f[k][i];
					inv[k][x] = i;
				}
	cout <<"�������"<< dp[n][m] << "��" << endl;
	cout << "���䣺\n";
	sum = m;
	for (int i = n; i >= 1;i--) {
		cout << "��" << i << "����Ŀ����" << inv[i][sum] << "��"<< endl;
		sum -= inv[i][sum];
	}
}
//input 
//5 4
//0 0 0 0
//11 0 2 20
//12 5 10 21
//13 10 30 22
//14 15 32 23
//15 20 40 24
