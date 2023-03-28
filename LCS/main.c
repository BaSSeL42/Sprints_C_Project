#include <stdio.h>
#include "STD_types.h"
#include "LCS.h"

// #define arrSize     10

 uint8_t size;

 /*
 9, 0, 7, 5, 3, 8, -10, 4, 2, 1
 9, 0, 7, 5, 3, 8, -10, 4, 2, 1, 6, 12
 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
 2, 8, 4, 10, 6, 20, 16, 12, 14, 16
 */
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
    }

    uint8_t arrSize = sizeof(array) / sizeof(array[0]);

   (void)insertionSort(array, arrSize);

    printArray(array, arrSize);


    ret = lcsGetSize(array, arrSize, &val);

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
        printf(" \n %d ", val);
        // printArray(array, arrSize);
    }

    



    return 0;
}