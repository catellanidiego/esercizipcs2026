#include <iostream>
#include <fstream>
#include <string>
/**Per lo sviluppo di questo codice è stato utilizzato il supporto dell'IA (Gemini) per chiarimenti sulla sintassi */

int main(int argc, const char *argv[])
{
	if (argc < 2) {
		std::cout << "Errore: file non passato";
	}
	else {
		std::ifstream ifs(argv[1]);
		if (ifs.is_open()) {
			for (int r=1; r<= 3; r++){
				std::string citta = "a";
				float t_1 = 0;
				float t_2 = 0;
				float t_3 = 0;
				float t_4 = 0;
				ifs >> citta >> t_1 >> t_2 >> t_3 >> t_4;
				float media = 0;
				media = (t_1 + t_2 + t_3 + t_4)/4;
				std::cout << citta << "  "<< media << "\n";
			}
		}
		else {
			std::cout << "Errore nell'apertura del file";
		}
	}
	return 0;
}