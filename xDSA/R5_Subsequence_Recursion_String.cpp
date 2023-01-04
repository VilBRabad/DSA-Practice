#include<bits/stdc++.h>
using namespace std;

class Subsequence{
private:
    void helper(string str, string output, int index, vector<string>&ans){
        //Base Case
        if(index >= str.length()){
            ans.push_back(output);
            return;
        }

        //exclude - Not take
        helper(str, output, index+1, ans);

        //Include - Take
        char element = str[index];
        output.push_back(element);
        helper(str, output, index+1, ans);
    }

public:
    vector<string> answer(string str){
        string output = "";
        vector<string> ans;
        helper(str, output, 0, ans);
        return ans;
    }
};

int main(){

    Subsequence get_ans;

    string str;
    cin>>str;
    vector<string> ans = get_ans.answer(str);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}