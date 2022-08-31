/*
 * Test_Functions.c
 *
 *  Created on: 31 Aug 2022
 *      Author: shashankchandrasekaran
 */
#include "Main_Functions.h"

int test_uint_to_binstr()
{
	char array[255];
	char *str=&array[0];
	int Rvalue,strcomp;
	char exp_str1[]="0b0";
	char exp_str2[]="0b11111111";
	char exp_str3[]="0b11111111111111111111111111111111";
	char exp_str4[]="";
	char exp_str5[]="";
	/*************************************First test case**************************************************/
	Rvalue=uint_to_binstr(str,4,0,1);
	strcomp=strcmp(str,exp_str1);
	if(Rvalue!=3)
	{
		printf("The production function uint_to_binstr has failed due to incorrect return of number of characters\n");
		return 0;
	}
	else if(strcomp!=0)
	{
		printf("The production function uint_to_binstr has failed due to incorrect return string\n");
		return 0;
	}
	/*************************************Second test case**************************************************/
	Rvalue=uint_to_binstr(str,260,255,8);
	strcomp=strcmp(str,exp_str2);
	if(Rvalue!=10)
	{
		printf("The production function uint_to_binstr has failed due to incorrect return of number of characters\n");
		return 0;
	}
	else if(strcomp!=0)
	{
		printf("The production function uint_to_binstr has failed due to incorrect return string\n");
		return 0;
	}
	/*************************************Third test case**************************************************/
	Rvalue=uint_to_binstr(str,35,4294967295,32);
	strcomp=strcmp(str,exp_str3);
	if(Rvalue!=34)
	{
		printf("The production function uint_to_binstr has failed due to incorrect return of number of characters\n");
		return 0;
	}
	else if(strcomp!=0)
	{
		printf("The production function uint_to_binstr has failed due to incorrect return string\n");
		return 0;
	}
	/*************************************Fourth test case**************************************************/
	Rvalue=uint_to_binstr(str,4,3,5);
	strcomp=strcmp(str,exp_str4);
	if(Rvalue!=-1)
	{
		printf("The production function uint_to_binstr has failed due to incorrect return\n");
		return 0;
	}
	else if(strcomp!=0)
	{
		printf("The production function uint_to_binstr has failed due to incorrect return string\n");
		return 0;
	}
	else if(Rvalue==-1)
	{
		printf("The production function uint_to_binstr has returned -1 due to invalid inputs\n");
	}
	/*************************************Fifth test case**************************************************/
	Rvalue=uint_to_binstr(str,0,0,0);
	strcomp=strcmp(str,exp_str5);
	if(Rvalue!=-1)
	{
		printf("The production function uint_to_binstr has failed due to incorrect return\n");
		return 0;
	}
	else if(strcomp!=0)
	{
		printf("The production function uint_to_binstr has failed due to incorrect return string\n");
		return 0;
	}
	else if(Rvalue==-1)
	{
		printf("The production function uint_to_binstr has returned -1 due to invalid inputs\n");
	}

	return 1;
}

int test_int_to_binstr()
{
	char array[255];
	char *str=&array[0];
	int Rvalue,strcomp;
	char exp_str1[]="0b01000110";
	char exp_str2[]="0b10000001";
	char exp_str3[]="";
	char exp_str4[]="";
	/*************************************First test case**************************************************/
	Rvalue=int_to_binstr(str,11,70,8);
	strcomp=strcmp(str,exp_str1);
	if(Rvalue!=10)
	{
		printf("The production function int_to_binstr has failed due to incorrect return of number of characters\n");
		return 0;
	}
	else if(strcomp!=0)
	{
		printf("The production function int_to_binstr has failed due to incorrect return string\n");
		return 0;
	}
	/*************************************Second test case**************************************************/
	Rvalue=int_to_binstr(str,20,-127,8);
	strcomp=strcmp(str,exp_str2);
	if(Rvalue!=10)
	{
		printf("The production function int_to_binstr has failed due to incorrect return of number of characters\n");
		return 0;
	}
	else if(strcomp!=0)
	{
		printf("The production function int_to_binstr has failed due to incorrect return string\n");
		return 0;
	}
	/*************************************Third test case**************************************************/
	Rvalue=int_to_binstr(str,10,-6,1);
	strcomp=strcmp(str,exp_str3);
	if(Rvalue!=-1)
	{
		printf("The production function int_to_binstr has failed due to incorrect return\n");
		return 0;
	}
	else if(strcomp!=0)
	{
		printf("The production function int_to_binstr has failed due to incorrect return string\n");
		return 0;
	}
	else if(Rvalue==-1)
	{
		printf("The production function int_to_binstr has returned -1 due to invalid inputs\n");
	}

	/*************************************Fourth test case**************************************************/
	Rvalue=int_to_binstr(str,1,3,5);
	strcomp=strcmp(str,exp_str4);
	if(Rvalue!=-1)
	{
		printf("The production function uint_to_binstr has failed due to incorrect return\n");
		return 0;
	}
	else if(strcomp!=0)
	{
		printf("The production function uint_to_binstr has failed due to incorrect return string\n");
		return 0;
	}
	else if(Rvalue==-1)
	{
		printf("The production function uint_to_binstr has returned -1 due to invalid inputs\n");
	}
	return 1;
}


int test_uint_to_hexstr()
{
	char array[255];
	char *str=&array[0];
	int Rvalue,strcomp;
	char exp_str1[]="0x20";
	char exp_str2[]="0x0000FFFF";
	char exp_str3[]="";
	char exp_str4[]="";
	/*************************************First test case**************************************************/
	Rvalue=uint_to_hexstr(str,5,32,8);
	strcomp=strcmp(str,exp_str1);
	if(Rvalue!=4)
	{
		printf("The production function int_to_hexstr has failed due to incorrect return of number of characters\n");
		return 0;
	}
	else if(strcomp!=0)
	{
		printf("The production function uint_to_hexstr has failed due to incorrect return string\n");
		return 0;
	}
	/*************************************Second test case**************************************************/
	Rvalue=uint_to_hexstr(str,19,65535,32);
	strcomp=strcmp(str,exp_str2);
	if(Rvalue!=10)
	{
		printf("The production function uint_to_hexstr has failed due to incorrect return of number of characters\n");
		return 0;
	}
	else if(strcomp!=0)
	{
		printf("The production function uint_to_hexstr has failed due to incorrect return string\n");
		return 0;
	}
	/*************************************Third test case**************************************************/
	Rvalue=uint_to_hexstr(str,6,32,10);
	strcomp=strcmp(str,exp_str3);
	if(Rvalue!=-1)
	{
		printf("The production function uint_to_hexstr has failed due to incorrect return\n");
		return 0;
	}
	else if(strcomp!=0)
	{
		printf("The production function uint_to_hexstr has failed due to incorrect return string\n");
		return 0;
	}
	else if(Rvalue==-1)
	{
		printf("The production function uint_to_hexstr has returned -1 due to invalid inputs\n");
	}
	/*************************************Fourth test case**************************************************/
	Rvalue=uint_to_hexstr(str,1,15,1);
	strcomp=strcmp(str,exp_str4);
	if(Rvalue!=-1)
	{
		printf("The production function uint_to_hexstr has failed due to incorrect return\n");
		return 0;
	}
	else if(strcomp!=0)
	{
		printf("The production function uint_to_hexstr has failed due to incorrect return string\n");
		return 0;
	}
	else if(Rvalue==-1)
	{
		printf("The production function uint_to_hexstr has returned -1 due to invalid inputs\n");
	}

	return 1;
}

int test_twiggle_bit()
{
	uint32_t Rvalue=twiggle_bit(300,4,SET);
	if(Rvalue!=316)
	{
		printf("The production function twiggle bit has failed due to incorrect SET operation\n");
		return 0;
	}
	Rvalue=twiggle_bit(210,4,CLEAR);
	if(Rvalue!=194)
	{
		printf("The production function twiggle bit has failed due to incorrect CLEAR operation\n");
		return 0;
	}
	Rvalue=twiggle_bit(180,4,TOGGLE);
		if(Rvalue!=164)
		{
			printf("The production function twiggle bit has failed due to incorrect Toggle operation\n");
			return 0;
		}
	Rvalue=twiggle_bit(180,34,SET);
			if(Rvalue==0xFFFFFFFF)
			{
				printf("The production function twiggle bit has returned 0xFFFFFFFF due to bit out of range");
			}
		return 1;

		}

int test_grab_three_bits()
{
	uint32_t Rvalue=grab_three_bits(450,4);
	if(Rvalue!=4)
	{
		printf("The production function grab three bits has failed\n");
		return 0;
	}
	Rvalue=grab_three_bits(250,32);
	if(Rvalue==0xFFFFFFFF)
		{
		   printf("The production function grab three bits has returned 0xFFFFFFFF due to incorrect start bit\n");
		}
	return 1;
}

int test_hexdump()
{
	char array[]="0x0000 48 69 00";
	 const char *buf=
	    "Hi";
	  char str[1024];
	  puts(hexdump(str, sizeof(str), buf, strlen(buf)+1));
	  if(strcmp(array,str)==0)
	  {
		  return 1;
	  }
	  else
	  {
		  return 0;
	  }
}

int main()
{
	/**************************** Calling Uint_to_binstr test function********************************/
	int Rvalue_Uint_Binstr = test_uint_to_binstr();
	if (Rvalue_Uint_Binstr==1)
	{
		printf("The overall test function uint_to_binstr has passed\n\n");
	}
	else if (Rvalue_Uint_Binstr==0)
	{
		printf("The overall test function uint_to_binstr has failed\n\n");
	}

	/**************************** Calling int_to_binstr test function********************************/
	int Rvalue_int_Binstr = test_int_to_binstr();
	if (Rvalue_int_Binstr==1)
	{
		printf("The overall test function int_to_binstr has passed\n\n");
	}
	else if (Rvalue_int_Binstr==0)
	{
		printf("The overall test function int_to_binstr has failed\n\n");
	}

	/**************************** Calling uint_to_hexstr test function********************************/
	int Rvalue_uint_hexstr = test_uint_to_hexstr();
	if (Rvalue_uint_hexstr==1)
	{
		printf("The overall test function uint_to_hexstr has passed\n\n");
	}
	else if (Rvalue_uint_hexstr==0)
	{
		printf("The overall test function uint_to_hexstr has failed\n\n");
	}
	/**************************** Calling twiggle bits test function********************************/
	int Rvalue_twiggle_bit=test_twiggle_bit();
	if (Rvalue_twiggle_bit==1)
	{
		printf("The overall test function twiggle_bit has passed\n\n");
	}
	else if (Rvalue_twiggle_bit==0)
	{
		printf("The overall test function twiggle_bit has failed\n\n");
	}
	/**************************** Calling grab three bits test function********************************/
	int Rvalue_grab_three_bits=test_grab_three_bits();
	if (Rvalue_grab_three_bits==1)
	{
		printf("The overall test function grab three bits has passed\n\n");
	}
	else if (Rvalue_grab_three_bits==0)
	{
		printf("The overall test function grab three bits has failed\n\n");
	}
	/**************************** Calling grab three bits test function********************************/
	int Rvalue_hexdump=test_hexdump();
	if (Rvalue_hexdump==1)
	{
		printf("The overall test function hexdump has passed\n\n");
	}
	else if (Rvalue_hexdump==0)
	{
		printf("The overall test function hexdump has failed\n\n");
	}
}
