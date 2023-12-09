#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Atom{
	int X, Y;

	Atom(int atomX, int atomY) : X(atomX), Y(atomY) { }

	Atom() : X(0), Y(0) { }
};

class BlackBox{
	public:
		int rows, columns;
		int x = 0;
		int y = 0;
		int atomNumber;
		Atom atoms[8];
		char board[12][12];
		
		bool markedPositions[12][12];
		
		BlackBox(int size) {
			rows = size + OFFSET;
			columns = size + OFFSET;

			getAtomsNumber(size);
			generateAtoms();
			createBoard();
			drawAtoms();
			zaznacz_przypuszczalne_miejsca();
		}
		
		void createBoard();
		void boardDraw();
		void clearConsole();

		void setCursor();

		void generateAtoms();

		void moving();
		void zaznacz_przypuszczalne_miejsca();


		void atomBoard();
		void getAtomsNumber(int size);
		void drawAtoms();
		
		void mainScreen();
		void menuOptions();

		
	private:

		const int OFFSET = 2;

		void moveLeft();
		void moveDown();
		void moveRight();
		void moveUp();

};



void BlackBox::mainScreen(){
	cout << "----------------------------------------------------------------\n";
	cout <<
        "__________.__                 __     __________              \n"
        "\\______   \\  | _____    ____ |  | __ \\______   \\ _______  ___\n"
        " |    |  _/  | \\__  \\ _/ ___\\|  |/ /  |    |  _//  _ \\  \\/  /\n"
        " |    |   \\  |__/ __ \\\\  \\___|    <   |    |   (  <_> >    < \n"
        " |______  /____(____  /\\___  >__|_ \\  |______  /\\____/__/\\_ \\\n"
        "        \\/          \\/     \\/     \\/         \\/            \\/\n";
	cout << "----------------------------------------------------------------\n";

		cout << "Katarzyna Konopko 197862\n" << endl;
		
		//zostalo undo, redo, strzal
		
}
void BlackBox::menuOptions(){
	cout << "----------------------------------------------------------------\n";
		cout << "MENU: " << endl;
		cout << "1. Poruszanie sie (W, S, A, D) / (w, s, a, d)" << endl;
		cout << "2. Rozpocznij etap od nowa (R) / (r)" << endl;
		cout << "3. Wyjscie z gry (Q) / (q)" << endl;
		cout << "4. Zaznacz przypuszczalne polozenie atomu (o)" << endl;
		cout << "5. Zakoncz gre i wyswietl rozwiazanie (k)" << endl;
		cout << "6. Wyswietl rozwiazanie (p)" << endl;
		cout << "7. Pomoc/Help (H)" << endl;
		cout << "----------------------------------------------------------------\n" << endl;
}

void BlackBox::zaznacz_przypuszczalne_miejsca() {
   createBoard();
    board[x][y] = 'o';
    cout << "Zaznaczono przypuszczalne miejsce atomu." << endl;
}


void BlackBox::createBoard(){    //tworzenie planszy do tablicy

	for(int i = 0; i < rows; ++i){
		for(int j = 0; j < columns; ++j){
			if(i == 0 || i == rows - 1 || j == 0 || j == columns - 1){
				board[i][j] = '=';
			}
			else{
				board[i][j] = '.';
			}
		}
	}
}


void BlackBox::boardDraw(){     //rysowanie planszy z tablicy na konsole

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			cout << " " << board[i][j] << " ";
		}
		cout << endl;
	}
}


void BlackBox::setCursor(){     //stawianie kursora w punkcie 0
	createBoard();
	board[x][y] = '@';
}


void BlackBox::getAtomsNumber(int size){  //ilosc atomow dla poszczegolnej planszy
	switch(size){
		case 5:{
			atomNumber = 3;
			break;
		}
		case 8:{
			atomNumber = 5;
			break;
		}
		case 10:{
			atomNumber = 8;
			break;
		}
	}
}


void BlackBox::generateAtoms(){  //tworzenie randomowych wspolrzednych dla atomow
srand(time(NULL));

	for (int i = 0; i < 8; ++i){
			atoms[i].X = rand() % (rows - 2) + 1;
			atoms[i].Y = rand() % (columns - 2) + 1;
	}
}

void BlackBox::drawAtoms(){  //wyswietlanie atomow na tablicy
	createBoard();
	generateAtoms();
	for (int i = 0; i < atomNumber; ++i){
		board[atoms[i].X][atoms[i].Y] = '#';
	}
}


void BlackBox::moveLeft(){  //przypisanie ruchu
	if(y > 0){
		--y;
	}
}
void BlackBox::moveDown(){
	if(x < rows - 1){
		++x;
	}
}
void BlackBox::moveRight(){
	if(y < columns - 1){
		++y;
	}
}
void BlackBox::moveUp(){
	if(x > 0){
		--x;
	}
}



void BlackBox::moving(){  //przypisanie klawiszy do ruchu

char key;
cout << "Ruch: ";
cin >> key;

board[x][y] = '.';

	switch(key){
		case 'w':{
			moveUp();
			break;
		}
		case 's':{
			moveDown();
			break;
		}
		case 'a':{
			moveLeft();
			break;
		}
		case 'd':{
			moveRight();
			break;
		}
		case 'q':{
			exit(0);
			break;
		}
		case 'o':{
			zaznacz_przypuszczalne_miejsca();
			break;
		}
	}
}

void BlackBox::clearConsole(){  //czyszczenie planszy
	system("cls");
}


int main(){
	int boardSize, atomNumber;
	char key;
	
		cout << "Poziomy trudnosci: " << endl;
		cout << "1 - latwy   2 - sredni   3 - trudny" << endl;
		cout << "Wybierz poziom trudnosci: "; cin >> boardSize;
		
 switch(boardSize){
		case 1:{
			boardSize = 5;
			break;
		}
		case 2:{
			boardSize = 8;
			break;
		}
		case 3:{
			boardSize = 10;
			break;
		}
		default:{
			cout << "Nie ma takiego poziomu";
			return 1;
		}
	}

	BlackBox chuj = BlackBox(boardSize);

	while (true){
//		chuj.clearConsole();
		chuj.menuOptions();
		chuj.setCursor();
		chuj.boardDraw();
		chuj.moving();

	}
return 0;
}
		
