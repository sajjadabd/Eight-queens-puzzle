#include <iostream>
#include <windows.h>

using namespace std;


const int length = 8;
char chessBoard[length][length];

int totalCounter = 0;


void sleep(){
    Sleep(1000);
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

    cout << endl << endl;
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
		totalCounter++;
        //cout << endl << endl << "------------------------------" << endl;
        //printChessBoard(chessBoard,length);
        for(int i=0;i<length;i++) {
            for(int j=0;j<length;j++) {
                if( chessBoard[j][i] == '$' ){
                    if( i == length - 1){
                        cout << length - j - 1 ;
                    } else {
                        cout << length - j - 1 << " ";
                    }
                   
                }
            }
        }
		
		
		//cout << endl;
		//printChessBoard(chessBoard,length);
		//sleep();
		
		
        cout << endl ;
        //cout << endl << endl << "------------------------------" << endl;
    }

    for( int row=length-1 ; row>=0 && currentColumn < length-1 ; row-- ) {
        moveForward(row,currentColumn + 1);
    }

}


void startCrawling( int currentRow, int currentColumn ) {
    QueenNinjaAttack(currentRow,currentColumn);

    

    for(int col=currentColumn+1;col<length;col++) {

        // if( nQueensComplete() ){
        //     //printChessBoard(chessBoard,length);
        //     break;
        // }

        // cout << "---------------------------" << endl;
        // cout << "---------------------------" << endl;
        // cout << "------ COLUMN : " << col <<  " ------" << endl;
        // cout << "---------------------------" << endl;
        // cout << "---------------------------" << endl;

        if ( checkAllIsFull(col) ) {
            resetNextHouses(col-1);
            resetQueenNinja();
            break;
        }

        for( int row=length-1 ; row>=0 ; row-- ) {

            // if ( checkAllIsFull(col) ) {
            //     resetNextHouses(col-1);
            //     resetQueenNinja();
            //     col--;
            //     break;
            // }
            

            if( chessBoard[row][col] == '*' || chessBoard[row][col] == '$' ) {
                continue;
            } else {
                // cout << "---------------------------" << endl;
                // cout << "---------------------------" << endl;
                // cout << "------ ROW : " << row <<  " ------" << endl;
                // cout << "---------------------------" << endl;
                // cout << "---------------------------" << endl;
                startCrawling(row,col);
                //QueenNinjaAttack(row,col);
                //break;
            }
        }

    }
}

int main(){
    int firstInput ;

    setChessBoardToFalse();

    //cout << "Enter First Queen : ";
	//cin >> firstInput;
	
	for(int i=0;i<=7;i++){
		firstInput = i;
		
		int currentColumn = 0;
		int currentRow = length - firstInput - 1;

		int counter = 0;
		
		firstInitialization(firstInput);
		moveForward(currentRow,currentColumn);
		//startCrawling(currentRow,currentColumn);
		//printChessBoard(chessBoard,length);
	}
    
    cout << endl << endl;
	cout << "Total Number Of Solutions : " << totalCounter << endl;
    cout << endl << endl;

    return 0;
}