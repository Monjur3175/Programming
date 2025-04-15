def main():
    import sys
    input = sys.stdin.read().split()
    idx = 0
    T = int(input[idx])
    idx += 1
    for _ in range(T):
        N = int(input[idx])
        idx += 1
        S = input[idx]
        idx += 1
        a = S.count('-')
        m = S.count('_')
        left = a // 2
        right = (a + 1) // 2
        print(m * left * right)

if __name__ == "__main__":
    main()