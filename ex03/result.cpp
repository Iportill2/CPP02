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
    std::cout << area << std::endl;
    return area > 0.0;
}

bool point_inside_the_triangle(Punto A, Punto B, Punto C, Punto D) //BSP
{
    float areaTotal = calculate_the_area(A, B, C);
    float areaABD = calculate_the_area(A, B, D);
    float areaACD = calculate_the_area(A, C, D);
    float areaBCD = calculate_the_area(B, C, D);
    if(areaTotal == (areaABD + areaACD + areaBCD))
        return (true);
    else
        return(false);
}

int main() 
{
    Punto A = {-2, 2};
    Punto B = {0, 0};
    Punto C = {-2, -2};
    Punto D = {-1, 0};

    if (is_a_triangle(A, B, C)) 
    {
        std::cout << "Los puntos A, B, y C forman un triangulo." << std::endl;
    } 
    else 
        std::cout << "Los puntos A, B, y C no forman un triangulo." << std::endl;

        
    if (point_inside_the_triangle(A, B, C, D)) //BSP
    {
        std::cout << "El punto D esta dentro del triangulo ABC." << std::endl;
    } 
    else 
        std::cout << "El punto D no esta dentro del triangulo ABC." << std::endl;

    return 0;
}
