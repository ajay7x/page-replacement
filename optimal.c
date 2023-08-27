#include <stdio.h>
int main() {
  int p[20], f[20], fn, i, j, k, fi, n, farthest, pos, flag, pf = 0;
  printf("\n enter the number of pages: ");
  scanf("%d", &n);
  printf("\n enter the sequence: \n");
  for (i = 0; i < n; i++) {
    scanf("%d", &p[i]);
  }
  printf("\n enter the number of frames:\n");
  scanf("%d", &fn);
  for (j = 0; j < fn; j++) {
    f[j] = -1;
  }
  for (i = 0; i < n; i++) {
    flag = 0;
    for (j = 0; j < fn; j++) {
      if (f[j] == p[i]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      pf++;
      farthest = -1;
      pos = -1;
      for (j = 0; j < fn; j++) {
        if (f[j] == -1) {
          f[j] = p[i];
          goto l1;
        }
      }
      for (j = 0; j < fn; j++) {
        fi = -1;
        for (k = i + 1; k < n; k++) {
          if (p[k] == f[j]) {
            fi = k;
            break;
          }
        }
        if (fi == -1) {
          pos = j;
          break;
        }
        if (fi > farthest) {
          farthest = fi;
          pos = j;
        }
      }
      f[pos] = p[i];
    }
  l1:
    printf("\n");
    for (j = 0; j < fn; j++) {
      printf("%d\t", f[j]);
    }
  }
  printf("\nPage fault is: %d", pf);
  return 0;
}