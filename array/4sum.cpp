#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	set<vector<int> > res;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < int(nums.size() - 3); i++)
	{
		for (int j = i + 1; j < int(nums.size() - 2); j++)
		{
			if (j > i + 1 && nums[j] == nums[j - 1])
			{
				continue;
			}
			int left = j + 1;
			int right = nums.size() - 1;
			while (left < right)
			{
				if (nums[i] + nums[j] + nums[left] + nums[right] == target)
				{
					res.insert({ nums[i], nums[j], nums[left], nums[right] });
					left++;
					right--;
				}
				else if (nums[i] + nums[j] + nums[left] + nums[right] < target)
				{
					left++;
				}
				else
				{
					right--;
				}
			}
		}
	}
	return vector<vector<int> >(res.begin(), res.end());
}

int main(void)
{
	vector<int> nums;
	nums = { 1, 0, -1, 0, -2, 2 };
	vector<vector<int> > res = fourSum(nums, 0);
	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < res[i].size(); ++j)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}