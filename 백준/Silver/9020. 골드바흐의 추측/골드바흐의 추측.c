#include <stdio.h>
#include <math.h>
int main(void) {
	int t, n;
	scanf("%d", &t);
	while ((t--) > 0) {
		int a[10000] = { 0, };
		int res[2] = { 0, };
		int aindex = 0;
		scanf("%d", &n);
		for (int i = 2; i < n; i++) {
			int end = (int)sqrt(i);
			if (i == 2 || i == 3) {
				a[aindex++] = i;
				continue;
			}
			for (int j = 2; j <= end; j++) {
				if (i % j == 0) break;
				else if (j == end && i % j != 0) a[aindex++] = i;
			}
		}
		for (int i = aindex - 1; i >= 0; i--) {
			int k = 0;
			if (a[i] * 2 == n) {
				res[0] = a[i];
				res[1] = a[i];
				break;
			}
			for (int j = i - 1; j >= 0; j--) {
				if (a[i] + a[j] == n) {
					if (res[0] == 0 || (res[1] - res[0] > a[i] - a[j])) {
						res[0] = a[j];
						res[1] = a[i];
					}
					break;
				}
			}
		}
		printf("%d %d\n", res[0], res[1]);
	}
	return 0;
}