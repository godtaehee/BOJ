#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	vector<int> s;
	vector<int> real;
	
	int T, a, sum = 0;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> a;
		s.push_back(a);
	}

	sort(s.begin(), s.end());

	for (auto a : s) {
		sum += a;
		real.push_back(sum);
	}

	sum = 0;

	for (auto a : real)
		sum += a;

	cout << sum;


	return 0;
}
