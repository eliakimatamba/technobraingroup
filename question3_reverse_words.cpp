/*
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatanated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have
a single space separting the words.
Do no include any extra spaces.
*/

#include <iostream>
#include <string>
using namespace std;

void reverseWords(string &s)
{
    int lengthOfString = s.length();
    string reversedString = "";
    string word = "";

    if (s[0] == ' ')
    {
        int counter = 0;
        while (s[counter] == ' ')
        {
            counter++;
        }
        s = s.substr(counter, lengthOfString);
    }

    for (int i = 0; i < lengthOfString; i++)
    {
        if (s[i] == ' ')
        {
            reversedString = ' ' + word + reversedString;
            word = "";
        }
        else
        {
            word = word + s[i];
        }

        if (i == lengthOfString - 1)
        {
            reversedString = word + reversedString;
        }
    }

    s = reversedString;

    if (reversedString[0] == ' ')
    {
        int counter = 0;
        while (reversedString[counter] == ' ')
        {
            counter++;
        }
        s = reversedString.substr(counter, lengthOfString);
    }
}

int main()
{
    string s = "  hello world!  ";
    cout << "Input: " << s << endl;
    reverseWords(s);

    if (s[0] == ' ')
    {
        int counter = 0;
        while (s[counter] == ' ')
        {
            counter++;
        }
        s = s.substr(counter, s.length());
    }
    cout << "Output: " << s << endl;
    return 0;
}
