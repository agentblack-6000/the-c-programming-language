"""
C File Spawner
Creates C files with the specified name for regular programs or exercises with a main function.
"""

import os
from argparse import ArgumentParser

ENCODING="utf-8"

def main():
    """Parses command line arguments and creates specified file"""

    # Create argument parser
    parser = ArgumentParser(description="Create C files as per K&R with some boilerplate code")

    # Add flags
    parser.add_argument("-n", "--name", nargs=2, metavar=("file_name", "chapter"), dest="name")
    parser.add_argument("-e", "--exercise", nargs=1, dest="exercise")

    # Parse command line arguments
    args = parser.parse_args()

    # Call relavent methods, otherwise print help
    if args.name is not None:
        file_name, chapter = args.name
        create_standard_file(name=file_name, chapter_number=chapter)
    elif args.exercise is not None:
        create_exercise_file(args.exercise[0])
    else:
        parser.print_help()
        parser.exit()

def create_standard_file(name, chapter_number):
    """Creates a regular file with specified name and a main function"""

    # Naviagates to appropriate directory
    os.chdir(f"{os.getcwd()}/chapter_{chapter_number}")

    # Creates file
    with open(f"{name}.c", "w", encoding=ENCODING) as file:
        write_main_function(file)

def create_exercise_file(name):
    """Creates a file with the appropriate exercise name with a main function"""
    chapter, exercise_number = name.split("-")

    # Naviagates to appropriate directory
    os.chdir(f"{os.getcwd()}/chapter_{chapter}/exercises")

    # Creates file
    with open(f"ex{chapter}_{exercise_number}.c", "w", encoding=ENCODING) as file:
        write_main_function(file)


def write_main_function(file):
    """Writes the standard I/O C library and a main function to file"""

    # Includes header files
    file.write("#include <stdio.h>\n\n")

    # Creates space for program documentation
    file.write("/* */\n\n")

    # Creates main function
    file.write("int main(void)\n")
    file.write("{\n\n")
    file.write("}")

if __name__ == "__main__":
    main()
