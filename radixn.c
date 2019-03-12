//********************************************************************
//*                    EEE2046F/EEE2050F C template                  *
//*==================================================================*
//* WRITTEN BY: CHRIS KATEERA 	                 		             *
//* DATE CREATED: 14/03/18                                           *
//* MODIFIED:  14/03/18                                              *
//*==================================================================*
//* PROGRAMMED IN: cODE bLOCKS                                       *
//* TARGET:    PC                                                    *
//*==================================================================*
//* DESCRIPTION:    decimal to radix-n converter                     *
//*                                                                  *
//********************************************************************
// INCLUDE FILES
//====================================================================
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//====================================================================
// GLOBAL CONSTANTS
//====================================================================

#define TITLE "DECIMAL TO RADIX-n converter"
#define AUTHOR "CHRIS KATEERA"
#define YEAR "2018"

//====================================================================
// GLOBAL VARIABLES
//====================================================================
 int decimal,radix;
 char converted[100]; //global char to accommodate the largest char that can be created.
//====================================================================
// FUNCTION DECLARATIONS
//====================================================================
char* Dec2RadixN(int decValue, int radValue){

            int nValue = (int)floor((log(decValue)/log(radValue))); //to get largest power radix will be raised to for initial division
            char symbols[16]= {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'}; //include hexadecimal
            int quotient,remainder;
            int count=0;

            for(int i = nValue ; i>=0 ;i--){
                quotient= (int)(decValue/pow(radValue,i));
                remainder= decValue% (int)pow(radValue,i);
                decValue=remainder;
                converted[count]=symbols[quotient]; count++;//=symbols[quotient];
                }
                converted[count]='\0'; //null terminator for printing out
            return converted;
}
//====================================================================
// MAIN FUNCTION
//====================================================================
int main (void)
{

    printf("*****************************\n");
    printf("%s\n", TITLE);
    printf("Written by: %s \n", AUTHOR);
    printf("Date: %s \n", YEAR);
    printf("*****************************\n");

    while(1){
        printf("Enter a decimal number: ");
        scanf("%d",&decimal);
        if (decimal<0) break; //(e)
        printf("The number you entered is %d \n",decimal);
        printf("Enter a radix for the converter between 2 and 16: ");
        scanf("%d",&radix);
        if (radix<2 | radix>16) break;
        printf("The radix you entered is %d \n",radix);
        printf("The radix-%d value is : %s\n",radix,Dec2RadixN(decimal,radix));
        printf("The log2 of the number is %.2f \n",log2(decimal)); //(f)
        printf("The integer result of the number divided by %d is %d \n", radix, (decimal/radix)); //(g)
        printf("The remainder is %d \n",(decimal%radix));
    }
    printf("EXIT");
    return 0;
}							// End of main

//********************************************************************
// END OF PROGRAM
//********************************************************************
