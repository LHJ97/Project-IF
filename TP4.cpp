// TP4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

int circuit = 0;

int main()
{
	cout << "******************Bienvenue au CalculImpedance*******************\n";
	cout << "Choisir le circuit que vous voulez travailler" << endl;
	cout << "1. RL serie" << endl;
	cout << "2. RL parallele" << endl;
	cout << "3. RC serie" << endl;
	cout << "4. RL parallele" << endl;
	cout << "5. LC serie" << endl;
	cout << "6. LC parallele" << endl;
	cout << "Saisir ici: " << endl;
	cin >> circuit;

	switch (circuit) {
	case 1: RL_S(); break;
	case 2: RL_P(); break;
	case 3: RC_S(); break;
	case 4: RC_P(); break;
	case 5: LC_S(); break;
	case 6: LC_P(); break;
	default: break;
	}
}

