#include "Security.h"

#include "Security.h"

#include <iostream>

using namespace std;


int Security(const int min, const int max, string line)
{
    string list;
    int value = 0;
    bool wrong = true;
    while (wrong)
    {
        int temp, current = 0;
        cin >> line;
        wrong = false;
        for (int i = 0; i < line.size(); i++)
        {
            current += line[i] - 48;

            if (line.size() > 1 && i < line.size() - 1)
            {
                current *= 10;
            }
        }
        if (current >= min && current <= max)
        {
            for (int i = 0; i < line.size(); i++)
            {
                temp = line[i];

                if (temp < 48 || temp  > 57)
                {
                    cout << endl << "Введено неверное значение. Повторите попытку  ";
                    wrong = true;
                    break;
                }
            }
        }
        else
        {
            cout << endl << "Введено неверное значение. Повторите попытку  ";
            wrong = true;
        }
        if (!wrong)
        {
            value = current;
        }
    }
    return value;
}

