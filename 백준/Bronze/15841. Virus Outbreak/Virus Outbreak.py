DP = [0 for _ in range(491)]
DP[1] = 1
DP[2] = 1
prev = 2
while True:
    n = int(input())
    if prev < n:
        for i in range(prev + 1, n + 1):
            DP[i] = DP[i - 1] + DP[i - 2]

    if n == -1:
        break;
    print(f'Hour {n}: {DP[n]} cow(s) affected')