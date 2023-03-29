import ply.lex as lex
import sys
import os

reserved = {}

variables = {}

with open("keywords.txt","r") as f:
    for line in f:
        val = line.strip()
        reserved[val] = val.upper()

try:
    test_file = sys.argv[1]
except IndexError:
    test_file = "test_prog.txt"

if not (os.path.exists(test_file)):
    print(f"The file {test_file} not found, proceeding with default test_prog.txt file")
    test_file = "test_prog.txt"


tokens = (
    "FIN_DE_LINEA",
    "LETRA",
    "DIGITO",
    "OPERACION",
    "VALENCIA",
    "ENLACE",
    "IDCONT",
    "ID",
    "ELEMENTO_QUIMICO",
    "MODELO_MOLECULAR",
    "COMPUESTO",
    "COMPUESTOS",
    "ELEMENTO",
    "GRUPO_FUNCIONAL",
    "GRUPO_FUNCIONAL_INFERIOR",
    "GRUPO_FUNCIONAL_SUPERIOR",
    "MODELO_GRUPO_FUNCIONAL",
    "SENTENCIA",
    "SENTENCIAS",
    "PARENTESIS_IZQ",
    "PARENTESIS_DER",
    "TIPO",
    "PALABRA_RESERVADA",
    "COR_IZQ",
    "COR_DER",
    "ASIGNACION"
)

t_COR_IZQ = r"\["
t_COR_DER = r'\]'
t_PARENTESIS_IZQ = r"\("
t_PARENTESIS_DER = r"\)"
t_FIN_DE_LINEA = r"(:|;)"
t_DIGITO = r"[0-9]"
t_TIPO = r"modelo"
t_VALENCIA = r"[1-9]"
t_ENLACE = r"(-|=|:|::)"
t_ignore = " \t"

def t_ASIGNACION (t):
    r":="
    return t

def t_OPERACION(t):
    r"(graficar2d|graficar3d|pesomolecular)"
    return t

def t_ELEMENTO_QUIMICO(t):
    r"(H|Li|Na|K|Rb|Cs|Fr|Be|Mg|Ca|Sr|Ba|Ra|Sc|Y|Ti|Zr|Hf|Db|V|Nb|Ta|Ji|Cr|Mo|W|Rf|Mn|Tc|Re|Bh|Fe|Ru|Os|Hn|Co|Rh|Ir|Mt|Ni|Pd|Pt|Cu|Ag|Au|Zn|Cd|Hg|B|Al|Ga|In|Ti|C|Si|Ge|Sn|Pb|N|P|As|Sb|Bi|O|S|Se|Te|Po|F|Cr|Br|I|At|He|Ne|Ar|Kr|Xe|Rn)"
    return t

def t_ID(t):
    r"[A-Za-z]+\d*"
    isPR = reserved.get(t.value,"ID") 
    if isPR != "ID":
        t.type = "PALABRA_RESERVADA"
    else:
        t.type = isPR
        variables[t.value] = ""
    return t

def t_newline(t):
    r'\n+'
    t.lexer.lineno += len(t.value)

def t_COMMENT(t):
    r'\#.*'
    pass
    # No return value. Token discarded

def t_error(t):
    line = f"CARACTER INVALIDO {t.value[0]},{sys.argv[0]}:{t.lineno}.{t.lexpos}"
    print(line)
    o.write(line+"\n")
    t.lexer.skip(1)

lexer = lex.lex()


with open(test_file, "r") as f:
    with open("output.txt","w") as o:
        for data in f:
            # data = input("Input data: ")
            lexer.input(data)
            for tok in lexer:
                line = f"(<{tok.type}>,{tok.value},{sys.argv[0]}:{tok.lineno}.{tok.lexpos})"
                o.write(line+"\n")
                print(line)
        line = "\n\nTABLA DE SIMBOLOS"
        o.write(line+"\n")
        print(line)
        for val in variables:
            o.write(val+"\n")
            print(val)
        line = "\n\nPALABRAS RESERVADAS"
        o.write(line+"\n")
        print(line)
        for val in reserved:
            o.write(val+"\n")
            print(val)

