// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hh"


// Unqualified %code blocks.
#line 23 "parser.yy"

# include "driver.hh"

#line 50 "parser.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 142 "parser.cc"

  /// Build a parser object.
  parser::parser (driver& drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_DIGITO: // "digito"
      case symbol_kind::S_VALENCIA: // "valencia"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FIN_DE_LINEA: // "fin_de_linea"
      case symbol_kind::S_LETRA: // "letra"
      case symbol_kind::S_TIPO: // "tipo"
      case symbol_kind::S_OPERACION: // "operacion"
      case symbol_kind::S_ELEMEN: // "elemen"
      case symbol_kind::S_ENLACE: // "enlace"
      case symbol_kind::S_ID: // "id"
      case symbol_kind::S_IDCONT: // "idcont"
      case symbol_kind::S_SENTENCIAS: // "sentencias"
      case symbol_kind::S_SENTENCIA: // "sentencia"
      case symbol_kind::S_MODELO_MOLECULAR: // "modelo_molecular"
      case symbol_kind::S_COMPUESTO: // "compuesto"
      case symbol_kind::S_COMPUESTOS: // "compuestos"
      case symbol_kind::S_ELEMENTO: // "elemento"
      case symbol_kind::S_ELEMENTO_QUIMICO: // "elemento_quimico"
      case symbol_kind::S_GRUPO_FUNCIONAL: // "grupo_funcional"
      case symbol_kind::S_GRUPO_FUNCIONAL_INFERIOR: // "grupo_funcional_inferior"
      case symbol_kind::S_GRUPO_FUNCIONAL_SUPERIOR: // "grupo_funcional_superior"
      case symbol_kind::S_MODELO_GRUPO_FUNCIONAL: // "modelo_grupo_funcional"
      case symbol_kind::S_exp: // exp
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_DIGITO: // "digito"
      case symbol_kind::S_VALENCIA: // "valencia"
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FIN_DE_LINEA: // "fin_de_linea"
      case symbol_kind::S_LETRA: // "letra"
      case symbol_kind::S_TIPO: // "tipo"
      case symbol_kind::S_OPERACION: // "operacion"
      case symbol_kind::S_ELEMEN: // "elemen"
      case symbol_kind::S_ENLACE: // "enlace"
      case symbol_kind::S_ID: // "id"
      case symbol_kind::S_IDCONT: // "idcont"
      case symbol_kind::S_SENTENCIAS: // "sentencias"
      case symbol_kind::S_SENTENCIA: // "sentencia"
      case symbol_kind::S_MODELO_MOLECULAR: // "modelo_molecular"
      case symbol_kind::S_COMPUESTO: // "compuesto"
      case symbol_kind::S_COMPUESTOS: // "compuestos"
      case symbol_kind::S_ELEMENTO: // "elemento"
      case symbol_kind::S_ELEMENTO_QUIMICO: // "elemento_quimico"
      case symbol_kind::S_GRUPO_FUNCIONAL: // "grupo_funcional"
      case symbol_kind::S_GRUPO_FUNCIONAL_INFERIOR: // "grupo_funcional_inferior"
      case symbol_kind::S_GRUPO_FUNCIONAL_SUPERIOR: // "grupo_funcional_superior"
      case symbol_kind::S_MODELO_GRUPO_FUNCIONAL: // "modelo_grupo_funcional"
      case symbol_kind::S_exp: // exp
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_DIGITO: // "digito"
      case symbol_kind::S_VALENCIA: // "valencia"
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_FIN_DE_LINEA: // "fin_de_linea"
      case symbol_kind::S_LETRA: // "letra"
      case symbol_kind::S_TIPO: // "tipo"
      case symbol_kind::S_OPERACION: // "operacion"
      case symbol_kind::S_ELEMEN: // "elemen"
      case symbol_kind::S_ENLACE: // "enlace"
      case symbol_kind::S_ID: // "id"
      case symbol_kind::S_IDCONT: // "idcont"
      case symbol_kind::S_SENTENCIAS: // "sentencias"
      case symbol_kind::S_SENTENCIA: // "sentencia"
      case symbol_kind::S_MODELO_MOLECULAR: // "modelo_molecular"
      case symbol_kind::S_COMPUESTO: // "compuesto"
      case symbol_kind::S_COMPUESTOS: // "compuestos"
      case symbol_kind::S_ELEMENTO: // "elemento"
      case symbol_kind::S_ELEMENTO_QUIMICO: // "elemento_quimico"
      case symbol_kind::S_GRUPO_FUNCIONAL: // "grupo_funcional"
      case symbol_kind::S_GRUPO_FUNCIONAL_INFERIOR: // "grupo_funcional_inferior"
      case symbol_kind::S_GRUPO_FUNCIONAL_SUPERIOR: // "grupo_funcional_superior"
      case symbol_kind::S_MODELO_GRUPO_FUNCIONAL: // "modelo_grupo_funcional"
      case symbol_kind::S_exp: // exp
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_DIGITO: // "digito"
      case symbol_kind::S_VALENCIA: // "valencia"
        value.move< int > (that.value);
        break;

      case symbol_kind::S_FIN_DE_LINEA: // "fin_de_linea"
      case symbol_kind::S_LETRA: // "letra"
      case symbol_kind::S_TIPO: // "tipo"
      case symbol_kind::S_OPERACION: // "operacion"
      case symbol_kind::S_ELEMEN: // "elemen"
      case symbol_kind::S_ENLACE: // "enlace"
      case symbol_kind::S_ID: // "id"
      case symbol_kind::S_IDCONT: // "idcont"
      case symbol_kind::S_SENTENCIAS: // "sentencias"
      case symbol_kind::S_SENTENCIA: // "sentencia"
      case symbol_kind::S_MODELO_MOLECULAR: // "modelo_molecular"
      case symbol_kind::S_COMPUESTO: // "compuesto"
      case symbol_kind::S_COMPUESTOS: // "compuestos"
      case symbol_kind::S_ELEMENTO: // "elemento"
      case symbol_kind::S_ELEMENTO_QUIMICO: // "elemento_quimico"
      case symbol_kind::S_GRUPO_FUNCIONAL: // "grupo_funcional"
      case symbol_kind::S_GRUPO_FUNCIONAL_INFERIOR: // "grupo_funcional_inferior"
      case symbol_kind::S_GRUPO_FUNCIONAL_SUPERIOR: // "grupo_funcional_superior"
      case symbol_kind::S_MODELO_GRUPO_FUNCIONAL: // "modelo_grupo_funcional"
      case symbol_kind::S_exp: // exp
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        switch (yykind)
    {
      case symbol_kind::S_FIN_DE_LINEA: // "fin_de_linea"
#line 55 "parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 405 "parser.cc"
        break;

      case symbol_kind::S_LETRA: // "letra"
#line 55 "parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 411 "parser.cc"
        break;

      case symbol_kind::S_DIGITO: // "digito"
#line 55 "parser.yy"
                 { yyoutput << yysym.value.template as < int > (); }
#line 417 "parser.cc"
        break;

      case symbol_kind::S_TIPO: // "tipo"
#line 55 "parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 423 "parser.cc"
        break;

      case symbol_kind::S_OPERACION: // "operacion"
#line 55 "parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 429 "parser.cc"
        break;

      case symbol_kind::S_VALENCIA: // "valencia"
#line 55 "parser.yy"
                 { yyoutput << yysym.value.template as < int > (); }
#line 435 "parser.cc"
        break;

      case symbol_kind::S_ELEMEN: // "elemen"
#line 55 "parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 441 "parser.cc"
        break;

      case symbol_kind::S_ENLACE: // "enlace"
#line 55 "parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 447 "parser.cc"
        break;

      case symbol_kind::S_ID: // "id"
#line 55 "parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 453 "parser.cc"
        break;

      case symbol_kind::S_IDCONT: // "idcont"
#line 55 "parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 459 "parser.cc"
        break;

      case symbol_kind::S_SENTENCIAS: // "sentencias"
#line 55 "parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 465 "parser.cc"
        break;

      case symbol_kind::S_SENTENCIA: // "sentencia"
#line 55 "parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 471 "parser.cc"
        break;

      case symbol_kind::S_MODELO_MOLECULAR: // "modelo_molecular"
#line 55 "parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 477 "parser.cc"
        break;

      case symbol_kind::S_COMPUESTO: // "compuesto"
#line 55 "parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 483 "parser.cc"
        break;

      case symbol_kind::S_COMPUESTOS: // "compuestos"
#line 55 "parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 489 "parser.cc"
        break;

      case symbol_kind::S_ELEMENTO: // "elemento"
#line 55 "parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 495 "parser.cc"
        break;

      case symbol_kind::S_ELEMENTO_QUIMICO: // "elemento_quimico"
#line 55 "parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 501 "parser.cc"
        break;

      case symbol_kind::S_GRUPO_FUNCIONAL: // "grupo_funcional"
#line 55 "parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 507 "parser.cc"
        break;

      case symbol_kind::S_GRUPO_FUNCIONAL_INFERIOR: // "grupo_funcional_inferior"
#line 55 "parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 513 "parser.cc"
        break;

      case symbol_kind::S_GRUPO_FUNCIONAL_SUPERIOR: // "grupo_funcional_superior"
#line 55 "parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 519 "parser.cc"
        break;

      case symbol_kind::S_MODELO_GRUPO_FUNCIONAL: // "modelo_grupo_funcional"
#line 55 "parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 525 "parser.cc"
        break;

      case symbol_kind::S_exp: // exp
#line 55 "parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 531 "parser.cc"
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (drv));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_DIGITO: // "digito"
      case symbol_kind::S_VALENCIA: // "valencia"
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_FIN_DE_LINEA: // "fin_de_linea"
      case symbol_kind::S_LETRA: // "letra"
      case symbol_kind::S_TIPO: // "tipo"
      case symbol_kind::S_OPERACION: // "operacion"
      case symbol_kind::S_ELEMEN: // "elemen"
      case symbol_kind::S_ENLACE: // "enlace"
      case symbol_kind::S_ID: // "id"
      case symbol_kind::S_IDCONT: // "idcont"
      case symbol_kind::S_SENTENCIAS: // "sentencias"
      case symbol_kind::S_SENTENCIA: // "sentencia"
      case symbol_kind::S_MODELO_MOLECULAR: // "modelo_molecular"
      case symbol_kind::S_COMPUESTO: // "compuesto"
      case symbol_kind::S_COMPUESTOS: // "compuestos"
      case symbol_kind::S_ELEMENTO: // "elemento"
      case symbol_kind::S_ELEMENTO_QUIMICO: // "elemento_quimico"
      case symbol_kind::S_GRUPO_FUNCIONAL: // "grupo_funcional"
      case symbol_kind::S_GRUPO_FUNCIONAL_INFERIOR: // "grupo_funcional_inferior"
      case symbol_kind::S_GRUPO_FUNCIONAL_SUPERIOR: // "grupo_funcional_superior"
      case symbol_kind::S_MODELO_GRUPO_FUNCIONAL: // "modelo_grupo_funcional"
      case symbol_kind::S_exp: // exp
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // unit: exps
#line 59 "parser.yy"
           {}
#line 812 "parser.cc"
    break;

  case 4: // exps: exps exp
#line 61 "parser.yy"
                        {}
#line 818 "parser.cc"
    break;

  case 5: // exp: "fin_de_linea"
#line 66 "parser.yy"
               {}
#line 824 "parser.cc"
    break;

  case 6: // exp: "letra"
#line 67 "parser.yy"
          {}
#line 830 "parser.cc"
    break;

  case 7: // exp: "digito"
#line 68 "parser.yy"
           {}
#line 836 "parser.cc"
    break;

  case 8: // exp: "tipo"
#line 69 "parser.yy"
         {}
#line 842 "parser.cc"
    break;

  case 9: // exp: "operacion"
#line 70 "parser.yy"
              {}
#line 848 "parser.cc"
    break;

  case 10: // exp: "valencia"
#line 71 "parser.yy"
             {}
#line 854 "parser.cc"
    break;

  case 11: // exp: "enlace"
#line 72 "parser.yy"
           {}
#line 860 "parser.cc"
    break;

  case 12: // exp: "id"
#line 73 "parser.yy"
       {}
#line 866 "parser.cc"
    break;

  case 13: // exp: "idcont"
#line 74 "parser.yy"
           {}
#line 872 "parser.cc"
    break;

  case 14: // exp: "sentencias"
#line 75 "parser.yy"
               {}
#line 878 "parser.cc"
    break;

  case 15: // exp: "sentencia"
#line 76 "parser.yy"
              {}
#line 884 "parser.cc"
    break;

  case 16: // exp: "modelo_molecular"
#line 77 "parser.yy"
                     {}
#line 890 "parser.cc"
    break;

  case 17: // exp: "compuesto"
#line 78 "parser.yy"
              {}
#line 896 "parser.cc"
    break;

  case 18: // exp: "compuestos"
#line 79 "parser.yy"
               {}
#line 902 "parser.cc"
    break;

  case 19: // exp: "elemento"
#line 80 "parser.yy"
             {}
#line 908 "parser.cc"
    break;

  case 20: // exp: "elemento_quimico"
#line 81 "parser.yy"
                     {}
#line 914 "parser.cc"
    break;

  case 21: // exp: "grupo_funcional"
#line 82 "parser.yy"
                    {}
#line 920 "parser.cc"
    break;

  case 22: // exp: "grupo_funcional_inferior"
#line 83 "parser.yy"
                             {}
#line 926 "parser.cc"
    break;

  case 23: // exp: "grupo_funcional_superior"
#line 84 "parser.yy"
                             {}
#line 932 "parser.cc"
    break;

  case 24: // exp: "modelo_grupo_funcional"
#line 85 "parser.yy"
                           {}
#line 938 "parser.cc"
    break;


#line 942 "parser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -4;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      -4,     6,    -3,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4
  };

  const signed char
  parser::yydefact_[] =
  {
       3,     0,     2,     1,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     4
  };

  const signed char
  parser::yypgoto_[] =
  {
      -4,    -4,    -4,    -4
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     1,     2,    24
  };

  const signed char
  parser::yytable_[] =
  {
       4,     5,     6,     7,     8,     9,     3,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23
  };

  const signed char
  parser::yycheck_[] =
  {
       3,     4,     5,     6,     7,     8,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23
  };

  const signed char
  parser::yystos_[] =
  {
       0,    25,    26,     0,     3,     4,     5,     6,     7,     8,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    27
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    24,    25,    26,    26,    27,    27,    27,    27,    27,
      27,    27,    27,    27,    27,    27,    27,    27,    27,    27,
      27,    27,    27,    27,    27
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\"fin_de_linea\"",
  "\"letra\"", "\"digito\"", "\"tipo\"", "\"operacion\"", "\"valencia\"",
  "\"elemen\"", "\"enlace\"", "\"id\"", "\"idcont\"", "\"sentencias\"",
  "\"sentencia\"", "\"modelo_molecular\"", "\"compuesto\"",
  "\"compuestos\"", "\"elemento\"", "\"elemento_quimico\"",
  "\"grupo_funcional\"", "\"grupo_funcional_inferior\"",
  "\"grupo_funcional_superior\"", "\"modelo_grupo_funcional\"", "$accept",
  "unit", "exps", "exp", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const signed char
  parser::yyrline_[] =
  {
       0,    59,    59,    61,    61,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1423 "parser.cc"

#line 86 "parser.yy"


void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
