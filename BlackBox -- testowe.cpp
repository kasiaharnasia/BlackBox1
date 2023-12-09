#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class BlackBox{
	public:
		int x, y;
	
		BlackBox() : lol(69) { }
};



void Plansza(int maxwiersze, int maxkolumny, int atomy){
	char plansza[maxwiersze][maxkolumny] = {};
	for (int i = 0; i < maxwiersze; ++i){
		for (int j = 0; j < maxkolumny; ++j){

			if (i == 0 || i == maxwiersze - 1 || j == 0 || j == maxkolumny - 1) {
				cout << " = ";
			}
			
			if (x == pionowo, y == poziomo){
				cout << "@";
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
		int i = rand() % (maxwiersze - 1);
		int j = rand() % (maxkolumny - 1);

		if(plansza[i][j] != atom){
			plansza[i][j] = atom;
			++liczbaAtomow;
		}
	}

	cout << endl << "Liczba ukrytych atomow: " << atomy << endl;

	// tablica dla losowych atomow:
	for (int i = 0; i < maxwiersze; ++i) {
    for (int j = 0; j < maxkolumny; ++j) {
      if (i == 0 || i == maxwiersze - 1 || j == 0 || j == maxkolumny - 1) {
        cout << " = ";
      } else {
        cout << " " << (plansza[i][j] == atom ? "#" : ".") << " ";
      }
    }
    cout << endl;
  }

}


void Poruszanie(int maxwiersze, int maxkolumny, int &pionowo, int &poziomo){
	char klawisze = getchar();
	
	int poprzednie_pionowo = pionowo;
	int poprzednie_poziomo = poziomo;
	
	if (klawisze == 'w' && pionowo > 0){
		--pionowo;
	} else if (klawisze == 'a' && poziomo > 0){
		--poziomo;
	} else if (klawisze == 's' && pionowo < maxwiersze - 1){
		++pionowo;
	} else if (klawisze == 'd' && poziomo < maxkolumny - 1){
		++poziomo;
	} else if (klawisze == 'q' || klawisze == 'Q'){
		exit(0);
	}
	
	char poprzednia_plansza[poprzednie_pionowo][poprzednie_poziomo] = {"."};
	char plansza[pionowo][poziomo] = {'O'};
	
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
	int maxwiersze, maxkolumny;
	int pionowo = 1;
	int poziomo = 1;
	
	switch(wybor){
		case 1:{
			maxwiersze = 7;
			maxkolumny = 7;
			Plansza(maxwiersze, maxkolumny, 3);
			break;
		} 
		case 2:{
			maxwiersze = 10;
			maxkolumny = 10;
			Plansza(maxwiersze, maxkolumny, 5);
			break;
		} 
		case 3:{
			maxwiersze = 12;
			maxkolumny = 12;
			Plansza(maxwiersze, maxkolumny, 8);
			break;
		} 
		default:{
			cout << "Wybrano zly poziom";
			break;
		} 
	}
	
	while(true){
		Poruszanie(maxwiersze, maxkolumny, pionowo, poziomo);
	}
	
}



int main(){
//	BlackBox blackbox;
//	cout << blackbox.lol;
//	blackbox.xd()
	
	
	int poziom, maxwiersze, maxkolumny;
	Menu();
	
	cin >> poziom; cout << endl;
	
	int poziomo = 1;
	int pionowo = 1;
	
	Poziomy(poziom);

return 0;
}
