/********************************************************************************/
/*                          INCLUDE
*********************************************************************************/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "std.h"
#include "stack.h"


/********************************************************************************/
/*                          Global Variables
*********************************************************************************/
st_stack myStack;

/********************************************************************************/
/*                          Function Implementation
*********************************************************************************/
void createEmptyStack(st_stack* stack)
{
    stack->top = -1;
    for (int8_t i = 0 ; i < stackSize ; i++)
    {
        stack->array[i] = 0;
    }
}



int8_t push(st_stack* stack, uint8_t data)
{
    int8_t errorStatus = C_OK;
    if(!isFull(stack))
    {
        stack->array[stack->top++] = data;
    }
    else 
    {
        errorStatus = C_NOK;
    }

    return errorStatus;

}


int8_t pop(st_stack* stack, uint8_t* data)
{
    int8_t errorStatus = C_OK;
    if(!isEmpty(stack))
    {
        stack->top -= 1;
        *data = stack->array[stack->top];
    }
    else 
    {
        errorStatus = C_NOK;
    }
    return errorStatus;
}


int8_t printStack(st_stack* stack)
{
    int8_t errorStatus = C_OK;
    int8_t temp = stack->top;

    if(!isEmpty(stack))
    {
        while(temp > -1)
        {
            printf("%d\n", stack->array[--temp]);
        }
    }
    else 
    {
        errorStatus = C_NOK;
    }

    return errorStatus;
}


int8_t getStackTop(st_stack* stack, uint8_t *topData)
{
    int8_t errorStatus = C_OK;
    int8_t temp = stack->top;
    if(isEmpty(stack) == 0)
    {
        *topData = stack->array[--temp];
    }
    else 
    {
        errorStatus = C_NOK;
    }

    return errorStatus;
    
}


int8_t isFull(st_stack* stack)
{
    if(stack->top < stackSize)
    {
        return 0;
    }
    else 
    {
        return -1;
    }
}


int8_t isEmpty(st_stack* stack)
{
    if(stack->top != -1)
    {
        return 0;
    }
    else 
    {
        return -2;
    }
}





int8_t isBalancedParantheses(uint8_t* str)
{
    int8_t stringLength = strlen(str);
    uint8_t st;
    int8_t errorState, retStatus, count = 0, c1 = 0, c2 = 0;
    
    for (int8_t i = 0; i <= stackSize ; i++)
    {
        (void)push(&myStack, str[i]);
    }

    for(int8_t j = 0 ; j < stackSize ; j++)
    {
        errorState = pop(&myStack, &st);

        if(errorState == 0)
        {
            
            if ( st == '{' || st == '}' || st == '(' || st == ')' )
            {
                printf("%c\n", st);
                if (st == '{')
                {
                    c1++;
                }
                else if(st == '(')
                {
                    c2++;
                }
                else if(st == '}')
                {
                    c1--;
                }
                else if ( st == ')')
                {
                    c2--;
                }
            }
            else if ( st == '[' || st == ']' || st == '<' || st == '>' )
            {
                return retStatus = -2;
            }
            else 
            {
                /* do nothing */
            }
        }
        else 
        {
            printf("Stack is Empty");
        }
    }
    printf("%d\n", c1);
    printf("%d\n", c2);
    count = abs(c1) + abs(c2) ; 

    if (count == 0)
    {
        retStatus = 0;
    }
    else 
    {
        retStatus = -1;
    }

    return retStatus;
}