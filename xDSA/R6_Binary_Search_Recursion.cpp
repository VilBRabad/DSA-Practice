#include<bits/stdc++.h>
using namespace std;

class Get_Ans{
// private:
//     void helper()
public:
    bool answer(int arr[], int size){
        //Base Case
        if(size == 0 || size == 1){
            return true;
        }
        if(arr[0]>arr[1]){
            return false;
        }
        //Recursive Relation
        else{
            answer(arr, size-1);
        }
    }

};

int main(){
    Get_Ans is_sorted;
    int arr[5] = {2, 4, 6, 7, 9};
    bool ans = is_sorted.answer(arr, 5);

    if(ans){
        cout<<"Array is Sorted"<<endl;
    }
    else{
        cout<<"Array is Not Sorted"<<endl;
    }

    return 0;
}