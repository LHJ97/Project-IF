#ifndef FUNCTION_H
#define FUNCTION_H
//Fonctions pour calculer le module et l'impedance
double ModuleS(double r, double i);
double ModuleP(double r, double i);

double ArgS(double r, double i);
double ArgP(double r, double i);

//Fonctions pour saisir la frequence et la valeur des composants R,L,C
void Frequence(double *fmin, double *fmax, int *n);
void SaisirValeur(double *valeur);

//Fonctions pour les circuits traites
void RC_S();
void RC_P();
void RL_S();
void RL_P();
void LC_S();
void LC_P();
#endif // FUNCTION_H
#pragma once
