#include <stdio.h>
#include <stdlib.h>

void updateMaxNValues(long *max, int n, long sum) {
  for (int i = 0; i < n; i++) {
    if (sum > max[i]) {
      for (int j = n-1; j > i; j--) {
        max[j] = max[j-1];
      }
      max[i] = sum;
      break;
    }
  }
}

int main() {
  FILE *fptr = fopen("input.txt", "r");
  char buf[64];
  long max[3] = {0}, currentCalories = 0;
  int n = 3;
  while(fgets(buf, sizeof(buf), fptr) != NULL) {
    if (buf[0] == '\n' || buf[0] == '\r') {
      // move on to the next elf
      updateMaxNValues(max, n, currentCalories);
      currentCalories = 0;
    } else {
      currentCalories += atoi(buf);
    }
  }
  long sum = max[0] + max[1] + max[2];
  printf("Total: %ld\n", sum);
  return 1;
}
