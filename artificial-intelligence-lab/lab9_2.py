import math, statistics, collections

"""
    Author: Koushik Sahu
    Created: 29 November 2021 Mon 22:16:54
"""

def evening(is_evening):
    return (1/3 if is_evening else 2/3)

def line(line_no):
    if line_no == 6:
        return 1/5
    elif line_no == 22:
        return 1/2
    elif line_no == 24:
        return 3/10

def length(size, evening_happened, line_no):
    ans = 1
    if size == 'short':
        if evening_happened:
            if line_no == 6: ans *= 1
            elif line_no == 22: ans *= 1/10
            elif line_no == 24: ans *= 1/5
        elif not evening_happened:
            if line_no == 6: ans *= 9/10
            elif line_no == 22: ans *= 0
            elif line_no == 24: ans *= 1/5
    else:
        if evening_happened:
            if line_no == 6: ans *= 0
            elif line_no == 22: ans *= 9/10
            elif line_no == 24: ans *= 4/5
        elif not evening_happened:
            if line_no == 6: ans *= 1/10
            elif line_no == 22: ans *= 1
            elif line_no == 24: ans *= 4/5
    return ans

def destination(is_alberatov, line_no):
    if is_alberatov:
        if line_no == 6: return 1/10
        elif line_no == 22: return 1/10
        elif line_no == 24: return 9/10
    elif not is_alberatov:
        if line_no == 6: return 9/10
        elif line_no == 22: return 9/10
        elif line_no == 24: return 1/10

def solve(is_evening, line_no, size, is_alberatov):
    ans = 0
    for i in is_evening:
        for j in line_no:
            for k in size:
                for l in is_alberatov:
                    ans += evening(i) * line(j) * length(k, i, j) * destination(l, j)
    return ans

if __name__ == '__main__':
    # for the first problem
    print(f'Problem 1:')
    numr = solve([True], [6, 22, 24], ['short'], [True])
    deno = solve([True], [6, 22, 24], ['short'], [True, False])
    prob = numr / deno
    print(f'Probability: {prob}')
    
    print(f'Problem 2:')
    numr = solve([True, False], [22], ['long'], [True, False])
    deno = solve([True, False], [22], ['short', 'long'], [True, False])
    prob = numr / deno
    print(f'Probability: {prob}')
    