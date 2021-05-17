#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e2 + 10;

inline int rd(){
    int x;
    scanf("%d", &x);
    return x;
}

struct Node{
    int id;
    int startTime;
    int endTime;
    bool operator<(Node tmp){
        if(endTime != tmp.endTime)return endTime < tmp.endTime;
        else return startTime < tmp.startTime;
    }
}timeInfo[maxn];

vector<int>save;
Node saveInfo[maxn];

int main(){
    int n = rd();
    for(int i = 0; i < n; i++){
        timeInfo[i].id = i;
        timeInfo[i].startTime = rd();
        timeInfo[i].endTime = rd();
        saveInfo[i] = timeInfo[i];
    }
    sort(timeInfo, timeInfo + n);
    save.push_back(timeInfo[0].id);
    int preEndTime = timeInfo[0].endTime;
    for(int i = 1; i < n; i++){
        int id = timeInfo[i].id;
        if(timeInfo[i].startTime >= preEndTime){
            save.push_back(id);
            preEndTime = timeInfo[i].endTime;
        }
    }
    printf("%d\n", save.size());
    for(int i = 0; i < save.size(); i++)
        printf("%d ", save[i] + 1);
    system("pause");
    return 0;
}
