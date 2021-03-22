#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;

const int maxn = 1e3 + 10;

int n, m, arr[maxn];

int Violence_search(int x){
    int index = 0;
    for(int i = 1; i <= n; i++){
        if(arr[i] == x){
            index = i;
            break;
        }
    }
    return index;
}

int Binary_search(int x){
    int l = 1;
    int r = n;
    while(r >= l){
        int mid = (l + r) >> 1;
        if(arr[mid] == x){
            return mid;
        }else if(arr[mid] > x){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return 0;
}


int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)scanf("%d", &arr[i]);
    int p1, p2;
    p1 = Violence_search(m);
    p2 = Binary_search(m);
    printf("Using violence method to get index : %d\n", p1);
    printf("Using binary method to get index : %d\n", p2);
    system("pause");
    return 0;
}
/*
5 3
7 8 9 10 11
10 5
1 4 5 6 7 8 9 11 12 13
*/