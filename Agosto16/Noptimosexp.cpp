//Programa que simula una función exponencial

#include<iostream>
#include<cmath>

double SerieB(double x, int N);
double NError(double x, int N);

int main(void)
{
  std::cout.precision(16); std::cout.setf(std::ios::scientific);

  int xmax = 700;
  int Nmax = 100000;
  int P = 10;
  
  for (int i = 1; i<=xmax; ++i){
    for (int N = P; N <= Nmax; ++N){
      if (NError(i, N) == NError(i, N+1)){
	std::cout<<i
		 <<"\t"
		 <<N
		 <<"\t"
		 <<NError(i, N)
		 <<std::endl;
	P=N-10;
	break;
	  }
    }
  }
  return 0;
}


/* se usa una forma recursiva para poder calcular sin que me de valores
de overflow cuando se realizan las operaciones con serieT (implementación tonta)
*/

double SerieB(double x, int N)
{
  double term=1.0, suma=1.0;
  for(int k = 0; k < N; ++k){
    term *= (-x)/(k+1);
    suma += term;
  }
  return suma;
}

/* Se hace una comparación entre la función expoenciañ contruida y la 
función expoencial de la libresia de cmath, y se genera un error para
encontar en N optimo*/

double NError(double x, int N)
{
  double ror = fabs(SerieB(x, N) - std::exp(x)) / std::exp(x);
  return ror;

}













