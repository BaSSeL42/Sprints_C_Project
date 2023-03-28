#include <stdio.h>
#include "STD_types.h"
#include "LCS.h"

// #define arrSize     10

 uint8_t size;
int main(void)
{
    uint8_t val;
    int8_t ret;
   
    printf("Please enter array size: ");
    scanf("%d", &size);
    int32_t array[size];
    
    for (int8_t i = 0; i < size ; i++)
    {
        scanf("%d", array+i);

        if(i == 0 && array[i] == 0x0A)
        {
            break;
        }
        
    }

    uint8_t arrSize = sizeof(array) / sizeof(array[0]);

   ret = insertionSort(array, arrSize);

    // printArray(array, arrSize);


    // ret = lcsGetSize(array, arrSize, &val);

    if(ret == EMPTY_ARRAY)
    {
        printf("\nEMPTY_ARRAY\n");
    }
    else if( ret == ARRAY_SIZE)
    {
        printf("\nARRAY_SIZE error \n");
    }
    else if( ret == NO_LCS )
    {
        printf("\nNO_LCS \n");
    }
    else 
    {
        // printf(" \n %d ", val);
        printArray(array, arrSize);
    }

    



    return 0;
}