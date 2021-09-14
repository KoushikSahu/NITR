import math, statistics, collections, copy

INF = int(1e9+5)

def take_input():
    print('Enter the number of cities: ', end='')
    n = int(input())
    print('Enter the number of edges: ', end='')
    m = int(input())
    global INF
    g = [[INF for i in range(n)] for i in range(n)]
    for i in range(m):
        print('Enter src dest wt: ', end='')
        u, v, wt = map(int, input().split())
        g[u][v] = wt
    return n, m, g

def pretty_print(x):
    for i in range(len(x)):
        print(" ".join(str(x[i])))

class BranchBound:
    def __init__(self, n, g):
        self.n = n
        self.g = g

    def run(self, src):
        optimal_path = list()
        gl = list()
        cst, g = BranchBound.eval_cost(self.g)
        for i in range(self.n): g[i][0] = INF
        gl.append((cst, src, g))
        while len(gl) > 0:
            print('available cities at this level:')
            for i in gl:
                print(f'vertex: {i[1]} cost: {i[0]}')
            cst, u, g = min(gl, key=lambda x: x[0])
            print('city choosen:')
            print(f'vertex: {u} cost: {cst}')
            if cst < INF:
                optimal_path.append(u)
                gl.clear()
                for i in range(self.n):
                    edge_cst = g[u][i]
                    if edge_cst < INF:
                        new_g = BranchBound.add_edge(g, u, i)
                        cst1, new_g = BranchBound.eval_cost(new_g)
                        gl.append((cst+edge_cst+cst1, i, new_g))
        return optimal_path
            
    @staticmethod
    def eval_cost(g_in):
        g = copy.deepcopy(g_in)
        n = len(g)
        cst = 0
        for i in range(n):
            cst += min(g[i][:])
            cst += min(g[:][i])
        for i in range(n):
            mn = min(g[i][:])
            for j in range(n):
                if g[i][j] < INF:
                    g[i][j] -= mn
        for j in range(n):
            mn = min(g[:][j])
            for i in range(n):
                if g[i][j] < INF:
                    g[j][i] -= mn
        if cst >= INF: cst = 0
        return cst, g

    @staticmethod
    def add_edge(g_in, u, v):
        g = copy.deepcopy(g_in)
        n = len(g)
        for i in range(n):
            g[u][i] = INF
            g[i][v] = INF
        g[v][u] = INF
        return g

if __name__ == '__main__':
    n, m, g = take_input()
    bb = BranchBound(n, g)
    optimal_path = bb.run(0)
    optimal_path.append(0)
    print(f'Optimal path: {optimal_path}')

