#pragma once
#include "includes.hpp"

namespace GE
{

//Klasa implementująca operacje matematyczne na wektorach, wektor może mieć wiele różnych typów (np. wektor int, wektor float)
template <typename T> class Vector2 {
public:

    T x;
    T y; 

    Vector2();
    Vector2(T X, T Y);
    Vector2(const Vector2<T>& vector);
};

//Przeciążanie operatorów poza klasą, aby móc używać w obu kierunkach (i brak definici w .cpp bo nie mam pojęcia jak to zrobić aby działało)
template <typename T> Vector2<T>::Vector2() : x(0), y(0) {}

template <typename T> Vector2<T>::Vector2(T X, T Y) : x(X), y(Y) {}

template <typename T> Vector2<T>::Vector2(const Vector2<T>& v) : x(v.x), y(v.y) {}

template <typename T> Vector2<T> operator -(const Vector2<T>& right) {
    return Vector2<T>(-right.x, -right.y);
}

template <typename T> Vector2<T>& operator +=(Vector2<T>& left, const Vector2<T>& right) {
    left.x += right.x;
    left.y += right.y;

    return left;
}

template <typename T>  Vector2<T>& operator -=(Vector2<T>& left, const Vector2<T>& right) {
    left.x -= right.x;
    left.y -= right.y;

    return left;
}

template <typename T> Vector2<T> operator +(const Vector2<T>& left, const Vector2<T>& right) {
    return Vector2<T>(left.x + right.x, left.y + right.y);
}

template <typename T> Vector2<T> operator -(const Vector2<T>& left, const Vector2<T>& right) {
    return Vector2<T>(left.x - right.x, left.y - right.y);
}

template <typename T> Vector2<T> operator *(const Vector2<T>& left, T right) {
    return Vector2<T>(left.x * right, left.y * right);
}

template <typename T> Vector2<T> operator *(T left, const Vector2<T>& right) {
    return Vector2<T>(right.x * left, right.y * left);
}

template <typename T> Vector2<T>& operator *=(Vector2<T>& left, T right) {
    left.x *= right;
    left.y *= right;

    return left;
}

template <typename T> Vector2<T> operator /(const Vector2<T>& left, T right) {
    return Vector2<T>(left.x / right, left.y / right);
}

template <typename T> Vector2<T>& operator /=(Vector2<T>& left, T right) {
    left.x /= right;
    left.y /= right;

    return left;
}

template <typename T> bool operator ==(const Vector2<T>& left, const Vector2<T>& right) {
    return (left.x == right.x) && (left.y == right.y);
}

template <typename T> bool operator !=(const Vector2<T>& left, const Vector2<T>& right) {
    return (left.x != right.x) || (left.y != right.y);
}

//Predefinicja dwóch typów - uint16_t i float
typedef Vector2<uint16_t> Vector2i;
typedef Vector2<float> Vector2f;

}