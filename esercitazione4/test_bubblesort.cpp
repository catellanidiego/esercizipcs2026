#include <vector>
#include <cstdlib>
#include <ctime>
//reperita documentazione online sull'uso di rand per generare la dimensione del vettore.
#include "bubblesort.hpp"
#include "is_sorted.hpp"
#include "randfiller.h"
int main() {
	srand(time(NULL));
	randfiller rf;
	for (int i=0; i<100; i++) {
		int dim = rand() % 1001;
		std::vector<int> v(dim);
		rf.fill(v, -100, 100);
		bubblesort(v);
		if (is_sorted(v) == EXIT_FAILURE) {
			return EXIT_FAILURE;
		};
	};
	std::vector<std::string> v_str = {
        "Nel mezzo del cammin di nostra vita / mi ritrovai per una selva oscura, / ché la diritta via era smarrita.",
        "Lasciate ogne speranza, voi ch’intrate.",
        "Amor, ch’a nullo amato amar perdona.",
        "Considerate la vostra semenza: / fatti non foste a viver come bruti, / ma per seguir virtute e canoscenza.",
        "E quindi uscimmo a riveder le stelle.",
        "Per correr miglior acque alza le vele / omai la navicella del mio ingegno.",
        "Ahi serva Italia, di dolore ostello, / nave sanza nocchiere in gran tempesta, / non donna di province, ma bordello!",
        "Libertà va cercando, ch'è sì cara, / come sa chi per lei vita rifiuta.",
        "Tu proverai sì come sa di sale / lo pane altrui, e come è duro calle / lo scendere e 'l salir per l'altrui scale.",
        "L'amor che move il sole e l'altre stelle."
    };
	bubblesort(v_str);
	if (is_sorted(v_str) == EXIT_FAILURE) {
			return EXIT_FAILURE;
		};
	return EXIT_SUCCESS;
};