#include "QueueRingBuffer.h"

#include <iostream>
using namespace std;
void CreateQueue(Queue* queueBuffer)
{
	queueBuffer->Size = 4;
	queueBuffer->Tail = queueBuffer->Head = queueBuffer->Length = 0;
	queueBuffer->Data = new int[queueBuffer->Size];

}

void Enqueue(Queue* queueBuffer, int data)
{
	if (queueBuffer->Tail == queueBuffer->Length)
	{
		queueBuffer->Tail = 0;
	}
	queueBuffer->Data[queueBuffer->Tail] = data;
	queueBuffer->Tail++;
	queueBuffer->Length++;
}

int Dequeue(Queue* queueBuffer)
{
	if (queueBuffer->Head == queueBuffer->Length)
	{
		queueBuffer->Head = 0;
	}
	int temp = 0;
	temp = queueBuffer->Data[queueBuffer->Head];
	queueBuffer->Data[queueBuffer->Head] = 0;
	queueBuffer->Head++;
	queueBuffer->Length--;
	return temp;
}

void RemoveQueue(Queue* queueBuffer)
{
	delete[] queueBuffer->Data;
}


