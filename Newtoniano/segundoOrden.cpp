#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;


double f(double n, double z, double y1, double y2)
{
  return -pow(y1, n)-(2.0*y2/z);
}

double g(double n, double z, double y1, double y2)
{
  return y2;
}


int main()
{
  int i = 0;

  double h = 0.0001;

  int N = 400.0/h;

  double L = 4000.0;
 
  

  double y1 = 1.0;

  double y2 = 0.0;

  double z = 1.0/100000000000000.0;

  double n = 1.0;

  bool llegoAfrontera = false;

  double frontera = 0.0;

  double derivada = 0.0;

  

  for (i = 0; i < N && !llegoAfrontera; i++)
    {
      double vy1 = y1;
      double vy2 = y2;

      double a1 = f(n, z, y1, y2);
      double b1 = g(n, z, y1, y2);

      double a2 = f(n, z+h/2.0, y1 + h*b1/2.0, y2 + h*a1/2.0);
      double b2 = g(n, z+h/2.0, y1 + h*b1/2.0, y2 + h*a1/2.0);

      double a3 = f(n, z+h/2.0, y1 + h*b2/2.0, y2 + h*a2/2.0);
      double b3 = g(n, z+h/2.0, y1 + h*a2/2.0, y2 + h*a2/2.0);

      double a4 = f(n, z+h, y1 + h*b3, y2 + h*a3);
      double b4 = g(n, z+h, y1 + h*b3, y2 + h*a3);

      z = z + h;

      y1 = y1 + h*(b1 + 2.0*b2 + 2.0*b3 + b4)/6.0;

      y2 = y2 + h*(a1 + 2.0*a2 + 2.0*a3 + a4)/6.0;

      cout << z << " " << y1 << " " << y2 << endl;


      if ( isnan(y2) || (vy1 > 0.0 && y1 < 0.0) )
	{
	  frontera = z;

	  derivada = vy2;

	  llegoAfrontera = true;
	}

    }

  cout << frontera << " " << derivada << " " << n << endl;

  return 0;

}
