/**
 * @file 155.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-05-11
 */
#include <bits/stdc++.h>
using namespace std;

class MinStack {
 private:
  vector<int> nums;
  vector<int> mins;

 public:
  MinStack() {}

  void push(int val) {
    nums.push_back(val);
    int idx = find_value(val);
    mins.insert(mins.begin() + idx, 1, val);
  }

  void pop() {
    int idx = find_value(*(nums.end() - 1));
    nums.erase(nums.end() - 1);
    mins.erase(mins.begin() + idx);
  }

  int top() { return *(nums.end() - 1); }

  int getMin() { return mins[0]; }

 private:
  int find_value(int val) {
    size_t i = 0, j = mins.size() - 1;
    while (i < j) {
      int mid = (i + j) / 2;
      if (mins[mid] == val) {
        return mid;
      } else if (mins[mid] < val) {
        i = mid + 1;
      } else {
        j = mid - 1;
      }
    }
    if (i >= mins.size())
      return mins.size();
    else if (j < 0)
      return 0;
    else {
      if (mins[i] < val)
        return i + 1;
      else
        return i;
    }
  }
};

int main(int argc, char const *argv[]) {
  MinStack s;
  s.push(-2);
  s.push(0);
  s.push(-3);
  cout << s.getMin() << endl;
  s.pop();
  cout << s.top() << endl;
  cout << s.getMin() << endl;
  return 0;
}
