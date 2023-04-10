import grammar
import sys
import os
from colorama import Fore, Style
from prettytable import PrettyTable

with open("parser_err_out.txt", "w") as f:
    f.write("")


def elem(text):
    if text == "-->":
        return f"{Fore.BLUE}{text}{Style.RESET_ALL}"
    if text.isupper():
        return f"{Fore.YELLOW}{text}{Style.RESET_ALL}"
    else:
        return f"{Fore.RED}{text}{Style.RESET_ALL}"


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
    contents = f.read()#.replace("\n", "")
    # print(contents)
    grammar.parser.parse(contents,tracking=True)
# for val in grammar.variables.values():
#     print(val)
parser_table = PrettyTable()
parser_table.field_names = ["Regla"]
parser_table.align["Regla"] = "l"

parser_table.add_rows(grammar.rules)

with open("parser_out.txt", "w") as f:
    f.write(str(parser_table))

parser_table = PrettyTable()
parser_table.field_names = ["Regla"]
parser_table.align["Regla"] = "l"

words = [x[0].split(" ") for x in grammar.rules]
for vals in words:
    word = ""
    for y in [elem(x) for x in vals]:
        word += f"{y} "
    parser_table.add_row([word])

print(parser_table)
