#include<iostream>// FOR BASIC INPUT OUTPUT
#include<cstring>// FOR CHARACTER ARRAY
#include<cstdlib>// FOR CLEAR THE SCREEN
#include<windows.h>//FOR SOUND
using namespace std;
class pieces {// BASE CLASS
protected:
	static char board[8][8];
public:
	static int X;//SCORE OF WHITE
	static int Y;//SCORE OF BLACK
	pieces() {// DEFAULT CONSTRUCTOR
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if ((i == 0 && j == 1) || (i == 0 && j == 6)) {
					board[i][j] = 'N';
				}
				else if ((i == 7 && j == 1) || (i == 7 && j == 6)) {
					board[i][j] = 'n';
				}
				else if ((i == 0 && j == 2) || (i == 0 && j == 5)) {
					board[i][j] = 'B';
				}
				else if ((i == 7 && j == 2) || (i == 7 && j == 5)) {
					board[i][j] = 'b';
				}
				else if ((i == 0 && j == 3)) {
					board[i][j] = 'Q';
				}
				else if ((i == 7 && j == 3)) {
					board[i][j] = 'q';
				}
				else if ((i == 0 && j == 0) || (i == 0 && j == 7)) {
					board[i][j] = 'R';
				}
				else if ((i == 7 && j == 0) || (i == 7 && j == 7)) {
					board[i][j] = 'r';
				}
				else if (i == 1) {
					board[i][j] = 'P';
				}
				else if (i == 6) {
					board[i][j] = 'p';
				}
				else if ((i == 0 && j == 4)) {
					board[i][j] = 'K';
				}
				else if ((i == 7 && j == 4)) {
					board[i][j] = 'k';
				}
				else {
					board[i][j] = '.';
				}
			}
		}
	}
	void soundi() {// FUNCTION OF SOUND FOR INVALID MOVE
		system("cls");
		cout << endl;
		Beep(900, 370);
		cout << "\033[31mInvalid move\033[0m" << endl;
		cout << endl;
		display();
		cout << endl;
		return;
	}
	void soundpp() {// FUNCTION OF SOUND FOR PAWN THAT NOT KILL OPPONENT PIECES IN VERTICAL DIRECTION
		system("cls");
		cout << endl;
		Beep(480, 220);
		cout << "\033[31mCannot kill opponent piece in vertical direction\033[0m" << endl;
		cout << endl;
		display();
		cout << endl;
		return;
	}
	void soundp() {// FUNCTION OF SOUND FOR ALREADY OCCUPY PLACE
		system("cls");
		cout << endl;
		Beep(480, 200);
		cout << "\033[31mAlready occupied by your own piece\033[0m" << endl;
		cout << endl;
		display();
		cout << endl;
		return;
	}
	void soundk() {// FUNCTION OF SOUND FOR NOT KILL KING
		system("cls");
		cout << endl;
		Beep(320, 180);
		cout << "\033[31mCannot kill another king\033[0m" << endl;
		cout << endl;
		display();
		cout << endl;
		return;
	}
	void soundc() {// FUNCTION OF SOUND FOR INVALID CHOICE
		system("cls");
		cout << endl;
		Beep(380, 280);
		cout << "\033[31mWrong choice\033[0m" << endl;
		cout << endl;
		display();
		cout << endl;
		return;
	}
	void soundii() {// FUNCTION OF SOUND FOR MOVE ITSELF
		system("cls");
		cout << endl;
		Beep(450, 300);
		cout << "\033[31mInvalid move (itself)\033[0m" << endl;
		cout << endl;
		display();
		cout << endl;
		return;
	}
	void soundio() {// FUNCTION OF SOUND FOR MOVE OUT OF BOUND
		system("cls");
		cout << endl;
		Beep(520, 230);
		cout << "\033[31mInvalid move (out of bound)\033[0m" << endl;
		cout << endl;
		display();
		cout << endl;
		return;
	}
	void soundav(char AV) {// FUNCTION OF SOUND FOR NO AVAILABILITY OF A PIECE
		system("cls");
		cout << endl;
		Beep(440, 160);
		cout << "\033[31mYou have no any piece of \033[0m"<<AV << endl;
		cout << endl;
		display();
		cout << endl;
		return;
	}
	void sounda() {// FUNCTION OF SOUND FOR INVALID SOURCE LOCATION OF PIECE
		system("cls");
		cout << endl;
		Beep(460, 240);
		cout << "\033[31mThe piece is not available at your desired position \033[0m" << endl;
		cout << endl;
		display();
		cout << endl;
		return;
	}
	void display() {// FUNCTION FOR DISPLAY GAME
		cout << "   ";
		for (char c = 'a'; c <= 'h'; c++) {// TO PRINT AT TOP LINE
			cout << c << "  ";
		}
		cout << endl;
		for (int i = 0; i < 8; i++) {
			cout << i + 1 << " ";  // TO PRINT AT LEFT SIDE
			for (int j = 0; j < 8; j++) {
				bool isLightSquare = (i + j) % 2 == 0;
				if (isLightSquare) {// FOR WHITE BACKGROUND
					cout << "\033[47m";  
				}
				else {
					cout << "\033[40m";  // FOR BLACK BACKGROUND
				}
				char piece = board[i][j];
				if (piece >= 'A' && piece <= 'Z') {// TO PRINT CAPITAL PIECES IN RED
					cout << "\033[31m " << piece << " \033[0m";
				}
				else if (piece >= 'a' && piece <= 'z') {// TO PRINT LOWER PIECES IN GREEN
					cout << "\033[32m " << piece << " \033[0m";
				}
				else {// FOR BLANK BOXES
					if (isLightSquare) {
						cout << "\033[30m   \033[0m";
					}
					else {
						cout << "\033[97m   \033[0m";
					}
				}
			}
			cout << "\033[0m";  
			cout << " " << i + 1;  // FOR PRINT NUMBERS RIGHT
			cout << endl;
		}
		cout << "   ";
		for (char c = 'a'; c <= 'h'; c++) {// FOR PRINT AT BOTTOM LINE
			cout << c << "  ";
		}
		cout << endl;
		return;
	}
	static void getBoardCopy(char dest[8][8]) {// FUNCTION FOR COPYING CURRENT BOARD INTO DESTINATION
		for (int i = 0; i < 8; ++i)
			for (int j = 0; j < 8; ++j)
				dest[i][j] = board[i][j];
	}
	static void setBoardFrom(const char src[8][8]) {// FUNCTION FOR SETTING BOARD FROM SOURCE
		for (int i = 0; i < 8; ++i)
			for (int j = 0; j < 8; ++j)
				board[i][j] = src[i][j];
	}
	static bool equalBoard(const char other[8][8]) {// FUNCTION FOR CHECKING IF TWO BOARDS ARE EQUAL
		for (int i = 0; i < 8; ++i)
			for (int j = 0; j < 8; ++j)
				if (board[i][j] != other[i][j]) {
					return false;
				}
		return true;
	}
	void findKing(int& kingRow, int& kingCol, char kingChar) {// FUNCTION FOR FINDING POSITION OF SPECIFIC KING
		kingRow = -1; kingCol = -1;
		for (int i = 0; i < 8; ++i)
			for (int j = 0; j < 8; ++j) {
				if (board[i][j] == kingChar) {
					kingRow = i;
					kingCol = j;
					return;
				}
			}
	}
	bool isUnderAttack(int row, int col, bool checkingForPlayer1) {// FUNCTION FOR CHECKING IF GIVEN POSITION IS UNDER ATTACK
		if (checkingForPlayer1) {//FOR PAWN
			if (row + 1 < 8) {
				if (col - 1 >= 0 && board[row + 1][col - 1] == 'p') {
					return true;
				}
				if (col + 1 < 8 && board[row + 1][col + 1] == 'p') {
					return true;
				}
			}
		}
		else {
			if (row - 1 >= 0) {
				if (col - 1 >= 0 && board[row - 1][col - 1] == 'P') {
					return true;
				}
				if (col + 1 < 8 && board[row - 1][col + 1] == 'P') {
					return true;
				}
			}
		}
		int kx[8] = { 1,1,-1,-1,2,2,-2,-2 };//FOR KNIGHT
		int ky[8] = { 2,-2,2,-2,1,-1,1,-1 };
		char enemyKnight = checkingForPlayer1 ? 'n' : 'N';
		for (int i = 0; i < 8; ++i) {
			int nx = row + kx[i], ny = col + ky[i];
			if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && board[nx][ny] == enemyKnight) {
				return true;
			}
		}
		char enemyKing = checkingForPlayer1 ? 'k' : 'K';//FOR KING
		for (int i = -1; i <= 1; ++i) {
			for (int j = -1; j <= 1; ++j) {
				if (i == 0 && j == 0) {
					continue;
				}
				int nx = row + i, ny = col + j;
				if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && board[nx][ny] == enemyKing) {
					return true;
				}
			}
		}
		char enemyR = checkingForPlayer1 ? 'r' : 'R';//FOR ROOK
		char enemyQ = checkingForPlayer1 ? 'q' : 'Q';//FOR QUEEN
		int straight[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
		for (int d = 0; d < 4; ++d) {
			int nx = row + straight[d][0], ny = col + straight[d][1];
			while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
				if (board[nx][ny] != '.') {
					if (board[nx][ny] == enemyR || board[nx][ny] == enemyQ) {
						return true;
					}
					break;
				}
				nx += straight[d][0]; ny += straight[d][1];
			}
		}
		char enemyB = checkingForPlayer1 ? 'b' : 'B';//FOR BISHOPS
		int diag[4][2] = { {1,1},{1,-1},{-1,1},{-1,-1} };
		for (int d = 0; d < 4; ++d) {
			int nx = row + diag[d][0], ny = col + diag[d][1];
			while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
				if (board[nx][ny] != '.') {
					if (board[nx][ny] == enemyB || board[nx][ny] == enemyQ) {
						return true;
					}
					break;
				}
				nx += diag[d][0]; ny += diag[d][1];
			}
		}
		return false;
	}
	bool isInCheck(int player) {// FUNCTION FOR CHECKING IF PLAYER'S KING IS IN CHECK
		int kr, kc;
		char kingChar = (player == 1) ? 'K' : 'k';
		bool checkingForPlayer1 = (player == 1);
		findKing(kr, kc, kingChar); // FIND KING POSITION
		if (kr == -1) {// IF KING NOT FOUND, CONSIDER CHECKED
			return true;
		}
		return isUnderAttack(kr, kc, checkingForPlayer1);// CHECK IF KING POSITION IS UNDER ATTACK
	}
	bool isPathClear(int fr, int fc, int tr, int tc) {// FUNCTION FOR CHECKING IF PATH BETWEEN TWO POSITIONS IS CLEAR
		int dr = tr - fr;
		int dc = tc - fc;
		int stepR = (dr == 0) ? 0 : (dr > 0 ? 1 : -1);
		int stepC = (dc == 0) ? 0 : (dc > 0 ? 1 : -1);
		if (stepR != 0 && stepC != 0 && abs(dr) != abs(dc)) {// INVALID MOVE FOR STRAIGHT OR DIAGONAL
			return false;
		}
		if (stepR == 0 && stepC == 0) {// SAME CELL
			return false;
		}
		int r = fr + stepR, c = fc + stepC;
		while (r != tr || c != tc) {
			if (board[r][c] != '.') {// PATH BLOCKED
				return false;
			}
			r += stepR; c += stepC;
		}
		return true;// PATH CLEAR
	}
	bool canMoveBasic(int fr, int fc, int tr, int tc) {// FUNCTION FOR CHECKING IF BASIC MOVE IS LEGAL FOR A PIECE
		if (fr == tr && fc == tc) {// SAME CELL
			return false;
		}
		if (fr < 0 || fr >= 8 || fc < 0 || fc >= 8) {// FROM OUT OF BOUNDS
			return false;
		}
		if (tr < 0 || tr >= 8 || tc < 0 || tc >= 8) {// TO OUT OF BOUNDS
			return false;
		}
		char piece = board[fr][fc];
		if (piece == '.') {// NO PIECE TO MOVE
			return false;
		}
		bool isWhite = isupper(piece);
		char target = board[tr][tc];
		if (target != '.') {
			if (isWhite && isupper(target)) { // CAN'T CAPTURE OWN PIECE
				return false;
			}
			if (!isWhite && islower(target)) {
				return false;
			}
		}
		char p = tolower(piece);
		int dr = tr - fr;
		int dc = tc - fc;
		int adr = abs(dr), adc = abs(dc);
		if (p == 'n') {// KNIGHT MOVE
			if ((adr == 1 && adc == 2) || (adr == 2 && adc == 1)) {
				return true;
			}
			return false;
		}
		else if (p == 'k') { // KING MOVE
			if (adr <= 1 && adc <= 1) {
				return true;
			}
			return false;
		}
		else if (p == 'r') {// ROOK MOVE
			if (dr == 0 || dc == 0) {
				return isPathClear(fr, fc, tr, tc);
			}
			return false;
		}
		else if (p == 'b') {// BISHOP MOVE
			if (adr == adc) {
				return isPathClear(fr, fc, tr, tc);
			}
			return false;
		}
		else if (p == 'q') {// QUEEN MOVE
			if (dr == 0 || dc == 0 || adr == adc) {
				return isPathClear(fr, fc, tr, tc);
			}
			return false;
		}
		else if (p == 'p') {// PAWN MOVE
			if (isWhite) {
				if (fc == tc) {
					if (dr == 1 && board[tr][tc] == '.') {
						return true;
					}
					if (fr == 1 && dr == 2 && board[fr + 1][fc] == '.' && board[tr][tc] == '.') {
						return true;
					}
					return false;
				}
				if (adr == 1 && adc == 1 && islower(board[tr][tc])) {
					return true;
				}
				return false;
			}
			else {
				if (fc == tc) {
					if (dr == -1 && board[tr][tc] == '.') {
						return true;
					}
					if (fr == 6 && dr == -2 && board[fr - 1][fc] == '.' && board[tr][tc] == '.') {
						return true;
					}
					return false;
				}
				if (adr == 1 && adc == 1 && isupper(board[tr][tc])) {
					return true;
				}
				return false;
			}
		}
		return false;
	}
	bool isMoveLegal(int player, int fr, int fc, int tr, int tc) {// FUNCTION FOR CHECKING IF A MOVE IS LEGAL
		if (!canMoveBasic(fr, fc, tr, tc)) { // INVALID BASIC MOVE
			return false;
		}
		char savedFrom = board[fr][fc];// SAVE ORIGINAL PIECE
		char savedTo = board[tr][tc];// SAVE TARGET CELL
		board[tr][tc] = savedFrom;// MAKE THE MOVE TEMPORARILY
		board[fr][fc] = '.';
		bool stillInCheck = isInCheck(player);// CHECK IF PLAYER STILL IN CHECK AFTER MOVE
		board[fr][fc] = savedFrom;// RESTORE BOARD
		board[tr][tc] = savedTo;
		return !stillInCheck;// MOVE LEGAL IF KING NOT IN CHECK
	}
	bool isCheckmate(int player) {// FUNCTION FOR CHECKING IF PLAYER IS IN CHECKMATE
		int kingRow = -1, kingCol = -1;
		char kingChar = (player == 1) ? 'K' : 'k';
		bool checkingForPlayer1 = (player == 1);
		findKing(kingRow, kingCol, kingChar);// FIND KING POSITION
		if (kingRow == -1) {// KING MISSING, CONSIDER CHECKMATE
			return true;
		}
		if (!isUnderAttack(kingRow, kingCol, checkingForPlayer1)) {// NOT ATTACKED, NOT CHECKMATE
			return false;
		}
		for (int fr = 0; fr < 8; ++fr) { // TRY ALL POSSIBLE MOVES TO SEE IF KING CAN ESCAPE
			for (int fc = 0; fc < 8; ++fc) {
				char piece = board[fr][fc];
				if (piece == '.') {
					continue;
				}
				bool isWhitePiece = isupper(piece);
				if ((player == 1 && !isWhitePiece) || (player == 2 && isWhitePiece)) {
					continue;
				}
				for (int tr = 0; tr < 8; ++tr) {
					for (int tc = 0; tc < 8; ++tc) {
						if (!canMoveBasic(fr, fc, tr, tc)) {
							continue;
						}
						char savedFrom = board[fr][fc];
						char savedTo = board[tr][tc];
						board[tr][tc] = savedFrom;// MAKE TEMPORARY MOVE
						board[fr][fc] = '.';
						int newKingR = kingRow, newKingC = kingCol;
						if (savedFrom == 'K' || savedFrom == 'k') {// UPDATE KING POSITION IF KING MOVED
							newKingR = tr; newKingC = tc;
						}
						else {
							int ktmp_r = -1, ktmp_c = -1;
							findKing(ktmp_r, ktmp_c, kingChar);
							if (ktmp_r != -1) {
								newKingR = ktmp_r;
								newKingC = ktmp_c;
							}
						}
						bool stillChecked = isUnderAttack(newKingR, newKingC, checkingForPlayer1);
						board[fr][fc] = savedFrom;// RESTORE BOARD
						board[tr][tc] = savedTo;
						if (!stillChecked) {// FOUND ESCAPE, NOT CHECKMATE
							return false;
						}
					}
				}
			}
		}
		return true; // NO ESCAPE, PLAYER IS IN CHECKMATE
	}
	void sounds(int a, int b, int c, int d, int e) {//FUNCTION OF SOUND FOR SUCCESSFULL MOVE
		board[a][b] = '.';
		board[c][d] = e;
		system("cls");
		cout << endl;
		Beep(850, 120);
		cout << "\033[32mSuccessfully moved\033[0m" << endl;
		cout << endl;
		return;
	}
	void successfully(int a, int b, int c, int d, char e) {// TO UPDATE BOARD AND GET SCORE FOR RED (WHITE)
		if ((board[c][d] == 'n') || (board[c][d] == 'b')) {// FOR BISHOPS AND KNIGHT
			X += 3;// INCREASE SCORE ACCORDING TO CAPTURED PIECE
			sounds(a, b, c, d, e);
			return;
		}
		if ((board[c][d] == 'p')) {// FOR PAWN
			X += 1;
			sounds(a, b, c, d, e);
			return;
		}
		if ((board[c][d] == 'q')) {// FOR QUEEN
			X += 9;
			sounds(a, b, c, d, e);
			return;
		}
		if ((board[c][d] == 'r')) {// FOR ROOK
			X += 5;
			sounds(a, b, c, d, e);
			return;
		}
		sounds(a, b, c, d, e);// FOR NOTHING CAPTURED PIECE
		return;
	}
	void success(int a, int b, int c, int d, char e) {// TO UPDATE BOARD AND GET SCORE FOR GREEN (BLACK)
		if ((board[c][d] == 'N') || (board[c][d] == 'B')) {// FOR BISHOPS AND KNIGHT
			Y += 3;// INCREASE SCORE ACCORDING TO CAPTURED PIECE
			sounds(a, b, c, d, e);
			return;
		}
		if ((board[c][d] == 'P')) {// FOR PAWN
			Y += 1;
			sounds(a, b, c, d, e);
			return;
		}
		if ((board[c][d] == 'Q')) {// FOR QUEEN
			Y += 9;
			sounds(a, b, c, d, e);
			return;
		}
		if ((board[c][d] == 'R')) {// FOR ROOK
			Y += 5;
			sounds(a, b, c, d, e);
			return;
		}
		sounds(a, b, c, d, e);// FOR NOTHING CAPTURED PIECE
		return;
	}
	void promotion(int c, int d,int a) {// FOR PROMOTION OF PAWN
		if (((c + 1) == a)) {// IF A==1 THEN IT IS PROMOTION OF GREEN AND IF A==8 THEN IT IS PROMOTION OF RED
			int g;
			bool convert = false;
			cout << "\033[32mCongratulation! now your this pawn get a power to convert it into another type of piece\033[0m" << endl;
			do {
				cout << "\033[34mYou convert it into:\033[0m" << endl;
				cout << "\033[33m1. Queen" << endl;
				cout << "2. Knight" << endl;
				cout << "3. Rook" << endl;
				cout << "4. Bishop\033[0m" << endl;
				cout << "\033[34mEnter your choice:\033[0m" << endl;
				cin >> g;
				switch (g) {
				case 1: {
					if (g == 1 && a == 8) {
						board[c][d] = 'Q';
						Beep(700,330);
						cout << "\033[32mYour pawn is successfully converted into Queen\033[0m" << endl;
						convert = true;
						return;
					}
					else if (g == 1 && a == 1) {
						board[c][d] = 'q';
						Beep(700, 330);
						cout << "\033[32mYour pawn is successfully converted into Queen\033[0m" << endl;
						convert = true;
						return;
					}
					break;
				}
				case 2: {
					if (g == 2 && a == 8) {
						board[c][d] = 'N';
						Beep(700, 330);
						cout << "\033[32mYour pawn is successfully converted into Knight\033[0m" << endl;
						convert = true;
						return;
					}
					else if (g == 2 && a == 1) {
						board[c][d] = 'n';
						Beep(700, 330);
						cout << "\033[32mYour pawn is successfully converted into Knight\033[0m" << endl;
						convert = true;
						return;
					}
					break;
				}
				case 3: {
					if (g == 3 && a == 8) {
						board[c][d] = 'R';
						Beep(700, 330);
						cout << "\033[32mYour pawn is successfully converted into Rook\033[0m" << endl;
						convert = true;
						return;
					}
					else if (g == 3 && a == 1) {
						board[c][d] = 'r';
						Beep(700, 330);
						cout << "\033[32mYour pawn is successfully converted into Rook\033[0m" << endl;
						convert = true;
						return;
					}
					break;
				}
				case 4: {
					if (g == 4 && a == 8) {
						board[c][d] = 'B';
						Beep(700, 330);
						cout << "\033[32mYour pawn is successfully converted into Bishop\033[0m" << endl;
						convert = true;
						return;
					}
					else if (g == 4 && a == 1) {
						board[c][d] = 'r';
						Beep(700, 330);
						cout << "\033[32mYour pawn is successfully converted into Bishop\033[0m" << endl;
						convert = true;
						return;
					}
				}
				default: {
					    convert = false;
						Beep(630, 280);
						cout << "\033[31mInvalid choice\033[0m" << endl;
						cout << "\033[34mTry again\033[0m" << endl;
						return;
					}
				}
			} while (convert==false);
		}
		return;
	}
	bool pathR(int a, int b, int c, int d) {// FUNCTION FOR PATH CHECK VERTICALLY
		int w = 0;
		int x = 0;
		int y = 0;
		int z = 0;
		if (d > b) {
			w = 1;
			y = a + x;
			z = b + w;
			while (y != c || z != d) {
				if (board[y][z] != '.') {
					system("cls");
					cout << endl;
					Beep(600, 450);
					cout << "\033[31mPath blocked \033[0m" << endl;
					cout << endl;
					display();
					return false;
				}
				y += x;
				z += w;
			}
		}
		else if (d < b) {
			x = 1;
			y = a + w;
			z = b - x;
			while (y != c || z != d) {
				if (board[y][z] != '.') {
					system("cls");
					cout << endl;
					Beep(600, 450);
					cout << "\033[31mPath blocked\033[0m" << endl;
					cout << endl;
					display();
					return false;
				}
				y += w;
				z -= x;
			}
		}
		return true;
	}
	bool pathr(int a, int b, int c, int d) {// FUNCTION FOR PATH CHECK HORIZONTALLY
		int w = 0;
		int x = 0;
		int y = 0;
		int z = 0;
		if (c > a) {
			w = 1;
			y = a + w;
			z = b + x;
			while (y != c || z != d) {
				if (board[y][z] != '.') {
					system("cls");
					cout << endl;
					Beep(600, 450);
					cout << "\033[31mPath blocked\033[0m" << endl;
					cout << endl;
					display();
					return false;
				}
				y += w;
				z += x;
			}
		}
		else if (c < a) {
			x = 1;
			y = a - x;
			z = b + w;
			while (y != c || z != d) {
				if (board[y][z] != '.') {
					system("cls");
					cout << endl;
					Beep(600, 450);
					cout << "\033[31mPath blocked\033[0m" << endl;
					cout << endl;
					display();
					return false;
				}
				y -= x;
				z += w;
			}
		}
		return true;
	}
	bool pathb1(int a, int b, int c, int d) {// FUNCTION FOR CHECK PATH DOWN RIGHT
		int w = 1;
		int y = 0;
		int z = 0;
		y = a + w;
		z = b + w;
		while (y != c || z != d) {
			if (board[y][z] != '.') {
				system("cls");
				cout << endl;
				Beep(600, 450);
				cout << "\033[31mPath blocked\033[0m" << endl;
				cout << endl;
				display();
				return false;
			}
			y += w;
			z += w;
		}
		return true;
	}
	bool pathb2(int a, int b, int c, int d) {// FUNCTION FOR CHECK PATH DOWN LEFT
		int w = 1;
		int y = 0;
		int z = 0;
		y = a + w;
		z = b - w;
		while (y != c || z != d) {
			if (board[y][z] != '.') {
				system("cls");
				cout << endl;
				Beep(600, 450);
				cout << "\033[31mPath blocked \033[0m" << endl;
				cout << endl;
				display();
				return false;
			}
			y += w;
			z -= w;
		}
		return true;
	}
	bool pathb3(int a, int b, int c, int d) {// FUNCTION FOR CHECK PATH UP RIGHT
		int w = 1;
		int y = 0;
		int z = 0;
		y = a - w;
		z = b + w;
		while (y != c || z != d) {
			if (board[y][z] != '.') {
				system("cls");
				cout << endl;
				Beep(600, 450);
				cout << "\033[31mPath blocked \033[0m" << endl;
				cout << endl;
				display();
				return false;
			}
			y -= w;
			z += w;
		}
		return true;
	}
	bool pathb4(int a, int b, int c, int d) {// FUNCTION FOR CHECK PATH UP LEFT
		int w = 1;
		int y = 0;
		int z = 0;
		y = a - w;
		z = b - w;
		while (y != c || z != d) {
			if (board[y][z] != '.') {
				system("cls");
				cout << endl;
				Beep(600, 450);
				cout << "\033[31mPath blocked\033[0m" << endl;
				cout << endl;
				display();
				return false;
			}
			y -= w;
			z -= w;
		}
		return true;
	}
	virtual void input() {// VIRTUAL FUNCTION FOR RED PIECES THAT HAVE DIFFERENT DEFINITIONS ACCORDING TO THEIR DERIVED CLASSES LOGIC

	}
	virtual void Input() {// VIRTUAL FUNCTION FOR GREEN PIECES THAT HAVE DIFFERENT DEFINITIONS ACCORDING TO THEIR DERIVED CLASSES LOGIC

	}
};
char pieces::board[8][8];// INITIALIZE OF STATIC MEMBERS
int pieces::X;
int pieces::Y;
class board {
	pieces b1;
public:
	board() {
		pieces();
	}
};
class bishops :public pieces {// CLASS FOR ALL FUNCTIONALITY OF BISHOPS
public:
	void input() {// INPUT FUNCTION FOR WHITE BISHOPS
		int av = 0;
		int a, b;
		char e;
		int c, d;
		char f;
		cout << "\033[34mWhich move do you want to move:\033[0m" << endl;
		for (int i = 0; i < 8; i++) {// FOR SHOWING LOCATION OF BISHOPS
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'B') {
					e = 'a' + j;
					cout << "\033[35mB at point \033[0m" << e << " " << i + 1 << endl;
					av += 1;
				}
			}
		}
		if (av == 0) {// FOR CHEKING THE AVAILABLE BISHOPS
			soundav('B');
			return;
		}
		cout << "\033[34mEnter your choice like a 1\033[0m" << endl;// FOR SELECT BISHOPS TO MOVE
		cin >> e;
		cin >> b;
		a = b - 1;
		b = e - 'a';
		if ((a >= 0 && a <= 7) && (b >= 0 && b <= 7)) {// TO CHECK VALIDNESS OF SELECTED BISHOPS
			if (board[a][b] == 'B') {
				cout << "\033[32mThe piece is available at your desired position \033[0m" << endl;
			}
			else {
				sounda();
				return;
			}
		}
		else {
			soundc();
			return;
		}
		cout << "\033[34mAt what point do you want to moved it :\033[0m" << endl;//FOR DESTINATION 
		cout << "\033[34mEnter your choice like b 3\033[0m" << endl;
		cin >> f;
		cin >> d;
		c = d - 1;
		d = f - 'a';
		if ((c >= 0 && c <= 7) && (d >= 0 && d <= 7)) {// FOR CHECKING OUT OF BOUND CONDITION
			if (a == c && b == d) {// FOR CHECKING ITSELF CONDITION
				soundii();
				return;
			}
			else {
				if (c > a) {// FOR LOWER SIDE MOVEMENT
					if (d > b) {// FOR RIGHT SIDE MOVEMENT
						if ((c - a) == (d - b)) {// FOR DIAGONAL MOVEMENT
							if (pathb1(a, b, c, d)==false) {// FOR CLEAR PATH
								return;
							}
							if ((board[c][d] != 'N') && (board[c][d] != 'Q') && (board[c][d] != 'R') && (board[c][d] != 'B') && (board[c][d] != 'P') && (board[c][d] != 'K')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
								if (board[c][d] != 'k') {// FOR NOT KILL OPPONENT KING
									successfully(a, b, c, d, 'B');
									return;
								}
								else {
									soundk();
									return;
								}
							}
							else {
								soundp();
								return;
							}
						}
						else {
							soundi();
							return;
						}
					}
					else {// FOR LEFT SIDE MOVEMENT
						if ((a + b) - c == d) {// FOR DIAGONAL MOVEMENT
							if (pathb2(a, b, c, d)==false) {// FOR CLEAR PATH
								return;
							}
							if ((board[c][d] != 'N') && (board[c][d] != 'Q') && (board[c][d] != 'R') && (board[c][d] != 'B') && (board[c][d] != 'P') && (board[c][d] != 'K')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
								if (board[c][d] != 'k') {// FOR NOT KILL OPPONENT KING
									successfully(a, b, c, d, 'B');
									return;
								}
								else {
									soundk();
									return;
								}
							}
							else {
								soundp();
								return;
							}
						}
						else {
							soundi();
							return;
						}
					}
				}
				else {// FOR UPPER SIDE MOVEMENT
					if (d > b) {// FOR RIGHT SIDE MOVEMENT
						if ((a + b) - c == d) {// FOR DIAGONAL MOVEMENT
							if (pathb3(a, b, c, d)==false) {// FOR CLEAR PATH
								return;
							}
							if ((board[c][d] != 'N') && (board[c][d] != 'Q') && (board[c][d] != 'R') && (board[c][d] != 'B') && (board[c][d] != 'P') && (board[c][d] != 'K')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
								if (board[c][d] != 'k') {// FOR NOT KILL OPPONENT KING
									successfully(a, b, c, d, 'B');
									return;
								}
								else {
									soundk();
									return;
								}
							}
							else {
								soundp();
								return;
							}
						}
						else {
							soundi();
							return;
						}
					}
					else {// FOR LEFT SIDE MOVEMENT
						if ((c - a) == (d - b)) {// FOR DIAGONAL MOVEMENT
							if (pathb4(a, b, c, d) == false) {// FOR CLEAR PATH
								return;
							}
							if ((board[c][d] != 'N') && (board[c][d] != 'Q') && (board[c][d] != 'R') && (board[c][d] != 'B') && (board[c][d] != 'P') && (board[c][d] != 'K')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
								if (board[c][d] != 'k') {// FOR NOT KILL OPPONENT KING
									successfully(a, b, c, d, 'B');
									return;
								}
								else {
									soundk();
									return;
								}
							}
							else {
								soundp();
								return;
							}
						}
						else {
							soundi();
							return;
						}
					}
				}
			}
		}
		else {
			soundio();
			return;
		}
	}
	void Input() {// INPUT FUNCTION FOR BLACK BISHOPS
		int av = 0;
		int a, b;
		char e;
		int c, d;
		char f;
		cout << "\033[34mWhich move do you want to move:\033[0m" << endl;
		for (int i = 0; i < 8; i++) {// FOR SHOWING LOCATION OF BISHOPS
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'b') {
					e = 'a' + j;
					cout << "\033[35mb at point \033[0m" << e << " " << i + 1 << endl;
					av += 1;
				}
			}
		}
		if (av == 0) {// FOR CHEKING THE AVAILABLE BISHOPS
			soundav('b');
			return;
		}
		cout << "\033[34mEnter your choice like a 4\033[0m" << endl;// FOR SELECT BISHOPS TO MOVE
		cin >> e;
		cin >> b;
		a = b - 1;
		b = e - 'a';
		if ((a >= 0 && a <= 7) && (b >= 0 && b <= 7)) {// TO CHECK VALIDNESS OF SELECTED BISHOPS
			if (board[a][b] == 'b') {
				cout << "\033[32mThe piece is available at your desired position \033[0m" << endl;
			}
			else {
				sounda();
				return;
			}
		}
		else {
			soundc();
			return;
		}
		cout << "\033[34mAt what point do you want to moved it :\033[0m" << endl;//FOR DESTINATION 
		cout << "\033[34mEnter your choice like b 3\033[0m" << endl;
		cin >> f;
		cin >> d;
		c = d - 1;
		d = f - 'a';
		if ((c >= 0 && c <= 7) && (d >= 0 && d <= 7)) {// FOR CHECKING OUT OF BOUND CONDITION
			if (a == c && b == d) {// FOR CHECKING ITSELF CONDITION
				soundii();
				return;
			}
			else {
				if (c > a) {// FOR LOWER SIDE MOVEMENT
					if (d > b) {// FOR RIGHT SIDE MOVEMENT
						if ((c - a) == (d - b)) {// FOR DIAGONAL MOVEMENT
							if (pathb1(a, b, c, d) == false) {// FOR CLEAR PATH
								return;
							}
							if ((board[c][d] != 'n') && (board[c][d] != 'q') && (board[c][d] != 'r') && (board[c][d] != 'b') && (board[c][d] != 'p') && (board[c][d] != 'k')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
								if (board[c][d] != 'K') {// FOR NOT KILL OPPONENT KING
									success(a, b, c, d, 'b');
									return;
								}
								else {
									soundk();
									return;
								}
							}
							else {
								soundp();
								return;
							}
						}
						else {
							soundi();
							return;
						}
					}
					else {// FOR LEFT SIDE MOVEMENT
						if ((a + b) - c == d) {// FOR DIAGONAL MOVEMENT
							if (pathb2(a, b, c, d) == false) {// FOR CLEAR PATH
								return;
							}
							if ((board[c][d] != 'n') && (board[c][d] != 'q') && (board[c][d] != 'r') && (board[c][d] != 'b') && (board[c][d] != 'p') && (board[c][d] != 'k')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
								if (board[c][d] != 'K') {// FOR NOT KILL OPPONENT KING
									success(a, b, c, d, 'b');
									return;
								}
								else {
									soundk();
									return;
								}
							}
							else {
								soundp();
								return;
							}
						}
						else {
							soundi();
							return;
						}
					}
				}
				else {// FOR UPPER SIDE MOVEMENT
					if (d > b) {// FOR RIGHT SIDE MOVEMENT
						if ((a + b) - c == d) {// FOR DIAGONAL MOVEMENT
							if (pathb3(a, b, c, d) == false) {// FOR CLEAR PATH
								return;
							}
							if ((board[c][d] != 'n') && (board[c][d] != 'q') && (board[c][d] != 'r') && (board[c][d] != 'b') && (board[c][d] != 'p') && (board[c][d] != 'k')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
								if (board[c][d] != 'K') {// FOR NOT KILL OPPONENT KING
									success(a, b, c, d, 'b');
									return;
								}
								else {
									soundk();
									return;
								}
							}
							else {
								soundp();
								return;
							}
						}
						else {
							soundi();
							return;
						}
					}
					else {// FOR LEFT SIDE MOVEMENT
						if ((c - a) == (d - b)) {// FOR DIAGONAL MOVEMENT
							if (pathb4(a, b, c, d) == false) {// FOR CLEAR PATH
								return;
							}
							if ((board[c][d] != 'n') && (board[c][d] != 'q') && (board[c][d] != 'r') && (board[c][d] != 'b') && (board[c][d] != 'p') && (board[c][d] != 'k')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
								if (board[c][d] != 'K') {// FOR NOT KILL OPPONENT KING
									success(a, b, c, d, 'b');
									return;
								}
								else {
									soundk();
									return;
								}
							}
							else {
								soundp();
								return;
							}
						}
						else {
							soundi();
							return;
						}
					}
				}
			}
		}
		else {
			soundio();
			return;
		}
	}
};
class king :public pieces {// CLASS FOR ALL FUNCTIONALITY OF KING
public:
	void input() {// FOR WHITE(RED) KING
		int a = -1, b = -1;
		char e;
		int c, d;
		char f;
		for (int i = 0; i < 8 && a == -1; i++) {
			for (int j = 0; j < 8 && a == -1; j++) {// FOR SHOWING LOCATION OF KING
				if (board[i][j] == 'K') {
					e = 'a' + j;
					cout << "\033[35mK at point \033[0m" << e << " " << i + 1 << endl;
					a = i; b = j;
				}
			}
		}
		cout << "\033[34mAt what point do you want to moved it :\033[0m" << endl;// ASK FOR DESINATION OF KING
		cout << "\033[34mEnter your choice like b 3\033[0m" << endl;
		cin >> f;
		cin >> d;
		c = d - 1;
		d = f - 'a';
		if ((c >= 0 && c < 8) && (d >= 0 && d < 8)) {// FOR OUT OF BOUND CHECK
			if (a == c && b == d) {// FOR INPUT ITSELF CHECK
				soundii();
				return;
			}
			if ((board[c][d] == 'N') || (board[c][d] == 'Q') || (board[c][d] == 'R') || (board[c][d] == 'B') || (board[c][d] == 'P') || (board[c][d] == 'K')) {// FOR ITS OWN PIECES CHECK
				soundp();
				return;
			}
			if (abs(c - a) <= 1 && abs(d - b) <= 1) {// FOR MOVEMENT OF KING
				if (board[c][d] != 'k') {// FOR NO CAPTURED OF ANOTHER KING
					successfully(a, b, c, d, 'K');
					return;
				}
				else {
					soundk();
					return;
				}
			}
			else {
				soundi();
				return;
			}
		}
		else {
			soundio();
			return;
		}
	}
	void Input() {// FOR BLACK (GREEN) KING
		int a = -1, b = -1;
		char e;
		int c, d;
		char f;
		for (int i = 0; i < 8 && a == -1; i++) {// FOR SHOWING LOCATION OF KING
			for (int j = 0; j < 8 && a == -1; j++) {
				if (board[i][j] == 'k') {
					e = 'a' + j;
					cout << "\033[35mk at point \033[0m" << e << " " << i + 1 << endl;
					a = i; b = j;
				}
			}
		}
		cout << "\033[34mAt what point do you want to moved it :\033[0m" << endl;// ASK FOR DESINATION OF KING
		cout << "\033[34mEnter your choice like b 3\033[0m" << endl;
		cin >> f; cin >> d;
		c = d - 1;
		d = f - 'a';
		if ((c >= 0 && c < 8) && (d >= 0 && d < 8)) {// FOR OUT OF BOUND CHECK
			if (a == c && b == d) {// FOR INPUT ITSELF CHECK
				soundii();
				return;
			}
			if ((board[c][d] == 'n') || (board[c][d] == 'q') || (board[c][d] == 'r') || (board[c][d] == 'b') || (board[c][d] == 'p') || (board[c][d] == 'k')) {// FOR ITS OWN PIECES CHECK
				soundp();
				return;
			}
			if (abs(c - a) <= 1 && abs(d - b) <= 1) {// FOR MOVEMENT OF KING
				if (board[c][d] != 'K') {// FOR NO CHECK ANOTHER KING
					success(a, b, c, d, 'k');
					return;
				}
				else {
					soundk();
					return;
				}
			}
			else {
				soundi();
				return;
			}
		}
		else {
			soundio();
			return;
		}
	}
};
class knight :public pieces {// CLASS FOR ALL FUNCTIONALITY OF KNIGHT
public:
	void input() {// INPUT FUNCTION FOR WHITE KNIGHT
		int av = 0;
		int a, b;
		char e;
		int c, d;
		char f;
		cout << "\033[34mWhich move do you want to move:\033[0m" << endl;
		for (int i = 0; i < 8; i++) {// FOR SHOWING LOCATION OF KNIGHT
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'N') {
					e = 'a' + j;
					cout << "\033[35mN at point \033[0m" << e << " " << i + 1 << endl;
					av += 1;
				}
			}
		}
		if (av == 0) {// FOR CHEKING THE AVAILABLE KNIGHT
			soundav('N');
			return;
		}
		cout << "\033[34mEnter your choice like b 2\033[0m" << endl;// FOR SELECT KNIGHT TO MOVE
		cin >> e;
		cin >> b;
		a = b - 1;
		b = e - 'a';
		if ((a >= 0 && a <= 7) && (b >= 0 && b <= 7)) {// TO CHECK VALIDNESS OF SELECTED KNIGHT
			if (board[a][b] == 'N') {
				cout << "\033[32mThe piece is available at your desired position \033[0m" << endl;
			}
			else {
				sounda();
				return;
			}
		}
		else {
			soundc();
			return;
		}
		cout << "\033[34mAt what point do you want to moved it :\033[0m" << endl;//FOR DESTINATION 
		cout << "\033[34mEnter your choice like b 3\033[0m" << endl;
		cin >> f;
		cin >> d;
		c = d - 1;
		d = f - 'a';
		if ((c >= 0 && c <= 7) && (d >= 0 && d <= 7)) {// FOR CHECKING OUT OF BOUND CONDITION
			if (a == c && b == d) {// FOR CHECKING ITSELF CONDITION
				soundii();
				return;
			}
			if (((c - a == 1) && (d - b == 2)) || ((c - a == 1) && (d - b == -2)) || ((c - a == -1) && (d - b == 2)) || ((c - a == -1) && (d - b == -2)) || ((c - a == 2) && (d - b == 1)) || ((c - a == 2) && (d - b == -1)) || ((c - a == -2) && (d - b == 1)) || ((c - a == -2) && (d - b == -1))) {// FOR IT VALID MOVEMENT
				if ((board[c][d] != 'N') && (board[c][d] != 'Q') && (board[c][d] != 'R') && (board[c][d] != 'B') && (board[c][d] != 'P') && (board[c][d] != 'K')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
					if (board[c][d] != 'k') {// FOR NOT KILL OPPONENT KING
						successfully(a, b, c, d, 'N');
						return;
					}
					else {
						soundk();
						return;
					}
				}
				else {
					soundp();
					return;
				}
			}
			else {
				soundi();
				return;
			}
		}
		else {
			soundio();
			return;
		}
	}
	void Input() {// INPUT FUNCTION FOR BLACK KNIGHT
		int av = 0;
		int a, b;
		char e;
		int c, d;
		char f;
		cout << "\033[34mWhich move do you want to move:\033[0m" << endl;
		for (int i = 0; i < 8; i++) {// FOR SHOWING LOCATION OF KNIGHT
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'n') {
					e = 'a' + j;
					cout << "\033[35mn at point \033[0m" << e << " " << i + 1 << endl;
					av += 1;
				}
			}
		}
		if (av == 0) {// FOR CHEKING THE AVAILABLE KNIGHT
			soundav('n');
			return;
		}
		cout << "\033[34mEnter your choice like g 6\033[0m" << endl;// FOR SELECT KNIGHT TO MOVE
		cin >> e;
		cin >> b;
		a = b - 1;
		b = e - 'a';
		if ((a >= 0 && a <= 7) && (b >= 0 && b <= 7)) {// TO CHECK VALIDNESS OF SELECTED KNIGHT
			if (board[a][b] == 'n') {
				cout << "\033[32mThe piece is available at your desired position \033[0m" << endl;
			}
			else {
				sounda();
				return;
			}
		}
		else {
			soundc();
			return;
		}
		cout << "\033[34mAt what point do you want to moved it :\033[0m" << endl;//FOR DESTINATION 
		cout << "\033[34mEnter your choice like b 3\033[0m" << endl;
		cin >> f;
		cin >> d;
		c = d - 1;
		d = f - 'a';
		if ((c >= 0 && c <= 7) && (d >= 0 && d <= 7)) {// FOR CHECKING OUT OF BOUND CONDITION
			if (a == c && b == d) {// FOR CHECKING ITSELF CONDITION
				soundii();
				return;
			}
			if (((c - a == 1) && (d - b == 2)) || ((c - a == 1) && (d - b == -2)) || ((c - a == -1) && (d - b == 2)) || ((c - a == -1) && (d - b == -2)) || ((c - a == 2) && (d - b == 1)) || ((c - a == 2) && (d - b == -1)) || ((c - a == -2) && (d - b == 1)) || ((c - a == -2) && (d - b == -1))) {// FOR ITS VALID MOVEMENT
				if ((board[c][d] != 'n') && (board[c][d] != 'q') && (board[c][d] != 'r') && (board[c][d] != 'b') && (board[c][d] != 'p') && (board[c][d] != 'k')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
					if (board[c][d] != 'K') {// FOR NOT KILL OPPONENT KING
						success(a, b, c, d, 'n');
						return;
					}
					else {
						soundk();
						return;
					}
				}
				else {
					soundp();
					return;
				}
			}
			else {
				soundi();
				return;
			}
		}
		else {
			soundio();
			return;
		}
	}
};
class pawn :public pieces {// CLASS FOR ALL FUNCTIONALITY OF PAWN
	bool x1 = false;// BOOLEAN VARIBLE FOR SAVE 1ST MOVE OF EVERY PAWN
	bool y1 = false;
public:
	void input() {// FOR RED PAWN
		int av = 0;
		int a, b;
		char e;
		int c, d;
		char f;
		cout << "\033[34mWhich move do you want to move:\033[0m" << endl;// FOR LOCATION OF PAWN DISPLAY
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'P') {
					e = 'a' + j;
					cout << "\033[35mP at point \033[0m" << e << " " << i + 1 << endl;
					av += 1;
				}
			}
		}
		if (av == 0) {// IF THERE IS NO ANY PIECE
			soundav('P');
			return;
		}
		cout << "\033[34mEnter your choice like g 2\033[0m" << endl;// ASK FOR SOURCE POINTS
		cin >> e;
		cin >> b;
		a = b - 1;
		b = e - 'a';
		if ((a >= 0 && a <= 7) && (b >= 0 && b <= 7)) {// CHECK FOR AVAILABILITY
			if (board[a][b] == 'P') {
				cout << "\033[32mThe piece is available at your desired position \033[0m" << endl;
			}
			else {
				sounda();
				return;
			}
		}
		else {
			soundc();
			return;
		}
		cout << "\033[34mAt what point do you want to moved it :\033[0m" << endl;// ASK FOR DESINATION POINTS
		cout << "\033[34mEnter your choice like b 3\033[0m" << endl;
		cin >> f;
		cin >> d;
		c = d - 1;
		d = f - 'a';
		if ((c >= 0 && c <= 7) && (d >= 0 && d <= 7)) {// FOR OUT OF BOUND CHECK
			if (a == c) {// FOR NO MOVEMENT HORIZONATLLY
				if (b == d) {// FOR INPUT ITSELF
					soundii();
					return;
				}
				soundi();
				return;
			}
			else if (b == d) {
				if (c < a) {// FOR NO UPWARD MOVEMENT
					soundi();
					return;
				}
				else {
					if (x1 == false || a == 1) {// FOR 1ST MOVE TO BE 1 OR 2 STEPS AND AFTER THAT ONLY TAKE 1 STEP
						if ((a - c) == -2 || (a - c) == -1) {
							if (board[c][d] == '.') {
								x1 = true;
								sounds(a, b, c, d, 'P');
								promotion(c, d,8);// IF PROMOTION OCCURS
								return;
							}
							else {
								if ((board[c][d] == 'N') || (board[c][d] == 'Q') || (board[c][d] == 'R') || (board[c][d] == 'B') || (board[c][d] == 'P') || (board[c][d] == 'K')) {// CHECK FOR ITS OWN PIECES
									soundp();
									return;
								}
								if ((board[c][d] == 'n') || (board[c][d] == 'q') || (board[c][d] == 'r') || (board[c][d] == 'b') || (board[c][d] == 'p') || (board[c][d] == 'k')) {// CHECK FOR KILL ANOTHER PIECE VERTICALLY
									soundpp();
									return;
								}
								return;
							}

						}
						else {
							soundi();
							return;
						}
					}
					else {
						if ((a - c) == -1) {// FOR NEXT MOVEMENT
							if (board[c][d] == '.') {// FOR PLACE IS BLANK
								sounds(a, b, c, d, 'P');
								promotion(c, d, 8);// IF PROMOTION OCCURS
								return;
							}
							else {
								if ((board[c][d] == 'N') || (board[c][d] == 'Q') || (board[c][d] == 'R') || (board[c][d] == 'B') || (board[c][d] == 'P') || (board[c][d] == 'K')) {// CHECK FOR ITS OWN PIECE
									soundp();
									return;
								}
								if ((board[c][d] == 'n') || (board[c][d] == 'q') || (board[c][d] == 'r') || (board[c][d] == 'b') || (board[c][d] == 'p') || (board[c][d] == 'k')) {// CHECK FOR KILL ANOTHER PIECE VERTICALLY
									soundpp();
									return;
								}
								return;
							}
						}
						else {
							soundi();
							return;
						}
					}
				}
			}
			else {
				if (c > a) {// FOR DIAGONAL MOVEMENT
					if (board[c][d] != '.') {
						if (((d - b) == -1) || ((d - b) == 1)) {
							if ((board[c][d] != 'N') && (board[c][d] != 'Q') && (board[c][d] != 'R') && (board[c][d] != 'B') && (board[c][d] != 'P') && (board[c][d] != 'K')) {// CHECK FOR ITS OWN PIECE
								if ((board[c][d] == 'n') || (board[c][d] == 'b')) {// FOR CAPTURED KNIGHT OR BISHOPS
									X += 3;// SCORE PROMOTION
									sounds(a, b, c, d, 'P');
									cout << endl;
									promotion(c, d,8);// IF PROMOTION OCCURS						
									return;
								}
								if ((board[c][d] == 'p')) {// FOR CAPTURED PAWN OTHER
									X += 1;
									sounds(a, b, c, d, 'P');
									cout << endl;
									promotion(c, d, 8);// IF PROMOTION OCCURS
									return;
								}
								if ((board[c][d] == 'q')) {// FOR CAPTURED QUEEN
									X += 9;
									sounds(a, b, c, d, 'P');
									cout << endl;
									promotion(c, d, 8);// IF PROMOTION OCCURS
									return;
								}
								if ((board[c][d] == 'r')) {// FOR CAPTURED ROOK
									X += 5;
									sounds(a, b, c, d, 'P');
									cout << endl;
									promotion(c, d, 8);// IF PROMOTION OCCURS
									return;
								}
							}
							else {
								soundp();
								return;
							}
						}
						else {
							soundi();
							return;
						}
					}
					else {
						soundi();
						return;
					}
				}
				else {
					soundi();
					return;
				}
			}
		}
		else {
			soundio();
			return;
		}
	}
	void Input() {// FOR GREEN PAWN
		int av = 0;
		int a, b;
		char e;
		int c, d;
		char f;
		cout << "\033[34mWhich move do you want to move:\033[0m" << endl;// FOR LOCATION OF PAWN DISPLAY
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'p') {
					e = 'a' + j;
					cout << "\033[35mp at point \033[0m" << e << " " << i + 1 << endl;
					av += 1;
				}
			}
		}
		if (av == 0) {// IF THERE IS NO ANY PIECE
			soundav('p');
			return;
		}
		cout << "\033[34mEnter your choice like h 7\033[0m" << endl;// ASK FOR SOURCE POINTS
		cin >> e;
		cin >> b;
		a = b - 1;
		b = e - 'a';
		if ((a >= 0 && a <= 7) && (b >= 0 && b <= 7)) {// CHECK FOR AVAILABILITY
			if (board[a][b] == 'p') {
				cout << "\033[32mThe piece is available at your desired position \033[0m" << endl;
			}
			else {
				sounda();
				return;
			}
		}
		else {
			soundc();
			return;
		}
		cout << "\033[34mAt what point do you want to moved it :\033[0m" << endl;// ASK FOR DESINATION POINTS
		cout << "\033[34mEnter your choice like b 3\033[0m" << endl;
		cin >> f;
		cin >> d;
		c = d - 1;
		d = f - 'a';
		if ((c >= 0 && c <= 7) && (d >= 0 && d <= 7)) {// FOR NO MOVEMENT HORIZONATLLY
			if (a == c) {// FOR NO HORIZONATALLY
				if (b == d) {// FOR INPUT ITSELF
					soundii();
					return;
				}
				soundi();
				return;
			}
			else if (b == d) {
				if (c > a) {// FOR NO DOWN MOVEMENT
					soundi();
					return;
				}
				else {
					if (y1 == false || a == 6) {// FOR 1ST MOVE TO BE 1 OR 2 STEPS AND AFTER THAT ONLY TAKE 1 STEP
						if ((a - c) == 2 || (a - c) == 1) {
							if (board[c][d] == '.') {
								y1 = true;
								sounds(a, b, c, d, 'p');
								cout << endl;
								promotion(c, d, 1);// IF PROMOTION OCCURS
								return;
							}
							else {
								if ((board[c][d] == 'N') || (board[c][d] == 'Q') || (board[c][d] == 'R') || (board[c][d] == 'B') || (board[c][d] == 'P') || (board[c][d] == 'K')) {// FOR KILL OTHER PIECES VERTICALLY
									soundpp();
									return;
								}
								if ((board[c][d] == 'n') || (board[c][d] == 'q') || (board[c][d] == 'r') || (board[c][d] == 'b') || (board[c][d] == 'p') || (board[c][d] == 'k')) {// FOR ITS OWN PIECES CHECK
									soundp();
									return;
								}
								return;
							}

						}
						else {
							soundi();
							return;
						}
					}
					else {
						if ((a - c) == 1) {// FOR NEXT MOVEMENT
							if (board[c][d] == '.') {// IF PLACE IS EMPTY
								sounds(a, b, c, d, 'p');
								cout << endl;
								promotion(c, d, 1);// IF PROMOTION OCCURS
								return;
							}
							else {
								if ((board[c][d] == 'N') || (board[c][d] == 'Q') || (board[c][d] == 'R') || (board[c][d] == 'B') || (board[c][d] == 'P') || (board[c][d] == 'K')) {// FOR KILL OTHER PIECES VERTICALLY
									soundpp();
									return;
								}
								if ((board[c][d] == 'n') || (board[c][d] == 'q') || (board[c][d] == 'r') || (board[c][d] == 'b') || (board[c][d] == 'p') || (board[c][d] == 'k')) {// FOR ITS OWN PIECES CHECK
									soundp();
									return;
								}
								return;
							}
						}
						else {
							soundi();
							return;
						}
					}
				}
			}
			else {
				if (c < a) {// FOR DIAGONAL MOVE
					if (board[c][d] != '.') {
						if (((d - b) == 1) || ((d - b) == -1)) {
							if ((board[c][d] != 'n') && (board[c][d] != 'q') && (board[c][d] != 'r') && (board[c][d] != 'b') && (board[c][d] != 'p') && (board[c][d] != 'k')) {// FOR OWN PIECE
								if ((board[c][d] == 'N') || (board[c][d] == 'B')) {// FOR CAPTURED KNIGHT OR BISHOPS
									Y += 3;// SCORE PROMOTION
									sounds(a, b, c, d, 'p');
									cout << endl;
									promotion(c, d, 1);// IF PROMOTION OCCURS
									return;
								}
								if ((board[c][d] == 'P')) {// FOR CAPTURED OTHER PAWN
									Y += 1;
									sounds(a, b, c, d, 'p');
									cout << endl;
									promotion(c, d, 1);// IF PROMOTION OCCURS
									return;
								}
								if ((board[c][d] == 'Q')) {// FOR CAPTURED QUEEN
									Y += 9;
									sounds(a, b, c, d, 'p');
									cout << endl;
									promotion(c, d, 1);// IF PROMOTION OCCURS
									return;
								}
								if ((board[c][d] == 'R')) {// FOR CAPTURED ROOK
									Y += 5;
									sounds(a, b, c, d, 'p');
									cout << endl;
									promotion(c, d, 1);// IF PROMOTION OCCURS
									return;
								}
							}
							else {
								soundp();
								return;
							}
						}
						else {
							soundi();
							return;
						}
					}
					else {
						soundi();
						return;
					}
				}
				else {
					soundi();
					return;
				}
			}
		}
		else {
			soundio();
			return;
		}
	}
};
class rook :public pieces {// CLASS FOR ALL FUNCTIONALITY OF ROOK 
public:
	void input() {// INPUT FUNCTION FOR WHITE ROOK
		int av=0;
		int a, b;
		char e;
		int c, d;
		char f;
		cout << "\033[34mWhich move do you want to move:\033[0m" << endl;
		for (int i = 0; i < 8; i++) {// FOR SHOWING LOCATION OF ROOK
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'R') {
					e = 'a' + j;
					cout << "\033[35mR at point \033[0m" << e << " " << i + 1 << endl;
					av += 1;
				}
			}
		}
		if (av == 0) {// FOR CHEKING THE AVAILABLE ROOKS
			soundav('E');
			return;
		}
		cout << "\033[34mEnter your choice like f 3\033[0m" << endl;// FOR SELECT ROOK TO MOVE
		cin >> e;
		cin >> b;

		a = b - 1;
		b = e - 'a';
		if ((a >= 0 && a <= 7) && (b >= 0 && b <= 7)) {// TO CHECK VALIDNESS OF SELECTED ROOK
			if (board[a][b] == 'R') {
				cout << "\033[32mThe piece is available at your desired position \033[0m" << endl;
			}
			else {
				sounda();
				return;
			}
		}
		else {
			soundc();
			return;
		}
		cout << "\033[34mAt what point do you want to moved it :\033[0m" << endl;//FOR DESTINATION 
		cout << "\033[34mEnter your choice like b 3\033[0m" << endl;
		cin >> f;
		cin >> d;
		c = d - 1;
		d = f - 'a';
		if ((c >= 0 && c <= 7) && (d >= 0 && d <= 7)) {// FOR CHECKING OUT OF BOUND CONDITION
			if (a == c) {// FOR VERTICAL MOVEMENT
				if (b == d) {// FOR CHECKING ITSELF CONDITION
					soundii();
					return;
				}
				else {
					if ((board[c][d] != 'N') && (board[c][d] != 'Q') && (board[c][d] != 'R') && (board[c][d] != 'B') && (board[c][d] != 'P') && (board[c][d] != 'K')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
						if (pathR(a, b, c, d) == false) {// FOR CHEKING CLEAR PATH
							return;
						}
						if (board[c][d] != 'k') {// FOR NOT KILL OPPONENT KING
							successfully(a, b, c, d, 'R');
							return;
						}
						else {
							soundk();
							return;
						}
					}
					else {
						soundp();
						return;
					}
				}
			}
			else if (b == d) {// FOR HORIZONTAL MOVEMENT
				if ((board[c][d] != 'N') && (board[c][d] != 'Q') && (board[c][d] != 'R') && (board[c][d] != 'B') && (board[c][d] != 'P') && (board[c][d] != 'K')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
					if (pathr(a, b, c, d) == false) {// FOR CHEKING CLEAR PATH
						return;
					}
					if (board[c][d] != 'k') {// FOR NOT KILL OPPONENT KING
						successfully(a, b, c, d, 'R');
						return;
					}
					else {
						soundk();
						return;
					}
				}
				else {
					soundp();
					return;
				}
			}
			else {
				soundi();
				return;
			}
		}
		else {
			soundio();
			return;
		}
	}
	void Input() {// INPUT FUNCTION FOR BLACK ROOK
		int av = 0;
		int a, b;
		char e;
		int c, d;
		char f;
		cout << "\033[34mWhich move do you want to move:\033[0m" << endl;
		for (int i = 0; i < 8; i++) {// FOR SHOWING LOCATION OF ROOK
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'r') {
					e = 'a' + j;
					cout << "\033[35mr at point \033[0m" << e << " " << i + 1 << endl;
					av += 1;
				}
			}
		}
		if (av == 0) {// FOR CHEKING THE AVAILABLE ROOKS
			soundav('r');
			return;
		}
		cout << "\033[34mEnter your choice like c 5\033[0m" << endl;// FOR SELECT ROOK TO MOVE
		cin >> e;
		cin >> b;
		a = b - 1;
		b = e - 'a';
		if ((a >= 0 && a <= 7) && (b >= 0 && b <= 7)) {// TO CHECK VALIDNESS OF SELECTED ROOK
			if (board[a][b] == 'r') {
				cout << "\033[32mThe piece is available at your desired position \033[0m" << endl;
			}
			else {
				sounda();
				return;
			}
		}
		else {
			soundc();
			return;
		}
		cout << "\033[34mAt what point do you want to moved it :\033[0m" << endl;//FOR DESTINATION 
		cout << "\033[34mEnter your choice like b 3\033[0m" << endl;
		cin >> f;
		cin >> d;

		c = d - 1;
		d = f - 'a';
		if ((c >= 0 && c <= 7) && (d >= 0 && d <= 7)) {// FOR CHECKING OUT OF BOUND CONDITION
			if (a == c) {// FOR VERTICAL MOVEMENT
				if (b == d) {// FOR CHECKING ITSELF CONDITION
					soundii();
					return;
				}
				else {
					if ((board[c][d] != 'n') && (board[c][d] != 'q') && (board[c][d] != 'r') && (board[c][d] != 'b') && (board[c][d] != 'p') && (board[c][d] != 'k')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
						if (pathR(a, b, c, d) == false) {// FOR CHEKING CLEAR PATH
							return;
						}
						if (board[c][d] != 'K') {// FOR NOT KILL OPPONENT KING
							success(a, b, c, d, 'r');
							return;
						}
						else {
							soundk();
							return;
						}

					}
					else {
						soundp();
						return;
					}
				}
			}
			else if (b == d) {// FOR HORIZONTAL MOVEMENT
				if ((board[c][d] != 'n') && (board[c][d] != 'q') && (board[c][d] != 'r') && (board[c][d] != 'b') && (board[c][d] != 'p') && (board[c][d] != 'k')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
					if (pathr(a, b, c, d) == false) {// FOR CHEKING CLEAR PATH
						return;
					}
					if (board[c][d] != 'K') {// FOR NOT KILL OPPONENT KING
						success(a, b, c, d, 'r');
						return;
					}
					else {
						soundk();
						return;
					}
				}
				else {
					soundp();
					return;
				}
			}
			else {
				soundi();
				return;
			}
		}
		else {
			soundio();
			return;
		}
	}
};
class queen :public pieces {// CLASS FOR ALL FUNCTIONALITY OF QUEEN
public:
	void input() {// INPUT FUNCTION FOR WHITE QUEEN
		int av = 0;
		int a, b;
		char e;
		int c, d;
		char f;
		cout << "\033[34mWhich move do you want to move:\033[0m" << endl;
		for (int i = 0; i < 8; i++) {// FOR SHOWING LOCATION OF QUEEN
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'Q') {
					e = 'a' + j;
					cout << "\033[35mQ at point \033[0m" << e << " " << i + 1 << endl;
					av += 1;
				}
			}
		}
		if (av == 0) {// FOR CHEKING THE AVAILABLE QUEEN
			soundav('Q');
			return;
		}
		cout << "\033[34mEnter your choice like d 2\033[0m" << endl;// FOR SELECT QUEEN TO MOVE
		cin >> e;
		cin >> b;
		a = b - 1;
		b = e - 'a';
		if ((a >= 0 && a <= 7) && (b >= 0 && b <= 7)) {// TO CHECK VALIDNESS OF SELECTED QUEEN
			if (board[a][b] == 'Q') {
				cout << "\033[32mThe piece is available at your desired position \033[0m" << endl;
			}
			else {
				sounda();
				return;
			}
		}
		else {
			soundc();
			return;
		}
		cout << "\033[34mAt what point do you want to moved it :\033[0m" << endl;//FOR DESTINATION 
		cout << "\033[34mEnter your choice like b 3\033[0m" << endl;
		cin >> f;
		cin >> d;
		c = d - 1;
		d = f - 'a';
		if ((c >= 0 && c <= 7) && (d >= 0 && d <= 7)) {// FOR CHECKING OUT OF BOUND CONDITION
			if (a == c) {// FOR VERTICAL MOVEMENT
				if (b == d) {// FOR CHECKING ITSELF CONDITION
					soundii();
					return;
				}
				else {
					if ((board[c][d] != 'N') && (board[c][d] != 'Q') && (board[c][d] != 'R') && (board[c][d] != 'B') && (board[c][d] != 'P') && (board[c][d] != 'K')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
						if (pathR(a, b, c, d) == false){// FOR CHEKING CLEAR CHECK
							return;
						}
						if (board[c][d] != 'k') {// FOR NOT KILL OPPONENT KING
							successfully(a, b, c, d, 'Q');
							return;
						}
						else {
							soundk();
							return;
						}
					}
					else {
						soundp();
						return;
					}
				}
			}
			else if (b == d) {// FOR HORIZONTAL MOVEMENT 
				if ((board[c][d] != 'N') && (board[c][d] != 'Q') && (board[c][d] != 'R') && (board[c][d] != 'B') && (board[c][d] != 'P') && (board[c][d] != 'K')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
					if (pathr(a, b, c, d) == false) {// FOR CHECKING CLEAR PATH
						return;
					}
					if (board[c][d] != 'k') {// FOR NOT KILL OPPONENT KING
						successfully(a, b, c, d, 'Q');
						return;
					}
					else {
						soundk();
						return;
					}
				}
				else {
					soundp();
					return;
				}
			}
			if (c > a) {// FOR LOWER SIDE
				if (d > b) {// FOR RIGHT SIDE MOVEMENT
					if ((c - a) == (d - b)) {// FOR DIAGONAL MOVEMENT
						if (pathb1(a, b, c, d) == false) {// FOR CLEAR PATH MOVEMENT
							return;
						}
						if ((board[c][d] != 'N') && (board[c][d] != 'Q') && (board[c][d] != 'R') && (board[c][d] != 'B') && (board[c][d] != 'P') && (board[c][d] != 'K')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
							if (board[c][d] != 'k') {// FOR NOT KILL OPPONENT KING
								successfully(a, b, c, d, 'Q');
								return;
							}
							else {
								soundk();
								return;
							}
						}
						else {
							soundp();
							return;
						}
					}
					else {
						soundi();
						return;
					}
				}
				else {// FOR LEFT SIDE MOVEMENT
					if ((a + b) - c == d) {// FOR DIAGONAL MOVEMENT
						if (pathb2(a, b, c, d) == false) {// FOR CLEAR PATH 
							return;
						}
						if ((board[c][d] != 'N') && (board[c][d] != 'Q') && (board[c][d] != 'R') && (board[c][d] != 'B') && (board[c][d] != 'P') && (board[c][d] != 'K')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
							if (board[c][d] != 'k') {// FOR NOT KILL OPPONENT KING 
								successfully(a, b, c, d, 'Q');
								return;
							}
							else {
								soundk();
								return;
							}
						}
						else {
							soundp();
							return;
						}
					}
					else {
						soundi();
						return;
					}
				}
			}
			else {// FOR UPPER MOVEMENT
				if (d > b) {// FOR RIGHT MOVEMENT
					if ((a + b) - c == d) {// FOR DIAGONAL MOVEMENT
						if (pathb3(a, b, c, d) == false) {// FOR CLEAR PATH
							return;
						}
						if ((board[c][d] != 'N') && (board[c][d] != 'Q') && (board[c][d] != 'R') && (board[c][d] != 'B') && (board[c][d] != 'P') && (board[c][d] != 'K')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
							if (board[c][d] != 'k') {// FOR NOT KILL OPPONENT KING
								successfully(a, b, c, d, 'Q');
								return;
							}
							else {
								soundk();
								return;
							}
						}
						else {
							soundp();
							return;
						}
					}
					else {
						soundi();
						return;
					}
				}
				else {// FOR LEFT SIDE MOVEMENT
					if ((c - a) == (d - b)) {// FOR DIAGONAL MOVEMENT
						if (pathb4(a, b, c, d) == false) {// FOR CLEAR PATH
							return;
						}
						if ((board[c][d] != 'N') && (board[c][d] != 'Q') && (board[c][d] != 'R') && (board[c][d] != 'B') && (board[c][d] != 'P') && (board[c][d] != 'K')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
							if (board[c][d] != 'k') {// FOR NOT KILL OPPONENT KING
								successfully(a, b, c, d, 'Q');
								return;
							}
							else {
								soundk();
								return;
							}
						}
						else {
							soundp();
							return;
						}
					}
					else {
						soundi();
						return;
					}
				}
			}
		}
		else {
			soundio();
			return;
		}
	}
	void Input() {// INPUT FUNCTION FOR BLACK QUEEN
		int av = 0;
		int a, b;
		char e;
		int c, d;
		char f;
		cout << "\033[34mWhich move do you want to move:\033[0m" << endl;
		for (int i = 0; i < 8; i++) {// FOR SHOWING LOCATION OF QUEEN
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'q') {
					e = 'a' + j;
					cout << "\033[35mq at point \033[0m" << e << " " << i + 1 << endl;
					av += 1;
				}
			}
		}
		if (av == 0) {// FOR CHEKING THE AVAILABLE QUEEN
			soundav('q');
			return;
		}
		cout << "\033[34mEnter your choice like e 7\033[0m" << endl;// FOR SELECT QUEEN TO MOVE
		cin >> e;
		cin >> b;
		a = b - 1;
		b = e - 'a';
		if ((a >= 0 && a <= 7) && (b >= 0 && b <= 7)) {// TO CHECK VALIDNESS OF SELECTED QUEEN
			if (board[a][b] == 'q') {
				cout << "\033[32mThe piece is available at your desired position \033[0m" << endl;
			}
			else {
				sounda();
				return;
			}
		}
		else {
			soundc();
			return;
		}
		cout << "\033[34mAt what point do you want to moved it :\033[0m" << endl;//FOR DESTINATION 
		cout << "\033[34mEnter your choice like b 3\033[0m" << endl;
		cin >> f;
		cin >> d;
		c = d - 1;
		d = f - 'a';
		if ((c >= 0 && c <= 7) && (d >= 0 && d <= 7)) {// FOR CHECKING OUT OF BOUND CONDITION
			if (a == c) {// FOR VERTICAL MOVEMENT
				if (b == d) {// FOR CHECKING ITSELF CONDITION
					soundii();
					return;
				}
				else {
					if ((board[c][d] != 'n') && (board[c][d] != 'q') && (board[c][d] != 'r') && (board[c][d] != 'b') && (board[c][d] != 'p') && (board[c][d] != 'k')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
						if (pathR(a, b, c, d) == false) {// FOR CLEAR PATH
							return;
						}
						if (board[c][d] != 'K') {// FOR NOT KILL OPPONENT KING
							success(a, b, c, d, 'q');
							return;
						}
						else {
							soundk();
							return;
						}
					}
					else {
						soundp();
						return;
					}
				}
			}
			else if (b == d) {// FOR HORIZONTAL MOVEMENT
				if ((board[c][d] != 'n') && (board[c][d] != 'q') && (board[c][d] != 'r') && (board[c][d] != 'b') && (board[c][d] != 'p') && (board[c][d] != 'k')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
					if (pathr(a, b, c, d) == false) {// FOR CLEAR PATH
						return;
					}
					if (board[c][d] != 'K') {// FOR NOT KILL OPPONENT KING
						success(a, b, c, d, 'q');
						return;
					}
					else {
						soundk();
						return;
					}
				}
				else {
					soundp();
					return;
				}
			}
			if (c > a) {// FOR LOWER MOVEMENT
				if (d > b) {// FOR RIGHT SIDE MOVEMENT
					if ((c - a) == (d - b)) {// FOR DIAGONAL MOVEMENT
						if (pathb1(a, b, c, d) == false) {// FOR CLEAR PATH
							return;
						}
						if ((board[c][d] != 'n') && (board[c][d] != 'q') && (board[c][d] != 'r') && (board[c][d] != 'b') && (board[c][d] != 'p') && (board[c][d] != 'k')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
							if (board[c][d] != 'K') {// FOR NOT KILL OPPONENT KING
								success(a, b, c, d, 'q');
								return;
							}
							else {
								soundk();
								return;
							}
						}
						else {
							soundp();
							return;
						}
					}
					else {
						soundi();
						return;
					}
				}
				else {// FOR LEFT SIDE MOVEMENT
					if ((a + b) - c == d) {// FOR DIAGONAL MOVEMENT
						if (pathb2(a, b, c, d) == false) {// FOR CLEAR PATH
							return;
						}
						if ((board[c][d] != 'n') && (board[c][d] != 'q') && (board[c][d] != 'r') && (board[c][d] != 'b') && (board[c][d] != 'p') && (board[c][d] != 'k')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
							if (board[c][d] != 'K') {// FOR NOT KILL OPPONENT KING
								success(a, b, c, d, 'q');
								return;
							}
							else {
								soundk();
								return;
							}
						}
						else {
							soundp();
							return;
						}
					}
					else {
						soundi();
						return;
					}
				}
			}
			else {// FOR UPPER SIDE MOVEMENT
				if (d > b) {// FOR RIGHT SIDE MOVEMENT
					if ((a + b) - c == d) {// FOR DIAGONAL MOVEMENT
						if (pathb3(a, b, c, d) == false) {// FOR CLEAR PATH
							return;
						}
						if ((board[c][d] != 'n') && (board[c][d] != 'q') && (board[c][d] != 'r') && (board[c][d] != 'b') && (board[c][d] != 'p') && (board[c][d] != 'k')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
							if (board[c][d] != 'K') {// FOR NOT KILL OPPONENT KING
								success(a, b, c, d, 'q');
								return;
							}
							else {
								soundk();
								return;
							}
						}
						else {
							soundp();
							return;
						}
					}
					else {
						soundi();
						return;
					}
				}
				else {// FOR LEFT SIDE MOVEMENT
					if ((c - a) == (d - b)) {// FOR DIAGONAL MOVEMENT
						if (pathb4(a, b, c, d) == false) {// FOR CLEAR PATH
							return;
						}
						if ((board[c][d] != 'n') && (board[c][d] != 'q') && (board[c][d] != 'r') && (board[c][d] != 'b') && (board[c][d] != 'p') && (board[c][d] != 'k')) {// FOR CHEKING ALREADY OCCUPIED CONDITION
							if (board[c][d] != 'K') {// FOR NOT KILL OPPONENT KING
								success(a, b, c, d, 'q');
								return;
							}
							else {
								soundk();
								return;
							}
						}
						else {
							soundp();
							return;
						}
					}
					else {
						soundi();
						return;
					}
				}
			}
		}
		else {
			soundio();
			return;
		}
	}
};
int main() {// MAIN FUNCTION FOR RUNNING THE CHESS GAME
	pieces *base=nullptr;// POINTER TO BASE PIECE
	knight n1;// KNIGHT OBJECT
	queen q1;// QUEEN OBJECT
	rook r1; // ROOK OBJECT
	bishops b1;// BISHOP OBJECT
	king k1;// KING OBJECT
	pawn P1; // PAWN OBJECT
	int player = 1;// PLAYER 1 STARTS
	cout << "  ======================================================================================" << endl;  // WELCOME MESSAGE
	cout << "||\033[33m WELCOME TO CHESS GAME MADE BY MUHAMMAD UZAIR HUSSAIN, ZAINAB SAGHEER AND SAADAN KHAN\033[0m ||\n";
	cout << "  ======================================================================================" << endl;
	cout << endl;
	cout << "\033[34mPlayer 1 \033[0m \033[31m(Red)\033[0m \033[34mstarts!\033[0m\n\n";
	while (true) {// MAIN GAME LOOP
		cout << "\033[35m=============================\033[0m\n";
		cout << "\033[34mCurrent Board:\033[0m\n";
		base->display();// DISPLAY CURRENT BOARD
		cout << endl;
		if (base->isCheckmate(player)) {// CHECK IF CURRENT PLAYER IS CHECKMATED
			int winner = (player == 1) ? 2 : 1;
			base->display();
			cout << endl;
			Beep(1000, 400);
			cout << "\033[32m\aPlayer\033[0m " << player << " \033[32mis checkmated. Player\033[0m " << winner << "\033[32m wins!\033[0m\n";
			cout << "\033[34mFinal Score :\033[0m \033[31mRed:\033[0m " << pieces::X << " \033[32m| Green: \033[0m" << pieces::Y << "\n";
			break;// END GAME
		}
		if (base->isInCheck(player)) {// ALERT IF KING IS IN CHECK
			Beep(750, 300);
			cout << "\033[31mPlayer \033[0m"<<player<<":\033[31mYour king is in danger!You MUST resolve it!\033[0m\n";
		}
		cout << "\033[34m>>> PLAYER\033[0m " << player << "\033[34m TURN <<<\033[0m" << (player == 1 ? "\033[31m (Red)\033[0m" : "\033[32m (Green)\033[0m") << "\n";// DISPLAY TURN INFO
		cout << "\033[34mScore :\033[0m\033[31m Red:\033[0m " << pieces::X << "\033[32m | Green: \033[0m" << pieces::Y << "\n\n";
		bool moveMade = false;
		while (!moveMade) {// LOOP UNTIL VALID MOVE MADE
			cout << "\033[34mWhich piece do you want to play:\033[0m\n";// DISPLAY PIECE OPTIONS
			cout << "\033[33m1. Queen    2. Knight    3. Rook\n";
			cout << "4. Bishop   5. King      6. Pawn\033[0m\n";
			cout << "\033[34mEnter your choice:\033[0m ";
			int choice;
			if (!(cin >> choice)) {// INPUT VALIDATION
				cin.clear();
				cin.ignore(256, '\n');
				system("cls");
				cout << endl;
				Beep(420, 250);
				cout << "\033[31mInvalid input. Please enter a number between 1 and 6.\033[0m\n";
				cout << endl;
				base->display();
				cout << endl;
				continue;
			}
			char prevBoard[8][8];// SAVE PREVIOUS BOARD
			pieces::getBoardCopy(prevBoard);
			int prevX = pieces::X;
			int prevY = pieces::Y;
			if (player == 1) {// PLAYER 1 MOVE INPUT
				switch (choice) {
				case 1: {
					base = &q1;
					base->input();
					break;
				}
				case 2: {
					base = &n1;
					base->input();
					break;
				}
				case 3: {
					base = &r1;
					base->input();
					break;
				}
				case 4: {
					base = &b1;
					base->input();
					break;
				}
				case 5: {
					base = &k1;
					base->input();
					break;
				}
				case 6: {
					base = &P1;
					base->input();
					break;
				}
				default:
					system("cls");
					Beep(500, 150);
					cout << "\033[31mInvalid choice. Enter 1-6.\033[0m\n";
					cout << endl;
					base->display();
					cout << endl;
					continue;
				}
			}
			else {// PLAYER 2 MOVE INPUT
				switch (choice) {
				case 1: {
					base = &q1;
					base->Input();
					break;
				}
				case 2: {
					base = &n1;
					base->Input();
					break;
				}
				case 3: {
					base = &r1;
					base->Input();
					break;
				}
				case 4: {
					base = &b1;
					base->Input();
					break;
				}
				case 5: {
					base = &k1;
					base->Input();
					break;
				}
				case 6: {
					base = &P1;
					base->Input();
					break;
				}
				default:
					system("cls");
					Beep(500, 150);
					cout << "\033[31mInvalid choice. Enter 1-6.\033[0m\n";
					cout << endl;
					base->display();
					cout << endl;
					continue;
				}
			}

			if (pieces::equalBoard(prevBoard)) {// CHECK IF BOARD CHANGED
				pieces::X = prevX;
				pieces::Y = prevY;
				continue;
			}
			if (base->isInCheck(player)) {// ILLEGAL MOVE CHECK (KING STILL IN CHECK)
				system("cls");
				Beep(480, 120);
				cout << "\033[31mILLEGAL MOVE! Your king is still in check. Try again.\033[0m\n";
				cout << endl;
				pieces::setBoardFrom(prevBoard);
				pieces::X = prevX;
				pieces::Y = prevY;
				base->display();
				if (base->isCheckmate(player)) {// CHECKMATE AFTER ILLEGAL MOVE
					int winner = (player == 1) ? 2 : 1;
					base->display();
					Beep(1000, 400);
					base->display();
					cout << endl;
					cout << "\033[32m\aPlayer\033[0m " << player << " \033[32mis checkmated. Player\033[0m " << winner << "\033[32m wins!\033[0m\n";
					cout << "\033[34mFinal Score:\033[0m\033[31m Red:\033[0m " << pieces::X << " \033[32m| Green: \033[0m" << pieces::Y << "\n";
					return 0;
				}
				continue;
			}
			moveMade = true;// VALID MOVE MADE
		}
		int opponent = (player == 1) ? 2 : 1;
		if (base->isCheckmate(opponent)) { // CHECK IF OPPONENT IS IN CHECKMATE OR CHECK
			cout << "\033[35m===========================================\033[0m" << endl;
			Beep(1000, 400);
			base->display();
			cout << endl;
			cout << "\033[32mCHECKMATE! Player\033[0m " << player << " \033[32mwins!\033[0m\n";
			cout << "\033[34mFinal Score: \033[0m \033[31mRed:\033[0m " << pieces::X << " \033[32m| Green:\033[0m " << pieces::Y << "\n";
			break;
		}
		else if (base->isInCheck(opponent)) {
			Beep(650, 400);
			cout << "\033[31mCHECK! Player \033[0m" << opponent << " \033[31mis in check.\033[0m\n";
		}
		player = opponent;// SWITCH PLAYER
	}
	cout << "\033[33mThank you for playing.\033[0m\n";// EXIT MESSAGE
	return 0;// END PROGRAM
}
