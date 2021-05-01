/**
 * @file intersect.h
 * @author Shao-Ting Chiu 
 * @brief Calculating inversions
 * @version 0.1
 * @date 2021-05-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef INTERSECT_H
#define INTERSECT_H


#include <stdlib.h>
#include <assert.h>
#include <limits.h> // INT_MAX
#include "utils.h"

typedef struct {
  int* p;
  int* l;
  int* r;
  int len;
} Paths;

/** Create path struct. where 'r' is max(q,r) / 'l' is the other. 
 * @note Arrays are copied and saved in heap. Use @ref kill_path to recycle the memory
*/
Paths init_path(int len, int p[], int q[], int r[]);
/** Free arrays of the Struct @ref Paths */
void kill_path(Paths);


/** Merge Sort first array along with 3 arrays. Increasing order
 * @param A array to be sorted
 * @param a2 paired array of `A`
 * @param a3 paired array of `A`
 * @param p left start index
 * @param r right start index
 * @note Ref: Chapter 4. CLRS
 */
void MERGE_SORT_FIRSTofThree(int* A, int* a2, int* a3, int p, int r);
/** Merge process of @ref MERGE_SORT_FIRSTofThree */
void MERGE_FIRSTofThree(int* A, int* a2, int* a3, int p, int q, int r);

/** Merge sort and total count inversions
 * @note Definition of inversions:
 * 
*/
int MERGE_SORT_COUNT_INVERSION(int* Ps, int* Ls, int* Rs,int l, int r);
int MERGE_COUNT_INVERSION(int* Ps, int* Ls, int* Rs, int l, int q, int r);

/** Sort ps in paths. Paths.l and Path.r will keep paired with Paths.p*/
void sortPaths_P(Paths);

/**
 * @brief Get the intersects object
 * 
 * @param n number of points
 * @param p array of `p` points
 * @param q array of `q` points
 * @param r array of `r` points
 * @return int number of intersects
 */
int get_intersects(int n, int* p, int* q, int* r);



#endif