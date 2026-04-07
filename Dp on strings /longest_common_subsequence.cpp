#include <bits/stdc++.h>
using namespace std;

int original(int ind1, int ind2, string &s1, string &s2) {
  if (ind1 < 0 || ind2 < 0)
    return 0;

  if (s1[ind1] == s2[ind2])
    return 1 + original(ind1 - 1, ind2 - 1, s1, s2);
  else
    return 0 + max(original(ind1 - 1, ind2, s1, s2),
                   original(ind1, ind2 - 1, s1, s2));
}

int helper(string &s1, string &s2) {
  int n = s1.size();
  int m = s2.size();

  return original(n - 1, m - 1, s1, s2);
}

int main() {
  string s1 = "abcd";
  string s2 = "abrt";

  int ans = helper(s1, s2);

  cout << ans << " ";
}