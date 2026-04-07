#include <bits/stdc++.h>
using namespace std;

bool helper(int ind, int k, vector<int> &arr, vector<vector<int>> &dp) {
  if (k == 0)
    return true;

  if (ind == 0)
    return (arr[0] == k);

  if (dp[ind][k] != -1)
    return dp[ind][k];

  bool nottake = helper(ind - 1, k, arr, dp);
  bool take = false;
  if (k >= arr[ind])
    take = helper(ind - 1, k - arr[ind], arr, dp);

  return dp[ind][k] = take | nottake;
}

bool subsetsum(vector<int> &arr, int target, vector<vector<int>> &dp) {
  int n = arr.size();
  return helper(n - 1, target, arr, dp);
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5};
  int target = 10;
  vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));
  cout << subsetsum(arr, target, dp) << endl;
}