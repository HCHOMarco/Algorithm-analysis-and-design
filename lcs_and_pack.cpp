#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;

string a, b;
int c[maxn][maxn], m[maxn][maxn];
void lcs(string a, string b){
	int lena = a.length();
	int lenb = b.length();
	memset(c, 0, sizeof c);
	for (int i = 1; i <= lena; i++){
		for (int j = 1; j <= lenb; j++){
			if (a[i - 1] == b[j - 1]){
				c[i][j] = c[i - 1][j - 1] + 1;
				m[i][j] = 2;
			}else{
				if (c[i][j - 1] >= c[i - 1][j]){
					c[i][j] = c[i][j - 1];
					m[i][j] = 0;
				}else{
					c[i][j] = c[i - 1][j];
					m[i][j] = 1;
				}
			}
		}
	}
	printf("结果是:%d\n", c[lena][lenb]);
	printf("操作方法是：\n");
	for (int i = 0; i <= lenb; i++){
		for (int j = 0; j <= lena; j++){
			printf("%d:", m[j][i]);
			if (m[j][i] == 2)
				printf("删除两个 ");
			else if (m[j][i] == 1)
				printf("删除x ");
			else
				printf("删除y ");
		}
		printf("\n");
	}
}

string ans;
void pack(int i, int j){
	if (i == 0 || j == 0)
		return;
	if (m[i][j] == 2){
		ans += a[i - 1];
		pack(i - 1, j - 1);
	}
	else if (m[i][j] == 1){
		pack(i - 1, j);
	}
	else if (m[i][j] == 0){
		pack(i, j - 1);
	}
}

int main()
{
	cin >> a >> b;
	lcs(a, b);
	pack(a.length(), b.length());
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	system("pause");
	return 0;
}
