import math, statistics, collections

class Environment:
    def __init__(self, curr_location, dirt, dirt_size=1, suck_score=5, move_time=1):
        self.dirt = {'a': True if dirt[0].lower() == 'dirty' else False,
                'b': True if dirt[1].lower() == 'dirty' else False}
        self.curr_location = curr_location.lower()
        self.score = 0
        self.scoring_system = {
            'suck': suck_score,
            'dirt_size': dirt_size,
            'move_time': move_time
        }

    def move(self):
        if self.dirt[self.curr_location]:
            return self.suck()
        else:
            if self.curr_location == 'a':
                return self.right()
            else:
                return self.left()

    def performance_score(self):
        return self.score

    def suck(self):
        self.score += self.scoring_system['suck']
        self.score += self.scoring_system['dirt_size']
        self.dirt[self.curr_location] = False
        return f'Suck'

    def left(self):
        self.curr_location = 'a'
        self.score -= self.scoring_system['move_time']
        return f'Left'

    def right(self):
        self.curr_location = 'b'
        self.score -= self.scoring_system['move_time']
        return f'Right'

def valid(actions):
    if len(actions)>=2:
        return actions[-1]=='Suck' or actions[-2]=='Suck'
    return True

if __name__ == '__main__':
    curr_location_pos = ['a', 'b']
    dirt_pos = [('clean', 'clean'),
            ('clean', 'dirty'),
            ('dirty', 'clean'),
            ('dirty', 'dirty')]
    for loc in curr_location_pos:
        for dirt in dirt_pos:
            env = Environment(loc, dirt)
            actions = list()
            while valid(actions):
                actions.append(env.move())
            print(f'Starting location: {loc}')
            print(f'Dirt position: {dirt}')
            print(f'Actions: {actions}')
            print(f'Performance measure: {env.performance_score()}')

