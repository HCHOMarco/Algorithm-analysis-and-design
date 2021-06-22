#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;

/**
 * n:任务数量
 * totTime:所有项目时间和
 * halfTime:时间和一半
 * cost:一个任务需要的时间
 * val:完成一个任务获得的贡献（在这里值等同于cost）
 * dp:在当前的时间空间下最多可以占的时间
 * path:记录机器路径，用来打印01背包的过程
 * vis:用来辅助最后的任务分配
 */
int n, totTime, halfTime;
int cost[maxn], val[maxn], dp[maxn], path[maxn][maxn], vis[maxn];

int main(){
    int n;
    printf("Enter the number of tasks: ");
    while(~scanf("%d", &n)){

        // 数据初始化
        for(int i = 0; i < maxn; i++){
            cost[i] = val[i] = dp[i] = vis[i] = 0;
        }
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                path[i][j] = 0;
            }
        }
        totTime = 0;

        int x = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &x);
            cost[i] = x;
            val[i] = x;
            totTime += x; 
        }

        halfTime = (totTime + 1) / 2;

        // 01背包实现并记录路径
        for(int i = 1; i <= n; i++){
            for(int j = halfTime; j >= cost[i]; j--){
                if(dp[j] < dp[j - cost[i]] + val[i]){
                    dp[j] = dp[j - cost[i]] + val[i];
                    path[i][j] = 1;
                }
            }
        }

        // 获得A，B两个机器运行时间
        int A = dp[halfTime];
        int B = totTime - A;

        // 输出调度方案（输出的是一个机器所需要的时间和任务分配）
        printf("A machine scheduling scheme(identifier): %d\n", A);
        int p = halfTime;
        for(int i = n; i >= 0; i--){
            if(p < 0)break;
            if(path[i][p]){
                printf(" %d", i);
                vis[i] = 1;
                p -= cost[i];
            }
        }
        printf("\nB machine scheduling scheme(identifier): %d\n", B);
        for(int i = 1; i <= n; i++){
            if(vis[i] == 0)
                printf(" %d", i);
        }

        //输出调度方案的最短时间
        printf("\nMinimum scheduling time: %d\n", max(A, B));
        printf("\nEnter the number of tasks: ");
    }
    system("pause");
    return 0;
}
