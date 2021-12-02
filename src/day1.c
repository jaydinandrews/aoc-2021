#include <stdio.h>

void part1(){

  FILE *fp = fopen("../input/day1.txt", "r");
  int currValue = 156;
  int prevValue = 156;
  int count = 0;
  while(fscanf(fp, "%d", &currValue) != EOF){
    if(currValue > prevValue){
      count++;
    }
    prevValue = currValue;
  }
  printf("PART ONE:\n");
  printf("Number of increases is: %d\n", count);
  fclose(fp);
}

void part2(){
  FILE *fp = fopen("../input/day1.txt", "r");
  int values[2000];
  int index = 0;
  int currValue;
  while(fscanf(fp, "%d", &currValue) != EOF){
    values[index] = currValue;
    index++;
  }
  
  int windowSums[1999];
  for(int i = 0; i < 2000 - 3 + 1; i++){
    int currSum = 0;
    for(int j = 0; j < 3; j++){
      currSum = currSum + values[i + j];
      windowSums[i] = currSum;
    }
  }
  fclose(fp);

  int count = 0;
  for(int i = 1; i <= 1999; i++){
    if(windowSums[i] > windowSums[i - 1]){
      count++;
    }
  }
  printf("PART TWO:\n");
  printf("Number of increases is %d\n", count);
}

int main(){
  part1();
  part2();
}
