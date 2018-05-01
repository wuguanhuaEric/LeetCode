#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) 
{
	int j = 0;
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());
	for (int i = 0; i < s.size() && j < g.size(); ++i) 
	{
		if (s[i] >= g[j]) ++j;
	}
	return j;
}

int main(void)
{
	vector<int> g = { 5, 10, 2, 9, 15, 9 };
	vector<int> s = {6, 1, 20, 3, 8};

	cout << findContentChildren(g, s) << endl;
	system("pause");
	return 0;
}