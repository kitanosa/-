#pragma once
#include <iostream>
#include <string>

template<typename T>// typename означает что T является ТИПОМ данных.
struct Pentagon {// template используется если нужно использовать несколько типов данных для пользователя. Например мы можем благодя tamplate использовать координаты как float так и int
    using coords = std::pair<T, T>;
    coords a, b, c, d, e;
    std::string name = "Pentagon";
    void print() {
        std::cout << "A: (" << a.first << ": " << a.second << ")" << "B: (" << b.first << ": " << b.second << ")" << "C: (" << c.first << ": " << c.second << ")" << "D: (" << d.first << ": " << d.second << ")" << "E: (" << e.first << ": " << e.second << ")"  << std::endl;
    }
};

template<typename T>
struct Hexagon {
    using coords = std::pair<T, T>;
    coords a, b, c, d, e, f;
    std::string name = "Hexagon";
    void print() {
        std::cout << "A: (" << a.first << ": " << a.second << ")" << "B: (" << b.first << ": " << b.second << ")" << "C: (" << c.first << ": " << c.second << ")" << "D: (" << d.first << ": " << d.second << ")" << "E: (" << e.first << ": " << e.second << ")" << "F: (" << f.first << ": " << f.second << ")"  << std::endl;
    }
};

template<typename T>
struct Octagon {
    using coords = std::pair<T, T>;
    coords a, b, c, d, e, f, g, h;
    std::string name = "Octagon";
    void print() {
        std::cout << "A: (" << a.first << ": " << a.second << ")" << "B: (" << b.first << ": " << b.second << ")" << "C: (" << c.first << ": " << c.second << ")" << "D: (" << d.first << ": " << d.second << ")" << "E: (" << e.first << ": " << e.second << ")" << "F: (" << f.first << ": " << f.second << ")" << "G: (" << g.first << ": " << g.second << ")" << "H: (" << h.first << ": " << h.second << ")"  << std::endl;
    }
};
