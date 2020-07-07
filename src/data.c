#include "memory.h"
#include "data.h"
#include <stdint.h>
/*****************************
 * Function Definitions
 ****************************/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
	uint8_t size=0;
	uint8_t t=1;
	if(data<0){
		*ptr='-';
		ptr++;
		data=-data;
		size++;
		t=2;
	}
	while(data>0){
		if(data%base>9)
			*ptr=data%base-10+'A';
		else
			*ptr=data%base+'0';
		ptr++;
		size++;
		data=data/base;
	}
	*ptr='\0';
	size++;
	my_reverse(ptr-(size-t)*sizeof(uint8_t),size-t);
	return size;
}

int32_t my_atoi(uint8_t* ptr, uint8_t digits, uint32_t base){
	int8_t factor;
	uint32_t fac=1;
	size_t i;
	uint8_t num=0;
	if(*ptr=='-'){
		factor=-1;
		ptr++;}
	else
		factor=1;
	for(i=digits-1;i>=0;i--){
		if(*(ptr+i)>'9')
			num+=(10+*(ptr+i)-'A')*fac*factor;
		else
			num+=(*(ptr+i)-'0')*fac*factor;
		fac*=base;
	}
	return num;
}
