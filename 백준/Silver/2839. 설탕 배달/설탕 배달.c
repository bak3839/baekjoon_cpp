#include <stdio.h>
int main(void) {
	int N, A = -1;
	scanf("%d", &N);
	if (N < 5) {
		if (N == 3) printf("1");
		else printf("-1");
	}
	else if (N == 7) printf("-1");
	else if (N % 5 == 0 && N >= 5) printf("%d", N / 5);
	else if (N % 5 != 0) {
		A = N / 5;
		if (N % 5 == 1) printf("%d", (A - 1) + 2);
		else if (N % 5 == 2) printf("%d", (A - 2) + 4);
		else if (N % 5 == 3) printf("%d", A + 1);
		else printf("%d", (A - 1) + 3);
	}
	else printf("%d", A);
	return 0;
}