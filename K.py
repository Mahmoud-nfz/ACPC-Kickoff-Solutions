t = int(input())
for _ in range(t):
    n = int(input())
    p = n 
    MOD = 1000000007
    print(((n * (n+1) * (n+2))//3 - p - (3*p*p +1) // 4) % MOD )