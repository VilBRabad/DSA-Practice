#include<iostream>
using namespace std;

int factorial(int n){
    // Base Case - Must return something - must be in recursive function
    if(n == 0){
        return 1;
    }

    // Recursive Relation
    int fact = n * factorial(n-1);

    return fact;
}

int main(){

    int n;
    cin>>n;

    int ans = factorial(n);
    cout<<ans<<endl;

    return 0;
}
