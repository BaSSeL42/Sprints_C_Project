#include <stdio.h>
#include "STD_types.h"
#include "LCS.h"




int8_t insertionSort(int32_t *array, uint8_t arraySize)
{
    int8_t errorStatus = C_OK;
    int32_t temp, j;
    if(arraySize != 0)
    {
        if(arraySize > 0 && arraySize <= 10)
        {
            for (int32_t i = 1; i < arraySize; i++)
            {
                temp = array[i];
                j = i-1;
                while( j >= 0 && array[j] > temp )
                {
                    array[j+1] = array[j];
                    j--;
                }
                array[j+1] = temp;
            }
        }
        else 
        {
            errorStatus = ARRAY_SIZE;
        }
    }
    else 
    {
        errorStatus = EMPTY_ARRAY;
    }


    return errorStatus;
}

void printArray(int32_t *array, uint8_t arraySize)
{
    for (int32_t i = 0; i < arraySize; i++)
    {
        printf("%d ", array[i]);
    }
}



int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS)
{
    int8_t errorStatus = C_OK;
    int32_t max = 0 , count = 1, flag = 0;
    int32_t initVal;


    if (arraySize != 0)
    {
        if (arraySize > 0 && arraySize <= 10)
        {
            initVal = array[1] - array[0];
            for (int32_t i = 1; i < arraySize; i++)
            {
                if( array[i] - array[i-1] == initVal )
                {
                    if(flag == 1)
                    {
                        count++;
                        flag = 0;
                    }
                    count++;
                }
                if( array[i] - array[i-1] != initVal || i==arraySize-1)
                {
                    initVal = array[i] - array[i-1];
                    flag = 1;
                    // count++;
                    if (count > max)
                    {
                        max = count;
                        count = 0;
                    }
                }
            }

            if (max == 1)
            {
                errorStatus = NO_LCS;
            }
            else 
            {
                *sizeofLCS = max;
            }
        }
        else 
        {
            errorStatus =  ARRAY_SIZE;
        }
    }
    else 
    {
        errorStatus =  EMPTY_ARRAY;
    }
    return errorStatus;
}









