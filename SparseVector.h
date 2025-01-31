#pragma once
#include <map>
#include <stdexcept>

class SparseVector {
private:
    int size; //Размер вектора
    std::map<int, double> values; //координаты ненулевых значений (index, value)

public:
    SparseVector(int n); //конструктор для вектора размера n
    void set(int index, double value); 
    double get(int index) const;

    SparseVector operator+(const SparseVector& other) const;
    SparseVector operator-(const SparseVector& other) const;
    double operator*(const SparseVector& other) const;

    void print() const;
};