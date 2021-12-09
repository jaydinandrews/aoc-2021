#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//boards
typedef struct bingoTable {
  int num[5][5];
  bool isMarked[5][5];
} bingoTable;

bingoTable boards[200];
int boardSize = 0;

int called[200];
int calledSize = 0;

void getData(){
  FILE *fp = fopen("../input/day4.txt", "r");

  boardSize = 0;
  calledSize = 0;

  //Get called numbers
  int value;
  while(fscanf(fp, "%d", &value) == 1){
    called[calledSize++] = value;

    if(fgetc(fp) == '\n'){
      break;
    }
  }

  //get all boards
  int numCount = 0;
  int i = 0;
  int j = 0;
  while(fscanf(fp, "%d", &value) == 1){
    if(j == 5){
      i++;
      j = 0;
    }
    boards[boardSize].num[i][j] = value;
    boards[boardSize].isMarked[i][j] = false;
    j++;
    numCount++;

    if(numCount == 25){
      numCount = 0;
      boardSize++;
      i = 0;
      j = 0;
    }
  }

  fclose(fp);
}

void print_board(bingoTable board){
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if(board.isMarked[i][j]){
        printf("_%d_", board.num[i][j]);
      } else {
      printf("%d ", board.num[i][j]);
      }
    }
    printf("\n");
  }
  printf("\n");
}

bool checkWin(bingoTable board){
  //check rows
  for(int i = 0; i < 5; i++){
    int rowMarked = 0;
    int colMarked = 0;
    for(int j = 0; j < 5; j++){
      if(board.isMarked[i][j]){
        rowMarked++;
      }
      if(board.isMarked[j][i]){
        colMarked++;
      }
    }
    if(rowMarked == 5 || colMarked == 5){
      return true;
    }
  }
  return false;
}

int sumUnmarked(bingoTable board){
  int sum = 0;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if(!board.isMarked[i][j]){
        sum += board.num[i][j];
      }
    }
  }
  return sum;
}

void part1(){
  getData();
  for(int numberCalled = 0; numberCalled < calledSize; numberCalled++){
    for(int board = 0; board < boardSize; board++){
      for(int row = 0; row < 5; row++){
        for(int col = 0; col < 5; col++){
          if(boards[board].num[row][col] == called[numberCalled]){
            boards[board].isMarked[row][col] = true;
          }

          if(checkWin(boards[board])){
            int sum = sumUnmarked(boards[board]);
            printf("Part 1: %d\n", sum * called[numberCalled]);
            return;
          }
        }
      }
    }
  }
}

void part2(){
  getData();
  bingoTable lastBoard;
  for(int numberCalled = 0; numberCalled < calledSize; numberCalled++){
    int winners = 0;
    for(int board = 0; board < boardSize; board++){
      for(int row = 0; row < 5; row++){
        for(int col = 0; col < 5; col++){
          if(boards[board].num[row][col] == called[numberCalled]){
            boards[board].isMarked[row][col] = true;
          }
        }
      }
      if(checkWin(boards[board])){
        winners++;
      }
    }
    if(winners == boardSize){
      int sum = sumUnmarked(lastBoard) - called[numberCalled];
      printf("Part 2: %d\n", sum * called[numberCalled]);
      return;
    }
    if(winners == boardSize - 1){
      for(int i = 0; i < boardSize; i++){
        if(!checkWin(boards[i])){
          lastBoard = boards[i];
        }
      }
    }
  }
}

int main(){
 part1(); 
 part2();
}
