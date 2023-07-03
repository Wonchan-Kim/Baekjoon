#include <string>
#include <vector>
#include <iostream>

using namespace std;

int n;
char mat[11][11];
string str;
vector<int> v;

bool check(int cnt)
{
	for (int i = 0; i < v.size(); i++)
	{
		int sum = 0;
		for (int j = i; j < v.size(); j++)
		{
			sum += v[j];

			if (sum == 0 && mat[i][j] != '0')
				return false;
			if (sum > 0 && mat[i][j] != '+')
				return false;
			if (sum < 0 && mat[i][j] != '-')
				return false;
		}
	}

	return true;
}

void func(int cnt)
{
	if (cnt == n)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << ' ';
		exit(0);
	}

	for (int i = -10; i <= 10; i++)
	{
		v.push_back(i);
		if (check(cnt))
			func(cnt + 1);
		v.pop_back();
	}
}

int main(void)
{
	cin >> n >> str;

	int idx = 0;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			mat[i][j] = str[idx++];
	func(0);
}