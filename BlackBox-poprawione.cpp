#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void Plansza(int wiersze, int kolumny, int atomy){
	char plansza[wiersze][kolumny];
	for (int i = 0; i < wiersze; ++i){
		for (int j = 0; j < kolumny; ++j){

			if (i == 0 || i == wiersze - 1 || j == 0 || j == kolumny - 1) {
				cout << " = ";
			}
			else {
				cout << " . ";
			}

		}
		cout << endl;
	}

	char atom = '#';
	srand(time(0));



	int liczbaAtomow = 0;
	while(liczbaAtomow < atomy){
		int i = rand() % (wiersze - 2) + 1;
		int j = rand() % (kolumny - 2) + 1;

		if(plansza[i][j] != atom){
			plansza[i][j] = atom;
			++liczbaAtomow;
		}
	}

	cout << endl << "Liczba ukrytych atomow: " << atomy << endl;

	// tablica dla losowych atomow:
	for (int i = 0; i < wiersze; ++i) {
    for (int j = 0; j < kolumny; ++j) {
      if (i == 0 || i == wiersze - 1 || j == 0 || j == kolumny - 1) {
        cout << " = ";
      } else {
        cout << " " << (plansza[i][j] == atom ? "#" : ".") << " ";
      }
    }
    cout << endl;
  }
	

}

void Poruszanie(int pionowo, int poziomo){
	
}


void Menu(){

cout << "----------------------------------------------------------------\n";
std::cout <<
        "__________.__                 __     __________              \n"
        "\\______   \\  | _____    ____ |  | __ \\______   \\ _______  ___\n"
        " |    |  _/  | \\__  \\ _/ ___\\|  |/ /  |    |  _//  _ \\  \\/  /\n"
        " |    |   \\  |__/ __ \\\\  \\___|    <   |    |   (  <_> >    < \n"
        " |______  /____(____  /\\___  >__|_ \\  |______  /\\____/__/\\_ \\\n"
        "        \\/          \\/     \\/     \\/         \\/            \\/\n";
cout << "----------------------------------------------------------------\n";

		cout << "Katarzyna Konopko 197862\n" << endl;
		cout << "Poziomy trudnosci: " << endl;
		cout << "1 - latwy   2 - sredni   3 - trudny" << endl;
		cout << "Wybierz poziom trudnosci: ";
}

void Poziomy(int wybor){
	switch(wybor){
		case 1:{
			Plansza(7,7,3);
			break;
		} 
		case 2:{
			Plansza(10,10,5);
			break;
		} 
		case 3:{
			Plansza(12,12,8);
			break;
		} 
		default:{
			cout << "Wybrano zly poziom";
			break;
		} 
	}
}

int main(){
	int poziom;
	Menu();
	
	cin >> poziom; cout << endl;
	
	Poziomy(poziom);

return 0;
}
