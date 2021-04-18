#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int N = 1e3+10;
struct node{
	double x, y;
}p[N];
double dis(node& a,node& b){
	return pow(a.x-b.x,2)+pow(a.y-b.y,2);
}
int comp(node& a,node& b){
	return a.x < b.x;
}
double Point(node p[],int n){
	double minn = inf;
	if(n<=3){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j) minn= min(minn,dis(p[i],p[j]));
			}
		}
	}else{
		node pl[N],pr[N],s[N];
		double m,dl,dr,d;
		int len1 = ceil(1.0*n/2);
		int len2,num=0;
		len2 = n - len1;
		for (int i = 0; i < len1; i++)
      	pl[i] = p[i];
   		for (int i = 0; i < len2; i++)
      	pr[i] = p[i];
      	
      	dl = Point(pl, len1);
    	dr = Point(pr,len2);
    	d = min(dl, dr);
    	minn = pow(d, 2); 
    	m = p[len1 - 1].x;
    	
    	for (int i = 0; i < n; i++) {
      	if (fabs(p[i].x - m) < d)
        s[num++]= p[i];
        
        for (int i = 0; i < num-1;i++) {
      	int k = i + 1;
      	while (k <= num - 1 && pow((s[k].y - s[i].y), 2)+pow((s[k].x - s[i].x), 2) < minn) {
        minn = min(pow((s[k].y - s[i].y), 2) + pow((s[k].x - s[i].x), 2), minn);
        k++;
     	}
    	}
  	}
  	return sqrt(minn);
    }
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
	sort(p, p + n, comp);
	cout<<Point(p, n)<<endl;
} 

/*
input:
6
3 2
-2 0
1 1
-0.5 0.5
4 0
7 8
*/
