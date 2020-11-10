#pragma once
#ifndef RINGBUFFER
#define RINGBUFFER

struct Ringbuffer
{
    int* data;          
    int  size;        
    int  freeSpace;     
    int  occupiedSpace; 
};
/// @brief 
/// @param ringbuffer 
void CreateRingBuffer(Ringbuffer* ringbuffer);
int GetFreeSpace(Ringbuffer * ringbuffer);
int GetOccupiedSpace(Ringbuffer* ringbuffer);
int Get(Ringbuffer* ringbuffer);
void Add(Ringbuffer* ringbuffer, int value);
#endif	// RINGBUFFER