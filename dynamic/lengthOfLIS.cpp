#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int>& nums)
{
	vector<int> dp(nums.size(), 1);
	int res = 0;

	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (nums[i] > nums[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		res = max(res, dp[i]);
	}
	return res;
}

int main(void)
{
	int arr[] = { 10, 9, 2, 5, 3, 7, 101, 18 };
	int count = sizeof(arr) / sizeof(arr[0]);
	vector<int> vec(arr, arr + count);
	int res = lengthOfLIS(vec);
	cout << res << endl;

	system("pause");
	return 0;
}