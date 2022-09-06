#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
     int lengthOfLongestSubstring(string s) {
          string substr = "";
          string temp;

          for (int i = 0; i < s.length(); i++) {
               temp = "";
               for(int j = i; j < s.length(); j++) {
                    if(duplicate(temp, s[j])) {
                         break;
                    }
                    temp += s[j];
               }
               if(temp.length() >= substr.length()) {
                    substr = temp;
                    // cout << substr << " " << temp << endl;
               }
          }
          return substr.length();
     }

     bool duplicate(string s, char c) {
          for(int i = 0; i < s.length(); i++) {
               if(s[i] == c) {
                    return true;
               }
          }
          return false;
     }
};

int main() {
     Solution solution;
     string str;

     str = "abcabcbb";
     cout << "Input: " << str << endl;
     cout << "Expected Output: 3" << endl;
     cout << "Your Ouput:      "
          << solution.lengthOfLongestSubstring(str) << endl;

     str = "bbbbb";
     cout << "Input: " << str << endl;
     cout << "Expected Output: 1" << endl;
     cout << "Your Ouput:      "
          << solution.lengthOfLongestSubstring(str) << endl;

     str = "pwwkew";
     cout << "Input: " << str << endl;
     cout << "Expected Output: 3" << endl;
     cout << "Your Ouput:      "
          << solution.lengthOfLongestSubstring(str) << endl;
}