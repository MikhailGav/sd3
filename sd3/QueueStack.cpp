#include "QueueStack.h"

void Init(QueueStack* QueueStack)
{
	QueueStack->firstStack = new Stack;
	QueueStack->secondStack = new Stack;

	CreateStack(QueueStack->firstStack);
	CreateStack(QueueStack->secondStack);

	QueueStack->Size = 0;
}

bool Enqueue(QueueStack* QueueStack, int value)
{
	Push(QueueStack->firstStack, value);
	QueueStack->Size++;
	return true;
}

bool Dequeue(QueueStack* QueueStack)
{
	int value;
	if (QueueStack->Size == 0)
	{
		return false;
	}

	QueueStack->Size--;

	if (QueueStack->secondStack->Top != 0)
	{
		int value;
		Pop(QueueStack->secondStack, value);
		return true;
	}

	int tmp = 0;
	while (Pop(QueueStack->firstStack, value))
	{
		Push(QueueStack->secondStack, tmp);
	}

	Pop(QueueStack->secondStack, value);
	return true;
}

void Clear(QueueStack* QueueStack)
{
	ÑlearStack(QueueStack->firstStack);
	ÑlearStack(QueueStack->secondStack);

	delete QueueStack->firstStack;
	delete QueueStack->secondStack;

	QueueStack->Size = 0;
}