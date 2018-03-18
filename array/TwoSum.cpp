#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
	vector<int> res;
	int len = nums.size();
	map<int, int> m;
	for (int i = 0; i < len; i++)
	{
		if (m.count(target - nums[i]))
		{
			res.push_back(i);
			res.push_back(nums[target - nums[i]]);
			return res;
		}
		m[nums[i]] = i;
	}
	
	return res;
}	

template <class T>
int getArrayLen(T& array)
{
	return (sizeof(array) / sizeof(array[0]));
}

int main(void)
{
	int arr[] = { 2, 7, 11, 5 };
	vector<int> testVec;
	
	for (int i = 0; i < getArrayLen(arr); i++)
	{
		testVec.push_back(arr[i]);
	}

	cout << testVec.size() << endl;
	vector<int> res(twoSum(testVec, 9));
	cout << res.size() << endl;
	
	system("pause");
	return 0;
}