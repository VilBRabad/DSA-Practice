
/* What is ***Palindrome*** ?
    if we read a string from right to left it must be same 
    as we read left to right.

    e.g. 1) NOON ---> Palindrome
         2) Vilas --> Not Palindrome
         3) abcba --> Palindrome
         4) mom ----> Palindrome
         5) min ----> Not Palindrome
*/

#include<bits/stdc++.h>
using namespace std;

int helper(string s, int start, int end){
    //Base case
    if(start >= end){
        return 1;
    }
    else if(s[start] != s[end]){
        return 0;
    }

    //Recursive call
    return helper(s, start+1, end-1);
}

int isPalindrome(string s){
    int n = s.size()-1;
    return helper(s, 0, n);
}

int main(){

    string S;
    cin>>S;
    cout<<isPalindrome(S)<<endl;

    return 0;
}


