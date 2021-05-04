/**
 * @file utils.h
 * @author Shao-Ting Chiu (r07945001@ntu.edu.tw)
 * @brief General Utilities
 * @version 0.1
 * @date 2021-04-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct {
    long n;
    long sol;
    long* ps;
    long* qs;
    long* rs;
} TriProb;

long* init_arr(long len);
void kill_arr(long*);

/** Noted that `right` is not included*/
void copy_arr(long* dst, long* src, long left, long right);

/** Return index of max element*/
long argmax(long n0, long n1);

void swap(long* a, long *b);

long ChooseMax(long a, long b);

TriProb ParseData(char* filePath);


void int2str(long , char *);
#endif