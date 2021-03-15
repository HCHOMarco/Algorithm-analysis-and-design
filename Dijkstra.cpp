#include<iostream>
#include<queue>
using namespace std;

const int maxn = 1e3 + 10;
const int inf = 0x3f3f3f3f;

int n, m;
int st = 0, ed = 7, vis[maxn]  = {0};//起点、终点、该点是否被访问过

struct Edge{//定义边
    int u, v, w;
    Edge(){}
    Edge(int u, int v, int w):u(u), v(v), w(w){}
};
vector<Edge>e[maxn];

struct Node{//定义点
    int id, dist;
    Node(){}
    Node(int id, int dist):id(id), dist(dist){}
    bool operator<(const Node & tmp)const {
        return tmp.dist < dist;
    }
};

int Dijkstra(char st, char ed){//Dijkstra算法求解两点之间的最短路
    int start = st - 97;//对点进行映射
    int end = ed - 97;
    int dis[maxn];//每个点到起点的最短距离
    for(int i = 0; i <= n; i++)dis[i] = inf;//初始化最短距离
    priority_queue<Node>q;//定义优先队列获取最近点
    q.push(Node(start, 0));
    while(!q.empty()){
        Node u = q.top();
        q.pop();
        if(vis[u.id] == 1)continue;
        vis[u.id] = 1;
        for(int i = 0; i < e[u.id].size(); i++){
            int v = e[u.id][i].v;
            if(vis[v] == 1)continue;
            if(dis[v] > u.dist + e[u.id][i].w){ // 进行松弛比较
                dis[v] = u.dist + e[u.id][i].w;
                q.push(Node(v, dis[v]));
            }
        }
    }
    return dis[end];
}

int main(){
    scanf("%d %d",&n ,&m);
    getchar();//读取回车
    for(int i = 0; i < m; i++){ // 读图同时转化
        char u, v;
        int w;
        scanf("%c %c %d", &u, &v, &w);
        getchar();//读取多余字符
        e[u - 97].push_back(Edge(u - 97, v - 97, w));
    }
    printf("%d\n", Dijkstra('a', 'h'));
    system("pause");
    return 0;
}
/*
8 11
a b 1
b d 2
c a 2
d c 1
d f 8
e d 2
e g 2
f e 2
g f 3
g h 3
h f 2
*/