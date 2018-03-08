# Intro
# ======
print (1, 2)
print ('hello world')

# single lne comment
''' multi
line comment
'''
""" multi line
comment
"""

# multi line prints with triple quotes
print("""lorem ipsum
dfsdfsd
dfsdfsdf
sdfsdf""")

# raw text prefix with r, chars not escaped
print(r'C:\\drive\location')

# Variables and Datatypes
# ========================
myStr = 'hello world'
myList = [1, 2, 3]
myInt = 21
myFloat = 2.6
myDict = {'a': 12, 'b': 'why', 'c': 3.5}
print(type(myStr), myStr)
print(type(myInt), myInt)
print(type(myFloat), myFloat)
print(type(myList), myList)
print(type(myDict), myDict)
print(myList[2])
print(myDict['b'])

# strings and int are immutable when passed as functions to paramaters
# lists and dicts are mutable

# String Functions
# =================

names = ['pet', 'stores', 'are', 'evil']

print(', '.join(names))

import os
file_name = 'test.txt'
dirs = '/Users/aninoymahapatra/dev/personal/interviews/python'
with open(os.path.join(dirs, file_name)) as f:
    print(f.read())


print(myStr.capitalize())
print(myStr.swapcase())
print(myStr.replace('world', 'everyone'))
print(myStr.count('l'))
print(myStr.startswith('el'))
print(myStr.endswith('ld'))
print(myStr.split())
print(myStr.find('x'))
print(myStr.index('l'))
''' find and index are exactly the same except find returns -1 when not found
whereas index throws a ValueError'''


# Files
# ======

fo = open('test.txt', 'w')  # mode w+ will create file if it doens't exist
print(fo.name)
print(fo.mode)
print(fo.closed)
fo.write('This is a new file\n')
fo.close()

fo = open('test.txt', 'a')  # append mode
fo.write('But is it really?')
fo.close()

fo = open('test.txt', 'r+')
text = fo.read()
smallText = fo.read(5)  # this will read only 5 bytes from current read pointer
print(text, smallText)


# Classes
# ========

class Person:
    __name = ''
    __email = ''  # double underscore is for private members

    def __init__(self, name, email):
        self.__name = name
        self.__email = email

    def get_name(self):
        return self.__name

    def get_email(self):
        return self.__email

    def toString(self):
        return '{} can be contacted at {}'.format(self.__name, self.__email)

brad = Person('Brad Johnson', 'brad@gmail.com')
print(brad.toString())


class Customer(Person):
    __bal = 0

    def __init__(self, name, email, bal):
        self.__name = name
        self.__email = email
        self.__bal = bal
        super(Customer, self).__init__(name, email)

    def toString(self):
        return '{} has a balance of {} and can be contacted at {}'.format(self.__name, self.__bal, self.__email)


john = Customer('JD', 'jd@gmail.com', 100)
print(john.toString())
