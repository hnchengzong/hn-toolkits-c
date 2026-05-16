#pragma once

#include <stddef.h>

extern size_t hn_strlen(const char *restrict str);
extern char *hn_strfd(const char *restrict str, const char find_char);
extern int hn_strrepl(char *restrict str, const char find_char,
                      const char replace_char);
extern int hn_strrev(char *restrict str);
extern int hn_strcmp(const char *restrict str1, const char *restrict str2);
extern int hn_strupper(char *restrict str);
extern int hn_strlower(char *restrict str);
extern int hn_strtrim(char *restrict str);