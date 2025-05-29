#include <iostream>
#include <cstring> // для strcmp

// Шаблон функції сортування методом вилучення
template <typename T>
void selectionSort(T* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i; // індекс мінімального елемента
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // оновлюємо індекс мінімального
            }
        }
        // обмін елементів
        if (minIndex != i) {
            T temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Спеціалізація для char*
template <>
void selectionSort<char*>(char** arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i; // індекс мінімального рядка
        for (int j = i + 1; j < size; ++j) {
            if (std::strcmp(arr[j], arr[minIndex]) < 0) {
                minIndex = j; // оновлюємо індекс мінімального
            }
        }
        // обмін рядків
        if (minIndex != i) {
            char* temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    // Тест з числами
    int nums[] = {64, 25, 12, 22, 11};
    int sizeNums = sizeof(nums) / sizeof(nums[0]);

    selectionSort(nums, sizeNums); // сортуємо числа

    std::cout << "Sorted numbers: ";
    for (int i = 0; i < sizeNums; ++i)
        std::cout << nums[i] << " ";
    std::cout << std::endl;

    // Тест з рядками
    char* words[] = { (char*)"banana", (char*)"apple", (char*)"cherry" };
    int sizeWords = sizeof(words) / sizeof(words[0]);

    selectionSort(words, sizeWords); // сортуємо рядки

    std::cout << "Sorted strings: ";
    for (int i = 0; i < sizeWords; ++i)
        std::cout << words[i] << " ";
    std::cout << std::endl;

    return 0;
}
