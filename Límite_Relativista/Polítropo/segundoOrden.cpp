#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

double f(double n, double m, double alfa, double beta, double r, double y1, double y2)
{
  double pi = 3.14159;

  double G = 6.67349e-11;
  
  double z = beta*(m*m - 1.0)*pow(y1, (1.0/m) - 2.0)*y2*y2/(m*m)  +  2.0*alfa*pow(y1, 1.0/n)/(r*r)  +  2.0*alfa*pow(y1, (1.0/n) - 1.0)*y2/(n*r);

  double c = m*pow(y1, 1.0 - (1.0/m))/(beta*(m+1.0));

  return c*(  z - 4.0*pi*G*y1 - 2.0*beta*pow(y1, 1.0/m)/(r*r) - 2.0*beta*(m+2.0)*pow(y1, (1.0/m) - 1.0)*y2/(m*r)  );

}

double g(double n, double m, double alfa, double beta, double r, double y1, double y2)
{
  return y2;
}


int main()
{
  double h = 1.0e-1;

  double densidadCentral = 1.0;
  
  double n = 2.0;
  
  double m = 3.0;

  double alfa = 1.0;

  double beta = 1.0;

  double r = 1.0e-3;

  double y1 = densidadCentral;

  double y2 = 0.0;

  bool llegoAfrontera = false;


  while(!llegoAfrontera)
    {
      double vy1 = y1;
      double vy2 = y2;

      double y1_k1 = g(n, m, alfa, beta, r, y1, y2);
      double y2_k1 = f(n, m, alfa, beta, r, y1, y2);

      double y1_k2 = g(n, m, alfa, beta, r+h/2.0, y1+h*y1_k1/2.0, y2+h*y2_k1/2.0);
      double y2_k2 = f(n, m, alfa, beta, r+h/2.0, y1+h*y1_k1/2.0, y2+h*y2_k1/2.0);

      double y1_k3 = g(n, m, alfa, beta, r+h/2.0, y1+h*y1_k2/2.0, y2+h*y2_k2/2.0);
      double y2_k3 = f(n, m, alfa, beta, r+h/2.0, y1+h*y1_k2/2.0, y2+h*y2_k2/2.0);

      double y1_k4 = g(n, m, alfa, beta, r+h, y1+h*y1_k3, y2+h*y2_k3);
      double y2_k4 = f(n, m, alfa, beta, r+h, y1+h*y1_k3, y2+h*y2_k3);

      r = r + h;

      y1 = y1 + h*(y1_k1 + 2.0*y1_k2 + 2.0*y1_k3 + y1_k4)/6.0;

      y2 = y2 + h*(y2_k1 + 2.0*y2_k2 + 2.0*y2_k3 + y2_k4)/6.0;


      if (isnan(y2) || (y1 < 0.01) ) 
	{
	  
	  llegoAfrontera = true;

	  cout << densidadCentral << " " << alfa << " " << beta << endl;
	  cout << n << " " << m << " " << m << endl;
	}
      else
	{
	  cout << r << " " << y1 << " " << y2 << endl;
	}

    }

  return 0;

}
