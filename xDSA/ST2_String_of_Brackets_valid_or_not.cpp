// Check for Balanced Brackets in an expression (well-formedness) using Stack
#include<bits/stdc++.h>
using namespace std;

bool getAns(string str){
    stack<char>st;

    for(int i=0; i<str.length(); i++){
        if(st.empty()){
            st.push(str[i]);
        }
        else if(st.top()=='(' && str[i] == ')'){
            st.pop();
        }
        else{
            st.push(str[i]);
        }
    }
    // cout<<st.top()<<endl;
    if(st.empty()){
        return true;
    }

    return false;
}

int main(){
    string str = "((()))"; //Valid
    // but now wap to check a string valid or not using stack
    bool ans = getAns(str);
    if(ans){
        cout<<"Valid"<<endl;
    }
    else{
        cout<<"Not valid"<<endl;
    }

    return 0;
}
