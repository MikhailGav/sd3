#include "stack.h"
#include "RingBuffer.h"
#include "Security.h"
#include "QueueRingBuffer.h"
#include "QueueStack.h"
#include "common.h"
// сделать один стиль имен файлов
#include <iostream>

#ifndef SECURITY_WIN32 
#define SECURITY_WIN32 

using namespace std;

enum class Menu   
{
    Stack           = 1,
    RingBuffer      = 2,
    QueueStack      = 3,
    QueueRingBuffer = 4,
};

int main()
{
    setlocale(LC_ALL, "Russian");
    bool isCreateRingBuffer= true;
    bool isOccupiedSpace = false;
    int valueForMenu = 0;
    do 
    {
        ShowMainMenu();
        cout << "выберите номер меню ";
          
        valueForMenu = GetInteger();
        switch (static_cast<Menu>(valueForMenu))
        {     
            case Menu::Stack:
            {
                    Stack* stack = new Stack;
                    int count = 0;
                    CreateStack(stack);
                    ServeStack(stack);
                    СlearStack(stack);
                    break;
            }
            case Menu::RingBuffer:
            {
                Ringbuffer* ringBuffer = new Ringbuffer;
                CreateRingBuffer(ringBuffer);
                ServeRingBuffer(ringBuffer, isOccupiedSpace);
                ClearRingBuffer(ringBuffer);
                break;
            }
            case Menu::QueueStack:
            {
                    QueueStack* queueStack = new QueueStack;
                    Init(queueStack);
                    ServeQueueStack(queueStack);
                    Clear(queueStack);
                    break;
            }
                case Menu::QueueRingBuffer:
                {
                    int value;
                    Queue* queueBuffer = new Queue;
                    CreateQueue(queueBuffer);
                    ServeQueueBuffer(queueBuffer, isCreateRingBuffer);
                    RemoveQueue(queueBuffer);
                    break;
                }
            default:
            {
                system("cls");
                break;
            }
        }    
    } while (valueForMenu != 0);
    return 0;
}
#endif