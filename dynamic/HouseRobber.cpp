#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int>& num)
{
	if (num.size() <= 1) return num.empty() ? 0 : num[0];
	vector<int> dp = {num[0], max(num[0], num[1])};
	for (int i = 2; i < num.size(); ++i)
	{
		dp.push_back(max(dp[i - 2] + num[i], dp[i - 1]));
	}
	return dp.back();
}

int main(void)
{
	int arr[] = { 5, 2, 6, 3, 1, 7 };
	size_t count = sizeof(arr) / sizeof(int);
	//initial vec
	vector<int> vec(arr, arr + count);
	cout << rob(vec) << endl;
	
	system("pause");
	return 0;
}

