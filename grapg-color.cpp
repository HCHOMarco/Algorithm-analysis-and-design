#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int a, b, n, res, m;
int graph[maxn][maxn], color[maxn];

bool check(int i){
    for (int j = 1; j <= n; j++){
        if (graph[i][j] && color[i] == color[j]){
            return false;
        }
    }
    return true;
}

int number = 1;
void dfs(int cur){
    if (cur > n){
        printf("programme %d:", number++);
        for (int i = 1; i <= n; i++){
            printf("%d ", color[i]);
        }
        res++;
        printf("\n");
    }else{
        for (int i = 1; i <= m; i++){
            color[cur] = i;
            if (check(cur)){
                dfs(cur + 1);
            }
            color[cur] = 0;
        }
    }
}

int main(){
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            graph[i][j] = 0;
    printf("please input n and m:\n");
    scanf("%d %d", &n, &m);
    printf("Please enter the point of each edge:\n");
    for (int i = 1;; i++){
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0)
            break;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    dfs(1);
    if (res == 0)
        printf("No\n");
    else
        printf("result = %d\n", res);
    return 0;
}
