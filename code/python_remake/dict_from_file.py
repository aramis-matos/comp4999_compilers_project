reserved = {}

with open("keywords.txt","r") as f:
    for line in f:
        val = line.strip()
        reserved[val] = val.upper()

for val in reserved.values():
    print(val)
