#include "perm.h"

#include <stdlib.h>

int perm_test(int argc, char **argv) {
  int ints1[] = {1, 2, 3};
  const int length1 = sizeof(ints1) / sizeof(ints1[0]);
  if (!next_permutation_ints(ints1, length1) || ints1[0] != 1 || ints1[1] != 3 || ints1[2] != 2) {
    return EXIT_FAILURE;
  }
  if (!next_permutation_ints(ints1, length1) || ints1[0] != 2 || ints1[1] != 1 || ints1[2] != 3) {
    return EXIT_FAILURE;
  }
  if (!next_permutation_ints(ints1, length1) || ints1[0] != 2 || ints1[1] != 3 || ints1[2] != 1) {
    return EXIT_FAILURE;
  }
  if (!next_permutation_ints(ints1, length1) || ints1[0] != 3 || ints1[1] != 1 || ints1[2] != 2) {
    return EXIT_FAILURE;
  }
  if (!next_permutation_ints(ints1, length1) || ints1[0] != 3 || ints1[1] != 2 || ints1[2] != 1) {
    return EXIT_FAILURE;
  }
  if (next_permutation_ints(ints1, length1) || ints1[0] != 1 || ints1[1] != 2 || ints1[2] != 3) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
