#pragma once
#ifndef RINGBUFFER
#define RINGBUFFER

/// @brief кольцевой буфер
struct Ringbuffer
{
    int* Data;          
    const int  Size = 4;        
    int  FreeSpace;     
    int  OccupiedSpace; 
};

/// @brief            создание Кольцевого буфера
/// @param ringbuffer структура
void CreateRingBuffer(Ringbuffer* ringBuffer);

/// @brief            Получите свободное место
/// @param ringbuffer буфер, над которым производится действие 
/// @return           возрат значение
int GetFreeSpace(Ringbuffer * ringbuffer);

/// @brief            Получите занятое место
/// @param ringbuffer буфер, над которым производится действие 
/// @return           возрат значение
int GetOccupiedSpace(Ringbuffer* ringbuffer);

/// @brief            получить знакчение
/// @param ringBuffer буфер, над которым производится действие 
/// @param isOccupiedSpace переменная
/// @return           возращает значение
int Get(Ringbuffer* ringBuffer, bool isOccupiedSpace);

/// @brief            функция добовляющая
/// @param ringBuffer буфер, над которым производится действие 
/// @param value      значение  
void AddRingBuffer(Ringbuffer* ringBuffer, int value );

/// @brief            очистка буфера
/// @param ringBuffer буфер, над которым производится действие 
void ClearRingBuffer(Ringbuffer* ringBuffer);
#endif	// RINGBUFFER