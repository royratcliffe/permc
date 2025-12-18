#include "perm.h"

static void swap_ints(int *lhs, int *rhs);

static void reverse_ints(int ints[], int start, int end);

bool next_permutation_ints(int ints[], int length) {
  /*
   * Find the largest index i such that ints[i] < ints[i + 1]. If no such
   * index exists, the permutation is the last permutation. Find the largest
   * index j greater than i such that ints[i] < ints[j]. Swap the value of
   * ints[i] with that of ints[j]. Finally, reverse the sequence from
   * ints[i + 1] up to and including the final element ints[length - 1].
   */
  int i = length - 2;
  while (i >= 0 && ints[i] >= ints[i + 1]) {
    i--;
  }
  /*
   * If no such index exists, the permutation is the last permutation.
   */
  if (i < 0) {
    reverse_ints(ints, 0, length - 1);
    return false;
  }
  /*
   * Find the largest index j greater than i such that ints[i] < ints[j].
   * Or, equivalently, find the rightmost element that is greater than ints[i].
   */
  int j = length - 1;
  while (ints[j] <= ints[i]) {
    j--;
  }
  /*
   * Swap the value of ints[i] with that of ints[j].
   * We know such a j must exist because i + 1 is such an index.
   * Why? Because ints[i] < ints[i + 1] by definition of i.
   */
  swap_ints(&ints[i], &ints[j]);
  /*
   * Reverse the sequence from ints[i + 1] up to and including the final
   * element ints[length - 1].
   */
  reverse_ints(ints, i + 1, length - 1);
  /*
   * Successfully generated the next permutation.
   */
  return true;
}

void swap_ints(int *lhs, int *rhs) {
  int temp = *lhs;
  *lhs = *rhs;
  *rhs = temp;
}

void reverse_ints(int ints[], int start, int end) {
  while (start < end) {
    swap_ints(&ints[start], &ints[end]);
    start++;
    end--;
  }
}
