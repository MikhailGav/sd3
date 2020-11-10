#pragma once
#ifndef STACK
#define STACK
struct Stack
{
	int* buffer;
	int bufferCapacity = 0;
	int top = 0;
};
void CreateStack(Stack* stack, int data);
void Push(Stack* stack, int data);
int StackTop(Stack* stack);
void Remove(Stack* stack);
void ÑlearStack(Stack* stack, bool isCreateStack);
#endif	// ifndef STACK