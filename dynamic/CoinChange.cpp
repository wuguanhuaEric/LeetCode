#include <iostream>
#include <vector>

using namespace std;

int CoinChange(vector<int>& coins, int amount)
{
	vector<int> dp(amount + 1, -1);
	dp[0] = 0;
	for (int i = 0; i <= amount; ++i)
	{
		for (int j = 0; j < coins.size(); ++j)
		{
			if (i - coins[j] >= 0 && dp[i - coins[j]] != -1)
			{
				if (dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1)
				{
					dp[i] = dp[i - coins[j]] + 1;
				}
			}
		}
	}
	return dp[amount];
}


int main(void)
{
	int arr[] = {1, 2, 5, 7, 10};
	int count = sizeof(arr) / sizeof(arr[0]);
	vector<int> coins(arr, arr + count);
	for (int i = 0; i <= 14; ++i)
	{
		cout << CoinChange(coins, i) << endl;
	}

	system("pause");
	return 0;
}