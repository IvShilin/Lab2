/***********************************************************************************************************************
*                                               РЕАЛИЗАЦИЯ ФУНКЦИЙ                                                     *
***********************************************************************************************************************/

#include "functions.h"

// Функция считывания и создания массивов
void readAndCreate(
        int **array,                                // Динамический массив указателей
        int **arrayFutureSourted,                   // Отсортированный массив указателей
        int &size,                                  // Длина массива
        const char *FILE_INPUT                      // Имя выходного файла
) {
    ifstream streamIn(FILE_INPUT);

    streamIn >> size;                               // Считывание с файла длины массива
    cout << "Кол-во элементов массива из случайных чисел: " << size << endl;
    (*array) = new int[size]();
    (*arrayFutureSourted) = new int[size]();
}

// Функция наполнения массивов
void fillingOfArrays(
        int **array,                                // Динамический массив указателей
        int **arrayFutureSourted,                   // Отсортированный массив указателей
        const int size                              // Длина массива
) {
    srand(time(nullptr));                           // Устанавливаем "семечко" для rand()
    for (int i = 0; i < size; i++) {
        (*array)[i] = rand() % 100000;              // Заполнение массива случайными значениями
        (*arrayFutureSourted)[i] = (*array)[i];
    }
}

// Функция вывода массива
void arraysOutput(
        int **array,                                // Динамический массив указателей
        const int size                              // Длина массива
) {
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "]\t" << (*array)[i] << endl;
    }
}

// Функция быстрой рекурсивной сортировки
void quickRecursiveSort(
        int **array,                                // Динамический массив указателей
        int left,                                   // Левая граница массива
        int right                                   // Правая граница массива
) {
    //Указатели в начало и в конец массива
    int L = left;                                   // Левая граница
    int R = right;                                  // Правая граница

    //Центральный элемент массива
    int mid = (*array)[(L + R) / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while ((*array)[L] < mid) {
            L++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while ((*array)[R] > mid) {
            R--;
        }

        //Меняем элементы местами
        if (L <= R) {
            int tmp = (*array)[L];
            (*array)[L] = (*array)[R];
            (*array)[R] = tmp;
            L++;
            R--;
        }
    } while (L < R);
    if (left < R) quickRecursiveSort(array, left, R);
    if (L < right) quickRecursiveSort(array, L, right);
}

// Функция линейного поиска
// Функция линейного поиска
void sentinelLinearSearch(
        int **array,                                  // Динамический массив указателей
        const int SIZE,                               // Длина массива
        int key                                       // Ключ индексов
) {
    cout << "Быстрый последовательный поиск\n";
    int count_comp = 0;                               // Счётчик сравнений
    int last = (*array)[SIZE - 1];                    // Последний элемент массива
    cout << "Искомое число: " << key << endl;
    (*array)[SIZE - 1] = key;                         // Число, которое мы ищем делаем последним элементом массива
    int i = 0;                                        // Переменная-счетчик
    while ((*array)[i] != key) {
        i++;
        count_comp++;
    }
    (*array)[SIZE - 1] = last;                         // Возвращаем последний элемент обратно
    if ((i < SIZE - 1) || ((*array)[SIZE - 1] == key)) {
        count_comp++;
        cout << key << " имеет индекс " << i << "\n\n";
    } // if
    cout << "Количество сравнений => " << count_comp << endl;
//    cout << " NOT_FOUND\n";
}

// Функция смена ключа
int changeKey(
        int **Array,                                  // Динамический массив указателей
        int number,                                   // Переменная для передачи значения ключа
        const int SIZE                                // Ключ индексов
) {
    int key = (*Array)[0];                            // Инициализация ключа поиска
    switch (number) {                                 // Смена ключ поиска
        default:
            return key;
        case 1:
            key = (*Array)[SIZE / 2];
            return key;
        case 2:
            key = (*Array)[SIZE - 1];
            return key;
    }
}

// Функция поиска
void T_find(int** array, int size, int key) {
    cout << "Искомое число: " << key << endl;
    int temp = (*array)[size - 1];                    // Временная-переменная
    (*array)[size - 1] = INT32_MAX;
    int i = 0;
    while ((*array)[i] < key && i < size) {                // Проходим последовательно весь массив
        i++;
    }
    // Вовращаем обратно последний элемент массива
    (*array)[size - 1] = temp;
    if ((*array)[i] == key) {
        cout << key << " имеет индекс: " << i << "\n\n";
    }
    else {
        cout << " Not found!\n";
    }
}

// Функция очищения памяти
void deleteArrs(
        const int *ARRAY,                           // Динамический массив указателей
        const int *ARRAY_SORTED                     // Отсортированный массив указателей
) {
    delete[] ARRAY;
    delete[] ARRAY_SORTED;
}


