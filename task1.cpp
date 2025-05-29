#include <iostream>
#include <cstring> // для функції strlen

// Template function to calculate the average
template <typename T>
T average(T* arr, int size) {
    T sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i]; // додаємо елемент до суми
    }
    return sum / size; // повертаємо середнє значення
}

// Template specialization for const char*
template <>
const char* average<const char*>(const char** arr, int size) {
    int totalLength = 0;
    for (int i = 0; i < size; ++i) {
        totalLength += std::strlen(arr[i]); // додаємо довжину рядка
    }
    int avgLength = totalLength / size;

    std::cout << "Average string length: " << avgLength << std::endl;

    // Повертаємо перший рядок як заглушку, бо обчислити "середній рядок" складно
    return arr[0];
}

int main() {
    // Тест з масивом чисел
    int numbers[] = {1, 2, 3, 4, 5};
    std::cout << "Average (int): " << average(numbers, 5) << std::endl;

    // Тест з масивом рядків
    const char* words[] = {"hello", "world", "C++"};
    average(words, 3); // виведе середню довжину рядків

    return 0;
}
