/*
Problem : Given two distinct words startWord and targetWord, 
and a list denoting wordList of unique words of equal lengths. 
Find the length of the shortest transformation sequence from startWord to targetWord.
Keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList
The second part of this problem can be found here.

Note: If no possible way to transform sequence from startWord to targetWord return 0
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        int n = wordList.size();
        int len = wordList[0].size();
        
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        
        st.erase(startWord);
        
        while(!q.empty()){
            string word =  q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(targetWord == word) return steps;
            
            for(int i=0; i<len; i++){
                char original = word[i];
                for(char ch = 'a'; ch<= 'z'; ch++){
                    word[i] = ch;
                    //word is found;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i] = original;
            }
        }
        
        return 0;
    }
};