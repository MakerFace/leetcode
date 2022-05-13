/**
 * @file 824.cpp
 * @brief 山羊拉丁文
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-04-21
 */

#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string toGoatLatin(string sentence) {
    string res;
    string end = "ma";
    bool work = false;
    for (size_t i = 0; i < sentence.size(); ++i) {
      work = false;
      end += "a";
      if (sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' ||
          sentence[i] == 'o' || sentence[i] == 'u' || sentence[i] == 'A' ||
          sentence[i] == 'E' || sentence[i] == 'I' || sentence[i] == 'O' ||
          sentence[i] == 'U') {
        work = true;
      }
      size_t j = i + 1;
      for (; j < sentence.size() && sentence[j] != ' '; ++j) {
      }
      if (work) {
        res += sentence.substr(i, j - i) + end + ' ';
      } else {
        res += sentence.substr(i + 1, j - i - 1) + sentence[i] + end + ' ';
      }
      i = j;
    }
    res = res.substr(0, res.size() - 1);
    return res;
  }
};
int main(int argc, char const *argv[]) {
  Solution s;
  std::cout << s.toGoatLatin("The quick brown fox jumped over the lazy dog")
            << std::endl;
  return 0;
}
