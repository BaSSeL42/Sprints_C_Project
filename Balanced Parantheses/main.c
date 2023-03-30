/********************************************************************************/
/*                          INCLUDE
*********************************************************************************/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "std.h"
#include "stack.h"


extern st_stack myStack;

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
    // uint8_t* myStr = "  {(2+3)/(<3+3>*(15-10))}";
    int8_t ret;
    uint8_t myVal, top;

    // ret = isBalancedParantheses(myStr);

    // if(ret == 0)
    // {
    //     printf("paranthesis are balanced\n");
    // }
    // else if (ret == -1)
    // {
    //     printf("paranthesis are not balanced\n");
    // }
    // else if (ret == -2)
    // {
    //     printf("Wrong expression \n");
    // }

    push(&myStack, 5);
    push(&myStack, 6);
    push(&myStack, 7);
    push(&myStack, 11);
    push(&myStack, 13);
    printf("-------------------ALL STACK-------------------------------\n");
    printStack(&myStack);
    printf("-------------------POP-------------------------------\n");
    pop(&myStack, &myVal);
    printf("%d\n", myVal);
    printf("-------------------Get TOP-------------------------------\n");
    getStackTop(&myStack, &top);
    printf("%d\n", top);
    printf("-------------------ALL STACK-------------------------------\n");
    printStack(&myStack);
    printf("--------------------------------------------------\n");
    push(&myStack, 8);
    push(&myStack, 10);
    push(&myStack, 55);
    push(&myStack, 99);
    push(&myStack, 54);
    push(&myStack, 52);
    push(&myStack, 77);
    printf("--------------------TOP------------------------------\n");
    getStackTop(&myStack, &top);
    printf("%d\n", top);

    printf("---------------------ALL STACK-----------------------------\n");
    printStack(&myStack);
    printf("------------------------POP--------------------------\n");
    pop(&myStack, &myVal);
    printf("%d\n", myVal);
    pop(&myStack, &myVal);
    printf("%d\n", myVal);
    pop(&myStack, &myVal);
    printf("%d\n", myVal);
    pop(&myStack, &myVal);
    printf("%d\n", myVal);
    printf("-----------------------TOP---------------------------\n");
    getStackTop(&myStack, &top);
    printf("%d\n", top);
    printf("------------------------ALL STACK--------------------------\n");
    printStack(&myStack);
    printf("-------------------------POP-------------------------\n");
    pop(&myStack, &myVal);
    printf("%d\n", myVal);
    pop(&myStack, &myVal);
    printf("%d\n", myVal);
    pop(&myStack, &myVal);
    printf("%d\n", myVal);
    pop(&myStack, &myVal);
    printf("%d\n", myVal);
    pop(&myStack, &myVal);
    printf("%d\n", myVal);
    pop(&myStack, &myVal);
    printf("%d\n", myVal);
    pop(&myStack, &myVal);
    printf("%d\n", myVal);
    printf("------------------------TOP--------------------------\n");
    ret = getStackTop(&myStack, &top);
    if (ret == C_NOK )
    {
        printf("Stack is Empty\n");
    }
    else
        printf("%d\n", top);
    printf("-------------------------ALL STACK-------------------------\n");
    printStack(&myStack);
    
    return 0;
}

