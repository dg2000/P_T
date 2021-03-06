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


int main()
{
  double h = 1.0e-4;
  double zo = 1.0e-4;
  double densidadCentral = 839957546.7;
  double n = 1.3;
  double m = 1.5;
  double alfa = 3115999.803/2.0;
  double beta = 3115999.803;

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
	  
	  cout << densidadCentral << " " << alfa << " " << beta << endl;
	  cout << n << " " << m << " " << m << endl;
	}

      else
	{
	  cout << z << " " << y1 << " " << y2 << endl;
	}
    }

  return 0;

}





  
