#include <iostream>
#include <iomanip>

using namespace std;



void Plansza(char plansza[wiersze][kolumny]) {
    
    for (int i = 0; i < wiersze; ++i) {
    	if(int j = 0, j < kolumny, ++j) {
    		if (i == 0 || i == wiersze-1 || j == 0 || j == kolumny-1) {
    			cout << "=";
				} else {
					cout << plansza[i][j] << " - ";
				}
			}
//        cout << setw(2) << setfill('0') << j << " ";
		cout << endl;
    }
   

}



void Menu(int poziom){
	cout << "Podaj poziom trudnosci: " << endl << "1 - latwy" << endl << "2 - sredni" << endl << "3 - trudny" << endl; 
	cout << "Poziom: "; cin >> poziom;
	
	switch (poziom){
		case 1:
			Plansza(5,5);
			break;
		case 2:
			Plansza(8,8);
			break;
		case 3:
			Plansza(10,10);
			break;	
		default:
			cout << "Nie ma takiego poziomu lol";
	}
}

int main() {
	
//	Menu(poziom);
		

return 0;
}


