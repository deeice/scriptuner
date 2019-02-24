#include <stdio.h>
#include <string.h>
#include <termios.h>

const char echo[6] = "-echo";

main (int argc, char **argv)
{
  struct termios t;
  if (-1 != tcgetattr(0,&t)){
    if ((argc > 1) && !strncmp(argv[1], echo, 5))
      t.c_lflag &= ~ECHO; /* turn off ECHO */
    else if ((argc > 1) && !strncmp(argv[1], echo+1, 4))
      t.c_lflag |= ECHO; /* turn on ECHO */
    else if ((argc > 1) && !strncmp(argv[1], "-g", 2))
      puts(echo+1);
    tcsetattr(0, TCSANOW, &t);
  }
}

