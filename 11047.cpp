#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> s;

	int n, m, a;
	int count = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a;
		if(m - a >= 0)
			s.push_back(a);
	}

	while (m != 0) {
		if (m - s.back() >= 0) {
			m -= s.back();
			count++;
		}
		else
			s.pop_back();
	}

	cout << count;






	return 0;
}
