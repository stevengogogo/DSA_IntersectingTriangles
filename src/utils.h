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

int* init_arr(int len);
void kill_arr(int*);

/** Noted that `right` is not included*/
void copy_arr(int* dst, int* src, int left, int right);

#endif