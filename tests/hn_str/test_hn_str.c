#include "../include/hn_str/hn_str.h"
#include <stdio.h>

int main(void) {
  char str[] = "  hello \n world & 123\t ";
  hn_strtrim(str);
  fprintf(stdout, "%s\n", str);
  hn_strrev(str);
  fprintf(stdout, "%s\n", str);
  hn_strrepl(str, '&', '*');
  fprintf(stdout, "%s\n", str);
  hn_strrev(str);
  hn_strupper(str);
  fprintf(stdout, "%s\n", str);
  hn_strlower(str);
  fprintf(stdout, "%s\n", str);
  fprintf(stdout, "length: %zu\n", hn_strlen(str));

  char *str2 = hn_strfd(str, 'w');
  fprintf(stdout, "%s\n", str2);
  int cmp_result = hn_strcmp(str, str2);
  fprintf(stdout, "cmp_result: %d\n", cmp_result);
}
