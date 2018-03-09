def simple_gen():
    yield 'oh'
    yield 'hello'
    yield 'there'

for i in simple_gen():
    print(i)

CORRECT_COMBO = (3, 6, 1)

found = False
for c1 in range(10):
    for c2 in range(10):
        for c3 in range(10):
            if (c1, c2, c3) == CORRECT_COMBO:
                print('Found the combo: {}'.format((c1, c2, c3)))
                found = True
                break
            print(c1, c2, c3)
        if found:
            break
    if found:
        break
# All this code can converted to a generator


def combo_gen():
    for c1 in range(10):
        for c2 in range(10):
            for c3 in range(10):
                yield(c1, c2, c3)

for (c1, c2, c3) in combo_gen():
    print(c1, c2, c3)
    if (c1, c2, c3) == CORRECT_COMBO:
        print('Found combo: {}'.format((c1, c2, c3)))
        break
