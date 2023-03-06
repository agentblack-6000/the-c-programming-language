from argparse import ArgumentParser

def main():
    parser = ArgumentParser(description="Create C files with some boilerplate code")

    parser.add_argument("-n", "--name", nargs=1, dest="name")
    args = parser.parse_args()

    create_standard_file(args.name[0])

def create_standard_file(name):
    with open(f"{name}.c", "w") as file:
        file.write("#include <stdio.h>\n\n")
        file.write("/* */\n\n")
        file.write("int main(void)\n")
        file.write("{\n\n")
        file.write("}")

if __name__ == "__main__":
    main()