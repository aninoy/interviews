import argparse


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--x', type=float, default=1.0, help='First operand')
    parser.add_argument('--y', type=float, default=1.0, help='Second operand')
    parser.add_argument('--op', type=str, default='add', help='The arithmatic operation')
    args = parser.parse_args()
    print(str(calc(args)))


def calc(args):
    if args.op == 'add':
        return args.x + args.y
    elif args.op == 'sub':
        return args.x - args.y
    elif args.op == 'mul':
        return args.x * args.y
    elif args.op == 'div':
        return args.x / args.y

if __name__ == '__main__':
    main()
