#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinArrowShots(vector<pair<int, int>>& points) {
	if (points.empty()) return 0;
	sort(points.begin(), points.end());
	int res = 1, end = points[0].second;
	for (int i = 1; i < points.size(); ++i) {
		if (points[i].first <= end) {
			end = min(end, points[i].second);
		}
		else {
			++res;
			end = points[i].second;
		}
	}
	return res;
}

int main(void)
{
	int arr[][4] = { { 10, 16 }, { 2, 8 }, { 1, 6 }, { 7, 12 } };
	vector<pair<int, int> > v;
	for (int i = 0; i < 4; ++i)
	{
		v.push_back(pair<int, int>());
		v[i].first = arr[i][0];
		v[i].second = arr[i][1];
	}
	cout << findMinArrowShots(v) << endl;

	system("pause");
	return 0;
}