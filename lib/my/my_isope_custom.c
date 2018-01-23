#include	"my.h"

int		my_isope_custom(char c, char *ops)
{
  if (c == ops[2] || c == ops[3] || c == ops[4] || c == ops[5] || c == ops[6])
    return (1);
  return (0);
}
