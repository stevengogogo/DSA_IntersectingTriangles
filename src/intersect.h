#ifndef INTERSECT_H
#define INTERSECT_H

#include "utils.h"
#include "stdlib.h"
#include "assert.h"

typedef struct {
  int* p;
  int* l;
  int* r;
  int len;
} Paths;

/** Create path struct. where 'r' is max(q,r) / 'l' is the other*/
Paths init_path(int len, int p[], int q[], int r[]);

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