// Katarzyna Konopko 197862 EiT BlackBox

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
		

		BlackBox(int size) {
			rows = size + OFFSET;
			columns = size + OFFSET;
			
			getAtomsNumber(size);
			generateAtoms();
			createBoard();
			drawAtoms();
			markingAtoms();
		}
		
		char board[12][12];
//		char previousboard[12][12];
		
		
		
		
		void createBoard();
		void boardDraw();
		void clearConsole();
		
		void setCursor();

		void generateAtoms();
		
		void moving();
		

		void atomBoard();
		void getAtomsNumber(int size);
		void drawAtoms();
		
		
		void markingAtoms();
		void possibleAtoms();
		void clearPossibleAtoms();
		
		
		
		void GameBoard();


	private:
		
		const int OFFSET = 2;

		void moveLeft();
		void moveDown();
		void moveRight();
		void moveUp();
		
		
//		bool compareBoards(char board1[12][12], char board2[12][12]);

};

void BlackBox::createBoard(){
	
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

void BlackBox::boardDraw(){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			cout << " " << board[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "Tablcia aotokmoow: " << endl; // chwilowe wyswietlanie wspolrzednych tych szmat
	for(int i = 0; i < atomNumber; ++i){
		cout << "Atom " << i + 1 << " X= " << atoms[i].X << ", Y= " << atoms[i].Y << endl;
	}
}

void BlackBox::setCursor(){  
	createBoard();
	board[x][y] = '@';
}

void BlackBox::getAtomsNumber(int size){
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

void BlackBox::generateAtoms(){
srand(time(NULL));

	for (int i = 0; i < 8; ++i){
			atoms[i].X = rand() % (rows - 2) + 1;
			atoms[i].Y = rand() % (columns - 2) + 1;
	}
}

void BlackBox::drawAtoms(){
	createBoard();
	generateAtoms();
	for (int i = 0; i < atomNumber; ++i){
		board[atoms[i].X][atoms[i].Y] = '#';
	}
}

void BlackBox::possibleAtoms(){
	int amount = 0;
	for (int i = 1; i < rows - 1; ++i){
		for (int j = 1; j < columns - 1; ++j){
			if (board[i][j] == '.'){
				if(amount < atomNumber){
					board[i][j] = 'o';
					++amount;
				}
				else{
					board[i][j] = '.';
				}
			}
		}
	}
}
void BlackBox::clearPossibleAtoms(){
	for(int i = 0; i < rows - 1; ++i){
		for (int j = 0; j < columns - 1; ++j){
			if (board[i][j] == 'o'){
				board[i][j] = '.';
			}
		}
	}
}
void BlackBox::markingAtoms(){
	if(x > 0 or x < rows - 1 or y > 0 or y < columns - 1){
		if(board[x][y] == 'o'){
			clearPossibleAtoms();
		}
		else{
			board[x][y] = 'o';
		}
	}
}


void BlackBox::moveLeft(){
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
//void BlackBox::markingAtoms(){
//	if (x > 0 and  x < rows - 1 and y > 0 and y < columns - 1){
//		board[x][y] = 'o';
//		
//		
//	}
//}


void BlackBox::moving(){

char key;
cout << "Ruch: ";
cin >> key;


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
			markingAtoms();
			break;
		}
		

		
	}
	
//	if (!compareBoards(previousboard, board)) {
//        clearConsole();
//    }
}

//// Funkcja do porównywania dwóch plansz
//bool BlackBox::compareBoards(char board1[12][12], char board2[12][12]) {
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < columns; ++j) {
//            if (board1[i][j] != board2[i][j]) {
//                return false;
//            }
//        }
//    }
//    return true;
//}


void BlackBox::clearConsole(){
	system("cls");
}

int main(){
	
	int boardSize, atomNumber;
	char key;
	cout << "Rozmiar planszy: "; cin >> boardSize;
	
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
			cout << "nie ma takiego poziomu";
			return 1;
		}
	}
	
	BlackBox chuj = BlackBox(boardSize);
	
	while (true){
//		chuj.clearConsole();
		chuj.setCursor();
		chuj.boardDraw();
		chuj.moving();
		chuj.markingAtoms();
	}
return 0;
}




// 2) stworzyæ zaznaczanie atomów na planszy

// 3) sprawdzanie czy w danym zaznaczeniu znajdowa³ sie atom, 
// jesli tak - O, jesli nie X pod koniec rozgrywki w tych miejscach

// 4) przypuszczalne zmiany zaznaczenia po³o¿enia

// 5) klawisz k - jako koniec rozgrywki -
// wyœwietlanie po³o¿enia atomów i liczbe trafionych.

// 6) z dowolnego etapu gry: opuszczanie jej/ rozpoczynanie nowej gry od dowolnego etapu

// 7) mo¿liwoœæ cofniêcia i ponowienia cofniêtych ruchów

// 8) STRZELANIE


// 1) naprawiæ chowanie sie atomow, (nie wiem czy one dzialaja, czy po prostu juz ich nie pokazuje)
