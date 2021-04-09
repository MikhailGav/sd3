#pragma once
#ifndef RINGBUFFER
#define RINGBUFFER

/// @brief ��������� �����
struct Ringbuffer
{
    int* Data;          
    const int  Size = 4;        
    int  FreeSpace;     
    int  OccupiedSpace; 
};

/// @brief            �������� ���������� ������
/// @param ringbuffer ���������
void CreateRingBuffer(Ringbuffer* ringBuffer);

/// @brief            �������� ��������� �����
/// @param ringbuffer �����, ��� ������� ������������ �������� 
/// @return           ������ ��������
int GetFreeSpace(Ringbuffer * ringbuffer);

/// @brief            �������� ������� �����
/// @param ringbuffer �����, ��� ������� ������������ �������� 
/// @return           ������ ��������
int GetOccupiedSpace(Ringbuffer* ringbuffer);

/// @brief            �������� ���������
/// @param ringBuffer �����, ��� ������� ������������ �������� 
/// @param isOccupiedSpace ����������
/// @return           ��������� ��������
int Get(Ringbuffer* ringBuffer, bool isOccupiedSpace);

/// @brief            ������� �����������
/// @param ringBuffer �����, ��� ������� ������������ �������� 
/// @param value      ��������  
void AddRingBuffer(Ringbuffer* ringBuffer, int value );

/// @brief            ������� ������
/// @param ringBuffer �����, ��� ������� ������������ �������� 
void ClearRingBuffer(Ringbuffer* ringBuffer);
#endif	// RINGBUFFER