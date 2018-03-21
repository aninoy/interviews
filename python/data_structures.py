from collections import deque


def main():
    # Lists
    a = []
    a.append(2)
    a[len(a):] = [1, 3, 3]
    print(a)
    a.insert(1, 4)  # value 4 at position 1
    print(a)
    print(a.index(3))  # return index of first item
    print(a.count(3))  # value occurences
    a.sort()
    print(a)
    a.reverse()
    print(a)
    a.pop()  # last item
    print(a)
    a.pop(2)  # from index 2
    print(a)
    a.remove(2)  # remove first item
    print(a)
    a.clear()  # remove all items
    print(a)
    a = a + [1, 3]
    print(a)

    # Queues
    q = deque([1, 2, 3, 4, 5])
    print(q)
    q.append(3)
    print(q)
    q.popleft()
    print(q)


if __name__ == '__main__':
    main()
