#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <time.h>
#include <sys/wait.h>
#include <math.h>

using namespace std;

double PI = acos(-1.0); // limit of rand function for angle

double x; // x coordenadas del centro de la aguja 
double a; // ángulo entre la posición vertical y la aguja
double l; // longitud de la aguja
double n; // número de intentos
double ca; // cantidad de aciertos
double y; // sin(angle) * l
double pi; // output
double i; // loop counter

void lanzar(){
	a = (double)rand()/(RAND_MAX)*2*PI;      // random angle (0 - 2PI)
	x = (double)rand()/(RAND_MAX)/2;         // random x (0 - 0.5)
	y = (l/2) * sin (a);
	if (x<=y){
		ca++;                                    
	}
}

int main(int argc, char* argv[]){
	n = (double)atoi(argv[1]);

	srand(time(NULL));

	//n = 1000;
	ca = 0;
	l = 1;

	struct timeval start;
	struct timeval end;
	double milisecs;
	long seconds, useconds;
  
	gettimeofday(&start, 0);
	for (i=0; i<n; i++){
		lanzar();
	}
	gettimeofday(&end, 0);

	seconds  = end.tv_sec  - start.tv_sec;
	useconds = end.tv_usec - start.tv_usec;
	milisecs = ((seconds) * 1000 + useconds/1000.0);
	cout << n << "\t" << ca <<"\t"; 
	pi = (l/ca)*(n);
	cout << milisecs << "\t" << pi << endl;
}


