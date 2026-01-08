#include "token.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int is_whitespace(int ch)
{
  return ch == ' ' || ch == '\t' || ch == '\v';
}


char* slice(char *buff, int len, int start, int end)
{
  if( end > len  || start < 0 || end < start) return NULL;
  char *slice = NULL;  
  int slice_len = (end - start);
  slice = malloc( slice_len + 1);
  memcpy(slice, buff + start, slice_len);
  slice[slice_len] = '\0';
  return slice;
}


int getNchar(char **buf, int *len)
{
  if(*len <= 0) return -1;
  int c = **buf;
  (*buf)++;
  (*len)--;
  return c;
}

struct s_token *make_token(char *buff, int line, int start, int end, int t)
{
  struct s_token *token = malloc(sizeof(struct s_token));
  token->start = start;
  token->pos = end;
  token->line = line;
  token->str = slice(buff, strlen(buff),start, end);
  token->tk = t;
  return token;
}


void parse(char *source, int len, struct s_token **tokens)
{
  char *origin = source;
  int total_len = len;
  int remaining = len;
  int c;
  int l = 1;
  int p = 0;
  while((c = getNchar(&source, &remaining)) != -1)
  {
    int start_c = p; // start position of the current char
    p++; // incrementing position
    switch(c) {
        case '(':
          printf("Left_paren -> line %d\n", l );
          break;
        case ')':
          break;
        case ';':
          break;
        case ' ':
            break;
        case '\n':
            l++;
            break;
        default:
            if ((c >= 'a' && c <= 'z') ||
                (c >= 'A' && c <= 'Z') ||
                c == '_') 
            {
                int start = start_c; //
                while (remaining > 0) {
                    char next = *source;
                    if ((next >= 'a' && next <= 'z') ||
                        (next >= 'A' && next <= 'Z') ||
                        (next >= '0' && next <= '9') ||
                        next == '_') 
                    {
                        getNchar(&source, &remaining); // get the next characters in the string
                        p++;
                    } else break;
                }
                int end = p; 
                char *str = slice(origin, total_len, start, end);
                if(str) {

                    printf("Identifier -> line %d, name %s\n", l, str);
                    free(str);
                }
            }
            break;
    } 
  }

}



  



