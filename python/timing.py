import timeit


input_list = range(100)


def div_by_five(num):
    return num % 5 == 0

xyz = (i for i in input_list if div_by_five(i))

print(timeit.timeit('''input_list = range(100)


def div_by_five(num):
    return num % 5 == 0

xyz = list(i for i in input_list if div_by_five(i))''', number=50))

print(timeit.timeit('''input_list = range(100)


def div_by_five(num):
    return num % 5 == 0

xyz = [i for i in input_list if div_by_five(i)]''', number=50))
