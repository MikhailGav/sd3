#include "stack.h"


void CreateStack(Stack* stack)
{
	stack->BufferCapacity = 8;
	stack->Buffer = new int[stack->BufferCapacity];
}

void Push(Stack* stack, int data)
{
	if (stack->Top >= stack->BufferCapacity)
	{
		stack->BufferCapacity = stack->BufferCapacity*2;
	}
	stack->Buffer[stack->Top] = data;
	stack->Top++;
	//int temp = stack->Top;
}

int StackTop( Stack* stack)
{
	if (stack->Top <= 1)
	{
		return 1;
	}
	return stack->Buffer[stack->Top - 1];
}

bool Pop( Stack* stack, int& value )
{
	if ( stack->Top <= 1)
	{
		return false;
	}

	value = stack->Buffer[--(stack->Top)];

	return true;
}

void ÑlearStack(Stack* stack)
{
	delete[] stack->Buffer;
	return;
}


