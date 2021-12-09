#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

void part1(){
  FILE *fp = fopen("../input/day3.txt", "r");
  char value[12];
  int count;
  int bits[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  while(fscanf(fp, "%s", value) != EOF){
    for(int i=0; i < 12; i++){
      value[i] = value[i] - 48;
      if(value[i] == 1){
        bits[i]++;
      }
    }
    count++;
  }

  printf("Gamma in 0b: ");
  for(int i = 0; i < 12; i++){
    if(bits[i] > count/2){
      printf("1");
    } else {
      printf("0");
    }
  }
  printf("\n");

  printf("Epsilon in 0b: ");
  for(int i = 0; i < 12; i++){
    if(bits[i] > count/2){
      printf("0");
    } else {
      printf("1");
    }
  }
  printf("\n");
<<<<<<< HEAD
  fclose(fp);
=======
  flcose(fp);
>>>>>>> c256ad23edfc2b4b568adcfaa53397861746af41
}

int main(){
  part1();

}
