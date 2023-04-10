import os
import sys

import ply.lex as lex
from prettytable import PrettyTable


reserved = {}

variables = {}

with open("keywords.txt", "r") as f:
    for line in f:
        val = line.strip()
        reserved[val] = val.upper()

try:
    test_file = sys.argv[1]
except IndexError:
    test_file = "test_prog.txt"

if not (os.path.exists(test_file)):
    print(
        f"The file {test_file} not found, proceeding with default\
    test_prog.txt file")
    test_file = "test_prog.txt"

tokenTable = PrettyTable()

# enumera los nombre de todos tokens que puede reconocer
tokens = [
    "FIN_DE_LINEA",
    # "LETRA",
    # "DIGITO",
    "OPERACION",
    "VALENCIA",
    "ENLACE",
    # "IDCONT",
    "ID",
    "ELEMENTO_QUIMICO",
    # "MODELO_MOLECULAR",
    # "COMPUESTO",
    # "COMPUESTOS",
    # "ELEMENTO",
    # "GRUPO_FUNCIONAL",
    # "GRUPO_FUNCIONAL_INFERIOR",
    # "GRUPO_FUNCIONAL_SUPERIOR",
    # "MODELO_GRUPO_FUNCIONAL",
    # "SENTENCIA",
    # "SENTENCIAS",
    "PARENTESIS_IZQ",
    "PARENTESIS_DER",
    "TIPO",
    # "PALABRA_RESERVADA",
    "COR_IZQ",
    "COR_DER",
    "ASIGNACION",
]

tokens = tokens + list(reserved.values())


# definiciones de los tokens y reglas de expresiones regulares
# t_COR_IZQ y t_COR_DER definen los tokens para corchetes izquierdos y
# derechos [ y ]
t_COR_IZQ = r"\["
t_COR_DER = r'\]'

# t_PARENTESIS_IZQ y t_PARENTESIS_DER definen los tokens para paréntesis
# izquierdos y derechos ( y )
t_PARENTESIS_IZQ = r"\("
t_PARENTESIS_DER = r"\)"

# define el token para el final de la línea, que puede ser : o ;
t_FIN_DE_LINEA = r"(:|;)"
# define los tokens para cualquier número entero del 1 al 9
t_VALENCIA = r"[1-9]"
# t_DIGITO = r"[0-9]"  # define los tokens para cualquier dígito del 0 al 9
t_TIPO = r"modelo"  # define el token para la palabra "modelo"
# define los tokens para diferentes tipos de enlaces químicos
t_ENLACE = r"(-|=|:|::)"
t_ignore = " \t"  # indica que se deben ignorar los espacios en blanco y
# tabulaciones


def t_ASIGNACION(t):  # identifica el token ":="
    r":="
    return t

# identifica el token graficar2d, graficar3d y pesomolecular


def t_OPERACION(t):
    r"(graficar2d|graficar3d|pesomolecular)"
    return t


def t_ELEMENTO_QUIMICO(t):  # define regla para el token elemento quimico
    r"(H|Li|Na|K|Rb|Cs|Fr|Be|Mg|Ca|Sr|Ba|Ra|Sc|Y|Ti|Zr|Hf|Db|V|Nb|Ta|Ji|Cr|Mo\
        |W|Rf|Mn|Tc|Re|Bh|Fe|Ru|Os|Hn|Co|Rh|Ir|Mt|Ni|Pd|Pt|Cu|Ag|Au|Zn|Cd|Hg|B\
        |Al|Ga|In|Ti|Cl|Si|Ge|Sn|Pb|N|P|As|Sb|Bi|O|S|Se|Te|Po|F|C|Br|I|At|He|\
        Ne|Ar|Kr|Xe|Rn)"
    return t

# identifica el token ID pero tambien idetifica el token de palabra reservada


def t_ID(t):
    r"[A-Za-z]+\d*"
    isPR = reserved.get(t.value, "ID")
    # if isPR != "ID":
    #     t.type = "PALABRA_RESERVADA"
    # else:
    #     t.type = isPR
    #     variables[t.value] = ""
    if isPR != "MODELO":
        t.type = isPR
    elif isPR == "MODELO":
        t.type = "TIPO"
    if isPR == "ID":
        variables[t.value] = ""
    return t


def t_newline(t):           # incrementa ek numero de linea
    r'\n+'
    t.lexer.lineno += len(t.value)


def t_COMMENT(t):           # Ignora comentarios
    r'\#.*'
    pass
    # No return value. Token discarded


def t_error(t):             # identifica error lexico
    tokenTable.add_row([tokenNum, "ERROR", t.value[0],
                       t.lineno, t.lexpos, test_file])
    t.lexer.skip(1)


lexer = lex.lex()

tokenNum = 1
if __name__ == "__main__":
    tokenTable.field_names = ["N.", "Token",
                              "Lexema", "Linea", "Posición", "Programa"]
    reservedWords = PrettyTable()
    reservedWords.field_names = ["Palabra Reservada"]
    symbolsTable = PrettyTable()
    symbolsTable.field_names = ["Variables"]

    with open(test_file, "r") as f:
        with open("output.txt", "w") as o:
            for data in f:
                # data = input("Input data: ")
                lexer.input(data)
                for tok in lexer:
                    tokenTable.add_row(
                        [tokenNum, tok.type, tok.value, tok.lineno, tok.lexpos,
                         test_file])
                    tokenNum += 1
                    # o.write(line+"\n")
            o.write(str(tokenTable))
            line = "\n\nTABLA DE SIMBOLOS"
            o.write(line+"\n")
            for val in variables:
                symbolsTable.add_row([val])
            o.write(str(symbolsTable)+"\n")
            line = "\n\nPALABRAS RESERVADAS"
            o.write(line+"\n")
            for val in reserved:
                reservedWords.add_row([val])
            o.write(str(reservedWords)+"\n")

    with open("output.txt", "r") as f:
        for line in f:
            print(line, end="")
