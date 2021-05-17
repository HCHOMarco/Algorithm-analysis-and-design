#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e2 + 10;

inline int rd(){
    int x;
    scanf("%d", &x);
    return x;
}

int n, volume,dp[maxn];
int cost[maxn], val[maxn];


int zoPack(){
    for(int i = 0; i < n; i++){
        for(int j = volume; j >= cost[i]; j--){
            dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
        }
    }
    return dp[volume];
}

int main(){
    printf("Please enter the quantity and space of the item\n");
    n = rd();
    volume = rd();

    printf("Please enter every things's cost:\n");
    for(int i = 0; i < n; i++)
        cost[i] = rd();

    printf("Please enter every things's value:\n");
    for(int i = 0; i < n; i++)
        val[i] = rd();

    printf("The max value is : ");
    printf("%d\n", zoPack());

    system("pause");
    return 0;
}
