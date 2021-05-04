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
#include <string.h>
#include "utils.h"

#define INT_MAX 2147483646

typedef struct {
  long val;
  long p;
} node;

typedef struct {
  long* p;
  node* l;
  node* r;
  long len;
} Paths;


typedef struct {
  long* L;
  long* R;
  node* a2_L;
  node* a2_R;
  node* a3_L;
  node* a3_R;
} MemMerge3;

typedef struct {
  node* Ls_L;
  node* Ls_R;
  node* Rs_L;
  node* Rs_R;
} MemMergeT;

/** Create path struct. where 'r' is max(q,r) / 'l' is the other. 
 * @note Arrays are copied and saved in heap. Use @ref kill_path to recycle the memory
*/
Paths init_path(long len, long p[], long q[], long r[]);
/** Free arrays of the Struct @ref Paths */
void kill_path(Paths);



MemMerge3 allocMemMerge3(long len);
void kill_MemMerge3(MemMerge3);

MemMergeT allocMemMergeT(long len);
void kill_MemMergeT(MemMergeT);

/** @brief Merge Sort first array along with 3 arrays. Increasing order
 * @param A array to be sorted
 * @param a2 paired array of `A`
 * @param a3 paired array of `A`
 * @param p left start index
 * @param r right start index
 * @note Ref: Chapter 4. CLRS
 */
void MERGE_SORT_FIRSTofThree(Paths pt, long p, long r, MemMerge3);
/** Merge process of @ref MERGE_SORT_FIRSTofThree */
void MERGE_FIRSTofThree(Paths pt, long p, long q, long r, MemMerge3);

/** Merge sort and total count inversions
 * @param Ps monotonous increasing 
 * @param Ls Min Array to be sorted
 * @param Rs Max Array to be sorted
 * @note Definition of inversions:
 * 1. Ls[i] >= Rs[j] when Ps[i] < Ps[j]. i!=j
 * 2. Ps[i] == Ps[j]. i!= j
 * Ref: 
 * 1. https://www.csie.ntu.edu.tw/~sprout/algo2016/ppt_pdf/divide_and_conquer.pdf
 * 2. https://www.geeksforgeeks.org/counting-inversions/
*/
long MERGE_SORT_COUNT_INVERSION(Paths pt,long l, long r, MemMergeT);
long MERGE_COUNT_INVERSION(Paths pt, long l, long q, long r, MemMergeT);

/** Sort ps in paths. `Paths.l` and `Path.r` will keep paired with `Paths.p`. Refer to @ref Paths*/
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
long get_intersects(long n, long* p, long* q, long* r);


//Basic Operations
void swapNode(node*, node*);
void copyNode(node* dst, node* src, long str, long end);

#endif