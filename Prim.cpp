#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>
using namespace std;

const int maxn = 1e4 + 10;

struct Node{ // 定义端点结构体
	int id, dist;
	Node(int id, int dist):id(id), dist(dist){}
	bool operator<(const Node & tmp)const{//重载<使其升序排序
		return tmp.dist < dist;
	}
};
int n, m, vis[maxn] = {0};//点数、边数、标记数组
vector<Node>graph[maxn];//记录图
int Prim(int st){
	int cnt = 0, res = 0;//边的数量、最小生成树结果
	priority_queue<Node>q;//定义优先队列进行优化获取最小边
    q.push(Node(st, 0));//起点入队
    while(!q.empty()){
        int v = q.top().id;
        int w = q.top().dist;
        q.pop();
        if(vis[v] == 1)continue;//判断该点有无被标记
        vis[v] = 1;
        res += w;
        for(int i = 0; i < graph[v].size(); i++){//将其所有领点且未被标记入队。
            if(vis[graph[v][i].id] == 1)continue;
            q.push(Node(graph[v][i].id, graph[v][i].dist));
        }
    }

	return res;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back(Node(v, w));
		graph[v].push_back(Node(u, w));
	}
	printf("%d\n", Prim(1));
	system("pause");
	return 0;
}
/*
4 5
1 2 1
2 3 4
3 4 5
4 1 2
2 4 3
*/