# PermC

A C library for generating lexicographical permutations of integer arrays.

## Overview

PermC provides an efficient implementation of the next permutation algorithm, which generates permutations in lexicographical order. This is useful for combinatorics, optimisation problems, and any scenario where you need to iterate through all possible arrangements of elements.

## Features

- **Efficient Algorithm**: Generates the next permutation in-place with O(n) time complexity
- **Lexicographical Order**: Produces permutations in sorted order
- **Cycle Detection**: Returns `false` when wrapping from the last to first permutation
- **Well-Tested**: Comprehensive test suite included
- **MIT Licensed**: Free to use in commercial and open-source projects

## Building

This project uses CMake for building:

```bash
# Configure the build
cmake -S . -B build

# Build the library
cmake --build build

# Run tests
cd build
ctest
```

## Usage

Include the header file and link against the library:

```c
#include "perm.h"

int main() {
    int arr[] = {1, 2, 3};
    const int len = sizeof(arr) / sizeof(arr[0]);

    // Generate and print all permutations in the array.
    do {
        printf("%d %d %d\n", arr[0], arr[1], arr[2]);
    } while (next_permutation_of_ints(arr, len)) {

    return 0;
}
```

Output:
```
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
```

## API Reference

### `next_permutation_of_ints`

```c
bool next_permutation_of_ints(int ints[], int length);
```

Generates the next lexicographical permutation of an array of integers.

**Parameters:**
- `ints`: Array of integers representing the current permutation
- `length`: The length of the array

**Returns:**
- `true` if the next permutation was generated
- `false` if the current permutation is the last permutation (in which case the array is reset to the first permutation in sorted order)

**Algorithm:**

1. Find the largest index `i` such that `ints[i] < ints[i + 1]`
2. If no such index exists, reverse the entire array and return `false`
3. Find the largest index `j` greater than `i` such that `ints[i] < ints[j]`
4. Swap `ints[i]` with `ints[j]`
5. Reverse the sequence from `ints[i + 1]` to the end
6. Return `true`

## Project Structure

```
permc/
├── CMakeLists.txt          # Build configuration
├── README.md               # This file
├── inc/
│   └── perm.h              # Public API header
├── src/
│   └── perm.c              # Implementation
└── tests/
    └── perm_test.c         # Unit tests
```

## Testing

The project includes a comprehensive test suite that validates all permutations of a 3-element array (6 permutations total) and verifies the wrap-around behavior.

Run tests with:
```bash
cd build
ctest
```

## Algorithm Complexity

- **Time Complexity**: O(n) for each call to `next_permutation_of_ints`
- **Space Complexity**: O(1) - operates in-place on the input array

## License

This project is licensed under the MIT License. See the SPDX identifier in source files for details.

## Author

Roy Ratcliffe

## Contributing

Contributions are welcome! Please feel free to submit pull requests or open issues for bugs and feature requests.
