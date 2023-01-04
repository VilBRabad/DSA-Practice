#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int target;
    cin>>n;
    cin>>target;
    vector<int> arr(n);
    for(auto &i : arr){
        cin>>i;
    }
    
    sort(arr.begin(), arr.end());
    bool found = false;

    for(int i=0; i<n; i++){
        int lo = i+1;
        int hi = n-1;
        while(lo<hi){
            int sum = arr[i]+arr[lo]+arr[hi];
            if(sum == target){
                found = true;
            }
            if(sum < target){
                lo++;
            }
            else{
                hi--;
            }
        }
    }
    if(found){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }

    return 0;
}