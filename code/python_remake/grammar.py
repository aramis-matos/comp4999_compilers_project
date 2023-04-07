from ply import yacc
from lexer import tokens, variables
from colorama import Fore, Back, Style
from prettytable import PrettyTable

parser_table = PrettyTable()
parser_table.field_names = ["Regla"]
parser_table.align["Regla"] = "l"

def elem(text):
    if text.isupper():
        return f"{Fore.YELLOW}{text}{Style.RESET_ALL}"
    else:
        return f"{Fore.RED}{text}{Style.RESET_ALL}"


def format_expr(p):
    types = [elem(x.type) for x in p.slice]
    rule = f"{types[0]}: "
    for val in types[1:]:
        rule += f"{val} "
    parser_table.add_row([rule])

start = "s"


def p_s(p):
    's : INICIO sentencias FIN'
    # p[0] = p[2]
    format_expr(p)


def p_sentencias(p):
    '''sentencias : sentencia FIN_DE_LINEA sentencias
                  | sentencia FIN_DE_LINEA'''
    # if (len(p) == 4):
    #     p[0] = p[1] + p[3]
    # elif (len(p) == 3):
    #     p[0] = p[1]
    format_expr(p)


def p_sentencia(p):
    '''sentencia : DEFINA ID COMO TIPO
                  | ID ASIGNACION modelo_molecular
                  | OPERACION PARENTESIS_IZQ ID PARENTESIS_DER'''
    # type1 = p[1].type
    # print(type1)
    format_expr(p)
    # if (len(p) == 4):
    #     print(p[1])
    #     print(p[3])
    #     variables[p[1]] = p[3]


def p_modelo_molecular(p):
    '''modelo_molecular : ELEMENTO_QUIMICO
                        | ELEMENTO_QUIMICO VALENCIA
                        | elemento grupo_funcional
                        | compuesto elemento
                        | compuesto elemento grupo_funcional
                        | compuesto compuesto compuestos'''
    format_expr(p)


def p_compuesto(p):
    '''compuesto : ELEMENTO_QUIMICO
                 | ELEMENTO_QUIMICO VALENCIA
                 | elemento grupo_funcional
                 | elemento grupo_funcional ENLACE
                 | elemento ENLACE'''
    format_expr(p)


def p_compuestos(p):
    '''compuestos : compuesto compuestos
                  | compuesto'''
    format_expr(p)


def p_elemento(p):
    '''elemento : ELEMENTO_QUIMICO
                | ELEMENTO_QUIMICO VALENCIA'''
    format_expr(p)


def p_grupo_funcional(p):
    '''grupo_funcional : grupo_funcional_inferior grupo_funcional_superior
                       | grupo_funcional_superior grupo_funcional_inferior
                       | PARENTESIS_IZQ modelo_grupo_funcional PARENTESIS_DER
                       | COR_IZQ modelo_grupo_funcional COR_DER'''
    format_expr(p)


def p_grupo_funcional_inferior(p):
    '''grupo_funcional_inferior : COR_IZQ modelo_grupo_funcional COR_DER'''
    format_expr(p)


def p_grupo_funcional_superior(p):
    '''grupo_funcional_superior : PARENTESIS_IZQ modelo_grupo_funcional PARENTESIS_DER'''
    format_expr(p)


def p_modelo_grupo_funcional(p):
    '''modelo_grupo_funcional : ENLACE modelo_molecular
                              | ELEMENTO_QUIMICO
                              | ELEMENTO_QUIMICO VALENCIA
                              | elemento grupo_funcional
                              | compuesto elemento
                              | compuesto elemento grupo_funcional
                              | compuesto compuesto compuestos'''
    format_expr(p)


def p_error(p):
    print(f"Syntax Error at line {p.lineno}, column {p.lexpos} by {p.type}")


parser = yacc.yacc(debug=True)
if __name__ == "__main__":
    while True:
        try:
            s = input('calc > ')
        except EOFError:
            break
        if not s:
            continue
        parser.parse(s)
