#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>
using namespace std;

const int maxn = 1e4 + 10;

struct Edge{//定义边的结构体
    int u, v, w;
    Edge(){}
    Edge(int u, int v, int w):u(u), v(v), w(w){}
    bool operator<(Edge tmp){//重载小于号进行升序排序
        return w < tmp.w;
    }
}e[maxn];

int n, m, fa[maxn];

void init(){//初始化
    for(int i = 1; i <= n; i++)fa[i] = i;
}

int Find(int x){//查找父亲结点
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

void Union(int x, int y){//合并
    int fx = Find(x);
    int fy = Find(y);
    fa[fx] = fy;
}

int Kruskal(){
    int cnt = 0, res = 0;
    init();
    sort(e, e + m);
    for(int i = 0; i < m; i++){
        if(Find(e[i].u) != Find(e[i].v)){//用并查集判断是否成环
            Union(e[i].u, e[i].v);
            cnt++;
            res += e[i].w;
        }
        if(cnt == n - 1)break;
    }
    return res;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        e[i] = Edge(u, v, w);
    }
    printf("%d\n", Kruskal());
    system("pause");
    return 0;
}
/*
4 6
1 2 1
1 3 4
1 4 1
2 3 3
2 4 2
3 4 5
*/