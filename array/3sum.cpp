#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<vector<int> > threeSum(vector<int>& nums)
{
	set<vector<int> > res;
	sort(nums.begin(), nums.end());
	for (int k = 0; k < nums.size(); ++k)
	{
		if (nums[k] > 0)
		{
			break;
		}
		int target = 0 - nums[k];
		int i = k + 1;
		int j = nums.size() - 1;
		while (i < j)
		{
			if (nums[i] + nums[j] == target)
			{
				res.insert({ nums[k], nums[i], nums[j] });
				while (i < j && nums[i] == nums[i + 1]) i++;
				while (i < j && nums[j] == nums[j - 1]) j--;
				i++;
				j--;
			}
			else if (nums[i] + nums[j] < target)
			{
				i++;
			}
			else
			{
				j--;
			}
		}
	}
	
	return vector<vector<int> >(res.begin(), res.end());
}

int main(void)
{
	vector<int> nums;
	nums = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int> > res = threeSum(nums);
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