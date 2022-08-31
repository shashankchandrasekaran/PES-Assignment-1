# PES-Assignment-1
Code for Assignment 1 for PES, ECEN-5813(B), Fall 2022

This code was developed to execute 6 functions without using standard library functions.

The compiler used was gcc and the code was developed in eclipse ide and cross verified in CUPES.

Following are the functions logic developed:

1) int uint_to_binstr(char *str, size_t size, uint32_t num, uint8_t nbits)

In this function, first variables and arrays were defined for pointer and to store other values being passed as argument in function.

The conditions were first check, if failed, null string and -1 returned.

if it passes, the logic using bitwise operators were developed to convert unsigned integer to binary and store each bit in the pointer.

The bits which were remaining were appended to string by zeros. In the end string was null terinated and length was counted. String was reversed as well.

2) int int_to_binstr(char *str, size_t size, int32_t num, uint8_t nbits)

This function also has the same operation like unsigned int but there is negative values as well.

The logic is developed in such a way that for positive numbers, it works as per the requirement above. For negative numbers, logic is developed in such a way that the number's 2 compliment is found. The operation is done bitwise through a carry bit.

Rest of the operation is same as above function

3) int uint_to_hexstr(char *str, size_t size, uint32_t num, uint8_t nbits)

In this function, number is converted to hexadecimal equivalent using bitwise operation to divide the number by 4.

The remainders obtained are converted to ASCIIs.

4) uint32_t twiggle_bit(uint32_t input, int bit, operation_t operation)

In this function, biwtise OR, AND and XOR are majorly used for Set, reset and toggle operation on the integer. A simple condition is checked if the bit is out of bounds.

5) uint32_t grab_three_bits(uint32_t input, int start_bit)

The 3 bits in input are shifted towards the end of output using shift bitwise operations. Condition is checked to ensure start bit is selected correctly.

6) char *hexdump(char *str, size_t size, const void *loc, size_t nbytes)

This function returns a pointer that stores the input string value in hex. Logic was such that each first offset was calculated and then the hex equivalent of the char values and each byte stored in pointer. 

The test functions were created based on some boundary and error conditions.

3 files are submitted 2 source and 1 header file.







