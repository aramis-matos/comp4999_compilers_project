from ply import yacc
from lexer import tokens, variables

start = "s"


def p_s(p):
    's : INICIO sentencias FIN'
    # p[0] = p[2]
    print(f"axiom: {p}")


def p_sentencias(p):
    '''sentencias : sentencia FIN_DE_LINEA sentencias
                  | sentencia FIN_DE_LINEA'''
    # if (len(p) == 4):
    #     p[0] = p[1] + p[3]
    # elif (len(p) == 3):
    #     p[0] = p[1]
    print(f"sentencias: {p}")


def p_sentencia(p):
    '''sentencia : DEFINA ID COMO TIPO
                  | ID ASIGNACION modelo_molecular
                  | OPERACION PARENTESIS_IZQ ID PARENTESIS_DER'''
    print(f"sentencia: {p}")


def p_modelo_molecular(p):
    '''modelo_molecular : ELEMENTO_QUIMICO
                        | ELEMENTO_QUIMICO VALENCIA
                        | elemento grupo_funcional
                        | compuesto elemento
                        | compuesto elemento grupo_funcional
                        | compuesto compuesto compuestos'''
    print(f"modelo_molecular: {p}")


def p_compuesto(p):
    '''compuesto : ELEMENTO_QUIMICO
                 | ELEMENTO_QUIMICO VALENCIA
                 | elemento grupo_funcional
                 | elemento grupo_funcional ENLACE
                 | elemento ENLACE'''
    print(f"compuesto: {p}")


def p_compuestos(p):
    '''compuestos : compuesto compuestos
                  | compuesto'''
    print(f"compuestos: {p}")


def p_elemento(p):
    '''elemento : ELEMENTO_QUIMICO
                | ELEMENTO_QUIMICO VALENCIA'''
    print(f"elemento: {p}")


def p_grupo_funcional(p):
    '''grupo_funcional : grupo_funcional_inferior grupo_funcional_superior
                       | grupo_funcional_superior grupo_funcional_inferior
                       | PARENTESIS_IZQ modelo_grupo_funcional PARENTESIS_DER
                       | COR_IZQ modelo_grupo_funcional COR_DER'''
    print(f"grupo_funcional: {p}")


def p_grupo_funcional_inferior(p):
    '''grupo_funcional_inferior : COR_IZQ modelo_grupo_funcional COR_DER'''
    print(f"grupo_funcional_inferior: {p}")


def p_grupo_funcional_superior(p):
    '''grupo_funcional_superior : PARENTESIS_IZQ modelo_grupo_funcional PARENTESIS_DER'''
    print(f"grupo_funcional_superior: {p}")


def p_modelo_grupo_funcional(p):
    '''modelo_grupo_funcional : ENLACE modelo_molecular
                              | ELEMENTO_QUIMICO
                              | ELEMENTO_QUIMICO VALENCIA
                              | elemento grupo_funcional
                              | compuesto elemento
                              | compuesto elemento grupo_funcional
                              | compuesto compuesto compuestos'''
    print(f"modelo_grupo_funcional: {p}")


def p_error(p):
    print(f"Syntax Error at {p.type}")


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
