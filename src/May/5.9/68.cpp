/**
 * @file 68.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-09
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> result;
    size_t i = 0, j = 1;
    size_t count = words[0].size();
    while (count and j < words.size()) {
      count += words[j].size();
      if (count + (j - i - 1) >= (size_t)maxWidth) {
        count -= words[j].size();
        int spaces = maxWidth - count;
        string temp;
        for (; i < j - 1; ++i) {
          int len = ceil((float)spaces / (j - i - 1));
          string space(len, ' ');
          spaces -= len;
          temp += words[i] + space;
        }
        temp += words[j - 1] + string(spaces, ' ');
        i = j;
        count = words[j].size();
        result.push_back(temp);
      }
      ++j;
    }
    string temp;
    count = 0;
    for (; i < words.size() - 1; ++i) {
      temp += words[i] + ' ';
      count += words[i].size() + 1;
    }
    temp += words[i];
    count += words[i].size();
    temp += string(maxWidth - count, ' ');
    result.push_back(temp);
    return result;
  }
};

int main(int argc, char const *argv[]) {
  Solution ans;
  vector<string> words = {"Don't", "go",    "around", "saying", "the",
                          "world", "owes",  "you",    "a",      "living;",
                          "the",   "world", "owes",   "you",    "nothing;",
                          "it",    "was",   "here",   "first."};
  auto res = ans.fullJustify(words, 30);
  for (auto var : res) {
    std::cout << var << std::endl;
  }
  return 0;
}
