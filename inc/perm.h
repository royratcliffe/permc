#ifndef PERM_H
#define PERM_H

#include <stdbool.h>

/*!
 * \brief Generate the next lexicographical permutation of an array of integers.
 * \details This function modifies the input array to represent the next
 * permutation in lexicographical order. If the current permutation is the last
 * permutation, the array is reset to the first permutation (sorted order).
 *
 * \param ints An array of integers representing the current permutation.
 * \param length The length of the array.
 * \return true if the next permutation was generated, false if the current
 * permutation is the last permutation (in which case the array is reset to the
 * first permutation).
 */
bool next_permutation_of_ints(int ints[], int length);

#endif /* PERM_H */
