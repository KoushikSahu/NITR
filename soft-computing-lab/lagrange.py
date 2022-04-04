from sympy import symbols, Eq, solve


"""
    Author: Koushik Sahu
    Created: 2022-04-04 13:51 IST
"""


def problem_1():
    print("Online marketing department problem")
    print("===================================")
    s, t, l = symbols('s t l')

    eq1 = Eq((21/4)*((t**(1/4))/s**(1/4)) - 25*l, 0)
    eq2 = Eq((7/4)*(s**(3/4)/t**(3/4)) - 250*l, 0)
    eq3 = Eq(25*s+250*t - 2500, 0)
    eqs = [eq1, eq2, eq3]

    ans = solve(eqs, [s, t, l], simplify=False)
    print(f'(s, t, l) = {ans}', end='\n\n')


def problem_2():
    print("Maximizing x + y under the constraint that x^2 + y^2 = 1")
    print("========================================================")
    x, y, l = symbols('x y l')

    eq1 = Eq(2*x*l - 1, 0)
    eq2 = Eq(2*y*l - 1, 0)
    eq3 = Eq(x**2 + y**2 - 1, 0)
    eqs = [eq1, eq2, eq3]

    possible_solutions = solve(eqs, [x, y, l], simplify=False)
    print(f'Possible solutions: (x, y, l) = {possible_solutions}')

    def value(x, y): return x + y

    print(f'Iterating through all the possible solutions and maximizing x + y...')
    NEG_INF = -(1e9+5)
    curr_value = NEG_INF
    solution = ()
    for possible_solution in possible_solutions:
        x = possible_solution[0]
        y = possible_solution[1]
        val = value(x, y)
        if val > curr_value:
            curr_value = val
            solution = possible_solution

    print(f'Solution: (x, y, l) = {solution}')


def main():
    problem_1()
    problem_2()


if __name__ == '__main__':
    main()

