#include "pch.h"

void RL_P()
{
	cout << "RL en parallele" << endl;
	// Initialisation de R et C
	double R;
	double L;
	double fmax;
	double fmin;
	int n;
	cout << "Saisir valeur de R: ";
	SaisirValeur(&R);
	cout << endl;
	cout << "Saisir valeur de L: ";
	SaisirValeur(&L);
	cout << endl;
	//Initialisation des frequences
	double a[100];
	Frequence(&fmin, &fmax, &n);
	//Premier cas ou on ne considere qu'une seule valeur de f
	if (n == 1) {
		// Calcul du module et d'argument
		cout << "|Z| : " << ModuleP(R, 2 * M_PI*fmax * L) << endl;
		cout << "Arg(Z) : " << ArgP(R, 2 * M_PI*fmax * L) << endl;
	}
	//Second cas ou on souhaite calculer les impedances de plusieurs frequences
	else {
		//Initatiation un pas de fmin a fmax puis trouver l'impedance correspondante
		for (int i = 0; i < n + 1; i++) {
			a[i] = (int)(fmin + i * (fmax - fmin) / n);
			cout << "Frequence f" << i + 1 << " : " << a[i] << "\t";
			// Calcul du module et d'argument
			cout << "|Z|" << i + 1 << " : " << ModuleP(R, 2 * M_PI*fmax * L) << "\t";
			cout << "Arg(Z)" << i + 1 << " : " << ArgP(R, 2 * M_PI*fmax * L) << endl;
		}
	}

}
