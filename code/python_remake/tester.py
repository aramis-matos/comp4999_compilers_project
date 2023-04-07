import grammar
import sys
import os


try:
    test_file = sys.argv[1]
except IndexError:
    test_file = "test_prog.txt"

if not (os.path.exists(test_file)):
    print(
        f"The file {test_file} not found, proceeding with default\
    test_prog.txt file")
    test_file = "test_prog.txt"

with open(test_file, 'r') as f:
    contents = f.read().replace("\n", "")
    # print(contents)
    grammar.parser.parse(contents)
# for val in grammar.variables.values():
#     print(val)
print(grammar.parser_table)
