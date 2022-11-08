class Solution {
 public:
  string interpret(string command) {
    const int n = command.size();
    int i = 0;
    string ans;
    while (i < n) {
      if (command[i] == 'G') {
        ans.push_back('G');
        ++i;
      } else {                        // '('
        if (command[i + 1] == ')') {  // ()
          ans.push_back('o');
          i += 2;
        } else {  // (al)
          ans.append("al");
          i += 4;
        }
      }
    }
    return ans;
  }
};