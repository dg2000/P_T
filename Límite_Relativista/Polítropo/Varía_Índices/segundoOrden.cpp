#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;


double f(double n, double m, double alfa, double beta, double z, double y1, double y2, double densidadCentral, double zo)
{
  double c = -2.0/(beta*(m+1)*pow(densidadCentral, 1.0/m));
  double a = y2*((alfa*m/n)*pow(densidadCentral, 1.0/n)*pow(y1, -1.0+m/n) - beta*pow(densidadCentral, 1.0/m))/z;
  double b = (alfa*pow(densidadCentral, 1.0/n)*pow(y1, m/n) - beta*pow(densidadCentral, 1.0/m)*y1)/(z*z);

  return -c*(a + b) - 2.0*y2/z - pow(y1, m);
}

double g(double n, double m, double alfa, double beta, double z, double y1, double y2, double densidadCentral, double zo)
{
  return y2;
}

double solucion(double h, double zo, double densidadCentral, double alfa, double beta,  double n, double m)
{
  double z = zo;
  double y1 = 1.0;
  double y2 = 0.0;

  bool llegoAfrontera = false;

  while(!llegoAfrontera)
    {
      double vy1 = y1;
      double vy2 = y2;

      double y1_k1 = g(n, m, alfa, beta, z, y1, y2, densidadCentral, zo);
      double y2_k1 = f(n, m, alfa, beta, z, y1, y2, densidadCentral, zo);

      double y1_k2 = g(n, m, alfa, beta, z+h/2.0, y1+h*y1_k1/2.0, y2+h*y2_k1/2.0, densidadCentral, zo);
      double y2_k2 = f(n, m, alfa, beta, z+h/2.0, y1+h*y1_k1/2.0, y2+h*y2_k1/2.0, densidadCentral, zo);

      double y1_k3 = g(n, m, alfa, beta, z+h/2.0, y1+h*y1_k2/2.0, y2+h*y2_k2/2.0, densidadCentral, zo);
      double y2_k3 = f(n, m, alfa, beta, z+h/2.0, y1+h*y1_k2/2.0, y2+h*y2_k2/2.0, densidadCentral, zo);

      double y1_k4 = g(n, m, alfa, beta, z+h, y1+h*y1_k3, y2+h*y2_k3, densidadCentral, zo);
      double y2_k4 = f(n, m, alfa, beta, z+h, y1+h*y1_k3, y2+h*y2_k3, densidadCentral, zo);

      z = z + h;

      y1 = y1 + h*(y1_k1 + 2.0*y1_k2 + 2.0*y1_k3 + y1_k4)/6.0;

      y2 = y2 + h*(y2_k1 + 2.0*y2_k2 + 2.0*y2_k3 + y2_k4)/6.0;


      if (isnan(y2) || (y1 < 0.0))
	{  
	  llegoAfrontera = true;
	  y1 = vy1;
	  y2 = vy2;
	  z = z - h;
	}

    }

  double c1 = 4*3.14159*(6.674e-11)/((beta*(m+1))**m);
  double c2 = beta*(m+1)*((densidadCentral)**(1.0/m));
  double c3 = c1*(c2**(m-1.0));
  double c4 = c3**0.5;

  double cfinal = -(4*3.14159*densidadCentral)/(c4*c4*c4)

  return z*z*y2;

}


int main()
{  
  double h = 1.0e-4;
  double zo = 1.0e-4;
  double densidadCentral = 839957546.7;
  double n_inicial = 1.4;
  double m_inicial = 1.5;
  double alfa_inicial = 3115999.803;
  double beta_inicial = 3115999.803/1.5;
  
  double n_final = 8.0;
  double m_final = 5.3;
  double alfa_final = 3115999.803*4.0;
  double beta_final = 3115999.803*4.0;

  double salto = 100000.0;

  std::string variable = "beta";

  if(variable.compare("m") == 0)
    {  
      for(int i = 0; m_inicial + i*salto < m_final; i++)
	{
	  double nuevo = solucion(h, zo, densidadCentral, alfa_inicial, beta_inicial, n_inicial, m_inicial + i*salto);
	  double chandrasekhar = solucion(h, zo, densidadCentral, beta_inicial, beta_inicial, m_inicial + i*salto, m_inicial + i*salto);
	  double masa = nuevo;//chandrasekhar;
	  

	  cout << m_inicial + i*salto << " " << masa << endl;
	}
      cout << alfa_inicial << " " << beta_inicial << endl;
      cout << n_inicial << " " << 0.0 << endl;
      cout << m_inicial << " " << m_final << endl;
    }

  else if(variable.compare("n") == 0)
    {
      for(int i = 0; n_inicial + i*salto < n_final; i++)
	{
	  double nuevo = solucion(h, zo, densidadCentral, alfa_inicial, beta_inicial, n_inicial + i*salto, m_inicial);
	  double chandrasekhar = solucion(h, zo, densidadCentral, alfa_inicial, beta_inicial, m_inicial, m_inicial);
	  double masa = nuevo/chandrasekhar;

	  cout << n_inicial + i*salto << " " << masa << endl;
	}
      cout << alfa_inicial << " " << beta_inicial << endl;
      cout << m_inicial << " " << 1.0 << endl;
      cout << n_inicial << " " << n_final << endl;
    }

  else if(variable.compare("alfa") == 0)
    {
      for(int i = 0; alfa_inicial + i*salto < alfa_final; i++)
	{
	  double nuevo = solucion(h, zo, densidadCentral, alfa_inicial + i*salto, beta_inicial, n_inicial, m_inicial);
	  double chandrasekhar = solucion(h, zo, densidadCentral, beta_inicial, beta_inicial, m_inicial, m_inicial);
	  double masa = nuevo/chandrasekhar;

	  cout << alfa_inicial + i*salto << " " << masa << endl;
	}
      cout << n_inicial << " " << m_inicial << endl;
      cout << beta_inicial << " " << 2.0 << endl;
      cout << alfa_inicial << " " << alfa_final << endl;
    }

else if(variable.compare("beta") == 0)
    {
      for(int i = 0; beta_inicial + i*salto < beta_final; i++)
	{
	  double nuevo = solucion(h, zo, densidadCentral, alfa_inicial, beta_inicial + i*salto, n_inicial, m_inicial);
	  double chandrasekhar = solucion(h, zo, densidadCentral, beta_inicial + i*salto, beta_inicial + i*salto, m_inicial, m_inicial);
	  double masa = nuevo/chandrasekhar;

	  cout << beta_inicial + i*salto << " " << masa << endl;
	}
      cout << n_inicial << " " << m_inicial << endl;
      cout << alfa_inicial << " " << 3.0 << endl;
      cout << beta_inicial << " " << beta_final << endl;
    }

      
}

  
      
