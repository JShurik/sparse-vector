#include <iostream>
#include "SparseVector.h"

int main() {
    setlocale(LC_ALL, "Russian");

    SparseVector v1(5); //Задаем вектор (1.5, 0.0, 0.0, -2.3, 0.0)
    v1.set(0, 1.5);
    v1.set(3, -2.3);

    SparseVector v2(5); //Задаем вектор (0.0, 3.0, 0.0, 2.3, 0.0)
    v2.set(1, 3.0);
    v2.set(3, 2.3);

    SparseVector sum = v1 + v2;
    SparseVector diff = v1 - v2;
    double mult = v1 * v2;

    std::cout << "Сумма: "; sum.print();
    std::cout << "Разность: "; diff.print();
    std::cout << "Скалярное произведение: " << mult << std::endl;

    return 0;
}
