/********************************************************************************/
/*                          INCLUDE
*********************************************************************************/
#include <stdio.h>
#include <string.h>
#include <math.h>
/********************************************************************************/
/*                          MACROS
*********************************************************************************/
#define stackSize       50

#define C_OK            0
#define C_NOK           -1
/********************************************************************************/
/*                          User Defined Data Types
*********************************************************************************/
typedef signed char      int8_t;
typedef unsigned char   uint8_t;

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


/********************************************************************************/
/*                          Global Variables
*********************************************************************************/
st_stack myStack;
/********************************************************************************/
/*                          Main function
*********************************************************************************/
/*
{(2+3)}
{((2+3)}
[(2+3)]
{(2+3)/((3+3)*(15-10))}
(2+3)/((3+3)*(15-10))
{{2+3)/((3+3)*(15-10)))
{(2+3(/((3+3)*(15-10))}
{(2+3)/((3+3(*)15-10))}
})2+3)/((3+3)*(15-10))}
{(2+3)/(<3+3>*(15-10))}
*/

int main(void)
{
    
    createEmptyStack(&myStack);
    uint8_t* myStr = "  {(2+3)/(<3+3>*(15-10))}";
    int8_t ret;

    ret = isBalancedParantheses(myStr);

    if(ret == 0)
    {
        printf("paranthesis are balanced\n");
    }
    else if (ret == -1)
    {
        printf("paranthesis are not balanced\n");
    }
    else if (ret == -2)
    {
        printf("Wrong expression \n");
    }
    
    return 0;
}


/********************************************************************************/
/*                          Function Implementation
*********************************************************************************/
void createEmptyStack(st_stack* stack)
{
    stack->top = 0;
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
        *data = stack->array[stack->top--];
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
            printf("%d", stack->array[temp]);
            temp--;
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
    if(isEmpty(stack) == 0)
    {
        *topData = stack->array[stack->top];
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