/*
 * Assignment 1.c
 *
 *  Created on: 24 Aug 2022
 *      Author: shashankchandrasekaran
 */

#include "Main_Functions.h"

int uint_to_binstr(char *str, size_t size, unsigned long int num, unsigned char nbits)
{
	int nbitsc=0; // Calculates number of bits in the unsigned 32 bit number
	int ctr=0; // Temporary variable for performing calculations
	int lenstr=0; //Variable to calculate length of string
	int i,j,store; //Used in For loop for reversing the string
	unsigned long int copy=num; //To make a copy of num to retain the value
	char *temp = str; // Temporary pointer to store the address of str pointer
	while(num!=0) // Loop to calculate nbits in the num
	{
		num=num>>1;
		nbitsc++;
	}
	num=copy; //num's initial value restored
	if ((size<(nbits+3)) || (nbitsc>nbits)) //To check error condition
	{
		*str='\0';
		return -1;
	}
	else
	{
		*str='0'; //String base address appended with 0
		str++;
		*str='b'; //String appended with b to signify binary
		str++;
		while (num!=0) //Loop to convert unsigned integer to binary
		{
			*str= (num&1) + 48;
			num=num>>1;
			str++;
			ctr++;
		}
		while(nbits-ctr>0) //Loop to append remaining elements to 0
		{
			*str='0';
			str++;
			ctr++;
		}
		*str='\0'; //Null terminating the string
		str=temp; // Assigning the str pointer to start address it was pointing to
		while(*str!='\0') //Loop to find number of characters in string
		{
			lenstr++;
			str++;
		}
		str=temp; //Initializing pointer again to start address
		for(i=2,j=lenstr-1;i<j;i++,j--) //Loop to reverse the string
		{
			store=*(str+i);
			*(str+i)=*(str+j);
			*(str+j)= store;
		}
		return lenstr; //Returning length of string
	}
}


int int_to_binstr(char *str, size_t size, long int num, char nbits)
{
	int nbitsc=0;//calculated bits for signed 32 bit signed integer
	int ctr=0;//Used for calculations and finding string length
	int i,j;
	int c=1; //carry bit
	long int temp=num;
	char *test = str;
	if (num<0) //Convert num to positive for conversion to binary in next loop
	{
		num=-num;
	}

	while(num!=0)
	{
		num=num>>1;
		nbitsc++;
	}
	num=temp; //Restoring value of num
	if ((size<nbits+3) || (nbitsc>nbits)) //Error conditions
	{
		*str='\0';
		return -1;
	}
	else
	{
		*str='0';
		str++;
		*str='b';
		str++;
		if(num>=0)
		{
			while (num!=0)
			{
				*str= (num&1) + 48; //ASCII conversion to store bit
				num=num>>1;
				str++;
				ctr++;
			}

			while(nbits-ctr>0) //Zeros appended in the remaining nbits
			{
				*str='0';
				str++;
				ctr++;
			}
		}
		else if (num<0)

		{   num=-num;//Changing num to positive for converting to binary
		while (num!=0)
		{
			*str= (num&1);
			*str= ((~(*str))+c)&1; //2s compliment for the bit
			if(*str==1)
			{
				c=0;
			}
			else if (*str==0 && c!=0)
			{
				c=1;
			}
			*str=*str+48;
			num=num>>1;
			str++;
			ctr++;
		}

		while(nbits-ctr>0)
		{
			*str='1'; //Remaining values appended to 1
			str++;
			ctr++;
		}
		}
		*str='\0'; //String set to null in the end
		ctr=0; //Reset to be used for counting string length
		str=test;

		while(*str!='\0')
		{
			ctr++;
			str++;
		}
		str=test;
		for(i=2,j=ctr-1;i<j;i++,j--) //String reversed
		{
			temp=*(str+i);
			*(str+i)=*(str+j);
			*(str+j)= temp;
		}
		return ctr;
	}
}

int uint_to_hexstr(char *str, size_t size, unsigned long int num, unsigned char nbits)
{
	int nbitsc=0; //calculated bits for signed 32 bit signed integer
	int ctr=0; //Used for calculations and finding string length
	int i,j;
	unsigned long int temp=num;
	char *test = str;
	while(num!=0)
	{
		num=num>>1;
		nbitsc++;
	}
	if ((((nbits>>2)+3)>size)|| (nbitsc>nbits)) //Error condition checks
	{
		*str='\0';
		return -1; //Returns if error
	}
	else if((nbits==4)||(nbits==8)||(nbits==16)||(nbits==32))
	{

		*str='0';
		str++;
		*str='x';
		str++;
		num=temp;

		while (num!=0) //Loop for conversion to hex
		{

			*str= (num&(15));
			if(*str==10)
			{
				*str='A';
			}
			else if (*str==11)
			{
				*str='B';
			}
			else if (*str==12)
			{
				*str='C';
			}
			else if (*str==13)
			{
				*str='D';
			}
			else if (*str==14)
			{
				*str='E';
			}
			else if (*str==15)
			{
				*str='F';
			}
			else
			{
				*str=*str+48;
			}
			num=num>>4;
			str++;
			ctr+=4;
		}

		while(nbits-ctr>0) //Loop to append zeros to remaining elements
		{
			*str='0';
			str++;
			ctr+=4;
		}

		*str='\0'; //Null terminating string
		ctr=0; //Variable reset
		str=test;

		while(*str!='\0')
		{
			ctr++;
			str++;
		}
		str=test;
		for(i=2,j=ctr-1;i<j;i++,j--)
		{
			temp=*(str+i);
			*(str+i)=*(str+j);
			*(str+j)= temp;
		}
		return ctr; //Returns string length
	}
	else
	{
		*str='\0';
		return -1; //Returns if error
	}
}

unsigned long int twiggle_bit(unsigned long int input, int bit, operation_t operation)
{
	unsigned long int op; //Stores output string
	if (bit>=0 && bit<32)
	{
		switch(operation)
		{
		case CLEAR:
			op=input & ~(0x00000001<<bit);
			break;

		case SET:
			op=input|(0x00000001<<bit);
			break;

		case TOGGLE:
			op =input^(0x00000001<<bit);
			break;
		}
		return op; //Returns output
	}
	else
	{
		return 0xFFFFFFFF; //Returns if error
	}
}

unsigned long int grab_three_bits(unsigned long int input, int start_bit)
{

	unsigned long int output;
	if (start_bit>=0 && start_bit<30)
	{
		output=input>>start_bit;
		output=output&7;
		return output;
	}
	else
	{
		output=0xFFFFFFFF;
		return output; //Returns when error condition pass
	}

}

char *hexdump(char *str, size_t size, const void *loc, size_t nbytes)
{
	int ctr=0,flag,i,calc,loclen=0;
	int temp2,temp3,temp4,temp5,temp6,num;
	char *temp=(char*)loc;
	char *store=str;
	for(i=0;*temp!='\0';i++)
	{
		temp++;
		loclen++;
	}
	temp=(char*)loc;
	if(str==NULL)
	{
		return str;
	}
	if ((size<nbytes)||(nbytes<1)||(nbytes>loclen+1))
	{
		*str='\0';
		return str;
	}
	else
	{
		*str='0';
		str++;
		*str='x';
		str++;
		for (i=0;i<4;i++)
		{
			*str='0';
			str++;
		}
		for(i=0;i<nbytes;i++)
		{
			if(((ctr&15) == 0) && ctr!=0 && flag==0)
			{
				*str='\n';
				str++;
				*str='0';
				str++;
				*str='x';
				str++;
				calc=ctr;
				calc=calc>>4;
				temp4=calc;
				calc=calc>>4;
				temp5=calc;
				calc=calc>>4;
				temp6=calc;
				if(temp4 >=10)
				{
					temp4 = temp4+55;
				}
				else
				{
					temp4 = temp4+48;
				}
				if(temp5 >=10)
				{
					temp5 = temp5+55;
				}
				else
				{
					temp5 = temp5+48;
				}
				if(temp6 >=10)
				{
					temp6 = temp6+55;
				}
				else
				{
					temp6 = temp6+48;
				}
				*str=temp6;
				str++;
				*str=temp5;
				str++;
				*str=temp4;
				str++;
				*str='0';
				str++;
			}
			flag=1;
			num=*temp;
			*str=32;
			str++;
			temp2=num&15;
			num=num>>4;
			temp3=num&15;
			if(temp2 >=10)
			{
				temp2 = temp2+55;
			}
			else
			{
				temp2 = temp2+48;
			}
			if(temp3 >=10)
			{
				temp3 = temp3+55;
			}
			else
			{
				temp3 = temp3+48;
			}

			*str=temp3;
			str++;
			*str=temp2;
			str++;
			ctr++;
			temp++;
			flag=0;
		}
	}
	*str='\0';
	str=store;
	return str;
}
