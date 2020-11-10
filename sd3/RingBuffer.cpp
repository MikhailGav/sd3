#include "RingBuffer.h"

void CreateRingBuffer(Ringbuffer* ringbuffer)
{
    ringbuffer->size = 256;
    ringbuffer->data = new int[ringbuffer->size];
    ringbuffer->freeSpace = ringbuffer->size;
    ringbuffer->occupiedSpace = 0;
}

int GetFreeSpace(Ringbuffer* ringbuffer)
{
    return ringbuffer->size - ringbuffer->occupiedSpace;
}

int GetOccupiedSpace(Ringbuffer* ringbuffer)
{
    return ringbuffer->occupiedSpace;
}

int Get(Ringbuffer* ringbuffer)
{
    int res = ringbuffer->data[0]; 
    for (int i = 1; i < ringbuffer->occupiedSpace; ++i)
    {
        ringbuffer->data[i - 1] = ringbuffer->data[i];
    }
    --ringbuffer->occupiedSpace;
    return res; 
}
void Add(Ringbuffer* ringbuffer, int value)
{
    if ((ringbuffer->size == 0) || (ringbuffer->size<0))
    {
        CreateRingBuffer(ringbuffer);
    }
    ringbuffer->data[ringbuffer->occupiedSpace++ % ringbuffer->size] = value;
}
