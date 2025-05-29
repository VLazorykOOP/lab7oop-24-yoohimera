#include <iostream>

// Клас масиву
template <typename T>
class MyArray {
private:
    T* data;       // масив даних
    int size;      // розмір масиву

public:
    // Конструктор
    MyArray(int size) {
        this->size = size;
        data = new T[size];
    }

    // Деструктор
    ~MyArray() {
        delete[] data;
    }

    // Доступ до елементів через оператор []
    T& operator[](int index) {
        return data[index];
    }

    // Повертає розмір масиву
    int getSize() const {
        return size;
    }

    // Доступ до елементів (для ітератора)
    T* getData() const {
        return data;
    }
};

// Клас ітератора
template <typename T>
class ArrayIterator {
private:
    T* ptr; // вказівник на поточний елемент

public:
    // Конструктор
    ArrayIterator(T* p) : ptr(p) {}

    // Оператор розіменування
    T& operator*() {
        return *ptr;
    }

    // Перехід до наступного елемента
    ArrayIterator& operator++() {
        ++ptr;
        return *this;
    }

    // Перевірка на нерівність
    bool operator!=(const ArrayIterator& other) const {
        return ptr != other.ptr;
    }
};

// Тестова програма
int main() {
    MyArray<int> arr(5); // створюємо масив з 5 елементів

    // Заповнюємо масив значеннями
    for (int i = 0; i < arr.getSize(); ++i) {
        arr[i] = (i + 1) * 10; // 10, 20, 30, 40, 50
    }

    // Створюємо ітератори
    ArrayIterator<int> begin(arr.getData());                         // початок
    ArrayIterator<int> end(arr.getData() + arr.getSize());           // кінець

    std::cout << "Array elements using custom iterator: ";

    // Обхід масиву за допомогою ітератора
    for (ArrayIterator<int> it = begin; it != end; ++it) {
        std::cout << *it << " "; // виводимо елемент
    }

    std::cout << std::endl;
    return 0;
}
