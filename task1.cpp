/*Сформировать случайным образом вектор из 20 элементов от 1 до 10000
Вывести его на экран. Удалить из него все элементы, в которых есть цифра k. Обязательно
использовать предикаты.*/

#include <iostream>
#include <vector>
#include <time.h>
#include <iterator>

bool ContainsNum(int x, int k)
{
    if (x > 0 && x < 10)
    {
        if (x == k)
            return true;
        else
            return false;
    }
    else
    {
        if (x > 9 && x < 100)
        {
            if (x % 10 == k || (x / 10)%10 == k)
                return true;
            else
                return false;
        }
        else
        {
            if (x > 99 && x < 1000)
            {
                if (x % 10 == k || (x / 10) % 10 == k || (x / 100)%10 == k)
                    return true;
                else
                    return false;
            }
            else
                if (x % 10 == k || (x / 10) % 10 == k || (x / 100) % 10 == k || (x / 1000) % 10 == k)
                    return true;
                else
                    return false;
        }
    }
}

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int a = 0;
    vector <int> vec;
    srand(time(NULL));
    for (int i = 0; i < 20; i++)
    {
        a = 1 + rand() % 9999;
        vec.push_back(a);
    }
    for (int i = 0; i < 20; i++)
    {
        cout << vec[i] << " ";
    }
    int k;
    cout << endl << "Введите число k: ";
    cin >> k;
    
    int count = 0;
    for (int i = 0; i < 20; i++) // считаем количество элементов, содержащих k
    {
        if (ContainsNum(vec[i], k))
        {
            count += 1;
        }
    }

    for (int i = 0; i < 20-count; i++)
    {
        if (ContainsNum(vec[i], k))
        {
            vector <int> ::iterator it = vec.begin();
            advance(it, i);
            vec.erase(it);
            i -= 1;
        }
    }

    vector <int> ::iterator it = vec.end(); // проверка последнего элемента
    int x = vec.at(vec.size()-1);
    if (ContainsNum(x, k))
        vec.erase(it-1);
;

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
}

/*
6436 7600 1942 6412 3415 6674 3347 9843 207 3305 4898 1319 2770 2481 7726 4933 475 4756 82 6561
Введите число k: 5
6436 7600 1942 6412 6674 3347 9843 207 4898 1319 2770 2481 7726 4933 82
*/

/*
7840 9127 5825 8948 2232 1231 8212 6298 9533 3845 6834 261 6997 6745 4868 1978 7875 7745 859 6856
Введите число k: 6
7840 9127 5825 8948 2232 1231 8212 9533 3845 1978 7875 7745 859
*/