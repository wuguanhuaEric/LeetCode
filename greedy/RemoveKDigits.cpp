#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string removeKDigits(string num, int k)
{
	string res = "";
	int n = num.size(), keep = n - k;
	for (char c : num)
	{
		while (k && res.size() && res.back() > c)
		{
			res.pop_back();
			--k;
		}
		res.push_back(c);
	}
	res.resize(keep);
	while (!res.empty() && res[0] == '0')
	{
		res.erase(res.begin());
	}
	return res.empty() ? "0" : res;
}

int main(void)
{
	string s1 = "1432219";
	int k1 = 3;

	string s2 = "10200";
	int k2 = 1;

	string s3 = "10";
	int k3 = 2;

	cout << removeKDigits(s1, k1) << endl;
	cout << removeKDigits(s2, k2) << endl;
	cout << removeKDigits(s3, k3) << endl;
	
	system("pause");
	return 0;
}