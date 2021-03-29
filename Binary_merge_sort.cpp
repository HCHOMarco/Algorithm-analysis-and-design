#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

const int maxn = 1e2 + 10;

int n, a[maxn];
vector<int>vec;

void merge_sort(int l, int r){ //进行递归排序
    int mid = (l + r) >> 1;
    if(l == r)return;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int p1 = l;
    int p2 = mid + 1;
    vec.clear();
    while(p1 <= mid && p2 <= r){ // 对每两个区间进行归并排序
        if(p1 <= mid && p2 <= r && a[p1] < a[p2]){
            vec.push_back(a[p1++]);
        }else if(p1 <= mid && p2 <= r && a[p1] >= a[p2]){
            vec.push_back(a[p2++]);
        }
    }
    while(p1 <= mid)vec.push_back(a[p1++]);
    while(p2 <= r)vec.push_back(a[p2++]);
    int p = 0;
    for(int i = l; i <= r; i++){ //修改原数组
        a[i] = vec[p++];
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    merge_sort(1, n);
    for(int i = 1; i <= n; i++)
        printf("%d ",a[i]);
    printf("\n");
    system("pause");
    return 0;
}