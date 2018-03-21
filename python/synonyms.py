def syn_search(q1, q2, syn_set):
    q = syn_concat(q1, q2)
    return (q in syn_set)


def match(q1, q2, syn_set):
    retval = True

    if len(q1) != len(q2):
        retval = False
    else:
        for i in range(len(q1)):
            if q1[i] != q2[i] and not syn_search(q1[i], q2[i], syn_set):
                retval = False
                break
    return retval


def syn_concat(q1, q2):
    q = ''
    if q1 < q2:
        q = q1 + q2
    else:
        q = q2 + q1
    return q


def create_syn_set(syn_list):
    syn_set = set()
    for q1, q2 in syn_list:
        syn_set.add(syn_concat(q1, q2))
    return syn_set


def main():
    syn_list = [('car', 'auto'), ('noy', 'aninoy'), ('compare', 'comparable'), ('price', 'value')]
    syn_set = create_syn_set(syn_list)
    print(syn_set)
    q1 = ['compare', 'auto', 'price']
    q2 = ['comparable', 'car', 'value']
    print(match(q1, q2, syn_set))


if __name__ == '__main__':
    main()
