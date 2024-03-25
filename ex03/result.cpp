#include <iostream>
#include <cmath>

struct Punto 
{
    float x, y;
};

float calculate_the_area(Punto A, Punto B, Punto C) 
{
    return std::abs((A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2.0);
}

bool is_a_triangle(Punto A, Punto B, Punto C) 
{
    float area = calculate_the_area(A, B, C);
    return area > 0.0;
}

bool point_inside_the_triangle(Punto A, Punto B, Punto C, Punto D) //BSP
{
    float areaTotal = calculate_the_area(A, B, C);
    float areaABD = calculate_the_area(A, B, D);
    float areaACD = calculate_the_area(A, C, D);
    float areaBCD = calculate_the_area(B, C, D);
    return areaTotal == (areaABD + areaACD + areaBCD);
}

int main() 
{
    Punto A = {1.0, 1.0};
    Punto B = {4.0, 1.0};
    Punto C = {2.0, 4.0};
    Punto D = {2.0, 2.0};

    if (is_a_triangle(A, B, C)) 
    {
        std::cout << "Los puntos A, B, y C forman un triangulo." << std::endl;
    } 
    else 
        std::cout << "Los puntos A, B, y C no forman un triangulo." << std::endl;

        
    if (point_inside_the_triangle(A, B, C, D)) 
    {
        std::cout << "El punto D esta dentro del triangulo ABC." << std::endl;
    } 
    else 
        std::cout << "El punto D no esta dentro del triangulo ABC." << std::endl;

    return 0;
}
