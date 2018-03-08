# range() generates a list, in memory but it is fast


xyz = [i for i in range(5)]
print(xyz)  # this is a list, in memory

xyz = (i for i in range(5))
print(xyz)  # this is a generator, not in memory

'''generators take longer when you need ot iterate through them
but they are instantly generated'''

input_list = [2, 5, 7, 15, 8, 90, 67, 23, 55, 25]


def div_by_five(num):
    return num % 5 == 0

xyz = (i for i in input_list if div_by_five(i))

for i in xyz:
    print(i)

# This is the same as
[print(i) for i in xyz]

[print(i, ii) for ii in range(5) for i in range(5)]

xyz = ((i, ii) for ii in range(5) for i in range(5))
for i in xyz:
    print(i)
