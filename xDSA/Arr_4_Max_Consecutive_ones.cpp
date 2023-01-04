#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n;
    cin>>k;
    vector<int> arr(n);
    for(auto &i : arr)
        cin>>i;
    
    int i=0, ans=0, zerocnt=0;
    for(int j=0; j<n; j++){
        if(arr[j]==0)
            zerocnt++;
        while(zerocnt>k){
            if(arr[i]==0)
                zerocnt--;
            i++;
        }
        ans = max(ans, j-i+1);
    }
    cout<<ans<<endl;

    return 0;
}