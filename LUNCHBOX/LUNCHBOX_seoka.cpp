#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<vector>
#include<algorithm>

#pragma warning(disable:4996)

using namespace std;

bool compare(pair<int, int> left, pair<int, int> right) {
	return left.second > right.second;
}

int main() {
	int n, maxsum, temp = 0, endtime;
	int NOL; // number of lunch
	int M, E;

	vector< pair<int, int> > lunchbox;

	cin >> n;

	for (int i = 0; i < n; i++) {
		maxsum = 0;
		temp = 0;

		cin >> NOL;

		lunchbox.resize(NOL);

		for (int j = 0; j < NOL; j++) {
			cin >> M;
			lunchbox[j].first = M;
		}

		for (int j = 0; j < NOL; j++) {
			cin >> E;
			lunchbox[j].second = E;
		}

		sort(lunchbox.begin(), lunchbox.end(), compare);

		vector< pair<int, int> >::iterator iter;
		for (iter = lunchbox.begin(); iter != lunchbox.end(); iter++) {
			temp += iter->first; //temp M�����ð�
			endtime = temp + iter->second;
			if (maxsum <= endtime) maxsum = endtime;
		}

		cout << maxsum << endl;
		lunchbox.clear();
	}

	return 0;
}