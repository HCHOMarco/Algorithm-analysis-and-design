#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;

int rd(){
    int x;
    scanf("%d", &x);
    return x;
}

int n, k;

int selectK(vector<int> &v, int k){
    vector<int>groupMid;
    vector<int>s1, s2;
    groupMid.clear();
    s1.clear();
    s2.clear();
    int len = v.size();
    int numOfGroup = len / 5;
    if(len <= 5){
        sort(v.begin(), v.end());
        return v[k - 1];
    }
    for(int i = 0; i < numOfGroup; i++){
        sort(v.begin() + 5 * i, v.begin() + 5 * i + 5);
        groupMid.push_back(v[5 * i + 2]);
    }
    int mid = selectK(groupMid, groupMid.size() / 2 + 1);
    for(int i = 0; i < numOfGroup; i++){
        if(v[5 * i + 2] < mid){
            s1.push_back(v[5 * i]);
            s1.push_back(v[5 * i + 1]);
            s1.push_back(v[5 * i + 2]);
            if(v[5 * i + 3] < mid)s1.push_back(v[5 * i + 3]);
            else s2.push_back(v[5 * i + 3]);
            if(v[5 * i + 4] < mid)s1.push_back(v[5 * i + 4]);
            else s2.push_back(v[5 * i + 4]);
        }else if(v[5 * i + 2] == mid){
            s1.push_back(v[5 * i]);
            s1.push_back(v[5 * i + 1]);
            s2.push_back(v[5 * i + 3]);
            s2.push_back(v[5 * i + 4]);
        }else{
            s2.push_back(v[5 * i + 2]);
            s2.push_back(v[5 * i + 3]);
            s2.push_back(v[5 * i + 4]);
            if(v[5 * i] < mid)s1.push_back(v[5 * i]);
            else s2.push_back(v[5 * i]);
            if(v[5 * i + 1] < mid)s1.push_back(v[5 * i + 1]);
            else s2.push_back(v[5 * i]);
        }
    }
    for(int i = 5 * numOfGroup; i < len; i++){
        if(v[i] < mid)s1.push_back(v[i]);
        else s2.push_back(v[i]);
    }

    if(k == s1.size() + 1)return mid;
    else if(k <= s1.size())return selectK(s1, k);
    else return selectK(s2, k - s1.size() - 1);
}

int main(){
    cout << "Please enter number of array and the kth:" << endl;
    n = rd();
    k = rd();
    vector<int>vec;
    for(int i = 0; i < n; i++){
        int num = rd();
        vec.push_back(num);
    }
    cout << selectK(vec, k) << endl;
    system("pause");
    return 0;
}