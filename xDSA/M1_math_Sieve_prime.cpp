//Approach - Sieve of Eratothes

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int count_prime(int n){
        int cnt=0;
        vector<bool> prime(n+1, true);
        prime[0]=prime[1]=false;

        for(int i=2; i<n; i++){
            if(prime[i]){
                cnt++;
                for(int j=2*i; j<n; j+=i){
                    prime[j]=0;
                }
            }
        }
        return cnt;
    }
};

int main(){

    Solution ans;
    int n;
    cin>>n;
    int cnt = ans.count_prime(n);
    cout<<cnt<<endl;
    // Homework--> Segmented sieve

    return 0;
}