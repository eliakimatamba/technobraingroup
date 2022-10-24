/*
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatanated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have
a single space separting the words.
Do no include any extra spaces.
*/
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

//function to reverse the input string
string reverseWords(string input){
    stringstream ss(input);
    string ans;
    string word;
    while(ss >> word)
    {
        reverse(word.begin(),word.end());
        ans += word;
        ans += " ";
    }
    ans.pop_back();
    return ans;
}

int main(){
    string input;
    getline(cin, input);
    cout<<reverseWords(input);
    return 0;
}