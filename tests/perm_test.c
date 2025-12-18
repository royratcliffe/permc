#include "perm.h"

#include <stdlib.h>
#include <stdio.h>

/*!
 * \brief Test the next_permutation_ints function.
 * \param argc The number of command-line arguments.
 * \param argv The command-line arguments.
 * \return EXIT_SUCCESS if all tests pass, EXIT_FAILURE otherwise.
 */
int perm_test(int argc, char **argv) {
  (void)argc;
  (void)argv;

  int ints1[] = {1, 2, 3};
  const int length1 = sizeof(ints1) / sizeof(ints1[0]);
  /*
   * Test all permutations of three elements.
   * There are 3! = 6 permutations.
   *
   * They are:
   * 1 2 3
   * 1 3 2
   * 2 1 3
   * 2 3 1
   * 3 1 2
   * 3 2 1
   */
  do {
    (void)printf("%d %d %d\n", ints1[0], ints1[1], ints1[2]);
  } while (next_permutation_of_ints(ints1, length1));

  if (!next_permutation_of_ints(ints1, length1) || ints1[0] != 1 || ints1[1] != 3 || ints1[2] != 2) {
    return EXIT_FAILURE;
  }
  if (!next_permutation_of_ints(ints1, length1) || ints1[0] != 2 || ints1[1] != 1 || ints1[2] != 3) {
    return EXIT_FAILURE;
  }
  if (!next_permutation_of_ints(ints1, length1) || ints1[0] != 2 || ints1[1] != 3 || ints1[2] != 1) {
    return EXIT_FAILURE;
  }
  if (!next_permutation_of_ints(ints1, length1) || ints1[0] != 3 || ints1[1] != 1 || ints1[2] != 2) {
    return EXIT_FAILURE;
  }
  if (!next_permutation_of_ints(ints1, length1) || ints1[0] != 3 || ints1[1] != 2 || ints1[2] != 1) {
    return EXIT_FAILURE;
  }
  /*
   * Now at the last permutation. The next call should reset to the first
   * permutation and return false.
   */
  if (next_permutation_of_ints(ints1, length1) || ints1[0] != 1 || ints1[1] != 2 || ints1[2] != 3) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
