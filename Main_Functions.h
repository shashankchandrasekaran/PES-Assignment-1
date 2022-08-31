/*
 * functions.h
 *
 *  Created on: 31 Aug 2022
 *      Author: shashankchandrasekaran
 */

#include<stdio.h>
#include<stdint.h>
#include<string.h>

typedef enum {
	CLEAR,
	SET,
	TOGGLE
} operation_t;

int uint_to_binstr(char *str, size_t size, unsigned long int num, unsigned char nbits);
int int_to_binstr(char *str, size_t size, long int num, char nbits);
int uint_to_hexstr(char *str, size_t size, unsigned long int num, unsigned char nbits);
unsigned long int twiggle_bit(unsigned long int input, int bit, operation_t operation);
unsigned long int grab_three_bits(unsigned long int input, int start_bit);
char *hexdump(char *str, size_t size, const void *loc, size_t nbytes);
