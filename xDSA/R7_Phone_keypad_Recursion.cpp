/*
    e.g input = "23"       2 = "abc", 3 = "efg"   This is like in Phone Keypad. You have to print Possible output
        & If No input mean empty input "", then print "".
        output = {'ad', 'ae', 'af', 'bd', 'be', 'bf', 'cd', 'ce', 'cf'}
*/
#include<iostream>
#include<vector>
#include<string.h>
//#include<bits/stdc++.h>  //By this All Library are imported. - This best in CP
using namespace std;

class Solution{
private:
    void solve(string digit, string output, int index, vector<string> &ans, string map[]){
        //Base case
        if(index>=digit.length()){
            ans.push_back(output);
            return;
        }

        int number = digit[index]-'0';
        string value = map[number];
        for(int i=0; i<value.length(); i++){
            output.push_back(value[i]);
            // Recursive Relation
            solve(digit, output, index+1, ans, map);
            output.pop_back();  //****** This is Called BackTracking ******
        }
    }
public:
    vector<string>LetterCombination(string digit){
        vector<string> ans;
        string output;
        if(digit.length()==0){
            return ans;
        }
        string mapping[10]= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digit, output, 0, ans, mapping);
        return ans;
    }

};

int main(){
    
    Solution GetAns;
    string digit;
    cin>>digit;
    vector<string>ans = GetAns.LetterCombination(digit);
    cout<<"{";
    for(int i=0; i<ans.size(); i++){
        cout<<"'"<<ans[i]<<"'";
        if(i<ans.size()-1){
            cout<<", ";
        }
    }
    cout<<"}";
    
    return 0;
}