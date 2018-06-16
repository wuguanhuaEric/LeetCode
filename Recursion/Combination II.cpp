#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void generate(int i, int sum, int target, vector<int>& nums, vector<vector<int> >& result, vector<int>& item, set<vector<int> >& res_set)
{
	if (i >= nums.size() || sum > target)
	{
		return;
	}
	sum += nums[i];
	item.push_back(nums[i]);
	if (target == sum && res_set.find(item) == res_set.end())
	{
		result.push_back(item);
		res_set.insert(item);
	}
	generate(i + 1, sum, target, nums, result, item, res_set);
	sum -= nums[i];
	item.pop_back();
	generate(i + 1, sum, target, nums, result, item, res_set);
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
	vector<vector<int> > result;
	vector<int> item;
	set<vector<int> > res_set;
	int sum = 0;
	sort(candidates.begin(), candidates.end());
	generate(0, sum, target, candidates, result, item, res_set);
	return result;
}

int main(void)
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);

	vector<vector<int> > result;
	result = combinationSum2(nums, 5);
	for (int i = 0; i < result.size(); ++i)
	{
		if (result[i].size() == 0)
			printf("[]");
		for (int j = 0; j < result[i].size(); ++j)
			printf("[%d]", result[i][j]);
		printf("\n");
	}

	system("pause");
	return 0;
}