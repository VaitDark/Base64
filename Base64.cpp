﻿// Base64.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include "Table.h"

using namespace std;
int shift = 0;
char a;
int bc[10000];
int main()
{
    ifstream inp("input.txt");
        int arr[8]{};
        //int bc[1000];
        int  ost, i;
        int j = 0;
        i = 0;
        while (inp.get(a)) {
        while (a != 0) {
            ost = a % 2;
            a /= 2;
            arr[i] = ost;
            i++;
        }
        i = 0;
        j = 8;
        while(!j==0){
            
            bc[8+shift - j] = arr[j-1];
            j--;
        }
        shift += 8;
    }
        inp.close();
        ofstream output("output.txt");
        shift -= 8;
        for (int i = 0; i < shift + 8; i++) {
            cout << bc[i];
        }
        cout << endl;
        ost = (shift + 8) % 6;
        ost = 6 - ost;
        //ost /= 2;
        for (int i =0; i <ost; i++) {
             bc[(shift+8-1)+i]=0;
        }
        for (int i = 0; i < shift + 8 + (ost ); i++) {
            cout << bc[i];
        }
        bool b = true;
        i = 1;
        int shetchic = 0;
        int boof[6];
        while (b) {
            if (shetchic<=shift+8+ost) {
                boof[i-1] = bc[shetchic];
                if (i % 6==0) {
                    int bfnum;
                    bfnum = boof[5] * 1;
                    bfnum += boof[4] * 2;
                    bfnum += boof[3] * 4;
                    bfnum += boof[2] * 8;
                    bfnum += boof[1] * 16;
                    bfnum += boof[0] * 32;
                    a= table(bfnum);
                    output << a;
                }
            }
            else {
                b = false;
            }
            if (i % 6 == 0) {
                i = 1;
            }
            else {
                i++;
            }
            shetchic++;
        }
        for (int i = 0; i < ost/2; i++) {
            output << "=";
        }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
