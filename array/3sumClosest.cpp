#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target)
{
	int closest = nums[0] + nums[1] + nums[2];
	int diff = abs(target - closest);
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 2; ++i)
	{
		int left = i + 1;
		int right = nums.size() - 1;
		int sum = nums[i] + nums[left] + nums[right];
		int new_diff = abs(sum - target);
		if (new_diff < diff)
		{
			diff = new_diff;
			closest = sum;
		}
		if (sum < target)
		{
			left++;
		}
		else
		{
			right--;
		}
	}

	return closest;
}

int main(void)
{
	vector<int> nums;
	nums = { -1, 2, 1, -4 };
	int res = threeSumClosest(nums, 0);
	cout << res << endl;

	system("pause");
	return 0;
}