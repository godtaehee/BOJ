#include <vector>

using namespace std;

long long sum(vector<int> &a) {
	long long ans = 0;
    for(auto b : a)
        ans+=b;
	return ans;
}
