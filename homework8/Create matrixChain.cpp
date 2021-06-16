#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int m[N][N] = {0}, s[N][N];  
//m[i][i]��ʼ��Ϊ0�����ڴ洢�˷��������м�ֵ  s[][]���ڴ洢����λ�õ��±�

void matrixChain(int p[], int n) {
	for (int r = 2; r <= n; r++) {  //rΪ��ǰ�����ģ
		for (int i = 1; i <= n - r + 1; i++) {  //��� 
			int j = i + r - 1;  //�յ�
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
			s[i][j] = i;

			//������ͬ����λ�ã��洢��С�ĳ˷���������λ���±�
			for (int k = i + 1; k <= j - 1; k++) {
				int temp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (temp < m[i][j]) {
					m[i][j] = temp;
					s[i][j] = k;
				}
			}
		}
	}

	//������
	cout <<"��С�˷�����Ϊ��"<<m[1][6]<< endl;
//	cout << "����λ�����⵽��Ϊ��";
//	cout << "s[1,6]=4  s[1,4]=1  s[2,4]=2\n";
}

int main() {
	freopen("input.txt","r",stdin);
	int n,p[N];  
	//n��ʾ�������  p[]��ʾ��������������
	cin>>n;
	for (int i = 0; i <= n; i++)  //n��������n+1��������
		cin>>p[i];
	matrixChain(p, n);
}
