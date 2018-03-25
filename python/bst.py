class Node:
    def __init__(self, data):
        self.data = data
        self.left = self.right = None


class Bst:
    head = None

    def insert(self, data):
        newNode = Node(data)
        if self.head is None:
            # empty tree
            self.head = newNode
        else:
            cur = self.head
            prev = None
            while cur is not None:
                if data <= cur.data:
                    prev = cur
                    cur = cur.left
                else:
                    prev = cur
                    cur = cur.right
            if data <= prev.data:
                prev.left = newNode
            else:
                prev.right = newNode
        print("inserted")

    def find(self, data):
        print("found")

    def successor(self, data):
        print("successor")

    def inorder(self, node):
        if node is not None:
            self.inorder(node.left)
            print(node.data)
            self.inorder(node.right)

    def preorder(self, node):
        if node is not None:
            print(node.data)
            self.preorder(node.left)
            self.preorder(node.right)

    def postorder(self, node):
        if node is not None:
            self.postorder(node.left)
            self.postorder(node.right)
            print(node.data)

    def print_tree(self):
        self.preorder(self.head)


def main():
    tree = Bst()
    tree.insert(4)
    tree.insert(2)
    tree.insert(3)
    tree.print_tree()
    tree.insert(1)
    tree.insert(5)
    tree.print_tree()


if __name__ == '__main__':
    main()
