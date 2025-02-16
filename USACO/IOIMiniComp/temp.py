import sys

input_data = sys.stdin.read().strip().split()
t = int(input_data[0])
index = 1

for _ in range(t):
    n = input_data[index]
    index += 1
    
    # Compute the sum of digits modulo 9
    s_mod_9 = sum(int(d) for d in n) % 9
    
    # If already divisible by 9, answer immediately
    if s_mod_9 == 0:
        print("YES")
        continue
    
    # Prepare a DP array for residues mod 9
    dp = [False]*9
    dp[0] = True
    
    # We only need to account for digits 2 (which can become 4 => +2 mod 9)
    # and 3 (which can become 9 => +6 mod 9).
    # Each occurrence of '2' or '3' can add either 0 or its respective increment (2 or 6 mod 9).
    
    for d in n:
        if d == '2':
            new_dp = dp[:]
            for r in range(9):
                # If dp[r] was reachable, then dp[(r+2) mod 9] can also be reached
                if dp[r]:
                    new_dp[(r + 2) % 9] = True
            dp = new_dp
        elif d == '3':
            new_dp = dp[:]
            for r in range(9):
                # If dp[r] was reachable, then dp[(r+6) mod 9] can also be reached
                if dp[r]:
                    new_dp[(r + 6) % 9] = True
            dp = new_dp
    
    # We want (s_mod_9 + increment) % 9 == 0 => increment % 9 == (-s_mod_9) % 9
    need = (-s_mod_9) % 9
    print("YES" if dp[need] else "NO")
