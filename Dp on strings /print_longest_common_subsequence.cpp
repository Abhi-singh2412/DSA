#include <bits/stdc++.h>
using namespace std;

string helper(string &s1, string &s2) {
  int n = s1.size();
  int m = s2.size();
  vector<vector<int>> dp(
      n + 1,
      vector<int>(
          m + 1,
          -1)); // i did n + 1 and m +1 because this dp matrix is 1 based
                // indexing not 0 based look at striver video u will understand
                // (it is mainly because u cant represent -1 contion in the base
                // case as u did in memoization so here index 0 is treated as
                // index -1 and similarily index 2 will be index 1 and index 4
                // will be index 3 so onn)

  // base case
  for (int j = 0; j <= m; j++)
    dp[0][j] = 0;
  for (int i = 0; i <= n; i++)
    dp[i][0] = 0; // here [i][0] represents [i][-1] and similariy same for j

  // tabulation
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  int len = dp[n][m];
  string ans = "";
  for (int i = 0; i < len; i++) {
    ans += "$";
  }

  int index = len - 1;

  int i = n, j = m;

  while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) {
      ans[index] = s1[i - 1];
      index--;
      i--, j--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }
  return ans;
}

int main() {
  string s1 = "csyuhakcaukc";
  string s2 = "cahuwkauchucxahu";

  string ans = helper(s1, s2);
  cout << ans << " ";
}