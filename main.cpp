/***********************************************************************************************************************
*                                               Курс ПРОГРАММИРОВАНИЕ                                                  *
************************************************************************************************************************
*   Project type :Win64 Console Application                                                                            *
*   Project name :Lab2                                                                                                 *
*   File name    :Lab2.exe                                                                                             *
*   Language     :CPP14, CLION                                                                                          *
*   Programmers  :Папуашвили Георгий Давидович Шилини Иван Алексеевич, М3О-210Б-21                                     *
*   Modified By   :                                                                                                     *
*   Created      :18.10.2022                                                                                           *
*   Last revision:19.10.2022                                                                                           *
*______________________________________________________________________________________________________________________*
* Comment: Лабораторная работа №8 (лабораторная работа №2, 2-й курс)                                                   *
***********************************************************************************************************************/

#include "functions.h"


/***********************************************************************************************************************
*                                               ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ                                                  *
***********************************************************************************************************************/

const char *FILE_INPUT = "input.txt";                           // Файл со входными данными
const char *FILE_OUTPUT[] = {"Time_Comparisons.csv"};           // Файл с информацией о времени и кол-ве сравнений
ofstream stream_out(*FILE_OUTPUT);                                     // Открываем новый поток вывода с выходным файлом




/***********************************************************************************************************************
*                                                ОСНОВНАЯ ПРОГРАММА                                                    *
***********************************************************************************************************************/

int main() {

    setlocale(LC_ALL, "ru");
    SetConsoleOutputCP(CP_UTF8);

    int *array;                                         // Указатель на несортированный массив
    int *arraySorted;                                   // Указатель на сортированный массив
    int size;                                           // Инициализация длины массива

    readAndCreate(&array, &arraySorted, size, &*FILE_INPUT);           // Вызов функции чтения файла
    fillingOfArrays(&array, &arraySorted, size);                                       // Вызов функции наполнения массивов

    //cout << "-------rand--------\n";
    //arraysOutput(&array, size);                                                                       // Вызов функции вывода массива в консоль
    int leftBound = 0;                                  // Задание левой границы
    int rightBound = size - 1;                          // Задание правой границы
    quickRecursiveSort(&arraySorted, leftBound, rightBound);                              // Вызов функции быстрой рекурсивной сортировки

//    cout << "-------rand sort--------\n";
//    arraysOutput(&arraySorted, size);                                                                 // Вызов функции сортировки массива
//    cout << "=============================main part===========================================\n";
    // Цикл смены позиции "ключа"
    for (int i = 0; i < 3; i++) {
        int keyOfSLS = changeKey(&array, i, size);                                    // Ключ для смены индекса для SLS
        int keyOfT = changeKey(&arraySorted, i, size);                                // Ключ для смены индекса для T_find

        //SLS
        cout << "SLS" << ";;" << endl;
        auto begin1 = chrono::steady_clock::now();                       // Установка таймера и начало отсчета
        sentinelLinearSearch(&array, size, keyOfSLS);                                    // Вызов функции SLS
        auto end1 = std::chrono::steady_clock::now();                                       // Остановка таймера
        auto elapsed_ms1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1); // Получение времени

        cout << "time(ms)= ";
        stream_out << elapsed_ms1.count() << ";;" << endl;                            // Запись времени в файл
        cout << elapsed_ms1.count() << ";" << endl;
        cout << "-----------------------------------------\n";

        //T_FIND
        cout << "T-find" << ";;" << endl;
        auto begin2 = chrono::steady_clock::now();                      // Установка таймера и начало отсчета
        T_find(&arraySorted, size, keyOfT);                                               // Вызов функции T_find
        auto end2 = std::chrono::steady_clock::now();                   // Остановка таймера
        auto elapsed_ms2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2); // Получение времени
        cout << "time(ms)= ";
        stream_out << elapsed_ms2.count() << ";;" << endl;                            // Запись времени в файл
        cout << elapsed_ms2.count() << ";" << endl;
        cout << "-----------------------------------------\n";
    }//for

    deleteArrs(array, arraySorted);                                                 // Очищение памяти
    return 0;
}