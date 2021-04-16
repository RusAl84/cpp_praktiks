#include "iostream"

class Figure {
public:
    int corner_counter;
    int* parts;

    virtual void outParts() {
        for (int i = 0; i < corner_counter * 3; ++i)
            std::cout << parts[i] << ' ';

    }

};

class Triangle : public Figure {

public:
    Triangle(int a, int a_angle, int a_len, int b, int b_angle, int b_len, int c, int c_angle, int c_len) {
        corner_counter = 3;
        parts = new int[corner_counter * 3];
        parts[0] = a;
        parts[1] = a_angle;
        parts[2] = a_len;
        parts[3] = b;
        parts[4] = b_angle;
        parts[5] = b_len;
        parts[6] = c;
        parts[7] = c_angle;
        parts[8] = c_len;
    }



};

class RegularTriangle : public Triangle {
public:
    RegularTriangle(int a, int a_len, int b, int b_len, int c, int c_len) :
        Triangle(a, 60, a_len, b, 60, b_len, c, 60, c_len) {}
};




int main() {

    Triangle triangle = Triangle(12, 1, 1, 1, 1, 1, 1, 1, 11);
    triangle.outParts();


    return 0;
}

