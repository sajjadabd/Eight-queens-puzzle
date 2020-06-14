#include <iostream>
#include <time.h>
//#include <windows.h>

using namespace std;


const int length = 8;
char chessBoard[length][length];


void sleepcp(int milliseconds) // Cross-platform sleep function
{
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC/1000;
    while (clock() < time_end){
		
    }
}


void setChessBoardToFalse(){
    for(int i=0;i<length;i++){
        for(int j=0;j<length;j++){
            chessBoard[i][j] = '0';
        }
    }
}

void printChessBoard(char myChessBoard[][length],int length){
    for(int i=0;i<length;i++){
        for(int j=0;j<length;j++){
            cout << myChessBoard[i][j] << " ";
        }
        cout << endl;
    }
	cout << endl;
}

void set1Horizontal(int currentRow,int currentColumn){
    for(int i=currentRow,j=0;j<length;j++){
        if(chessBoard[i][j] == '$'){
            continue;
        } else {
            chessBoard[i][j] = '*';
        }
    }
}

void set1Vertical(int currentRow,int currentColumn){
    for(int i=0,j=currentColumn;i<length;i++){
        if(chessBoard[i][j] == '$'){
            continue;
        } else {
            chessBoard[i][j] = '*';
        }
    }
}

void set1Orib(int currentRow,int currentColumn){
    for(int i=currentRow,j=currentColumn; i<length && j<length ;i++,j++){
        if(chessBoard[i][j] == '$'){
            continue;
        } else {
            chessBoard[i][j] = '*';
        }
    }

    for(int i=currentRow,j=currentColumn; i>=0 && j>=0 ;i--,j--){
        if(chessBoard[i][j] == '$'){
            continue;
        } else {
            chessBoard[i][j] = '*';
        }
    }

    for(int i=currentRow,j=currentColumn; i>=0 && j<length ;i--,j++){
        if(chessBoard[i][j] == '$'){
            continue;
        } else {
            chessBoard[i][j] = '*';
        }
    }

    for(int i=currentRow,j=currentColumn; i<length && j>=0 ;i++,j--){
        if(chessBoard[i][j] == '$'){
            continue;
        } else {
            chessBoard[i][j] = '*';
        }
    }
}

void set1ForDangerousHouse(int currentRow,int currentColumn){
    set1Horizontal(currentRow,currentColumn);
    set1Vertical(currentRow,currentColumn);
    set1Orib(currentRow,currentColumn);
}

void printStatistics(int row,int col){
    cout << "row : " << row << endl;
    cout << "col : " << col << endl;
    cout << endl;
}

void QueenNinjaAttack(int currentRow, int currentColumn){
    chessBoard[currentRow][currentColumn] = '$';
    set1ForDangerousHouse(currentRow,currentColumn);
    //printChessBoard(chessBoard,length);
    //printStatistics(currentRow,currentColumn);
    //sleep();
}

void QueenNinjaAttackWithoutDelay(int currentRow, int currentColumn){
    chessBoard[currentRow][currentColumn] = '$';
    set1ForDangerousHouse(currentRow,currentColumn);
    //printChessBoard(chessBoard,length);
    //printStatistics(currentRow,currentColumn);
}

void firstInitialization(int firstInput){
    setChessBoardToFalse();
    int currentColumn = 0;
    int currentRow = length - firstInput - 1;
    //QueenNinjaAttack(currentRow,currentColumn);
    //chessBoard[currentRow][currentColumn] = '$';
    //set1ForDangerousHouse(currentRow,currentColumn);
    //printChessBoard(chessBoard,length);
}

bool checkAllIsFull(int currentColumn){
    bool allIsStar = true;
    for(int i=0,j=currentColumn;i<length;i++){
        if( chessBoard[i][j] == '*' || chessBoard[i][j] == '$' ){
            //continue;
        } else {
            allIsStar = false;
        }
    }
    return allIsStar;
}

void resetNextHouses(int col){
    for(int i=0;i<length;i++) {
        for(int j=col;j<length;j++) {
            chessBoard[i][j] = '0';
        }
    }
}

void resetStarToZero(){
    for(int i=0;i<length;i++) {
        for(int j=0;j<length;j++) {
            if(chessBoard[i][j] == '*'){
                chessBoard[i][j] = '0';
            }
        }
    }
}

void resetQueenNinja(){
    for(int i=0;i<length;i++) {
        for(int j=0;j<length;j++) {
            if( chessBoard[i][j] != '$' ){
                chessBoard[i][j] = '0';
            }
        }
    }

    for(int i=0;i<length;i++) {
        for(int j=0;j<length;j++) {
            if( chessBoard[i][j] == '$' ){
                //QueenNinjaAttack(i,j);
                QueenNinjaAttackWithoutDelay(i,j);
            }
        }
    }
}

bool nQueensComplete(){
    int nQueensCounter = 0;
    for(int i=0;i<length;i++) {
        for(int j=0;j<length;j++) {
            if( chessBoard[i][j] == '$' ){
                nQueensCounter++;
            }
        }
    }

    if(nQueensCounter < 8){
        return false;
    } else {
        return true;
    }
}

void moveForward(int currentRow, int currentColumn){
	
	

    if ( checkAllIsFull(currentColumn) ) {
        resetNextHouses(currentColumn);
        resetStarToZero();
        resetQueenNinja();
    }
	
	if( chessBoard[currentRow][currentColumn] == '*' ) {
        return;
    }

    QueenNinjaAttack(currentRow,currentColumn);
	

    if( nQueensComplete() ){
        //cout << endl << endl << "------------------------------" << endl;
        printChessBoard(chessBoard,length);
        for(int i=0;i<length;i++) {
            for(int j=0;j<length;j++) {
                if( chessBoard[j][i] == '$' ){

                    cout << " " << length - j - 1 ;

                }
            }
        }
        cout << endl ;
        cout << endl << endl << "------------------------------" << endl << endl;
		sleepcp(500);
    }

    for( int row=length-1 ; row>=0 && currentColumn < length-1 ; row-- ) {
        moveForward(row,currentColumn + 1);
    }

}


int main(){
    int firstInput ;

    setChessBoardToFalse();
	int currentColumn;
	int currentRow;
	
    //cout << "Enter First Queen : ";
	for(int i=0;i<=7;i++){
		firstInput = i;
		currentColumn = 0;
		currentRow = length - firstInput - 1;
		
		firstInitialization(firstInput);
		moveForward(currentRow,currentColumn);
	}
    


    return 0;
}