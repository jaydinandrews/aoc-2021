#include <stdio.h>
#include <stdlib.h>

void part1(){
  FILE *fp = fopen("../input/day2.txt", "r");

  char direction[10];
  int value;
  int horizontal = 0;
  int depth = 0;

  while(fscanf(fp, "%s %d", direction, &value) != EOF){
    printf("%s %d\n", direction, value);
    if(strcmp(direction, "forward") == 0){
      horizontal += value;
    }
    if(strcmp(direction, "down") == 0){
      depth += value;
    }
    if(strcmp(direction, "up") == 0){
      depth -= value;
    }
  }
  int final = depth * horizontal;
  printf("PART ONE:\n");
  printf("Depth is: %d\n", depth);
  printf("Horizontal is %d\n", horizontal);
  printf("Value is %d\n", final);
  fclose(fp);
}

void part2(){
  FILE *fp = fopen("../input/day2.txt", "r");

  char direction[10];
  int value;
  int horizontal = 0;
  int depth = 0;
  int aim = 0;

  while(fscanf(fp, "%s %d", direction, &value) != EOF){
    printf("%s %d\n", direction, value);
    if(strcmp(direction, "forward") == 0){
      horizontal += value;
      depth += (aim * value);
    }
    if(strcmp(direction, "down") == 0){
      aim += value;
    }
    if(strcmp(direction, "up") == 0){
      aim -= value;
    }
    printf("aim=%d\n", aim);
    printf("depth=%d\n", depth);
  }
  int final = depth * horizontal;
  printf("PART TWO:\n");
  printf("Depth is: %d\n", depth);
  printf("Horizontal is %d\n", horizontal);
  printf("Value is %d\n", final);
  fclose(fp);

}


int main(){
  part1();
  part2();
}
