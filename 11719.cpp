#include <iostream>

using namespace std;

int main() {

	char s[100];

	while (fgets(s, 100, stdin)) {
		printf("%s", s);
	}

	return 0;
}
