/* Считать из трех текстовых файлов три множества слов (set1, set2 и set3).Слова в
разных множествах могут повторяться. Сформировать еще одно множество, которое
будет содержать слова, имеющиеся в первом или втором множестве, но которых нет в
третьем множестве.Обязательно использовать алгоритмы работы с множествами!*/

#include <iostream>
#include <fstream>
#include <set>
#include <iterator>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    set <string> set1, set2, set3, set4;
    ifstream f1("file1.txt");
    ifstream f2("file2.txt");
    ifstream f3("file3.txt");

    if (f1)
    {
        string n;
        while (f1 >> n)
            set1.insert(n);
        f1.close();
    }
    else
        cout << "Ошибка при открытии файла file1";

    if (f2)
    {
        string n;
        while (f2 >> n)
            set2.insert(n);
        f2.close();
    }
    else
        cout << "Ошибка при открытии файла file2";

    if (f3)
    {
        string n;
        while (f3 >> n)
            set3.insert(n);
        f3.close();
    }
    else
        cout << "Ошибка при открытии файла file3";

    for (set <string> ::iterator it = set1.begin(); it != set1.end(); it++)
    {
        set4.insert(*it);
    }
    
    for (set <string> ::iterator it = set2.begin(); it != set2.end(); it++)
    {
        set4.insert(*it);
    }

    for (set <string> ::iterator it = set3.begin(); it != set3.end(); it++)
    {
        set <string> ::iterator search;
        set <string> ::iterator beg = set4.begin();
        set <string> ::iterator end = set4.end();
        search = find(beg, end, *it);
        if (search != end)
            set4.erase(*it);
    }

    for (set <string> ::iterator it = set4.begin(); it != set4.end(); it++)
        cout << *it << " ";
}

/*
file1 = home string plate fork apple
file2 = spoon leader song sleep pear banana string
file3 = apple pink fork grape wind plate banana
ответ:
home leader pear sleep song spoon string
*/