#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SWAP(x, y) {int tmp = x; x = y; y = tmp;};

int board[1000][1000];

typedef struct line {
  int x1;
  int y1;
  int x2;
  int y2;
} line;

line lines[500];
int linesSize = 0;

bool isStraight(int x1, int y1, int x2, int y2){
  return (x1==x2) || (y1==y2);
}

void getData(){
  FILE *fp = fopen("../input/day5.txt", "r");
  int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  while(fscanf(fp, "%d,%d -> %d,%d", &x1, &y1, &x2, &y2) == 4){
    lines[linesSize].x1 = x1;
    lines[linesSize].y1 = y1;
    lines[linesSize].x2 = x2;
    lines[linesSize].y2 = y2;
    linesSize++;
  }
  fclose(fp);
  memset(board, 0, 1000 * 1000 * sizeof(int));
}

void part1(){
  getData();
  int line = 0;
  int count = 0;
  while(line < linesSize){
    int x1 = lines[line].x1;
    int y1 = lines[line].y1;
    int x2 = lines[line].x2;
    int y2 = lines[line].y2;
    line++;

    if(!isStraight(x1, y1, x2, y2)) continue;

    if(x1 > x2) SWAP(x1, x2);
    if(y1 > y2) SWAP(y1, y2);

    for(int i = x1; i <= x2; i++){
      for(int j = y1; j <= y2; j++){
        if(board[j][i] == 1) count++;
        board[j][i]++;
      }
    }
  }
  printf("Part 1: %d\n", count);
}

void part2(){
  getData();
  int line = 0;
  int count = 0;
  while(line < linesSize){
    int x1 = lines[line].x1;
    int y1 = lines[line].y1;
    int x2 = lines[line].x2;
    int y2 = lines[line].y2;
    line++;
  }
    printf("Part 2: %d\n", count);
    for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++){
        printf("%d ", board[i][j]);
      }
      printf("\n");
    }
}

int main(){
  part1();
  //part2();
}
