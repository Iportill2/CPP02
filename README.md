# CPP Module 02 - Ad-hoc polymorphism, operator overloading and Orthodox Canonical class form

## 📋 Descripción General

El **CPP Module 02** se centra en el aprendizaje de conceptos fundamentales de C++98:
- **Polimorfismo ad-hoc** (sobrecarga de operadores)
- **Sobrecarga de operadores**
- **Forma Canónica Ortodoxa** de las clases
- **Números de punto fijo** y su aritmética
- **Binary Space Partitioning (BSP)**

Este módulo implementa una clase `Fixed` que representa números de punto fijo con 8 bits fraccionarios, progresivamente añadiendo funcionalidad en cada ejercicio.

---

## 📁 Estructura del Proyecto

```
CPP02/
├── ex00/           # Forma Canónica Ortodoxa básica
├── ex01/           # Constructores y conversiones
├── ex02/           # Sobrecarga completa de operadores
├── ex03/           # Aplicación BSP con clase Point
└── README.md       # Este archivo
```

---

## 🚀 Ejercicios

### Ex00: My First Class in Orthodox Canonical Form

**Objetivo**: Implementar la forma canónica ortodoxa básica de una clase Fixed.

**Archivos**:
- `Fixed.hpp` - Declaración de la clase
- `Fixed.cpp` - Implementación básica
- `main.cpp` - Pruebas del subject

**Conceptos Clave**:
- **Constructor por defecto**
- **Constructor de copia**
- **Operador de asignación**
- **Destructor**
- Números de punto fijo con 8 bits fraccionarios

**Compilación y Ejecución**:
```bash
cd ex00
make
./My_First_Class_in_Orthodox_Canonical_Form
```

**Salida esperada**:
```
Default constructor called
Copy constructor called
Copy assignment operator called
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
```

---

### Ex01: Towards a more useful fixed-point number class

**Objetivo**: Añadir constructores útiles y funciones de conversión.

**Archivos**:
- `Fixed.hpp` - Declaración extendida
- `Fixed.cpp` - Implementación con conversiones
- `main.cpp` - Pruebas del subject

**Nuevas Funcionalidades**:
- **Constructor desde int**: Convierte entero a punto fijo
- **Constructor desde float**: Convierte float a punto fijo
- **toInt()**: Convierte punto fijo a entero
- **toFloat()**: Convierte punto fijo a float
- **Sobrecarga del operador <<**: Para mostrar como float

**Compilación y Ejecución**:
```bash
cd ex01
make
./Towards_a_more_useful_fixed-point_number_class
```

**Conceptos Técnicos**:
- **Desplazamiento de bits**: Para conversión int ↔ fixed
- **Redondeo**: `roundf()` para conversión float → fixed
- **Casting estático**: Para conversiones seguras

---

### Ex02: Now we're talking

**Objetivo**: Implementar sobrecarga completa de operadores.

**Archivos**:
- `Fixed.hpp` - Declaración con todos los operadores
- `Fixed.cpp` - Implementación completa
- `main.cpp` - Pruebas exhaustivas

**Operadores Implementados**:

#### Operadores de Comparación:
- `>`, `<`, `>=`, `<=`, `==`, `!=`

#### Operadores Aritméticos:
- `+`, `-`, `*`, `/`

#### Operadores de Incremento/Decremento:
- `++` (pre-incremento)
- `++` (post-incremento)
- `--` (pre-decremento)
- `--` (post-decremento)

#### Funciones Min/Max:
- `static Fixed& min(Fixed& a, Fixed& b)`
- `static const Fixed& min(const Fixed& a, const Fixed& b)`
- `static Fixed& max(Fixed& a, Fixed& b)`
- `static const Fixed& max(const Fixed& a, const Fixed& b)`

**Compilación y Ejecución**:
```bash
cd ex02
make
./Now_we\'re_talking
```

**Aspectos Técnicos Críticos**:
- **Aritmética de punto fijo**: Multiplicación y división requieren ajustes de bits
- **Diferencia pre/post incremento**: Post-incremento devuelve copia del valor anterior
- **Sobrecarga const**: Funciones min/max tienen versiones const y no-const

---

### Ex03: BSP (Binary Space Partitioning)

**Objetivo**: Aplicar la clase Fixed en un algoritmo de geometría computacional.

**Archivos**:
- `Fixed.hpp` / `Fixed.cpp` - Clase Fixed completa
- `Point.hpp` / `Point.cpp` - Clase Point con coordenadas Fixed
- `bsp.cpp` - Implementación del algoritmo BSP
- `main.cpp` - Pruebas del algoritmo

**Funcionalidad**:
- **Clase Point**: Representa un punto 2D con coordenadas Fixed **constantes**
- **Función bsp()**: Determina si un punto está dentro de un triángulo
- **Algoritmo**: Usa áreas de triángulos para la determinación

**Compilación y Ejecución**:
```bash
cd ex03
make
./BSP
```

**Nota Técnica Importante**:
La clase Point tiene miembros `const Fixed x, y`, lo que hace imposible implementar el operador de asignación. Según las mejores prácticas de C++98, se elimina el operador de asignación en lugar de tener uno defectuoso.

---

## 🔧 Detalles Técnicos

### Representación de Punto Fijo

La clase Fixed usa **8 bits fraccionarios**:
- **Valor almacenado**: `int _fixedPointValue`
- **Conversión int → fixed**: `valor << 8` (multiplicar por 256)
- **Conversión fixed → int**: `valor >> 8` (dividir por 256)
- **Conversión float → fixed**: `roundf(valor * 256)`
- **Conversión fixed → float**: `float(valor) / 256`

### Aritmética de Punto Fijo

```cpp
// Suma y resta: directas
result = a._fixedPointValue + b._fixedPointValue;

// Multiplicación: requiere ajuste
result = (a._fixedPointValue * b._fixedPointValue) >> 8;

// División: requiere ajuste
result = (a._fixedPointValue << 8) / b._fixedPointValue;
```

### Algoritmo BSP

El algoritmo determina si un punto P está dentro del triángulo ABC calculando:
1. Área del triángulo ABC
2. Áreas de los triángulos PBC, APC, ABP
3. Si suma de áreas parciales = área total → punto está dentro

---

## 🛠️ Compilación

Cada ejercicio incluye un Makefile con:
- **Compilador**: `c++`
- **Flags**: `-Wall -Wextra -Werror -std=c++98`
- **Targets**: `all`, `clean`, `fclean`, `re`

```bash
# Para compilar todos los ejercicios
for ex in ex00 ex01 ex02 ex03; do
    cd $ex && make && cd ..
done
```

---

## 📊 Verificación de Funcionamiento

### Ex00 - Orthodox Canonical Form
✅ Todos los constructores y operadores llamados correctamente  
✅ Gestión adecuada de memoria  
✅ Salida coincide con el subject  

### Ex01 - Conversiones
✅ Conversiones int/float funcionando  
✅ Precisión de punto fijo mantenida  
✅ Operador << mostrando valores como float  

### Ex02 - Operadores
✅ Todos los operadores de comparación  
✅ Aritmética de punto fijo correcta  
✅ Pre/post incremento diferenciados  
✅ Funciones min/max con sobrecargas const  

### Ex03 - BSP
✅ Algoritmo BSP funcionando  
✅ Clase Point con miembros const  
✅ Determinación correcta dentro/fuera del triángulo  

---

## 🎯 Conceptos Aprendidos

1. **Forma Canónica Ortodoxa**: Base fundamental de toda clase C++
2. **Sobrecarga de Operadores**: Hacer que las clases se comporten como tipos nativos
3. **Aritmética de Punto Fijo**: Alternativa a float para precisión determinística
4. **const-correctness**: Diferentes versiones de funciones para objetos const/no-const
5. **Gestión de miembros const**: Limitaciones del operador de asignación

---

## 🚨 Errores Comunes Evitados

- ❌ **Auto-asignación**: Verificar `this != &other` en operador=
- ❌ **Aritmética incorrecta**: Multiplicación/división requieren ajustes de bits
- ❌ **Nombres de variables**: Usar `_fixedPointValue` y `_fractionalBits` según estándares
- ❌ **Operador= con miembros const**: No implementar si es imposible hacerlo bien
- ❌ **Fugas de memoria**: Todos los constructores/destructores balanceados

---

## 📚 Referencias

- [Orthodox Canonical Class Form](https://www.francescosabatini.it/orthodox-canonical-class-form/)
- [Fixed-point arithmetic](https://en.wikipedia.org/wiki/Fixed-point_arithmetic)
- [C++ Operator Overloading](https://en.cppreference.com/w/cpp/language/operators)
- [Binary Space Partitioning](https://en.wikipedia.org/wiki/Binary_space_partitioning)

---

*Ejercicio completado siguiendo los estándares de evaluación de 42 School* ✅
