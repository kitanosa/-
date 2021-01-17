#pragma once
#include<iostream>
#include<tuple>
#include <math.h>
// 5тиугольник 6тиугольник 8миугольник
double deg72 = (72*M_PI)/180;
double deg36 = (36*M_PI)/180;
double deg60 = (60 * M_PI) / 180;
double deg45 = (45 * M_PI) / 180;

template<typename T, typename S>// в СИ пришлось бы один из аргументов делать как указатель потому что в СИ не ссылочного типа
void get_coords_pentagon(T& tuple, S side) {// tuple это передача по ссылке. А это означает что после того как tuple.a.first и другие изменят свои значения то обратно в main
    tuple.a.first = side*cos(deg72);// вернется уже измененное значение и не те нули которые мы передали в tuple. Так что передача по ссылке -ТОП.
    tuple.a.second = 0;
    tuple.b.first = side*cos(deg72)+side;
    tuple.b.second = 0;
    tuple.c.first = 2*side*cos(deg72)+side;
    tuple.c.second = side*sin(deg72);
    tuple.d.first = side*cos(deg72)+0.5*side;
    tuple.d.second = side*sin(deg72)+side*sin(deg36);
    tuple.e.first = 0;
    tuple.e.second = side*sin(deg72);
}

template<typename T, typename S>
void get_coords_hexagon(T& tuple, S side) {
    tuple.a.first = 0.5 * side;
    tuple.a.second = 0;
    tuple.b.first = 1.5 * side;
    tuple.b.second = 0;
    tuple.c.first = 2 * side;
    tuple.c.second = side * sin(deg60);
    tuple.d.first = 1.5 * side;
    tuple.d.second = 2 * side * sin(deg60);
    tuple.e.first = 0.5 * side;
    tuple.e.second = side * sin(deg60);
    tuple.f.first = 0;
    tuple.f.second = sin(deg60);
}

template<typename T, typename S>
void get_coords_octagon(T& tuple, S side) {
    tuple.a.first = side*cos(deg45);
    tuple.a.second = 0;
    tuple.b.first = side * cos(deg45) + side;
    tuple.b.second = 0;
    tuple.c.first = 2*side * cos(deg45);
    tuple.c.second = side * sin(deg45);
    tuple.d.first = 2 * side * cos(deg45);
    tuple.d.second = side * sin(deg45) + side;
    tuple.e.first = side * cos(deg45) + side;
    tuple.e.second = 2 * side * cos(deg45) + side;
    tuple.f.first = side * cos(deg45);
    tuple.f.second = side * sin(deg45);
    tuple.g.first = 0;
    tuple.g.second = side * cos(deg45) + side;
    tuple.h.first = 0;
    tuple.h.second = side * cos(deg45);
}

template <typename T, int index> typename std::enable_if< index >= std::tuple_size<T>::value, void>::type print_tuple(T&) {
    std::cout << std::endl;
}

template <class T, int index> typename std::enable_if < index <std::tuple_size<T>::value, void> ::type print_tuple(T& tuple) {
    auto vertex = std::get<index>(tuple);
    print(vertex);
    print_tuple<T, index + 1>(tuple);
}

template<typename T>
void print(T& obj) {
    std::cout << obj.name << "'s coordinates are: " <<std::endl;
    obj.print();
}

template<typename T>
double square_of_pentagon(T& obj) {
    double side = obj.b.first - obj.a.first;
    return ((side*side)/4.0)*sqrt(25+10*sqrt(5));
}

template<typename T>
double square_of_hexagon(T& obj) {
    double side = obj.b.first - obj.a.first;
    return ((3*sqrt(3))/2)*side*side;
}

template<typename T>
double square_of_octagon(T& obj) {
    double side = obj.b.first - obj.a.first;
    return 2*side*side*(1 + sqrt(2));
}

template<typename T>
double square(T& tuple) {
    double t = 0;
    t = t + square_of_pentagon(std::get<0>(tuple)) + square_of_pentagon(std::get<1>(tuple));// std::get это рекурсивный перебор всех значений кортежа
    t = t + square_of_hexagon(std::get<2>(tuple)) + square_of_hexagon(std::get<3>(tuple));
    t = t + square_of_octagon(std::get<4>(tuple)) + square_of_octagon(std::get<5>(tuple));
    return t;
}
