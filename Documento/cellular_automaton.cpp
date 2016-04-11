	# include <cstdlib>
	# include <iostream>
	# include <ctime>

	using namespace std;

	int main ( );
	void timestamp ( );

	int main ( )
	{
	  int i;
	  int j;
	  int n;
	  int step_num;
	  char *x;
	  char *x_old;

	  timestamp ( );
	  cout << "\n";
	  cout << "CELLULAR_AUTOMATON:\n";
	  cout << "  C++ version.\n";

	  n = 80; // cantidad de pasos
	  step_num = 80;

	  x = new char[n+2]; //se crea en memorial la ubicacion de la celula actual
	  x_old = new char[n+2]; //se crea en memorial la ubicacion de la celula muerta

	  for ( i = 0; i <= n + 1; i++ ) // inicialicacion de la lattice
	  {
	    x[i] = ' ';
	  }
	  x[40] = '*'; //en la ultima ubicacion de ponte la primera celular

	  for ( i = 1; i <= n; i++ )
	  {
	    cout << x[i];  // se imprime la primera fila
	  }
	  cout << "\n";

	  for ( j = 1; j <= step_num; j++ ) // se guarda la lattice anterior
	  {
	    for ( i = 0; i < n + 2; i++ )
	    {
	      x_old[i] = x[i];
	    }
	    for ( i = 1; i <= n; i++ )
	    {
	//
	//  The transformation rules are:
	//
	//  111  110  101  100  011  010  001  000
	//   |    |    |    |    |    |    |    |
	//   0    0    0    1    1    1    1    0
	//
	//  which means this rule has binary code 00011110 = 16 + 8 + 4 + 2 = 30

	//  Determina si vive o muere depende de lo que se tenga en la lattice donde se guarda lo anterior

	      if ( ( x_old[i-1] == ' ' && x_old[i] == ' ' && x_old[i+1] == '*' ) ||
	           ( x_old[i-1] == ' ' && x_old[i] == '*' && x_old[i+1] == ' ' ) ||
	           ( x_old[i-1] == ' ' && x_old[i] == '*' && x_old[i+1] == '*' ) ||
	           ( x_old[i-1] == '*' && x_old[i] == ' ' && x_old[i+1] == ' ' ) )
	      {
	        x[i] = '*';
	      }
	      else
	      {
	        x[i] = ' ';
	      }
	    }
	//
	// Hacer cumplir las condiciones de contorno periódicas .
	//
	    x[0] = x[n];
	    x[n+1] = x[1];

	    for ( i = 1; i <= n; i++ )
	    {
	      cout << x[i];
	    }
	    cout << "\n";
	  }
	//
	//  Se libera la memoria por el stackoverflow
	//
	  delete [] x;
	  delete [] x_old;
	//
	//  Terminate.
	//
	  cout << "\n";
	  cout << "CELLULAR_AUTOMATON:\n";
	  cout << "  Normal end of execution.\n";
	  cout << "\n";
	  timestamp ( );

	  return 0;
	}
	//****************************************************************************80

	void timestamp ( )

/*
	Imprime el tiempo en el cual se corrio el programa

	*/
	{
	# define TIME_SIZE 40

	  static char time_buffer[TIME_SIZE];
	  const struct std::tm *tm_ptr;
	  size_t len;
	  std::time_t now;

	  now = std::time ( NULL );
	  tm_ptr = std::localtime ( &now );

	  len = std::strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm_ptr );

	  std::cout << time_buffer << "\n";

	  return;
	# undef TIME_SIZE
	}
