#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e2 + 10;

inline int rd() {
	int x;
    scanf("%d", &x);
    return x;
}

int p[maxn],m[maxn][maxn],s[maxn][maxn];
int n;

void print(int s[][maxn], int i, int j) {//输出方案
	if (i == j) {
		printf("A%d", i);
	} else {
		printf("(");
		print(s,i,s[i][j]);
		print(s,s[i][j]+1,j);
		printf(")");
	}
}

void MatrixChain(int n) {
	int j,t;
	for (int r = 2; r <= n; r++) {//r为当前问题规模（长度）
		for (int i = 1; i <= n - r + 1; i++) { //i的起点不断变化，各种r长
			j = i + r - 1;  //不同终点
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];//划分为Ai(Ai+1...Aj)
			s[i][j] = i;//初始化
			for (int k = i + 1; k <= j - 1; k++) {//不同的划分位置
				t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j]) {
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
}


void print_s(int a[][maxn]){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%lld ",a[i][j]);
		}
		printf("\n");
	}
} 

int main() {
	n=rd();
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=n; j++) {
			m[i][j]=0;
			s[i][j]=0;
		}
	}
	for(int i=0; i<=n; ++i) {
		p[i]=rd();
	}
	MatrixChain(n);
	printf("Minimum total times: %d\n", m[1][n]);
	printf("Multiplication order：");
	print(s,1,n);
	printf("\n");
	printf("S: \n");
	print_s(s);
	printf("M: \n");
	print_s(m);
	return 0;
}
