# Sorting Algorithm - The Big O Notation

![Complexity](https://www.thetechedvocate.org/wp-content/uploads/2023/10/1_q2VFIS_3aSZ2SnaTemmtuw-660x400@2x.jpg#xxxxxxxxxxxx)

This repository contains implementations of various sorting algorithms in C. Each algorithm is implemented for sorting both arrays and doubly linked lists.

## Algorithms Included

- **Bubble Sort:** A simple algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.

- **Insertion Sort:** Builds the final sorted array one item at a time, less efficient on large lists than more advanced algorithms.

- **Selection Sort:** Repeatedly selects the minimum element and swaps it with the first unsorted element.

- **Quick Sort:** Uses the Lomuto partition scheme, always choosing the last element as the pivot.

- **Shell Sort:** Utilizes the Knuth sequence for efficient sorting of arrays.

- **Count Sort:** A non-comparison-based sorting algorithm suitable for integers with a limited range.

- **Merge Sort:** Divides the unsorted list into n sub-lists, each containing one element, and then repeatedly merges sub-lists to produce new sorted sub-lists until there is only one sub-list remaining.

- **Heap Sort:** Builds a binary heap and then recursively swaps the largest element with the last element.

- **Radix Sort:** Sorts numbers by processing individual digits.

- **Bitonic Sort:** A parallel sorting algorithm that performs well on hardware with parallel processing units.

- **Quick Sort (Hoare Partition Scheme):** Another implementation of quicksort using the Hoare partition scheme.

- **Sort Deck:** An intriguing sorting algorithm inspired by a deck of cards, providing a unique perspective on sorting strategies.

## Usage

To employ these sorting algorithms, include the relevant header file in your C program and call the corresponding function. The functions are designed to sort arrays or doubly linked lists in ascending order, providing a hands-on understanding of the sorting process.

## Compiling the binary

To compile the sorting algorithms binary, run the following command in your terminal:

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 <Required C files> -o <Output filename>
```

## Example Usage

Each algorithm implementation comes with a main file which is in seperate tests directory [tests](./tests) containing all test cases for the algorithms. For instance, the bubble sort algorithm 0-bubble_sort.c is complemented by 0-main.c and so on.

```c
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 tests/0-main.c 0-bubble_sort.c -o bubble
```

## Credit

This project was completed as part of the ALX software engineering program. Dive in, explore, and enhance your understanding of sorting algorithms!

## Feedback

For queries, echoes, and thoughts that bloom and fuss, don't hesitate to connect, in our haven. [Cletus Samuel](https://cletsymedia.github.io/Prof-Portfolio/) and [Amanda Obi](https://github.com/ObiChika)🙏🙏🙏🙏🙏🙏🙏
