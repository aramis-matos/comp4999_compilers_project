from colorama import Fore, Back, Style
from prettytable import PrettyTable


def elem(text):
    if text.isupper():
        return f"{Back.BLACK}{Fore.YELLOW}{text}{Style.RESET_ALL}"
    else:
        return f"{Back.BLACK}{Fore.RED}{text}{Style.RESET_ALL}"


table = PrettyTable()
table.field_names = ["Regla"]
table.add_row([elem("modelo_grupo_funcional")])
table.add_row([elem("COR_DER")])

print(table)
