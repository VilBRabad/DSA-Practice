
/* Counting no. of ways to go through the stairs 
    a person can take only 1 or 2 steps (1 or 2 stairs)*/

#include<bits/stdc++.h>
using namespace std;

int answer(int n){
    //Base Case
    if (n == 1 || n == 2){
        return n;
    }
    //Recurive Relation
    int ans = answer(n-1) + answer(n-2);
    return ans;
}

int main(){

    int n;
    cin>>n;

    int ans = answer(n);
    cout<<ans<<endl;

    return 0;
}