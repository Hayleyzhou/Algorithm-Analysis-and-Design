#include<bits/stdc++.h>
using namespace std;
const int N =1e5; 
int n, a[N], tmp[N];
void merge(int a[],int left, int mid, int right,int tmp[]) {
    int startA = left, startB = mid + 1, pos=1;        
	//�鲢���������飬posΪtmp�����е��±�
    while (startA <= mid && startB <= right) {
        if (a[startA] < a[startB]) //��Сֵ����tmp����
            tmp[pos++]=a[startA++];
        else
            tmp[pos++] = a[startB++];
    }
    //ʣ���������tmp��
    while (startA<=mid)
        tmp[pos++] = a[startA++];
    while (startB <= right)
        tmp[pos++] = a[startB++];
    //����ԭ����Ϊ�鲢������
    pos = 1;
    for (int i = left; i <= right; i++)
        a[i] = tmp[pos++];
}

void mergeSort(int a[], int left, int right,int temp[]) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid, temp);                //����˼���
        mergeSort(a, mid + 1, right, temp);
        merge(a, left, mid, right, temp);             //�鲢����������
    }
}

int main()
{
	cin>>n;  //����������� 
	for(int i=1;i<=n;i++) cin>>a[i];   //���� 
    cout << "before��";
    for (int i = 1; i <= n; i++)  cout << a[i] << " ";
    cout << endl;
    mergeSort(a,1,n,tmp);
    cout << "after��";
    for (int i = 1; i <= n; i++)  cout << a[i] <<" ";  //������ 
}
