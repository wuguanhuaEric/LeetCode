#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canJump1(vector<int>& nums)
{
	int n = nums.size();
	vector<int> dp(n, 0);
	for (int i = 1; i < n; ++i)
	{
		dp[i] = max(dp[i - 1], nums[i - 1]) - 1;
		if (dp[i] < 0) return false;
	}
	return (dp.back() >= 0);
}

bool canJump2(vector<int>& nums)
{
	int n = nums.size();
	int reach = 0;
	for (int i = 0; i < n; ++i)
	{
		if (reach < i || reach >= n - 1) break;
		reach = max(reach, i + nums[i]);
	}
	return (reach >= n - 1);
}

int main(void)
{
	vector<int> nums1 = { 2, 3, 1, 1, 4 };
	vector<int> nums2 = { 3, 2, 1, 0, 4 };

	cout << canJump1(nums1) << endl;
	cout << canJump2(nums1) << endl;
	cout << canJump1(nums2) << endl;
	cout << canJump2(nums2) << endl;

	system("pause");
	return 0;
}