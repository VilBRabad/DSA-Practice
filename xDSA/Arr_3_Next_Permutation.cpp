#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int k, l;
        for(k = N-2; k>=0; k--){
            if(arr[k] < arr[k+1]){
                break;
            }
        }
        if(k < 0){
            reverse(arr.begin(), arr.end()); //In Interview use two point reverse method. if Interviewer is comfortable with STL reverse func. then use it.
        }
        else{
            for(l = N-1; l>k; l--){
                if(arr[l] > arr[k]){
                    break;
                }
            }
            swap(arr[k], arr[l]);
            reverse(arr.begin()+k+1, arr.end());
        }
        return arr;
    }
};