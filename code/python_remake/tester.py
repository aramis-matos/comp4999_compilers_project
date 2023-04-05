import lexer
import parser
import re

with open("test_prog.txt", 'r') as f:
    contents = f.read().replace("\n", "")
    print(contents)
    parser.parser.parse(contents)
