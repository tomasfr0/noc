#include "noc.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#define WINDOWS_PLATFORM
#else
#define LINUX_PLATFORM
#endif


char* read_content(const char *fname)
{
  FILE *fp = NULL;
  fp = fopen(fname, "r");
  if(fp == NULL) return NULL;
  fseek(fp, 0, SEEK_END);
  long s = ftell(fp);
  rewind(fp);
  char *source = (char*) malloc(sizeof(char) * s);
  fread(source, 1, s, fp);
  fclose(fp);
  return source;
}


int main(int argc, char **argv)
{
  
  if(argc-1 < 0) return NOC_FAILURE;
  char *source = read_content(argv[1]);  
  int len = strlen(source);
  struct s_token *tokens = (struct s_token*) malloc(sizeof(struct s_token));
  parse(source, len, &tokens);
/*
  int c;
  
  while((c = getNchar(&source, &l)) != -1) {
    printf("%c ", c);  
  }
*/
  free(source);
  free(tokens);
  
  return NOC_EXIT;
}
