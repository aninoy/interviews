x = [1, 2, 3, 4]
y = [12, 5, 34, 56]
z = ['a', 'b', 'c', 'd']
for a, b, c in zip(x, y, z):
    print(a, b, c)

for i in zip(x, y, z):
    print(i)

print(list(zip(x, y, z)))
print(dict(zip(x, y)))

# variables in list comprehension are limited to the scope of of the list comprehension

[print(x, y) for x, y in zip(x, y)]
print(x)  # Prints the original list since x in list comprehension is a temp variables

for x, y in zip(x, y):
    print(x, y)
print(x)  # Overwrites the x list variable above, since this x is not a temp variable
