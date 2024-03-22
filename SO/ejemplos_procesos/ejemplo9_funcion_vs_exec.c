#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main ()
{

  int ret;
  int hijo;
  int codigo_fin;
  ret = fork ();


  if (ret == 0)
    {
      fprintf (stdout, "Proceso %d: antes de mifunc\n", getpid ());
      execlp ("./mifunc", "mifunc", (char *) 0);
      fprintf (stdout, "Proceso %d: despues de mifunc\n", getpid ());
      exit (0);
    }
  else
    {
      hijo = wait (&codigo_fin);
      while (hijo > 0)
	{
	  if (WIFEXITED (codigo_fin))
	    {
	      fprintf (stdout, "Hijo %d acaba con codigo %d\n", hijo,
		       WEXITSTATUS (codigo_fin));

	    }
	  hijo = wait (&codigo_fin);

	}

    }


}
