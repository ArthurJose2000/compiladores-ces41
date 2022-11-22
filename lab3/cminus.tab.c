/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "cminus.y"

#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static int savedValue; /* used for declarations */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void);
int yyerror(char *s);


#line 89 "cminus.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "cminus.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_VOID = 6,                       /* VOID  */
  YYSYMBOL_WHILE = 7,                      /* WHILE  */
  YYSYMBOL_ID = 8,                         /* ID  */
  YYSYMBOL_NUM = 9,                        /* NUM  */
  YYSYMBOL_ASSIGN = 10,                    /* ASSIGN  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_LT = 12,                        /* LT  */
  YYSYMBOL_LEQT = 13,                      /* LEQT  */
  YYSYMBOL_GT = 14,                        /* GT  */
  YYSYMBOL_GEQT = 15,                      /* GEQT  */
  YYSYMBOL_EQ = 16,                        /* EQ  */
  YYSYMBOL_NEQ = 17,                       /* NEQ  */
  YYSYMBOL_PLUS = 18,                      /* PLUS  */
  YYSYMBOL_MINUS = 19,                     /* MINUS  */
  YYSYMBOL_TIMES = 20,                     /* TIMES  */
  YYSYMBOL_OVER = 21,                      /* OVER  */
  YYSYMBOL_LPAREN = 22,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 23,                    /* RPAREN  */
  YYSYMBOL_LBRACK = 24,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 25,                    /* RBRACK  */
  YYSYMBOL_LBRACE = 26,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 27,                    /* RBRACE  */
  YYSYMBOL_SEMI = 28,                      /* SEMI  */
  YYSYMBOL_COMA = 29,                      /* COMA  */
  YYSYMBOL_ERROR = 30,                     /* ERROR  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_program = 32,                   /* program  */
  YYSYMBOL_decl_lista = 33,                /* decl_lista  */
  YYSYMBOL_decl = 34,                      /* decl  */
  YYSYMBOL_id = 35,                        /* id  */
  YYSYMBOL_var_decl = 36,                  /* var_decl  */
  YYSYMBOL_37_1 = 37,                      /* $@1  */
  YYSYMBOL_38_2 = 38,                      /* $@2  */
  YYSYMBOL_fun_decl = 39,                  /* fun_decl  */
  YYSYMBOL_params = 40,                    /* params  */
  YYSYMBOL_param_list = 41,                /* param_list  */
  YYSYMBOL_param = 42,                     /* param  */
  YYSYMBOL_comp_decl = 43,                 /* comp_decl  */
  YYSYMBOL_loc_decls = 44,                 /* loc_decls  */
  YYSYMBOL_stmt_list = 45,                 /* stmt_list  */
  YYSYMBOL_stmt = 46,                      /* stmt  */
  YYSYMBOL_exp_decl = 47,                  /* exp_decl  */
  YYSYMBOL_sel_decl = 48,                  /* sel_decl  */
  YYSYMBOL_itera_decl = 49,                /* itera_decl  */
  YYSYMBOL_ret_decl = 50,                  /* ret_decl  */
  YYSYMBOL_exp = 51,                       /* exp  */
  YYSYMBOL_var = 52,                       /* var  */
  YYSYMBOL_simp_exp = 53,                  /* simp_exp  */
  YYSYMBOL_rela = 54,                      /* rela  */
  YYSYMBOL_soma_exp = 55,                  /* soma_exp  */
  YYSYMBOL_soma = 56,                      /* soma  */
  YYSYMBOL_termo = 57,                     /* termo  */
  YYSYMBOL_mult = 58,                      /* mult  */
  YYSYMBOL_fator = 59,                     /* fator  */
  YYSYMBOL_ativ = 60,                      /* ativ  */
  YYSYMBOL_args = 61,                      /* args  */
  YYSYMBOL_arg_list = 62                   /* arg_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   128

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  120

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    33,    33,    36,    45,    47,    48,    50,    54,    63,
      72,    72,    84,    84,    97,   110,   124,   126,   133,   142,
     144,   153,   162,   174,   187,   198,   208,   210,   219,   221,
     222,   223,   224,   225,   227,   229,   232,   237,   244,   250,
     251,   256,   262,   264,   265,   272,   278,   281,   283,   285,
     287,   289,   291,   294,   300,   303,   305,   308,   314,   317,
     319,   322,   324,   326,   328,   333,   341,   343,   345,   354
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "INT",
  "VOID", "WHILE", "ID", "NUM", "ASSIGN", "RETURN", "LT", "LEQT", "GT",
  "GEQT", "EQ", "NEQ", "PLUS", "MINUS", "TIMES", "OVER", "LPAREN",
  "RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE", "SEMI", "COMA",
  "ERROR", "$accept", "program", "decl_lista", "decl", "id", "var_decl",
  "$@1", "$@2", "fun_decl", "params", "param_list", "param", "comp_decl",
  "loc_decls", "stmt_list", "stmt", "exp_decl", "sel_decl", "itera_decl",
  "ret_decl", "exp", "var", "simp_exp", "rela", "soma_exp", "soma",
  "termo", "mult", "fator", "ativ", "args", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-74)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      10,    -3,    -3,    27,    10,   -74,   -74,   -74,   -74,    20,
      47,   -74,   -74,    52,    26,   -74,    52,    34,   -74,    -3,
      -3,    23,    41,   -74,   -74,    29,   -74,    50,    54,    62,
      75,    65,    62,    66,    67,    69,   -74,   -74,    -3,   -74,
      61,   -74,    70,   -74,   -74,    77,   -74,   -74,    -3,    -3,
     -74,     3,   -11,    31,    71,    73,   -74,    32,     0,   -74,
     -74,    55,   -74,   -74,   -74,   -74,   -74,   -74,    72,    86,
     -74,    49,    64,   -74,   -74,     0,     0,   -74,    74,    76,
       0,     0,   -74,     0,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,     0,     0,   -74,   -74,     0,    78,    80,   -74,
     -74,   -74,    81,    79,    82,   -74,   -74,    68,    64,   -74,
      25,    25,   -74,     0,   -74,    93,   -74,   -74,    25,   -74
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     2,     4,     6,     5,     7,     0,
       0,     1,     3,     0,     0,     8,     0,     0,     9,     0,
      17,     0,    16,    19,    10,     0,    12,    20,    21,     0,
       0,     0,     0,     0,     0,     0,    26,    14,     0,    18,
       0,    15,     0,    22,    23,    28,    11,    13,     0,     0,
      25,     0,     0,     0,     0,     0,    64,     0,     0,    24,
      35,    43,    30,    27,    29,    31,    32,    33,     0,    62,
      42,    46,    54,    58,    63,     0,     0,    39,     0,     0,
      67,     0,    34,     0,    48,    47,    49,    50,    51,    52,
      55,    56,     0,     0,    59,    60,     0,     0,     0,    40,
      61,    69,     0,    66,     0,    41,    62,    45,    53,    57,
       0,     0,    65,     0,    44,    36,    38,    68,     0,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -74,   -74,   -74,   101,     1,    83,   -74,   -74,   -74,    90,
     -74,    84,   -25,   -74,   -74,   -73,   -74,   -74,   -74,   -74,
     -57,   -20,   -74,   -74,    17,   -74,    18,   -74,    14,   -74,
     -74,   -74
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,    61,     6,    31,    33,     7,    21,
      22,    23,    62,    45,    51,    63,    64,    65,    66,    67,
      68,    69,    70,    92,    71,    93,    72,    96,    73,    74,
     102,   103
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      78,    79,     9,    10,    37,     8,    54,    41,     8,    56,
      55,     8,    56,    14,    57,     1,     2,    15,    97,    98,
      27,    28,    58,   101,   104,    58,   105,    11,    54,    36,
      59,    60,    55,     8,    56,    24,    57,   115,   116,    28,
       8,    56,    13,    26,    14,   119,    29,    58,    15,    52,
      53,    36,    32,    60,    58,    17,   117,    19,    20,    18,
      77,    84,    85,    86,    87,    88,    89,    90,    91,    16,
      30,    17,   106,   106,    34,    18,   106,    80,    35,    81,
      19,    38,    48,    49,    94,    95,    90,    91,    36,    46,
      40,    42,    43,    75,    44,    76,    83,   118,    47,   100,
      82,   110,    99,   111,   112,    12,    25,   114,   113,   107,
     109,   108,     0,     0,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50
};

static const yytype_int8 yycheck[] =
{
      57,    58,     1,     2,    29,     8,     3,    32,     8,     9,
       7,     8,     9,    24,    11,     5,     6,    28,    75,    76,
      19,    20,    22,    80,    81,    22,    83,     0,     3,    26,
      27,    28,     7,     8,     9,     9,    11,   110,   111,    38,
       8,     9,    22,     9,    24,   118,    23,    22,    28,    48,
      49,    26,    23,    28,    22,    24,   113,     5,     6,    28,
      28,    12,    13,    14,    15,    16,    17,    18,    19,    22,
      29,    24,    92,    93,    24,    28,    96,    22,    24,    24,
       5,     6,     5,     6,    20,    21,    18,    19,    26,    28,
      25,    25,    25,    22,    25,    22,    10,     4,    28,    23,
      28,    23,    28,    23,    23,     4,    16,    25,    29,    92,
      96,    93,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,    32,    33,    34,    36,    39,     8,    35,
      35,     0,    34,    22,    24,    28,    22,    24,    28,     5,
       6,    40,    41,    42,     9,    40,     9,    35,    35,    23,
      29,    37,    23,    38,    24,    24,    26,    43,     6,    42,
      25,    43,    25,    25,    25,    44,    28,    28,     5,     6,
      36,    45,    35,    35,     3,     7,     9,    11,    22,    27,
      28,    35,    43,    46,    47,    48,    49,    50,    51,    52,
      53,    55,    57,    59,    60,    22,    22,    28,    51,    51,
      22,    24,    28,    10,    12,    13,    14,    15,    16,    17,
      18,    19,    54,    56,    20,    21,    58,    51,    51,    28,
      23,    51,    61,    62,    51,    51,    52,    55,    57,    59,
      23,    23,    23,    29,    25,    46,    46,    51,     4,    46
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    34,    35,    36,    36,
      37,    36,    38,    36,    39,    39,    40,    40,    41,    41,
      42,    42,    42,    42,    43,    44,    44,    45,    45,    46,
      46,    46,    46,    46,    47,    47,    48,    48,    49,    50,
      50,    51,    51,    52,    52,    53,    53,    54,    54,    54,
      54,    54,    54,    55,    55,    56,    56,    57,    57,    58,
      58,    59,    59,    59,    59,    60,    61,    61,    62,    62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     3,
       0,     7,     0,     7,     6,     6,     1,     1,     3,     1,
       2,     2,     4,     4,     4,     2,     0,     2,     0,     1,
       1,     1,     1,     1,     2,     1,     5,     7,     5,     2,
       3,     3,     1,     1,     4,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     4,     1,     0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: decl_lista  */
#line 34 "cminus.y"
                 { savedTree = yyvsp[0];}
#line 1215 "cminus.tab.c"
    break;

  case 3: /* decl_lista: decl_lista decl  */
#line 37 "cminus.y"
                 { YYSTYPE t = yyvsp[-1];
                   if (t != NULL)
                   { while (t->sibling != NULL)
                        t = t->sibling;
                     t->sibling = yyvsp[0];
                     yyval = yyvsp[-1]; }
                     else yyval = yyvsp[0];
                 }
#line 1228 "cminus.tab.c"
    break;

  case 4: /* decl_lista: decl  */
#line 45 "cminus.y"
                    { yyval = yyvsp[0]; }
#line 1234 "cminus.tab.c"
    break;

  case 5: /* decl: fun_decl  */
#line 47 "cminus.y"
                       { yyval = yyvsp[0]; }
#line 1240 "cminus.tab.c"
    break;

  case 6: /* decl: var_decl  */
#line 48 "cminus.y"
                       { yyval = yyvsp[0]; }
#line 1246 "cminus.tab.c"
    break;

  case 7: /* id: ID  */
#line 50 "cminus.y"
                 {yyval = newExpNode(IdK);
                  yyval->attr.name = copyString(ID_name);
                  yyval->lineno = lineno;}
#line 1254 "cminus.tab.c"
    break;

  case 8: /* var_decl: INT id SEMI  */
#line 55 "cminus.y"
                { yyval = newTypeNode();
                  yyval->type = Integer;
                  yyval->lineno = savedLineNo;
                  
                  yyval->child[0] = newDeclNode(VarK);
                  yyval->child[0]->attr.name = yyvsp[-1]->attr.name;
                  yyval->child[0]->lineno = yyvsp[-1]->lineno;
                }
#line 1267 "cminus.tab.c"
    break;

  case 9: /* var_decl: VOID id SEMI  */
#line 64 "cminus.y"
                { yyval = newTypeNode();
                  yyval->type = Void;
                  yyval->lineno = savedLineNo;
                  
                  yyval->child[0] = newDeclNode(VarK);
                  yyval->child[0]->attr.name = yyvsp[-1]->attr.name;
                  yyval->child[0]->lineno = yyvsp[-1]->lineno;
                }
#line 1280 "cminus.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 72 "cminus.y"
                                { savedValue = atoi(tokenString); }
#line 1286 "cminus.tab.c"
    break;

  case 11: /* var_decl: INT id LBRACK NUM $@1 RBRACK SEMI  */
#line 73 "cminus.y"
                {
                  yyval = newTypeNode();
                  yyval->type = Integer;

                  yyval->child[0] = newDeclNode(VarK);
                  yyval->child[0]->attr.name = yyvsp[-5]->attr.name;
                  yyval->child[0]->lineno = yyvsp[-5]->lineno;

                  yyval->child[0]->child[0] = newExpNode(ConstK);
                  yyval->child[0]->child[0]->attr.val = savedValue;
                }
#line 1302 "cminus.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 84 "cminus.y"
                                 { savedValue = atoi(tokenString); }
#line 1308 "cminus.tab.c"
    break;

  case 13: /* var_decl: VOID id LBRACK NUM $@2 RBRACK SEMI  */
#line 85 "cminus.y"
                {
                  yyval = newTypeNode();
                  yyval->type = Void;

                  yyval->child[0] = newDeclNode(VarK);
                  yyval->child[0]->attr.name = yyvsp[-5]->attr.name;
                  yyval->child[0]->lineno = yyvsp[-5]->lineno;

                  yyval->child[0]->child[0] = newExpNode(ConstK);
                  yyval->child[0]->child[0]->attr.val = savedValue;
                }
#line 1324 "cminus.tab.c"
    break;

  case 14: /* fun_decl: INT id LPAREN params RPAREN comp_decl  */
#line 98 "cminus.y"
                {
                  yyval = newTypeNode();
                  yyval->type = Integer;

                  yyval->child[0] = newDeclNode(FunK); 
                  yyval->child[0]->attr.name = yyvsp[-4]->attr.name;
                  yyval->child[0]->lineno = yyvsp[-4]->lineno;
                  yyval->child[0]->scope_name = yyvsp[-4]->attr.name;

                  yyval->child[0]->child[0] = yyvsp[-2];
                  yyval->child[0]->child[1] = yyvsp[0];
                }
#line 1341 "cminus.tab.c"
    break;

  case 15: /* fun_decl: VOID id LPAREN params RPAREN comp_decl  */
#line 111 "cminus.y"
                {
                  yyval = newTypeNode();
                  yyval->type = Void;

                  yyval->child[0] = newDeclNode(FunK); 
                  yyval->child[0]->attr.name = yyvsp[-4]->attr.name;
                  yyval->child[0]->lineno = yyvsp[-4]->lineno;
                  yyval->child[0]->scope_name = yyvsp[-4]->attr.name;

                  yyval->child[0]->child[0] = yyvsp[-2];
                  yyval->child[0]->child[1] = yyvsp[0];
                }
#line 1358 "cminus.tab.c"
    break;

  case 16: /* params: param_list  */
#line 125 "cminus.y"
              { yyval = yyvsp[0]; }
#line 1364 "cminus.tab.c"
    break;

  case 17: /* params: VOID  */
#line 127 "cminus.y"
              { 
                yyval = newDeclNode(VarK);
                yyval->attr.name = "void";
                yyval->type = Void;
              }
#line 1374 "cminus.tab.c"
    break;

  case 18: /* param_list: param_list COMA param  */
#line 134 "cminus.y"
              { YYSTYPE t = yyvsp[-2];
                   if (t != NULL)
                   { while (t->sibling != NULL)
                        t = t->sibling;
                     t->sibling = yyvsp[0];
                     yyval = yyvsp[-2]; }
                     else yyval = yyvsp[0];
                 }
#line 1387 "cminus.tab.c"
    break;

  case 19: /* param_list: param  */
#line 142 "cminus.y"
                    { yyval = yyvsp[0]; }
#line 1393 "cminus.tab.c"
    break;

  case 20: /* param: INT id  */
#line 145 "cminus.y"
                { yyval = newTypeNode();
                  yyval->type = Integer;
                  yyval->lineno = savedLineNo;
                  
                  yyval->child[0] = newDeclNode(VarK);
                  yyval->child[0]->attr.name = yyvsp[0]->attr.name;
                  yyval->child[0]->lineno = yyvsp[0]->lineno;
                }
#line 1406 "cminus.tab.c"
    break;

  case 21: /* param: VOID id  */
#line 154 "cminus.y"
                { yyval = newTypeNode();
                  yyval->type = Void;
                  yyval->lineno = savedLineNo;
                  
                  yyval->child[0] = newDeclNode(VarK);
                  yyval->child[0]->attr.name = yyvsp[0]->attr.name;
                  yyval->child[0]->lineno = yyvsp[0]->lineno;
                }
#line 1419 "cminus.tab.c"
    break;

  case 22: /* param: INT id LBRACK RBRACK  */
#line 163 "cminus.y"
                {
                  yyval = newTypeNode();
                  yyval->type = Integer;

                  yyval->child[0] = newDeclNode(VarK);
                  yyval->child[0]->attr.name = yyvsp[-2]->attr.name;
                  yyval->child[0]->lineno = yyvsp[-2]->lineno;

                  yyval->child[0]->child[0] = newExpNode(ConstK);
                  yyval->child[0]->child[0]->type = Void;
                }
#line 1435 "cminus.tab.c"
    break;

  case 23: /* param: VOID id LBRACK RBRACK  */
#line 175 "cminus.y"
                {
                  yyval = newTypeNode();
                  yyval->type = Void;

                  yyval->child[0] = newDeclNode(VarK);
                  yyval->child[0]->attr.name = yyvsp[-2]->attr.name;
                  yyval->child[0]->lineno = yyvsp[-2]->lineno;

                  yyval->child[0]->child[0] = newExpNode(ConstK);
                  yyval->child[0]->child[0]->type = Void;
                }
#line 1451 "cminus.tab.c"
    break;

  case 24: /* comp_decl: LBRACE loc_decls stmt_list RBRACE  */
#line 188 "cminus.y"
              { 
                YYSTYPE t = yyvsp[-2];
                if (t != NULL)
                { while (t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = yyvsp[-1]; 
                  yyval = yyvsp[-2]; }
                else yyval = yyvsp[-1];
              }
#line 1465 "cminus.tab.c"
    break;

  case 25: /* loc_decls: loc_decls var_decl  */
#line 199 "cminus.y"
              { 
                YYSTYPE t = yyvsp[-1];
                if (t != NULL)
                { while (t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = yyvsp[0];
                  yyval = yyvsp[-1]; }
                else yyval = yyvsp[0];
              }
#line 1479 "cminus.tab.c"
    break;

  case 26: /* loc_decls: %empty  */
#line 208 "cminus.y"
                     {yyval = NULL;}
#line 1485 "cminus.tab.c"
    break;

  case 27: /* stmt_list: stmt_list stmt  */
#line 211 "cminus.y"
              { YYSTYPE t = yyvsp[-1];
                if (t != NULL)
                { while (t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = yyvsp[0];
                  yyval = yyvsp[-1]; }
                  else yyval = yyvsp[0];
              }
#line 1498 "cminus.tab.c"
    break;

  case 28: /* stmt_list: %empty  */
#line 219 "cminus.y"
                     {yyval = NULL;}
#line 1504 "cminus.tab.c"
    break;

  case 29: /* stmt: exp_decl  */
#line 221 "cminus.y"
                       { yyval = yyvsp[0]; }
#line 1510 "cminus.tab.c"
    break;

  case 30: /* stmt: comp_decl  */
#line 222 "cminus.y"
                        { yyval = yyvsp[0]; }
#line 1516 "cminus.tab.c"
    break;

  case 31: /* stmt: sel_decl  */
#line 223 "cminus.y"
                       { yyval = yyvsp[0]; }
#line 1522 "cminus.tab.c"
    break;

  case 32: /* stmt: itera_decl  */
#line 224 "cminus.y"
                         { yyval = yyvsp[0]; }
#line 1528 "cminus.tab.c"
    break;

  case 33: /* stmt: ret_decl  */
#line 225 "cminus.y"
                       { yyval = yyvsp[0]; }
#line 1534 "cminus.tab.c"
    break;

  case 34: /* exp_decl: exp SEMI  */
#line 228 "cminus.y"
              { yyval = yyvsp[-1]; }
#line 1540 "cminus.tab.c"
    break;

  case 35: /* exp_decl: SEMI  */
#line 230 "cminus.y"
              { yyval = NULL; }
#line 1546 "cminus.tab.c"
    break;

  case 36: /* sel_decl: IF LPAREN exp RPAREN stmt  */
#line 233 "cminus.y"
              { yyval = newStmtNode(IfK);
                yyval->child[0] = yyvsp[-2];
                yyval->child[1] = yyvsp[0];
              }
#line 1555 "cminus.tab.c"
    break;

  case 37: /* sel_decl: IF LPAREN exp RPAREN stmt ELSE stmt  */
#line 238 "cminus.y"
              { yyval = newStmtNode(IfK);
                yyval->child[0] = yyvsp[-4];
                yyval->child[1] = yyvsp[-2];
                yyval->child[2] = yyvsp[0];
              }
#line 1565 "cminus.tab.c"
    break;

  case 38: /* itera_decl: WHILE LPAREN exp RPAREN stmt  */
#line 245 "cminus.y"
              { yyval = newStmtNode(RepeatK);
                yyval->child[0] = yyvsp[-2];
                yyval->child[1] = yyvsp[0];
              }
#line 1574 "cminus.tab.c"
    break;

  case 39: /* ret_decl: RETURN SEMI  */
#line 250 "cminus.y"
                          { yyval = newStmtNode(ReturnK); }
#line 1580 "cminus.tab.c"
    break;

  case 40: /* ret_decl: RETURN exp SEMI  */
#line 252 "cminus.y"
                { yyval = newStmtNode(ReturnK);
                  yyval->child[0] = yyvsp[-1]; 
                }
#line 1588 "cminus.tab.c"
    break;

  case 41: /* exp: var ASSIGN exp  */
#line 257 "cminus.y"
              { yyval = newExpNode(OpK);
                yyval->child[0] = yyvsp[-2];
                yyval->child[1] = yyvsp[0];
                yyval->attr.op = ASSIGN;
              }
#line 1598 "cminus.tab.c"
    break;

  case 42: /* exp: simp_exp  */
#line 262 "cminus.y"
                       { yyval = yyvsp[0]; }
#line 1604 "cminus.tab.c"
    break;

  case 43: /* var: id  */
#line 264 "cminus.y"
                  {yyval = yyvsp[0];}
#line 1610 "cminus.tab.c"
    break;

  case 44: /* var: id LBRACK exp RBRACK  */
#line 266 "cminus.y"
              {
                yyval = newExpNode(IdK);
                yyval->attr.name = yyvsp[-3]->attr.name;
                yyval->child[0] = yyvsp[-1];
              }
#line 1620 "cminus.tab.c"
    break;

  case 45: /* simp_exp: soma_exp rela soma_exp  */
#line 273 "cminus.y"
              { yyval = newExpNode(OpK);
                yyval->child[0] = yyvsp[-2];
                yyval->child[1] = yyvsp[0];
                yyval->attr.op = yyvsp[-1];
              }
#line 1630 "cminus.tab.c"
    break;

  case 46: /* simp_exp: soma_exp  */
#line 279 "cminus.y"
              { yyval = yyvsp[0]; }
#line 1636 "cminus.tab.c"
    break;

  case 47: /* rela: LEQT  */
#line 282 "cminus.y"
              { yyval = LEQT; }
#line 1642 "cminus.tab.c"
    break;

  case 48: /* rela: LT  */
#line 284 "cminus.y"
              { yyval = LT; }
#line 1648 "cminus.tab.c"
    break;

  case 49: /* rela: GT  */
#line 286 "cminus.y"
              { yyval = GT; }
#line 1654 "cminus.tab.c"
    break;

  case 50: /* rela: GEQT  */
#line 288 "cminus.y"
              { yyval = GEQT; }
#line 1660 "cminus.tab.c"
    break;

  case 51: /* rela: EQ  */
#line 290 "cminus.y"
              { yyval = EQ; }
#line 1666 "cminus.tab.c"
    break;

  case 52: /* rela: NEQ  */
#line 292 "cminus.y"
              { yyval = NEQ; }
#line 1672 "cminus.tab.c"
    break;

  case 53: /* soma_exp: soma_exp soma termo  */
#line 295 "cminus.y"
              { yyval = newExpNode(OpK);
                yyval->child[0] = yyvsp[-2];
                yyval->child[1] = yyvsp[0];
                yyval->attr.op = yyvsp[-1];
              }
#line 1682 "cminus.tab.c"
    break;

  case 54: /* soma_exp: termo  */
#line 301 "cminus.y"
              { yyval = yyvsp[0]; }
#line 1688 "cminus.tab.c"
    break;

  case 55: /* soma: PLUS  */
#line 304 "cminus.y"
              { yyval = PLUS; }
#line 1694 "cminus.tab.c"
    break;

  case 56: /* soma: MINUS  */
#line 306 "cminus.y"
              { yyval = MINUS; }
#line 1700 "cminus.tab.c"
    break;

  case 57: /* termo: termo mult fator  */
#line 309 "cminus.y"
              { yyval = newExpNode(OpK);
                yyval->child[0] = yyvsp[-2];
                yyval->child[1] = yyvsp[0];
                yyval->attr.op = yyvsp[-1];
              }
#line 1710 "cminus.tab.c"
    break;

  case 58: /* termo: fator  */
#line 315 "cminus.y"
              { yyval = yyvsp[0]; }
#line 1716 "cminus.tab.c"
    break;

  case 59: /* mult: TIMES  */
#line 318 "cminus.y"
              { yyval = TIMES; }
#line 1722 "cminus.tab.c"
    break;

  case 60: /* mult: OVER  */
#line 320 "cminus.y"
              { yyval = OVER; }
#line 1728 "cminus.tab.c"
    break;

  case 61: /* fator: LPAREN exp RPAREN  */
#line 323 "cminus.y"
              { yyval = yyvsp[-1]; }
#line 1734 "cminus.tab.c"
    break;

  case 62: /* fator: var  */
#line 325 "cminus.y"
              { yyval = yyvsp[0]; }
#line 1740 "cminus.tab.c"
    break;

  case 63: /* fator: ativ  */
#line 327 "cminus.y"
              { yyval = yyvsp[0]; }
#line 1746 "cminus.tab.c"
    break;

  case 64: /* fator: NUM  */
#line 329 "cminus.y"
              { yyval = newExpNode(ConstK);
                yyval->attr.val = atoi(tokenString);
              }
#line 1754 "cminus.tab.c"
    break;

  case 65: /* ativ: id LPAREN args RPAREN  */
#line 334 "cminus.y"
              {
                yyval = newAtvNode(AtvK);
                yyval->attr.name = yyvsp[-3]->attr.name;
                yyval->lineno = yyvsp[-3]->lineno;
                yyval->child[0] = yyvsp[-1];
              }
#line 1765 "cminus.tab.c"
    break;

  case 66: /* args: arg_list  */
#line 342 "cminus.y"
              { yyval = yyvsp[0]; }
#line 1771 "cminus.tab.c"
    break;

  case 67: /* args: %empty  */
#line 343 "cminus.y"
                     {yyval = NULL;}
#line 1777 "cminus.tab.c"
    break;

  case 68: /* arg_list: arg_list COMA exp  */
#line 346 "cminus.y"
              { YYSTYPE t = yyvsp[-2];
                if (t != NULL)
                { while (t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = yyvsp[0];
                  yyval = yyvsp[-2]; }
                  else yyval = yyvsp[0];
              }
#line 1790 "cminus.tab.c"
    break;

  case 69: /* arg_list: exp  */
#line 355 "cminus.y"
              { yyval = yyvsp[0]; }
#line 1796 "cminus.tab.c"
    break;


#line 1800 "cminus.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 357 "cminus.y"


int yyerror(char * message)
{ fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  fprintf(listing,"Current token: ");
  printToken(yychar,tokenString);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void)
{ yyparse();
  return savedTree;
}

