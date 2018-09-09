#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;


//double pi = 3.14159;

//double G = 6.67191e-11

double f(double n, double m, double alfa, double beta, double z, double u1, double u2, double Y)
{
  return -2.0*u2/z  -  pow(u1-Y, m);
}

double g(double n, double m, double alfa, double beta, double z, double u1, double u2, double Y)
{
  return u2;
}

double c(double n, double m, double alfa, double beta, double z, double u1, double u2, double Y, double densidadCentral, double zo)
{
  double p = pow(u1-Y, n)*densidadCentral;
  double a = (alfa*pow(p, 1.0/n) - beta*pow(p, 1.0/m))/z;

  return  2.0*a;
}


int main()
{
  double h = 1.0e-5;
  double zo = 1.0e-5;
  double densidadCentral = 1.0;
  double alfa = 0.9;
  double beta = 1.0;
  double n = 10.0;
  double m = 10.0;
  
  double Fc = ;
  double phiC = Fc - beta*(m+1)*pow(densidadCentral, 1.0/m);
  
  double z = zo;
  double Y = Fc/(phiC - Fc);
  double u1 = 1.0 + Y;
  double u2 = 1.0;

  bool llegoAfrontera = false;

  while(!llegoAfrontera)
    {
      double u1_k1 = g(n, m, alfa, beta, z, u1, u2, Y);
      double u2_k1 = f(n, m, alfa, beta, z, u1, u2, Y);
      double Y_k1 =  c(n, m, alfa, beta, z, u1, u2, Y, densidadCentral, zo);

      double u1_k2 = g(n, m, alfa, beta, z+h/2.0, u1+h*u1_k1/2.0, u2+h*u2_k1/2.0, Y+h*Y_k1/2.0);
      double u2_k2 = f(n, m, alfa, beta, z+h/2.0, u1+h*u1_k1/2.0, u2+h*u2_k1/2.0, Y+h*Y_k1/2.0);
      double Y_k2 =  c(n, m, alfa, beta, z+h/2.0, u1+h*u1_k1/2.0, u2+h*u2_k1/2.0, Y+h*Y_k1/2.0, densidadCentral, zo);

      double u1_k3 = g(n, m, alfa, beta, z+h/2.0, u1+h*u1_k2/2.0, u2+h*u2_k2/2.0, Y+h*Y_k2/2.0);
      double u2_k3 = f(n, m, alfa, beta, z+h/2.0, u1+h*u1_k2/2.0, u2+h*u2_k2/2.0, Y+h*Y_k2/2.0);
      double Y_k3 =  c(n, m, alfa, beta, z+h/2.0, u1+h*u1_k2/2.0, u2+h*u2_k2/2.0, Y+h*Y_k2/2.0, densidadCentral, zo);

      double u1_k4 = g(n, m, alfa, beta, z+h, u1+h*u1_k3, u2+h*u2_k3, Y+h*Y_k3);
      double u2_k4 = f(n, m, alfa, beta, z+h, u1+h*u1_k3, u2+h*u2_k3, Y+h*Y_k3);
      double Y_k4 =  c(n, m, alfa, beta, z+h, u1+h*u1_k3, u2+h*u2_k3, Y+h*Y_k3, densidadCentral, zo);

      z = z+h;
      u1 = u1 + h*(u1_k1 + 2.0*u1_k2 + 2.0*u1_k3 + u1_k4)/6.0;
      u2 = u2 + h*(u2_k1 + 2.0*u2_k2 + 2.0*u2_k3 + u2_k4)/6.0;
      Y = Y + h*(Y_k1 + 2.0*Y_k2 + 2.0*Y_k3 + Y_k4)/6.0;

      if(isnan(u2) || u1-Y < 0.0 || z > 10.0)
	{
	  llegoAfrontera = true;
	  cout << densidadCentral << " " << alfa << " " << beta << endl;
	  cout << n << " " << m << " " << zo << endl;
	}
      else
	{
	  cout << z << " " << u1-Y << " " << u2 - c(n, m , alfa, beta, z, u1, u2, Y, densidadCentral, zo) << endl;
	}
    }

  return 0;
 }
      


