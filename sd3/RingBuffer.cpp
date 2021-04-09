#include "ringBuffer.h"

void CreateRingBuffer(Ringbuffer* ringBuffer)
{
    ringBuffer->Data = new int[ringBuffer->Size];
    ringBuffer->FreeSpace = ringBuffer->Size;
    ringBuffer->OccupiedSpace = 0;
}

int GetFreeSpace(Ringbuffer* ringBuffer)
{
    return ringBuffer->Size - ringBuffer->OccupiedSpace;
}

int GetOccupiedSpace(Ringbuffer* ringBuffer)
{
    return ringBuffer->OccupiedSpace;
}

int Get(Ringbuffer* ringBuffer, bool isOccupiedSpace)
{
    int result = ringBuffer->Data[0];
    for (int i = 1; i <= ringBuffer->OccupiedSpace; ++i)
    {
        ringBuffer->Data[i - 1] = ringBuffer->Data[i];
        ringBuffer->OccupiedSpace--;
    }
    return result;
    /*if (ringBuffer->OccupiedSpace <= 0)
    {
        isOccupiedSpace = true;
        delete[] ringBuffer->Data;
    }*/
   
}
void AddRingBuffer(Ringbuffer* ringBuffer, int value)
{
    ringBuffer->Data[ringBuffer->OccupiedSpace++ % ringBuffer->Size] = value;
    if (ringBuffer->OccupiedSpace > 4)
    {
        ringBuffer->OccupiedSpace = 4;
    }
}

void ClearRingBuffer(Ringbuffer* ringBuffer)
{
    delete[] ringBuffer->Data;
}

