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
 * @file stats.c
 * @brief This program finds various stats of a given array
 *
 * This program sorts a given array;
 * finds the mean, median, max and min values
 * of the terms of the array
 *
 * Malhar Kulkarni
 * 13/06/2020
 *
 */



#include "platform.h"
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void print_statistics(unsigned char min, unsigned char max, unsigned char mean, unsigned char med);
void print_array(unsigned char* ch,int len);
unsigned char* sort_array(unsigned char* ch, int len);
unsigned char find_minimum(unsigned char* ch, int len);
unsigned char find_maximum(unsigned char* ch, int len);
unsigned char find_mean(unsigned char* ch, int len);
unsigned char find_median(unsigned char* ch, int len);
int main2() {
  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  sort_array(test, SIZE);
  unsigned char min=find_minimum(test, SIZE);
  unsigned char max=find_maximum(test, SIZE);
  unsigned char mean=find_mean(test, SIZE);
  unsigned char median=find_median(test, SIZE);
  printf("Sorted Array:\n");
  print_array(test, SIZE);
  print_statistics(min, max, mean, median);
  return 0;
}

/* Add other Implementation File Code Here */
void print_statistics(unsigned char min, unsigned char max, unsigned char mean, unsigned char median)
{
	PRINTF("Minimum:\t%c\nMaximum:\t%c\nMean:\t%c\nMedian:\t%c\n",min,max,mean,median);
}
void print_array(unsigned char* ch,int len)
{
	#ifdef VERBOSE
		for(int i=0;i<len;i++)
		{
			PRINTF("%c\t",ch[i]);
		}
		PRINTF("\n");
	#endif
}
unsigned char find_median(unsigned char* ch, int len)
{
	if(len%2==1)
	{
		return ch[(int)(len/2)];
	}
	else
	{
		return (unsigned char)((int)((ch[len/2]+ch[len/2+1])/2));
	}
}
unsigned char find_mean(unsigned char* ch, int len)
{
	int s=0;
	for(int i=0;i<len;i++)
	{
		s+=ch[i];
	}
	return (unsigned char)((int)(s/len));
}
unsigned char find_maximum(unsigned char*ch, int len)
{
	return ch[0];
}
unsigned char find_minimum(unsigned char*ch, int len)
{
	return ch[len-1];
}
unsigned char* sort_array(unsigned char*ch, int len)
{
	unsigned char t;
	for(int i=0;i<len-1;i++)
	{
		for(int j=0;j<len-i-1;j++)
		{
			if(ch[j]<ch[j+1])
			{
				t=ch[j];
				ch[j]=ch[j+1];
				ch[j+1]=t;
			}
		}
	}
	return ch;
}

