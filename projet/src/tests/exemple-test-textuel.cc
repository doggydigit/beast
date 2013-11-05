#include "../RandomGenerator/Uniform.h"
#include "../RandomGenerator/Normal.h"

#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	// Génère quelques valeurs de Uniform et de Normal et les affiches
    // dans un "graph"

    unsigned int const NB_CASE_U(20);
    unsigned int const NB_CASE_N(30);

    vector<int> ugraph(NB_CASE_U);
    vector<int> ngraph(NB_CASE_N);

    Uniform udist(0, 100);
    Normal ndist(0, 1);

    unsigned int const NB_VALEUR(1000);

    for (unsigned int i = 0; i < NB_VALEUR; ++i) {

        // génère depuis Uniform
        ++ugraph[std::floor(udist.getValue()/(100.0/NB_CASE_U))];

        // génère depuis normal
        double val = ndist.getValue() + 2.0;
        if (val < 0.0) val =  0.0;
        if (val > 4.0) val =  4.0;
        ++ngraph[std::floor(val/(4.0/NB_CASE_N))];

    }

    // Affiche les graphs
    cout << "UNIFORM(0, 100)" << endl;
    for (int i = 0; i < ugraph.size(); ++i) {
        cout << string(ugraph[i], '*') << endl;
    }

    cout << endl << endl;

    cout << "NORMAL(0, 1)" << endl;
    for (int i = 0; i < ngraph.size(); ++i) {
        cout << string(ngraph[i], '*') << endl;
    }

	return 0;
}

