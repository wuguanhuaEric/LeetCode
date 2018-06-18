#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

int dis(const pair<int, int>& pa, const pair<int, int>& pb)
{
	int d = (pa.first - pb.first)*(pa.first - pb.first) + (pa.second - pb.second)*(pa.second - pb.second);
	return d;
}

int numberOfBoomerangs(vector<pair<int, int>>& points)
{
	int res = 0;
	for (int i = 0; i < points.size(); ++i)
	{
		unordered_map<int, int> record;
		for (int j = 0; j < points.size(); ++j)
		{
			if (i != j)
			{
				record[dis(points[i], points[j])]++;
			}
		}

		for (unordered_map<int, int> ::iterator iter = record.begin(); iter != record.end(); ++iter)
		{
			res += (iter->second) * (iter->second - 1);
		}
	}
	return res;
}

int main(void)
{
	vector<pair<int, int> > strs = { {0, 0 }, { 1, 0 }, { 2, 0 }};
	int res = numberOfBoomerangs(strs);
	
	cout << res << endl;

	system("pause");
	return 0;
}