#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fptr = fopen("input.txt", "r");
  char buf[64];
  long max = 0, currentCalories = 0;
  while(fgets(buf, sizeof(buf), fptr) != NULL) {
    if (buf[0] == '\n' || buf[0] == '\r') {
      // move on to the next elf
      if (currentCalories > max) {
        max = currentCalories;
      }
      currentCalories = 0;
    } else {
      currentCalories += atoi(buf);
    }
  }
  printf("%ld\n", max);
  return 1;
}
