from blob import Blob
import random
import pygame
import numpy as np

STARTING_BLUE_BLOBS = 10
STARTING_RED_BLOBS = 3
STARTING_GREEN_BLOBS = 5
WIDTH = 800
HEIGHT = 600
WHITE = (255, 255, 255)
RED = (255, 0, 0)
BLUE = (0, 0, 255)
GREEN = (0, 255, 0)

game_display = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption('Blob World')
clock = pygame.time.Clock()


class BlueBlob(Blob):
    def __init__(self, x_bound, y_bound):
        super(BlueBlob, self).__init__(BLUE, x_bound, y_bound)

    def __add__(self, blob):
        if blob.color == RED:
            self.size -= blob.size
            blob.size -= self.size
        elif blob.color == GREEN:
            self.size += blob.size
            blob.size = 0
        elif blob.color == BLUE:
            pass
        else:
            raise Exception('Tried to combine blobs of unsupported colors.')


class RedBlob(Blob):
    def __init__(self, x_bound, y_bound):
        super(RedBlob, self).__init__(RED, x_bound, y_bound)


class GreenBlob(Blob):
    def __init__(self, x_bound, y_bound):
        super(GreenBlob, self).__init__(GREEN, x_bound, y_bound)


def is_touching(b1, b2):
    return np.linalg.norm(np.array([b1.x, b1.y]) - np.array([b2.x, b2.y])) < (b1.size + b2.size)


def handle_collisions(blob_list):
    blues, reds, greens = blob_list
    for bid, bblob in blues.copy().items():
        for other in reds, greens:
            for oid, oblob in other.copy().items():
                if bblob == oblob:
                    pass
                else:
                    if is_touching(bblob, oblob):
                        bblob + oblob
                        if oblob.size <= 0:
                            del other[oid]
                        if bblob.size <= 0:
                            del blues[bid]
    return blues, reds, greens


def draw_env(blob_list):
    blues, reds, greens = handle_collisions(blob_list)
    game_display.fill(WHITE)
    for blob_dict in blob_list:
        for blob_id in blob_dict:
            blob = blob_dict[blob_id]
            pygame.draw.circle(game_display, blob.color, [blob.x, blob.y], blob.size)
            blob.move()
    pygame.display.update()
    return blues, reds, greens


def main():
    blue_blobs = dict(enumerate([BlueBlob(WIDTH, HEIGHT) for i in range(STARTING_BLUE_BLOBS)]))
    red_blobs = dict(enumerate([RedBlob(WIDTH, HEIGHT) for i in range(STARTING_RED_BLOBS)]))
    green_blobs = dict(enumerate([GreenBlob(WIDTH, HEIGHT) for i in range(STARTING_GREEN_BLOBS)]))
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                quit()

        blue_blobs, red_blobs, green_blobs = draw_env([blue_blobs, red_blobs, green_blobs])
        clock.tick(60)


if __name__ == '__main__':
    main()
