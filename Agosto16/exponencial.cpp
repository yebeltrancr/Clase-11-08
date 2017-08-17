//Programa que simula una función exponencial

#include<iostream>
#include<cmath>

int fact(int n);
double SerieT(double x, int N);
double SerieB(double x, int N);


int main(void)
{
  std::cout.precision(16); std::cout.setf(std::ios::scientific);

  double x=22;

  for (int Nmax = 0; Nmax <= 100; ++Nmax){
    std::cout << Nmax
	      <<"\t" << SerieB(x, Nmax)
	      <<"\t" << std::fabs(SerieB(x, Nmax) - std::exp(-x))/std::exp(-x)
	      << std::endl;
  }
  return 0;
}

//función que crea el factorial

int fact(int n)
{
  if(n <= 0) return 1;
  return n*fact(n-1);
}

//Función para calcular terminos de la serie

double SerieT(double x,int N)
{
  double suma=0, term=0;
  for(int i=0; i<=N; i++){
    term= std::pow(-x,i)/fact(i);
    suma*=term;
  }

  return suma;
}

/* se usa una forma recursiva para poder calcular sin que me de valores
de overflow cuando se realizan las operaciones con serieT (implementación tonta)
*/

double SerieB(double x, int N){
  double term=1, suma=1;
  for(int k = 0; k < N; ++k){
    term *= (-x)/(k+1);
    suma += term;
  }
  return suma;
}
