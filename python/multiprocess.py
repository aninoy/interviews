from multiprocessing import Pool
import multiprocessing


def job(num):
    return num * 2


def spawn(num):
    print('Spawned: {}'.format(num))

if __name__ == '__main__':
    for i in range(2):
        p = multiprocessing.Process(target=spawn, args=(i,))
        p.start()
        # join will make sure processes wait for each other
        # so things have in an order
        # p.join()
    print("done")

    p = Pool(processes=20)
    data = p.map(job, range(20))
    p.close()
    print(data)
