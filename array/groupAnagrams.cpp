#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<string> >  groupAnagrams(vector<string>& strs)
{
	vector<vector<string> >  res;
	unordered_map<string, vector<string> > m;
	for (string str : strs)
	{
		string t = str;
		sort(t.begin(), t.end());
		m[t].push_back(str);
	}

	for (auto a : m)
	{
		res.push_back(a.second);
	}

	return res;
}

int main(void)
{
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string> > res = groupAnagrams(strs);
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