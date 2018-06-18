#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
{
	int res = 0;
	unordered_map<int, int> m;
	for (int i = 0; i < A.size(); ++i)
	{
		for (int j = 0; j < B.size(); ++j)
		{
			++m[A[i] + B[j]];
		}
	}

	for (int i = 0; i < C.size(); ++i)
	{
		for (int j = 0; j < D.size(); ++j)
		{
			if (m.find(-C[i] - D[j]) != m.end())
			{
				res += m[-C[i] - D[j]];
			}
		}
	}

	return res;
}

int main(void)
{
	vector<int> A = { 1, 2 };
	vector<int> B = { -2, -1 };
	vector<int> C = { -1, 2 };
	vector<int> D = {0, 2};

	int res = fourSumCount(A, B, C, D);
	cout << res << endl;

	system("pause");
	return 0;
}