#include "pch.h"

void LC_S()
{
	cout << "LC en serie" << endl;
	// Initialisation de R et C
	double L;
	double C;
	double fmax;
	double fmin;
	int n;
	cout << "Saisir valeur de L: ";
	SaisirValeur(&L);
	cout << endl;
	cout << "Saisir valeur de C: ";
	SaisirValeur(&C);
	cout << endl;
	//Initialisation des frequences
	double a[100];
	Frequence(&fmin, &fmax, &n);
	//Premier cas ou on ne considere qu'une seule valeur de f
	if (n == 1) {
		// Calcul du module et d'argument
		cout << "|Z| : " << ModuleS(0, 2 * M_PI*fmax * L - 1 / (2 * M_PI*fmax * C)) << endl;
		cout << "Arg(Z) : " << ArgS(0, 2 * M_PI*fmax * L - 1 / (2 * M_PI*fmax * C)) << endl;
	}
	//Second cas ou on souhaite calculer les impedances de plusieurs frequences
	else {
		//Initatiation un pas de fmin a fmax puis trouver l'impedance correspondante
		for (int i = 0; i < n + 1; i++) {
			a[i] = (int)(fmin + i * (fmax - fmin) / n);
			cout << "Frequence f" << i + 1 << " : " << a[i] << "\t";
			// Calcul du module et d'argument
			cout << "|Z|" << i + 1 << " : " << ModuleS(0, 2 * M_PI*a[i] * L - 1 / (2 * M_PI*a[i] * C)) << "\t";
			cout << "Arg(Z)" << i + 1 << " : " << ArgS(0, 2 * M_PI*a[i] * L - 1 / (2 * M_PI*a[i] * C)) << endl;
		}
	}


	plinit();
	plfont(2);

	int           i;
	static PLFLT  freql[121], ampl[121], phase[121];
	PLFLT         freq, max;
	PLINT         nlegend;
	PLCHAR_VECTOR text[2], symbols[2];
	PLINT         opt_array[2];
	PLINT         text_colors[2];
	PLINT         line_colors[2];
	PLINT         line_styles[2];
	PLFLT         line_widths[2];
	PLINT         symbol_numbers[2], symbol_colors[2];
	PLFLT         symbol_scales[2];
	PLFLT         legend_width, legend_height;

	pladv(0);
	max = 0;

	// Set up data for log plot

	for (i = 0; i <= 120; i++)
	{
		freql[i] = -2.0 + i / 20.0;
		freq = pow(10.0, freql[i]);
		ampl[i] = ModuleS(0, 2 * M_PI*freq * L - 1 / (2 * M_PI*freq * C));
		phase[i] = ArgS(0, 2 * M_PI*freq * L - 1 / (2 * M_PI*freq * C));
		if (ampl[i] > max) {
			max = ampl[i];
		}
	}


	plvpor(0.15, 0.85, 0.1, 0.85);
	plwind(-2.0, 4.0, 0.0, max);

	plcol0(1);
	plbox("bclnst", 0.0, 0, "bnstv", 0.0, 0);

	// Plot module vs freq

	plcol0(2);
	plline(121, freql, ampl);
	plcol0(2);

	// Put labels on

	plcol0(1);
	plmtex("b", 3.2, 0.5, 0.5, "Frequence (Hz)");
	plmtex("t", 2.0, 0.5, 0.5, "Module d'impedance et phase en fonction de la frequence");
	plcol0(2);
	plmtex("l", 5.0, 0.5, 0.5, "|Z| (Ohm)");
	nlegend = 1;



	plcol0(1);
	plwind(-2.0, 4.0, 45, 100.0);
	plbox("", 0.0, 0, "cmstv", 30.0, 3);
	plcol0(3);
	plline(121, freql, phase);
	plstring(121, freql, phase, "#(728)");
	plcol0(3);
	plmtex("r", 5.0, 0.5, 0.5, "Phase (degrees)");
	nlegend = 2;

	// Draw a legend
	// First legend entry.
	opt_array[0] = PL_LEGEND_LINE;
	text_colors[0] = 2;
	text[0] = "|Z| (Ohm)";
	line_colors[0] = 2;
	line_styles[0] = 1;
	line_widths[0] = 1.;

	symbols[0] = "";

	// Second legend entry.
	opt_array[1] = PL_LEGEND_LINE | PL_LEGEND_SYMBOL;
	text_colors[1] = 3;
	text[1] = "Phase (degrees)";
	line_colors[1] = 3;
	line_styles[1] = 1;
	line_widths[1] = 1.;

	symbol_colors[1] = 3;
	symbol_scales[1] = 1.;
	symbol_numbers[1] = 4;
	symbols[1] = "#(728)";

	// from the above opt_arrays we can completely ignore everything
	// to do with boxes.

	plscol0a(15, 32, 32, 32, 0.70);
	pllegend(&legend_width, &legend_height,
		PL_LEGEND_BACKGROUND | PL_LEGEND_BOUNDING_BOX, 0,
		0.0, 0.0, 0.1, 15,
		1, 1, 0, 0,
		nlegend, opt_array,
		1.0, 1.0, 2.0,
		1., text_colors, (const char **)text,
		NULL, NULL, NULL, NULL,
		line_colors, line_styles, line_widths,
		symbol_colors, symbol_scales, symbol_numbers, (const char **)symbols);
	plend();
	exit(0);

}
