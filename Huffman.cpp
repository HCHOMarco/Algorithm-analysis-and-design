#include<bits/stdc++.h>
using namespace std;

inline int rd(){
    int x;
    scanf("%d", &x);
    return x;
}

int res = 0;
vector<int>save;

int main(){
    int n = rd();
    // 利用小顶堆维护一个栈顶都是当前最小值的数据结构
    priority_queue<int, vector<int>, greater<int> >q;
    for(int i = 0; i < n; i++){
        int x = rd();
        q.push(x);
    }
    while(q.size() > 1){
        int x = q.top();q.pop();
        int y = q.top();q.pop();
        save.push_back(x);
        save.push_back(y);
        res += x + y;
        q.push(x + y);
    }
    printf("WPL = %d\n", res);
    for(int i = 0; i < save.size(); i++)
        printf("%d ", save[i]);
    printf("\n");
    system("pause");
    return 0;
}
