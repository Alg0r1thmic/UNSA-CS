#ifndef FUENTE_H
#define FUENTE_H

#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <ctime>
#include <cstdlib>


using namespace std;

typedef double TypeVal;
typedef function<TypeVal (vector<TypeVal>)> FitFun;



class Fuente{
	public:
		Fuente(){};
		Fuente(FitFun fitFun, int numVal);
		void setFitness();
		void getCandidatos(TypeVal KVal, int j);
		void setProbabilidad(TypeVal sumFit);
		void reemplazar();
		void print();
		vector<TypeVal> valores;
		TypeVal valorFun;
		TypeVal fitness;
		TypeVal probabilidad;
		TypeVal probAcumulada;		
		int count;
		FitFun fitFun;
};

Fuente::Fuente(FitFun fitFun, int numVal){
	this->fitFun = fitFun;
	count = 0;
	double randNum = 0;
	int signo = 0;
	for(int i = 0; i < numVal; i++){
		randNum = static_cast <double> (rand()) /( static_cast <float> (RAND_MAX/(5)));
		signo = rand() % 2;
		if(signo == 1) randNum = -randNum;
		valores.push_back(randNum);
	}
}

void Fuente::print(){
	for(TypeVal val : valores){
		cout<<val<<" ";
	}
	cout<<" | f() = "<<valorFun<<" | fit = "<<fitness<<" | Prob = "<<probabilidad<<" | Cont = "<<count<<endl;
}


void Fuente::setFitness(){
	valorFun = fitFun(valores);
	if(valorFun >= 0){
		fitness = 1.0 / (1.0 + valorFun);
	}
	else{
		fitness = 1.0 + abs(valorFun);
	}
}

void Fuente::getCandidatos(TypeVal KVal, int j){
	vector<TypeVal> candidato = valores;
	double omega = static_cast<double> (rand()) / (static_cast<double> (RAND_MAX));
	int signo = rand() % 2;
	if(signo == 1) omega = -omega;
	candidato[j] = valores[j] + omega * (valores[j] - KVal);
	TypeVal nuevoValorFun = fitFun(candidato);
	TypeVal nuevoFitness  = 0;
	if(nuevoValorFun >= 0){
		nuevoFitness = 1.0 / (1.0 + nuevoValorFun);
	}
	else{
		nuevoFitness = 1.0 + abs(nuevoValorFun);
	}
	if(fitness < nuevoFitness){
		count = 0;
		valores = candidato;
		valorFun = nuevoValorFun;
		fitness = nuevoFitness;
	}
	else count++;
}

void Fuente::setProbabilidad(TypeVal sumFit){
	probabilidad = fitness / sumFit;
}

void Fuente::reemplazar(){
	double numRand = 0;
	count = 0;
	for(int i = 0; i < valores.size(); i++){
		numRand = static_cast<double> (rand()) / (static_cast<double> (RAND_MAX));
		valores[i] = -5 + numRand * (10);
	}
	setFitness();
}


#endif