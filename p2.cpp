#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>

//Búsqueda binaria
template <typename T>
int busquedaBinaria(const T& x, const std::vector<T>& v, int ini, int fin) {
    if (ini > fin) {
        return -1; // No encontrado
    }

    int medio = ini + (fin - ini) / 2;

    if (v[medio] == x) {
        return medio;
    } else if (v[medio] > x) {
        return busquedaBinaria(x, v, ini, medio - 1);
    } else {
        return busquedaBinaria(x, v, medio + 1, fin);
    }
}

// Quicksort
template <typename T>
int partition(std::vector<T>& v, int ini, int fin) {
    T x = v[fin]; // Pivote al final
    int i = ini;

    for (int j = ini; j < fin; j++) {
        if (v[j] <= x) {
            std::swap(v[i], v[j]);
            i++;
        }
    }
    std::swap(v[i], v[fin]);
    return i;
}

template <typename T>
void quickSort(std::vector<T>& v, int ini, int fin) {
    if (ini < fin) {
        int pivot = partition(v, ini, fin);
        quickSort(v, ini, pivot - 1);
        quickSort(v, pivot + 1, fin);
    }
}

// Método para imprimir los vectores
template <typename T>
void mostrarVector(const std::vector<T>& v) {
    std::cout << "[ ";
    for (const auto& elem : v) {
        std::cout << elem << " ";
    }
    std::cout << "]\n";
}

int main()
{
    std::vector<int> enteros = {8, 3, 1, 7, 0, 10, 2};
    std::cout << "Original: ";
    for (int x : enteros)
        std::cout << x << ' ';
    if (!enteros.empty())
        quickSort(enteros, 0, static_cast<int>(enteros.size()) - 1);
    std::cout << "\nOrdenado: ";
    for (int x : enteros)
        std::cout << x << ' ';
    int indiceInt = busquedaBinaria(7, enteros, 0, static_cast<int>(enteros.size()) - 1);
    std::cout << "\nBusqueda de 7: " << indiceInt << "\n\n";


    std::vector<float> reales = {3.5f, 1.2f, 8.7f, 2.4f, 5.1f};
    std::cout << "Original: ";
    for (float x : reales)
        std::cout << x << ' ';
    if (!reales.empty())
        quickSort(reales, 0, static_cast<int>(reales.size()) - 1);
    std::cout << "\nOrdenado: ";
    for (float x : reales)
        std::cout << x << ' ';
    int indiceFloat = busquedaBinaria(2.4f, reales, 0, static_cast<int>(reales.size()) - 1);
    std::cout << "\nBusqueda de 2.4: " << indiceFloat << "\n\n";
	
    std::vector<char> caracteres = {'d', 'a', 'z', 'c', 'b'};
    std::cout << "Original: ";
    for (char x : caracteres)
        std::cout << x << ' ';
    if (!caracteres.empty())
        quickSort(caracteres, 0,
                  static_cast<int>(caracteres.size()) - 1);
    std::cout << "\nOrdenado: ";
    for (char x : caracteres)
        std::cout << x << ' ';
    int indiceChar = busquedaBinaria('c', caracteres, 0, static_cast<int>(caracteres.size()) - 1);
    std::cout << "\nBusqueda de 'c': " << indiceChar << '\n';

    return 0;
}
