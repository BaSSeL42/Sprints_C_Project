#ifndef STACK_H_
#define STACK_H_

/********************************************************************************/
/*                          MACROS
*********************************************************************************/
#define stackSize       50

#define C_OK            0
#define C_NOK           -1

/********************************************************************************/
/*                          User Defined Data Types
*********************************************************************************/
typedef struct stack
{
    uint8_t array[stackSize];
    int8_t top;
}st_stack;

/********************************************************************************/
/*                          Function Prototype
*********************************************************************************/
void createEmptyStack(st_stack* stack);
int8_t push(st_stack* stack, uint8_t data);
int8_t pop(st_stack* stack, uint8_t* data);
int8_t printStack(st_stack* stack);
int8_t getStackTop(st_stack* stack, uint8_t *topData);
int8_t isFull(st_stack* stack);
int8_t isEmpty(st_stack* stack);
int8_t isBalancedParantheses(uint8_t* str);





#endif /* STACK_H_ */