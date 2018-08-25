#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;






double a(double densidadCentral, double n, double m, double alfa, double beta, double z, double u1, double u2, double Y)
{
  return -2.0*u2/z - pow(u1 - Y, n);
}

double b(double densidadCentral, double n, double m, double alfa, double beta, double z, double u1, double u2, double Y)
{
  return u2;
}

double c(double densidadCentral, double n, double m, double alfa, double beta, double z, double u1, double u2, double Y)
{
  double p = densidadCentral*pow(u1 - Y, n);
  double num = beta*pow(p, 1.0/m) - alfa*pow(p, 1.0/n);

  return num/z; 
}

double solucion(double densidadCentral, double n, double m, double alfa, double beta, double h)
{
  double G = 6.67191e-11;

  double pi = 3.14159;

  double cte = pow( 4.0*pi*G*pow(alfa*(n+1)*pow(densidadCentral, 1.0/n), n-1) / pow(alfa*(n+1), n) , 0.5);

  double z = h;

  double u1 = densidadCentral;

  double u2 = 0.0;

  double Y = 0.0;

  bool llegoAfrontera = false;


  while(!llegoAfrontera)
    {
      double vu1 = u1;
      double vu2 = u2;
      double vY = Y;
      
      double u1_k1 = b(densidadCentral, n, m, alfa, beta, z, u1, u2, Y);
      double u2_k1 = a(densidadCentral, n, m, alfa, beta, z, u1, u2, Y);
      double Y_k1 = c(densidadCentral, n, m, alfa, beta, z, u1, u2, Y);

      double u1_k2 = b(densidadCentral, n, m, alfa, beta, z+h/2.0, u1+h*u1_k1/2.0, u2+h*u2_k1/2.0, Y);
      double u2_k2 = a(densidadCentral, n, m, alfa, beta, z+h/2.0, u1+h*u1_k1/2.0, u2+h*u2_k1/2.0, Y);
      double Y_k2 = c(densidadCentral, n, m, alfa, beta, z+h/2.0, u1+h*u1_k1/2.0, u2+h*u2_k1/2.0, Y);

      double u1_k3 = b(densidadCentral, n, m, alfa, beta, z+h/2.0, u1+h*u1_k2/2.0, u2+h*u2_k2/2.0, Y);
      double u2_k3 = a(densidadCentral, n, m, alfa, beta, z+h/2.0, u1+h*u1_k2/2.0, u2+h*u2_k2/2.0, Y);
      double Y_k3 = c(densidadCentral, n, m, alfa, beta, z+h/2.0, u1+h*u1_k2/2.0, u2+h*u2_k2/2.0, Y);

      double u1_k4 = b(densidadCentral, n, m, alfa, beta, z+h, u1+h*u1_k3, u2+h*u2_k3, Y);
      double u2_k4 = a(densidadCentral, n, m, alfa, beta, z+h, u1+h*u1_k3, u2+h*u2_k3, Y);
      double Y_k4 = c(densidadCentral, n, m, alfa, beta, z+h, u1+h*u1_k3, u2+h*u2_k3, Y);

      z = z + h;

      u1 = u1 + h*(u1_k1 + 2.0*u1_k2 + 2.0*u1_k3 + u1_k4)/6.0;

      u2 = u2 + h*(u2_k1 + 2.0*u2_k2 + 2.0*u2_k3 + u2_k4)/6.0;

      Y = Y + h*(Y_k1 + 2.0*Y_k2 + 2.0*Y_k3 + Y_k4)/6.0;


      if ( isnan(u2) || u1 < 0.1 || vu1 - u1 < 0) 
	{
	  llegoAfrontera = true;

	  u1 = vu1;
	  u2 = vu2;
	  Y = vY;	  
	}
    }

  double M = -4.0*pi*densidadCentral*z*z*u2/(cte*cte*cte);

  double* resultado = new double[3]; resultado[0] = z; resultado[1] = u2; resultado[2] = M;

  return z/cte;
}


int main()
{
  int L = 10;
  
  double indice_inicial = 2.0;

  double indice_final = 2.0;

  double salto = (indice_final - indice_inicial)/(L-1.0);

  double h = 1.0e-1;

  double densidadCentral = 1.0;
 
  double alfa = 1.0;

  double beta = 1.0;

  for(int i = 0; i <= L-1.0; i++)
    {
      for(int j = 0; j <= L-1.0; j++)
	{
	  cout << solucion(densidadCentral, indice_inicial + salto*j, indice_inicial + salto*i, alfa, beta, h) << " ";
	}
      cout << endl;
    } 

  return 0;
}
