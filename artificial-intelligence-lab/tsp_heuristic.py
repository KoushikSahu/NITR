import math, statistics, collections, copy

INF = 1e9+5

def take_input():
    # print('Enter the number of cities: ', end='')
    n = int(input())
    # print('Enter the number of edges: ', end='')
    m = int(input())
    g = list()
    for i in range(m):
        g.append([])
    for i in range(m):
        # print('Enter src dest wt: ', end='')
        u, v, wt = map(int, input().split())
        g[u].append((v, wt))
    return n, m, g

res = INF

def dfs(u, seen, cost, g, curr_path, optimal_path):
    seen[u] = True
    global res
    curr_path.append(u)
    for v, wt in g[u]:
        if v==0:
            seen_all = True
            for i in seen:
                seen_all &= i
            if seen_all:
                present_path = copy.deepcopy(curr_path)
                present_path.append(0)
                print(f'path considered: {present_path} cost: {cost+wt}')
                if cost+wt < res:
                    res = cost+wt
                    optimal_path.clear()
                    for city in curr_path: optimal_path.append(city)
        else:
            if not seen[v]:
                child_res = dfs(v, seen, cost+wt, g, curr_path, optimal_path)
                if child_res < res:
                    res = child_res
    seen[u] = False
    curr_path.pop()
    return res

if __name__ == '__main__':
    n, m, g = take_input()
    cost = 0
    seen = [False]*n
    curr_path = list()
    optimal_path = list()
    print(f'****** Brute forcing all the paths ******')
    min_cost = dfs(0, seen, cost, g, curr_path, optimal_path)
    optimal_path.append(0)
    print(f'Minimum cost: {min_cost}')
    print(f'Optimal path: {optimal_path}')

