#include<iostream>
using namespace std;
const int maxn = 1e2 + 10;
const int inf = 0x3f3f3f3f;

int n, m;//点的数量、边的数量
int graph[maxn][maxn];//存图

void initGraph(){//初始化图
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            graph[i][j] = inf;
    for(int i = 0; i < m; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
    }
}

void Floyd(){//Floyd算法求各点之间的最短路
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            if(graph[i][k] == inf)continue;
            for(int j = 1; j <= n; j++){
                if(graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    initGraph();
    Floyd();
    for(int i = 1; i <= n; i++){//输出矩阵
        for(int j = 1; j <= n; j++){
            if(i == j)graph[i][j] = 0;
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    system("pause");
    return 0;
}
/*
4 8
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12
*/