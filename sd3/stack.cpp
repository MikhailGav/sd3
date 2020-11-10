#include "stack.h"


void CreateStack(Stack* stack, int data)
{
	stack->bufferCapacity = 2;
	//stack->top = 0;
	stack->buffer = new int[stack->bufferCapacity];
	stack->buffer[stack->top] = data;
	stack->top++;
}

void Push(Stack* stack, int data)
{
	if (stack->top >= stack->bufferCapacity)
	{
		stack->bufferCapacity = stack->bufferCapacity * 2;
	}
	stack->buffer[stack->top] = data;
	stack->top++;

}
int StackTop( Stack* stack)
{
	return stack->buffer[stack->top - 1];
}
void Remove(Stack* stack)
{
	stack->top--;
}
void ÑlearStack(Stack* stack, bool isCreateStack)
{
	for (int i = 0; i < stack->top+1; i++)
	{
		Remove(stack);
	}
	if (stack->top == 0)
	{
		delete[] stack->buffer;
	}
	isCreateStack = false;

}


