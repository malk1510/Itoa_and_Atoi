/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h 
 * @brief Gives stats of unsigned char array
 *
 * Finds min, max, mean, median of a given char array
 *
 * @author Tej Ved
 * @date 13/06/2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Finds the minimum value of the array
 *
 * This program takes a sorted character array
 * and its length as input and then, 
 * simply returns the char at index len-1
 *
 * @param ch The array of unsigned characters
 * @param len Length of unsigned characters
 * 
 *
 * @return Smallest char in the array
 */
unsigned char find_minimum(unsigned char* ch, int len);
/**
 * @brief Finds the maximum value of the array
 *
 * This function takes a sorted character array
 * and its length as input and then,
 * simply returns the char at index 0
 *
 * @param ch The array of unsigned characters
 * @param len Length of ch
 */
unsigned char find_maximum(unsigned char* ch, int len);
/**
 * @brief Finds the mean value of the array
 *
 * This function takes a sorted character array
 * and its length as input and then,
 * iterates through every term of the array, and then,
 * adds them all up and returns the sum divided
 * by the length of the array.
 *
 * @param ch The array of unsigned characters
 * @param len Length of ch
 */
unsigned char find_mean(unsigned char* ch, int len);
/**
 * @brief Finds the median value of the array
 *
 * This function takes a sorted character array
 * and its length as input and then,
 * checks whether the length of this array is even or odd
 *
 * If odd, the character at the middle of the array is returned
 *
 * If even, the average of the two characters in the middle
 * is returned
 *
 * @param ch The array of unsigned characters
 * @param len Length of ch
 */
unsigned char find_median(unsigned char* ch, int len);
/**
 * @brief Sorts the array
 *
 * This function takes a character array and its length
 * and sorts it using bubble sort
 *
 * @param ch The array of unsigned characters
 * @param len Length of ch
 */
unsigned char* sort_array(unsigned char* ch, int len);
/**
 * @brief Prints the sorted array
 *
 * This function takes a sorted character array
 * as input, and prints it using a for loop
 *
 * @param ch The array of unsigned characters
 * @param len Length of ch
 */
void print_array(unsigned char* ch, int len);
/**
 * @brief Prints all the stats of a given character array
 *
 * This function takes the min, max, mean and median values 
 * of the array as input, and prints them.
 *
 * @param mean The mean value of the array
 * @param median The median value of the array
 * @param min The minimum value of the array
 * @param max The maximum value of the array
 *
 */
void print_statistics(unsigned char mean, unsigned char median, unsigned char max, unsigned char min);
#endif /* __STATS_H__ */
