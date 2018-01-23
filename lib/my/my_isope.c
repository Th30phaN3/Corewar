#include        "my.h"

int             my_isope(char c)
{
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
    return (1);
  return (0);
}
