#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.first > b.first;
}

int get_min_stop(int L, int P, vector<pair<int, int> > &stop)
{
	priority_queue<int> Q;
	int result = 0;
	stop.push_back(make_pair(0, 0));
	sort(stop.begin(), stop.end(), cmp);
	for (int i = 0; i < stop.size(); ++i)
	{
		int dis = L - stop[i].first;
		while (!Q.empty() && P < dis)
		{
			P += Q.top();
			Q.pop();
			result++;
		}
		if (Q.empty() && P < dis)
		{
			return -1;
		}
		P = P - dis;
		L = stop[i].first;
		Q.push(stop[i].second);
	}
	return result;
}

int main(void)
{
	vector<pair<int, int> > stop;
	int N;
	int L;
	int P;
	int distance;
	int fuel;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> distance >> fuel;
		stop.push_back(make_pair(distance, fuel));
	}
	cin >> L >> P;
	cout << get_min_stop(L, P, stop) << endl;

	system("pause");
	return 0;
}