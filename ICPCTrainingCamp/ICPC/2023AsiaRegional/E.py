def power(y, a, m, visited):
    if y == 0:
        return 1
    elif y == 1:
        return a % m
    elif y in visited:
        return visited[y]
    elif y % 2 == 0:
        p = power(y // 2, a, m, visited) % m
        visited[y] = ((p * p) - 2) % m
        return visited[y]
    else:
        p1 = power(y // 2, a, m, visited) % m
        p2 = power(y // 2 + 1, a, m, visited) % m
        visited[y] = ((p1 * p2) - a) % m
        return visited[y]


def main():
    a, b, m = map(int, input().split())
    visited = {}
    res = power(b, a, m, visited)
    if res < 0:
        res += m
    print(res)


if __name__ == "__main__":
    main()

