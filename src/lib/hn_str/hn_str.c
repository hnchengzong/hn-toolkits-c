#include "../include/hn_str/hn_str.h"
#include "../include/sort/hn_swap.h"
#include <stddef.h>
size_t hn_strlen(const char *str) {
  size_t len = 0;
  if (str == NULL) {
    return len;
  }
  for (; str[len] != '\0'; len++)
    ;
  return len;
}

char *hn_strfd(const char *restrict str, const char find_char) {
  if (str == NULL) {
    return NULL;
  }
  for (; *str != '\0'; str++) {
    if (*str == find_char)
      return str;
  }
  return NULL;
}

int hn_strrepl(char *restrict str, const char src_char,
               const char replace_str) {
  if (str == NULL) {
    return -1;
  }
  if (replace_str == "\0") {
    return -1;
  }
  if (hn_strfd(str, src_char) == NULL) {
    return 0;
  }
  for (; *str != '\0'; str++) {
    if (*str == src_char)
      *str = replace_str;
  }
  return 0;
}
int hn_strrev(char *restrict str) {
  if (str == NULL) {
    return -1;
  }
  const size_t len = hn_strlen(str);
  if (len == 0 || len == 1) {
    return 0;
  }
  char *start = str;
  char *end = str + len - 1;
  for (; start < end; start++, end--) {
    SWAP(*start, *end);
  }
  return 0;
}

int hn_strcmp(const char *restrict str1, const char *restrict str2) {
  if (str1 == NULL || str2 == NULL) {
    return -1;
  }
  for (; *str1 == *str2; str1++, str2++) {
    if (*str1 == '\0')
      return 0;
  }
  return *str1 - *str2;
}

int hn_strupper(char *restrict str) {
  if (str == NULL) {
    return -1;
  }
  for (; *str != '\0'; str++) {
    if (*str >= 'a' && *str <= 'z')
      *str -= 32;
  }
  return 0;
}

int hn_strlower(char *restrict str) {
  if (str == NULL) {
    return -1;
  }
  for (; *str != '\0'; str++) {
    if (*str >= 'A' && *str <= 'Z')
      *str += 32;
  }
  return 0;
}

int hn_strtrim(char *restrict str) {
  if (str == NULL) {
    return -1;
  }
  char *slow = str;
  for (char *fast = str; *fast != '\0'; fast++) {
    if (*fast == ' ' || *fast == '\t' || *fast == '\n') {
      continue;
    }
    *slow = *fast;
    *slow++;
  }
  *slow = '\0';
  return 0;
}
