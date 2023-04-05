import grammar

with open("test_prog.txt", 'r') as f:
    contents = f.read().replace("\n", "")
    # print(contents)
    grammar.parser.parse(contents)
for val in grammar.variables.values():
    print(val)
