#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
	int m = dungeon.size(), n = dungeon[0].size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
	dp[m][n - 1] = 1; dp[m - 1][n] = 1;
	for (int i = m - 1; i >= 0; --i) {
		for (int j = n - 1; j >= 0; --j) {
			dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
		}
	}
	return dp[0][0];
}

int main(void)
{  
	int arr[][3] = { { -2, -3, 3 }, { -5, -10, 1 }, { 10, 30, -5 } };
	vector<vector<int> > vec;
	for (int i = 0; i < 3; ++i)
	{
		vec.push_back(vector<int>());
		for (int j = 0; j < 3; ++j)
		{
			vec[i].push_back(arr[i][j]);
		}
	}
	cout << calculateMinimumHP(vec) << endl;

	system("pause");
	return 0;
}
