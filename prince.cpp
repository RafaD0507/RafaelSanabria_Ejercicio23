#include <iostream>
#include <cmath>

using namespace std;
double u_inicial(double x);

int main(){
  double x_down = 0;
  double x_up = 1;
  double c = 0.1;
  double dx = 0.01;
  double dt = 0.00001;
  double k = c*dt/dx;
  int nx = x_up/dx+1;
  double *u = new double[nx];
  double *temp = new double[nx];
  double *viejo = new double[nx];
  double **respuestas = new double*[4];

  for(int i=0; i<4; i++){
    respuestas[i] = new double[nx];
  }

  double x = x_down;
  
  for(int i=0; i<nx; i++){
    u[i] = u_inicial(x);
    temp[i] = u_inicial(x);
    viejo[i] = u_inicial(x);
    x = x + dx;
  }

  int soluciones = 0;
  int j = 1;

  while(soluciones<4){
    for(int i=1; i<nx-1; i++){
      if(j==1){
	u[i] = (k*k/2)*(temp[i+1]+temp[i-1]-2*temp[i])+temp[i];
      }else{
	u[i] = (k*k)*(temp[i+1]+temp[i-1]-2*temp[i])+2*temp[i]-viejo[i];
      }
    }
    
    if((u[nx/4]<=1.0 && soluciones==0) || (u[nx/4]<=0.5 && soluciones==1) || (u[nx/4]<=-0.5 && soluciones==2) || (u[nx/4]<=-0.99 && soluciones==3)){
	for(int i=0; i<nx; i++){
	  respuestas[soluciones][i] = u[i];
	}
	soluciones = soluciones + 1;
    }
    
    for(int i=1; i<nx; i++){
      viejo[i] = temp[i];
      temp[i] = u[i];
    }
    
    j = j + 1;
  }

  x = x_down;

  for(int i=0; i<nx; i++){
    cout<<x<<" "<<respuestas[0][i]<<" "<<respuestas[1][i]<<" "<<respuestas[2][i]<<" "<<respuestas[3][i]<<endl;
    x = x + dx;
  }
}

double u_inicial(double x){
  double pi = 3.141592654;
  return sin(2*pi*x);
}
