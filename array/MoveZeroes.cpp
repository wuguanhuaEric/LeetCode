#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) 
{
	for (int last = 0, cur = 0; cur < nums.size(); cur++) 
	{
		if (nums[cur] != 0)
		{
			if (last != cur)
			{
				swap(nums[last++], nums[cur]);
			}
			else
			{
				last++;
			}
		}
	}
}

int main(void)
{
	int arr[] = { 1, 0, 3, 0, 2 }; 
	int count = sizeof(arr) / sizeof(arr[0]);
	vector<int> vec(arr, arr + count);
	moveZeroes(vec);
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}