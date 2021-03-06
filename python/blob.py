import random


class Blob(object):

    def __init__(self, color, x_bound, y_bound, size_range=(4, 8), move_range=(-4, 5)):
        self.size = random.randrange(size_range[0], size_range[1])
        self.color = color
        self.x_bound = x_bound
        self.y_bound = y_bound
        self.x = random.randrange(0, self.x_bound)
        self.y = random.randrange(0, self.y_bound)
        self.move_range = move_range

    def move(self):
        self.move_x = random.randrange(self.move_range[0], self.move_range[1])
        self.move_y = random.randrange(self.move_range[0], self.move_range[1])
        self.x += self.move_x
        self.y += self.move_y

        if self.x < 0:
            self.x = 0
        elif self.x > self.x_bound:
            self.x = self.x_bound

        if self.y < 0:
            self.y = 0
        elif self.y > self.y_bound:
            self.y = self.y_bound
