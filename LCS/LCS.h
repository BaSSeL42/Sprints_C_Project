#ifndef LCS_H_
#define LCS_H_

#define C_OK             0
#define EMPTY_ARRAY     -1
#define ARRAY_SIZE      -2
#define NO_LCS          -3



int8_t insertionSort(int32_t *array, uint8_t arraySize);

void printArray(int32_t *array, uint8_t arraySize);

int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS);
 

#endif /*LCS_H_*/