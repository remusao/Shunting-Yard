#include <stdio.h>
#include <string.h>

#define MAX_EXP_SIZE 400

enum token
{
  END       = 0,
  LETTER    = 1,
  LBRACKET  = 2,
  PLUS      = 3,
  MINUS     = 4,
  MULT      = 5,
  DIV       = 6,
  POW       = 7,
  RBRACKET  = 8
};


int main(void)
{
  char chars[255];
  char s[MAX_EXP_SIZE + 1];
  char op[MAX_EXP_SIZE + 1];
  char output[MAX_EXP_SIZE + 1];
  int n, offset, op_len, output_len, tmp;


  memset(chars, LETTER, 255);
  chars['+'] = PLUS;
  chars['-'] = MINUS;
  chars['*'] = MULT;
  chars['/'] = DIV;
  chars['^'] = POW;
  chars['('] = LBRACKET;
  chars[')'] = RBRACKET;
  chars['\0'] = END;

  scanf("%i", &n);

  while (n--)
  {
    op_len = 0;
    output_len = 0;
    offset = 0;
    scanf("%s", s);
    tmp = chars[s[offset]];
    while (tmp)
    {
      if (tmp > LETTER)
      {
        switch (tmp)
        {
          case LBRACKET:
            op[op_len++] = '('; break;
          case RBRACKET:
            while (op[--op_len] != '(')
              output[output_len++] = op[op_len];
            break;
          default:
            while (op_len && tmp <= chars[op[op_len - 1]])
              output[output_len++] = op[--op_len];
            op[op_len++] = s[offset];
            break;
        }
      }
      else
        output[output_len++] = s[offset];
      offset++;
      tmp = chars[s[offset]];
    }
    while (op_len)
      output[output_len++] = op[--op_len];
    output[output_len] = '\0';
    printf("%s\n", output);
  }

  return 0;
}
