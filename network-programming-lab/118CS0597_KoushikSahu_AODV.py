
"""
    Author: Koushik Sahu
    Created: 2022-03-31 17:10 IST
"""


def get_input():
    n = int(input("Enter the number of nodes: "))
    m = int(input("Enter the number of edges: "))

    g = [[] for _ in range(n)]

    print("******* Enter topology *******")
    for _ in range(m):
        u, v = map(int, input("Enter nodes of the edges: ").split())
        u -= 1
        v -= 1
        g[u].append(v)
        g[v].append(u)

    src = int(input("Enter the source node: "))
    dest = int(input("Enter the destination node: "))
    src -= 1
    dest -= 1

    return n, m, g, src, dest


def dfs(u, dest, seen, parent, g, path, shortest_path):
    seen[u] = True
    path.append(u + 1)

    if u == dest:
        print(f"Route found: {path} \t Hop count: {len(path) - 1}")
        if len(shortest_path) == 0 or len(shortest_path) > len(path):
            shortest_path.clear()
            for i in path: shortest_path.append(i)
        
    for v in g[u]:
        if v != parent and not seen[v]:
            print(f"{u+1} sends RREQ to {v+1}")
            dfs(v, dest, seen, u, g, path, shortest_path)

    seen[u] = False
    path.pop()


def route_discovery(n, g, src, dest):
    seen = [False for _ in range(n)]
    path = []
    shortest_path = []
    dfs(src, dest, seen, -1, g, path, shortest_path)
    print(f"Path selected: {shortest_path} \t Hop Count: {len(shortest_path) - 1}")

    total_nodes = len(shortest_path)
    for idx, val in enumerate(reversed(shortest_path)):
        if idx + 1 < total_nodes:
            print(f"{val} sends RREP to {shortest_path[total_nodes - idx - 2]}")


def main():
    n, _, g, src, dest = get_input()
    print("***** Route discovery *****")
    route_discovery(n, g, src, dest)


if __name__ == '__main__':
    main()

