#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int jump(vector<int>& nums)
{
	if (nums.size() < 2)
		return 0;
	
	int cur_max = nums[0];
	int pre_max = nums[0];
	int jump_min = 1;

	for (int i = 1; i < nums.size(); ++i)
	{
		if (cur_max < i)
		{
			jump_min++;
			cur_max = pre_max;
		}
		if (pre_max < nums[i] + i)
		{
			pre_max = nums[i] + i;
		}
	}
	return jump_min;
}

int main(void)
{
	vector<int> nums1 = { 2, 3, 1, 1, 4 };

	cout << jump(nums1) << endl;

	system("pause");
	return 0;
}