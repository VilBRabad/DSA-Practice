// Adjacentcy Matrix

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    cin>>n>>m;
    int arr[n+1][n+1];
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        arr[u] = v;
        arr[v] = u;
    }

    return 0;
}