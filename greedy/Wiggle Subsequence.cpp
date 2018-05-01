#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int wiggleMaxLength(vector<int>& nums) 
{
	int p = 1, q = 1, n = nums.size();
	for (int i = 1; i < n; ++i) {
		if (nums[i] > nums[i - 1]) p = q + 1;
		else if (nums[i] < nums[i - 1]) q = p + 1;
	}

	return min(n, max(p, q));
}

int main(void)
{
	vector<int> v1 = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };
	vector<int> v2 = { 1, 7, 4, 9, 2, 5 };
	vector<int> v3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	cout << wiggleMaxLength(v1) << endl;
	cout << wiggleMaxLength(v2) << endl;
	cout << wiggleMaxLength(v3) << endl;

	system("pause");
	return 0;
}