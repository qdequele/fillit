#include <ft_fillit.h>

int main()
{
  int i;
  t_env test_env;
  t_coord coords;

  i = 0;
  while (i < 6){
    coords.x = i;
    coords.x = i * 2;
    push_tetrimino(&test_env, &coords);
    i++;
  }
  return (0);
}
