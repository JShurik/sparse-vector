#include "SparseVector.h"
#include <iostream>

SparseVector::SparseVector(int n) : size(n) {
    if (n <= 0) {
        throw std::invalid_argument("Размер вектора должен быть положительным");
    }
}

void SparseVector::set(int index, double value) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Индекс выходит за границы вектора");
    }
    if (value != 0) {
        values[index] = value;
    }
    else {
        values.erase(index);
    }
}

double SparseVector::get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Индекс выходит за границы вектора");
    }
    auto it = values.find(index);
    return it != values.end() ? it->second : 0.0;
}

SparseVector SparseVector::operator+(const SparseVector& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Размеры векторов не совпадают");
    }
    SparseVector result(size);
    for (const auto& pair : values) {
        result.set(pair.first, pair.second + other.get(pair.first));
    }
    for (const auto& pair : other.values) {
        if (values.find(pair.first) == values.end()) {
            result.set(pair.first, pair.second);
        }
    }
    return result;
}

SparseVector SparseVector::operator-(const SparseVector& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Размеры векторов не совпадают");
    }
    SparseVector result(size);
    for (const auto& pair : values) {
        result.set(pair.first, pair.second - other.get(pair.first));
    }
    for (const auto& pair : other.values) {
        if (values.find(pair.first) == values.end()) {
            result.set(pair.first, -pair.second);
        }
    }
    return result;
}

double SparseVector::operator*(const SparseVector& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Размеры векторов не совпадают");
    }
    double dot_product = 0.0;
    for (const auto& pair : values) {
        dot_product += pair.second * other.get(pair.first);
    }
    return dot_product;
}

void SparseVector::print() const {
    for (const auto& pair : values) {
        std::cout << "(" << pair.first << ": " << pair.second << ") ";
    }
    std::cout << std::endl;
}