#include <iostream>
#include <vector>
#include <algorithm>
#

using namespace std;

int minPathSum(vector<vector<int> > &grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int> > dp(m, vector<int>(n, 0));
	dp[0][0] = grid[0][0];
	for (int i = 1; i < m; ++i) dp[i][0] = grid[i][0] + dp[i - 1][0];
	for (int i = 1; i < n; ++i) dp[0][i] = grid[0][i] + dp[0][i - 1];
	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[m - 1][n - 1];
}

int main(void)
{
	int arr[][3] = { { 1, 3, 1 }, { 1, 5, 1 }, { 4, 2, 1 } };
	vector<vector<int> > vec;
	for (int i = 0; i < 3; ++i)
	{
		vec.push_back(vector<int>());
		for (int j = 0; j < 3; ++j)
		{
			vec[i].push_back(arr[i][j]);
		}
	}

	cout << minPathSum(vec) << endl;

	system("pause");
	return 0;
}