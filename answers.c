#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Write a function to count the total number of characters in all the command-line input arguments to main (excluding the program name). Assuming main calls this function. 
 */
unsigned int count_chars_in_args(int argc, char *argv[])
{
    int i, j, charCount=0;
    for (i=argc-1; i>=0; i--)
    {
        j=0;
        while (argv[i][j]!=0)
        {
            j++; charCount++;
        }
    }
    return charCount;
}

/*
 * Write a function to convert endian representation. Input is converted from bigendian to little endian, and vice-versa. 
 */
unsigned int endian_convert(unsigned int num)
{
    char i, temp, *returnVal=(char*) &num;
    for (i=0; i<2; i++)
    {
        temp=returnVal[i];
        returnVal[i]=returnVal[3-i];
        returnVal[3-i]=temp;
    }
    return *(unsigned int*) returnVal;
}

/* Write a function to reverse a string by creating a new string */
char *reverse_new_str(char *str)
{
    int i, len=strlen(str);
    char* returnStr=(char*) malloc (len+1);
    for (i=len-1; i>=0; i--) 
        returnStr[i]=str[len-1-i];
    returnStr[len];
    return returnStr;
}
		
/* Allocate a 2-D array where row[i] contains col[i] number of columns */
void *my_2d_alloc(int rows, int col)
{
    int i, **returnArr= (int**) malloc (rows*sizeof(int*));
    for (i=0; i<rows; i++)
    {
        returnArr[i]= (int*) malloc (col*sizeof(int));
    }
    return (void*) returnArr;
}

/* Write a function to replace repeated consecutive characters by a single instance of the character. E.g., aaaabbbcabba becomes abcaba */
char *deduplicate_in_place(char *str)
{
    int i, iter=0, len=strlen(str);
    char *returnStr= (char*) malloc (len+1);
    char mem=0;
    for (i=0; i<=len; i++)
    {
        if (str[i]!=mem) returnStr[iter++]=str[i];
        mem=str[i];
    }
    returnStr= (char*) realloc (returnStr, iter);
    returnStr[iter-1]=0;
    return returnStr;
}

/* Write a function to compute the cumulative sum of integer values of all characters in a string */
unsigned int str_weight(char *str)
{
    unsigned int returnInt=0, i;
    for (i=0; i<strlen(str) ; i++)
    {
        returnInt+=str[i];
    }
    return returnInt;
}

/* Given two integer arrays in1, in2, and an array of characters op, all of equal length (len), return an array of same length where ret[i] = in1[i] oper[i] in2[i]. op is either '+', '-', '*' or '/'. Guaranteed no overflow. No divide by zero. */
int *array_op(int *in1, char *op, int *in2, unsigned int len)
{
    int i, *returnArr=(int*) malloc (len*sizeof(int));
    for (i=0; i<len; i++)
    {
        switch (op[i])
        {
            case '+': returnArr[i]=in1[i]+in2[i]; break;
            case '-': returnArr[i]=in1[i]-in2[i]; break;
            case '*': returnArr[i]=in1[i]*in2[i]; break;
            case '/': returnArr[i]=in1[i]/in2[i]; break;
            default: printf("not an op"); break;
        }
    }
    return returnArr;
}

/* Given a number and a bit pattern of length len <= 8, find the index in num where that pattern appears, -1 otherwise.*/
int bit_hunt(unsigned long num, unsigned char pattern, unsigned int len)
{
    unsigned long longPattern=pattern;
    int i;
    unsigned long mask=(1<<len)-1;
    for (i=0; i<64-len; i++)
    {
        if ((longPattern<<i)==(num & (mask<<i))) return i;
    }
    return -1;
}

/* Given a number return 1 if it is a fibonacci number, else 0 */
unsigned int is_fibo(unsigned long num){
    unsigned long first=1, second=1, temp;
    while (second<num)
    {
        temp=second;
        second=first+second;
        first=temp;
    }
    if (second==num) return second;
    return 0;
}

/* Write a function that accepts a number 'x' and a number 'terms' and returns the sin of the number 'x' upto 'terms' number of terms in the infinite series for sin(x). You will be provided the infinite series. */
double my_sin1(double x, unsigned int terms); 

/* Write a function that accepts a number 'x' and a number 'delta' and returns the sin of the number 'x' accurate within 'delta' using the infinite series for sin(x). You will be provided the infinite series. You will also be allowed to use sin function from the math library to compute accuracy. */
double my_sin2(double x, unsigned int terms); 

/* Given a string and indices i1 and i2, perform an in-place swap of characters at i1 and i2 in the string */
void char_swap(char *str, int i1, int i2)
{
    char temp=str[i2];
    str[i2]=str[i1];
    str[i1]=temp;
}

/* Declare a structure that contains an integer i, float f and char c. Write a function struct_array_alloc that accepts an integer n and llocates memory for an array of n structures using malloc (or any other malloc family of functions) */
struct s
{
    int i;
    float f;
    char c;
};

struct s *struct_array_alloc(int n)
{
    return (struct s*) malloc (n * sizeof(struct s));
}

/* Write a function paritize that accepts and returns an unsigned long number where the return number is the same as the input number except that the most significant bit of the return number is set to 1 if the number of 1s in the remaining bits is even, and 0 otherwise */
unsigned long paritize(unsigned long num)
{
    unsigned long oneCount, numCpy=num<<1;
    while (numCpy!=0)
    {
        if (numCpy&1) oneCount++;
        numCpy>>=1;
    }
    if (oneCount&1) return num & 0x7fffffffffffffff;
    else return num | 0x8000000000000000;
}

/* Write a function is_palindrome that accepts an unsigned integer 'num' and a base 'b' 2 <= b < 36 and returns 1 if the integer is a palindrome in base b, 0 otherwise. */
unsigned int is_palindrome(unsigned long num, unsigned int base)
{
    unsigned int logVal=0, logSlave=num;
    int i;
    
    while (logSlave>0)
    {
        logVal++;
        logSlave/=base;
    }
    
    int values[logVal];
    
    for (i=logVal-1;i>=0;i--)
    {
        values[i]=num%base;
        num/=base;
    }
    
    for (i=0;i<logVal/2;i++)
    {
        if (!(values[i] == values[logVal-1-i])) return 0;
    }
    return 1;
}

/* Write a function that accepts an unsigned int number num and returns another unsigned int where the 1st 4 bits and the last 4 bits of each byte in the number are swapped. */
unsigned int swap_within(unsigned int n)
{
    unsigned char upper, lower, *input=(char*) &n;
    int i;
    for (i=0;i<4;i++)
    {
        upper=input[i]/0x10;
        lower=input[i]%0x10;
        lower <<=4;
        input[i]=upper|lower;
    }
    return *(unsigned int*) input;
}

/* Write a function that accepts 2 unsigned ints and returns an unsigned int that is the least common multiple of the two input numbers */
unsigned int lcm(unsigned int n1, unsigned int n2)
{
    unsigned int temp, copy1=n1, copy2=n2;
    while (copy2!=0)
    {
        temp=copy2;
        copy2=copy1%copy2;
        copy1=temp;
    }
    return n1*n2/copy1;
}

int main()
{
    printf("%d\n",lcm(48,128));
    printf("%d\n",is_palindrome(0x23432,16));
    printf("%x\n",swap_within(0x12345678));
    printf("%d\n",str_weight("kalem"));
    printf("%lx\n",paritize(0b01111));
    char str[]="asdfgh";
    char_swap(str,0,2);
    printf("%s\n",str);
    char *argv[]={"asd","qwe","zxcv"};
    printf("%d\n",count_chars_in_args(3, argv));
    printf("%x\n",endian_convert(0x12345678));
    printf("%s\n",reverse_new_str("qwerty"));
    printf("%s\n",deduplicate_in_place("aaaaahdhjadhsss"));
    int x[]={10,10,10,10};
    int y[]={5,5,5,5};
    char z[]={'+','-','*','/'};
    int *retArr=array_op(x,z,y,4);
    printf("%d %d %d %d\n",retArr[0],retArr[1],retArr[2],retArr[3]);
    printf("%d\n",bit_hunt(0b001010101010101100011,0b1100,4));
    printf("%d\n",is_fibo(55));
    printf("%d\n",is_fibo(56));
    return 0;
}
