#include <iostream>

// Шаблон класу циклічної черги
template <typename T>
class CircularQueue {
private:
    T* data;           // масив для зберігання елементів
    int front;         // індекс початку черги
    int rear;          // індекс кінця черги
    int capacity;      // максимальна кількість елементів
    int count;         // поточна кількість елементів

public:
    // Конструктор
    CircularQueue(int size) {
        capacity = size;
        data = new T[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    // Деструктор
    ~CircularQueue() {
        delete[] data;
    }

    // Додавання елемента в чергу
    void enqueue(T value) {
        if (isFull()) {
            std::cout << "Queue is full!" << std::endl; // черга переповнена
            return;
        }
        rear = (rear + 1) % capacity; // циклічне пересування вказівника rear
        data[rear] = value;           // вставка елемента
        count++;
    }

    // Видалення елемента з черги
    T dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl; // черга порожня
            return T(); // повертаємо стандартне значення
        }
        T val = data[front];          // зберігаємо елемент
        front = (front + 1) % capacity; // циклічне пересування вказівника front
        count--;
        return val; // повертаємо видалений елемент
    }

    // Перевірка, чи черга порожня
    bool isEmpty() const {
        return count == 0;
    }

    // Перевірка, чи черга заповнена
    bool isFull() const {
        return count == capacity;
    }

    // Повернення кількості елементів у черзі
    int size() const {
        return count;
    }

    // Виведення елементів черги
    void display() const {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl; // черга порожня
            return;
        }

        std::cout << "Queue elements: ";
        for (int i = 0; i < count; ++i) {
            std::cout << data[(front + i) % capacity] << " "; // обхід по колу
        }
        std::cout << std::endl;
    }
};

// Тестування в головній функції
int main() {
    CircularQueue<int> q(5); // створення черги розміром 5 для int

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display(); // виведення елементів

    q.dequeue();
    q.dequeue();

    q.display(); // виведення після видалення 2 елементів

    q.enqueue(60);
    q.enqueue(70);

    q.display(); // виведення після додавання ще 2 елементів

    return 0;
}
