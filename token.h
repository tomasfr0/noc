#define DEFAULT_VALUE 0

enum Token {
  LEFT_PAREN,
  RIGHT_PAREN,
  LEFT_BRACKET,
  RIGHT_BRACKET,
  COMMA,
  EQUAL,
  SEMICOLON,
  KEYWORD,
  IDENTIFIER,
  FUNCTION,
  NEWLINE,
  FEOF
};

enum VARIABLE_TYPE 
{
  STRING,
  INTEGER,
  FLOAT
};

enum Error {
  SYNTAX_ERROR,
  LOGIC_ERROR,
  RUNTIME_ERROR,
  COMPILER_ERROR
};

struct s_token {
  int start;
  int pos;
  int line;
  char *str; // ?? ? ? ? ? ?? 
  enum Token tk;
  union {
    int *i;
    double *f;
    char *s;
  };
};


int is_whitespace(int ch);
int getNchar(char **buf,int *len);
char* slice(char *buff, int len, int start, int end);
void parse(char *source, int len, struct s_token **tokens);
struct s_token *make_token(char buff[], int line, int start, int end, int t);

