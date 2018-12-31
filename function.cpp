#include "pch.h"

double ModuleS(double r, double x)
{
	double module = sqrt(r*r + x * x);
	return module;
}

double ModuleP(double r, double x)
{
	double module = sqrt(pow(r*x*x / (r*r + x * x), 2) + pow(r*r*x / (r*r + x * x), 2));
	return module;
}

double Module(double r, double x, int circuit)
{
	double module;
	if (circuit % 2 == 0)
	{
		module = sqrt(pow(r*x*x / (r*r + x * x), 2) + pow(r*r*x / (r*r + x * x), 2));
	}
	else {
		module = sqrt(r*r + x * x);
	}

	return module;
}

double ArgS(double r, double i)
{
	double arg;
	if (r == 0) arg = 90;
	else arg = atan2(i, r) * 180 / M_PI;
	return arg;
}

double ArgP(double r, double i)
{
	double arg;
	if (r == 0) arg = 90;
	else arg = atan2(r, i) * 180 / M_PI;
	return arg;
}

void Frequence(double *fmin, double *fmax, int *n)
{
	do {
		cout << "Saisir le nombre de frequence: ";
		cin >> *n;
		cout << endl;
		if (*n < 1) {
			cout << "Entrez une valeur positive non nulle!" << endl;
		}
	} while (*n < 1);

	if (*n > 1) {
		cout << "Saisir la frequence min: ";
		cin >> *fmin;
		cout << "Saisir la frequence max: ";
		cin >> *fmax;
		cout << endl;
	}
	else {
		cout << "Saisir la frequence: ";
		cin >> *fmax;
		cout << endl;
		*fmin = 1;
	}
}

void SaisirValeur(double *valeur)
{
	cin >> *valeur;
	cout << endl;
}


