#include <iostream>
#include "AS1.h"

using namespace std;
				       //       A   B   C   D   E   F   G   H   I   J   K   L  M
matrix costos = 			 {{ 0, 12,  3, 23,  1,  5, 23, 56, 12, 11, 89, 97, 52}, //A
					   		  {12,  0,  9, 18,  3, 41, 45,  5, 41, 27, 16, 76, 56}, //B
					   		  { 3,  9,  0, 89, 56, 21, 12, 48, 14, 29,  5, 91, 8}, //C
					   		  {23, 18, 89,  0, 87, 46, 75, 17, 50, 42,100, 70, 15}, //D
					   		  { 1,  3, 56, 87,  0, 55, 22, 86, 14, 33, 31, 84, 21}, //E
					   		  { 5, 41, 21, 46, 55,  0, 21, 76, 54, 81, 92, 37, 22}, //F
					   		  {23, 45, 12, 75, 22, 21,  0, 11, 57, 48, 39, 59, 22}, //G
					   		  {56,  5, 48, 17, 86, 76, 11,  0, 63, 24, 55, 58, 98}, //H
					   		  {12, 41, 14, 50, 14, 54, 57, 63,  0,  9, 44, 18, 52}, //I
					   		  {11, 27, 29, 42, 33, 81, 48, 24,  9,  0, 64, 65, 82}, //J
					   		  {89, 16, 5, 100, 31, 92, 39, 55, 44, 64,  0,  9, 70}, //K
					   		  {97, 76, 91, 70, 84, 37, 59, 58, 18, 65,  9,  0, 50}, //L
					   		  {52, 56,  8, 15, 21, 22, 22, 98, 52, 82, 70, 50,  0}};//M



int main(){
	srand(time(NULL));
	double femIni = 0.2;
	int numH = 4;
	int numIter = 100;
	int nBL = 5;

	double evaporacion = 0.9;
	double alfa = 1;
	double beta = 1;
	double Q = 1;

	AS as(costos, femIni, alfa, beta, Q, evaporacion, numH, numIter, nBL);
	as.run();
}