#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

void generate(string item, int left, int right, vector<string>& result)
{
	if (left == 0 && right == 0)
	{
		result.push_back(item);
		return;
	}

	if (left > 0)
	{
		generate(item + "(", left - 1, right, result);
	}

	if (left < right)
	{
		generate(item + ")", left, right - 1,  result);
	}
}

int main(void)
{
	vector<string> result;
	generate("", 3, 3, result);
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << endl;
	}

	system("pause");
	return 0;
}