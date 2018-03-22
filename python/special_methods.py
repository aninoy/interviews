class range_ex:
    def __init__(self, end, step=1):
        self.current = 0
        self.end = end
        self.step = step

    def __iter__(self):
        return self

    def __next__(self):
        if self.current >= self.end:
            raise StopIteration()
        else:
            return_val = self.current
            self.current += self.step
            return return_val


def range_gen(end):
    current = 0
    while current < end:
        yield current
        current += 1

print('Range ex class:')
x = range_ex(5)
next(x)
x.__next__()
for i in x:
    print(i)

print('Range gen method:')
x = range_gen(5)
next(x)
for i in x:
    print(i)
print(dir(x))
