#include <cstdio>

int main() {
	long long int n;
	scanf("%lld", &n);
	
	printf("%lld\n3\n", (n - 2) * (n - 1) * n / 6);
	return 0;
}