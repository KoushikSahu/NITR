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
    print('Enter starting location(a/b): ', end='')
    loc = input()
    assert(loc=='a' or loc=='b')
    print('Is location A dirty?(y/n): ', end='')
    a_dirty = input()
    assert(a_dirty=='y' or a_dirty=='n')
    print('Is location B dirty?(y/n): ', end='')
    b_dirty = input()
    assert(b_dirty=='y' or b_dirty=='n')
    dirt = list()
    dirt.append('dirty' if a_dirty=='y' else 'clean')
    dirt.append('dirty' if b_dirty=='y' else 'clean')
    env = Environment(loc, dirt)
    action = list()
    while valid(action):
        action.append(env.move())
    print(f'Actions: {action}')
    print(f'Performance score: {env.performance_score()}')

