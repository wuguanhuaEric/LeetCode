#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums)
{
	int n = nums.size();
	if (n == 0)
		return 0;
	if (n == 1)
		return nums[0];

	int sum_cur = nums[0];
	int max_sum = nums[0];

	for (int i = 1; i < n; ++i)
	{
		if (sum_cur > 0)
		{
			sum_cur += nums[i];
		}
		else
		{
			sum_cur = nums[i];
		}
		if (sum_cur > max_sum)
		{
			max_sum = sum_cur;
		}
	}
	return max_sum;
}

int main(void)
{
	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	size_t count = sizeof(arr) / sizeof(arr[0]);
	vector<int> vec(arr, arr + count);
	cout << maxSubArray(vec) << endl;

	system("pause");
	return 0;
}