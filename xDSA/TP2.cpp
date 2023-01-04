#include<bits/stdc++.h>
using namespace std;

vector<int> getAns(vector<int>arr, int l, int h){
    vector<int>answer;
    int n = arr.size();
    for(int i=0; i<n; i++){
        if((arr[i] >= l) && (arr[i] <= h)){
            answer.push_back(arr[i]);
        }
    }

    return answer;
}


int main(){

    

    return 0;
}