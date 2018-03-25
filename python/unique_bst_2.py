def recursive_bst(parent, rest):
    print('Start:', parent, rest)
    count = 0
    if len(rest) <= 1:
        if parent is None:
            count = 1
        else:
            count = 0
    else:
        for root in rest:
            left_rest = [i for i in rest if i < root]
            right_rest = [i for i in rest if i > root]
            print(root, left_rest, right_rest)
            lc = recursive_bst(root, left_rest)
            rc = recursive_bst(root, right_rest)
            if lc + rc == 0:
                count += 1
            else:
                count += lc * rc
    print('End:', parent, rest, count)
    return count


def numTrees(n):
    rest = [x for x in range(1, n + 1)]
    count = recursive_bst(None, rest)
    return count


def main():
    count = numTrees(19)
    print(count)

if __name__ == '__main__':
    main()
