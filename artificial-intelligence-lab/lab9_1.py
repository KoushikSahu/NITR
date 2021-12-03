"""
    Author: Koushik Sahu
    Created: 28 November 2021 Sun 18:31:27
"""

def buglary(happened):
    return (0.002 if happened else 0.998)

def earthquake(happened):
    return (0.001 if happened else 0.998)

def alarm(happened, buglary, earthquake):
    if buglary and earthquake:
        return (0.94 if happened else 0.06)
    elif buglary and not earthquake:
        return (0.95 if happened else 0.04)
    elif not buglary and earthquake:
        return (0.69 if happened else 0.69)
    return (0.001 if happened else 0.999)

def davidcalls(happened, alarm):
    if alarm:
        return (0.91 if happened else 0.09)
    return (0.05 if happened else 0.95)

def sophiecalls(happened, alarm):
    if alarm:
        return (0.75 if happened else 0.25)
    return (0.02 if happened else 0.98)

def solve(sophie_called,
            david_called,
            alarm_rang,
            buglary_occured,
            earthquake_occured):
    return sophiecalls(sophie_called, alarm_rang) * \
            davidcalls(david_called, alarm_rang) * \
            alarm(alarm_rang, buglary_occured, earthquake_occured) * \
            buglary(buglary_occured) * \
            earthquake(earthquake_occured)

if __name__ == '__main__':
    print(f'Did sophie call? (y/n): ', end='')
    sophie_called = (True if str(input()).upper() == 'Y' else False)
    print(f'Did david call? (y/n): ', end='')
    david_called = (True if str(input()).upper() == 'Y' else False)
    print(f'Did alarm ring? (y/n): ', end='')
    alarm_rang = (True if str(input()).upper() == 'Y' else False)
    print(f'Did buglary happen? (y/n): ', end='')
    buglary_occured = (True if str(input()).upper() == 'Y' else False)
    print(f'Did earthquake happen? (y/n): ', end='')
    earthquake_occured = (True if str(input()).upper() == 'Y' else False)

    prob = solve(sophie_called, 
                    david_called,
                    alarm_rang,
                    buglary_occured,
                    earthquake_occured)

    print(f'Probability: {prob}')
    