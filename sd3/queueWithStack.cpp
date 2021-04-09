#include "queueWithStack.h"

void Init(QueueWithStack* queue) 
{
	queue->MainStack = new Stack;
	queue->SecendoryStack = new Stack;

	Init(queue->MainStack);
	Init(queue->SecendoryStack);

	queue->Size = 0;
}

bool Enqueue(QueueWithStack* queue, int value)
{
	if (Push(queue->MainStack, value))
	{
		queue->Size++;
		return true;
	}
	return false;
}

bool Dequeue(QueueWithStack* queue, int& value)
{
	if (queue->Size == 0)
	{
		return false;
	}

	queue->Size--;
	if (queue->SecendoryStack->Count != 0)
	{
		Pop(queue->SecendoryStack, value);
		return true;
	}

	int tmp;
	while (Pop(queue->MainStack, tmp))
	{
		Push(queue->SecendoryStack, tmp);
	}
	
	Pop(queue->SecendoryStack, value);
	return true;
}

bool GetValue(QueueWithStack* queue, int& value, int position)
{
	/// @todo {}
	if (position < 0 || position >= queue->Size)
		return false;
	
	if (position < queue->MainStack->Count) 
	{
		return GetValue(queue->MainStack, value, position);
	}

	int tmpPosition = queue->SecendoryStack->Count + queue->MainStack->Count - position - 1;
	return GetValue(queue->SecendoryStack, value, tmpPosition);
}

void Clear(QueueWithStack* queue)
{
	Clear(queue->MainStack);
	Clear(queue->SecendoryStack);

	delete queue->MainStack;
	delete queue->SecendoryStack;

	queue->Size = 0;
}