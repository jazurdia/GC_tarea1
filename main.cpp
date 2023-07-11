#include "Color.h"
#include <vector>

// Definir las constantes de la dimensión de la pantalla
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Definir el framebuffer y el color de limpieza
std::vector<Color> framebuffer(SCREEN_WIDTH * SCREEN_HEIGHT);
Color clearColor;

// Función para limpiar el framebuffer
void clear() {
    std::fill(framebuffer.begin(), framebuffer.end(), clearColor);
}

int main() {
    Color c1(255, 100, 50);
    Color c2(100, 255, 200);
    Color c3 = c1 + c2;
    Color c4 = c1 * 0.5f;

    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c3 (c1 + c2): " << c3 << std::endl;
    std::cout << "c4 (c1 * 0.5): " << c4 << std::endl;
    return 0;
}

