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

The logic is developed in such a way that for positive numbers, it works as per the requirement.



