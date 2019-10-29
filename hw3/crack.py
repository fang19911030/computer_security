import sys

def transfer(s):
    trans = ''
    if len(s) > 10:
        return None
    for i in s:
        if i < 'A':
            return None
        if i >= 'Z':
            trans += chr(ord(i) - 32)
        else:
            trans += ide
    return trans

def get_serial(input_string):
    s = 0
    for i in trans:
        s += ord(i)
    return s^0x5678^0x1234

def main(args):
    name = None
    if len(args) < 2:
        name = input("Name:\n")
    else:
        name = args[1]
    print("Name:", name)
    trans = transfer(name)
    print("Serial:", get_serial(trans))


if __name__ == "__main__":
    main(sys.argv)


