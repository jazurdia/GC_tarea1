#ifndef GLOBALS_H
#define GLOBALS_H

#include "Color.h"
#include <vector>

// Definir las constantes de la dimensión de la pantalla
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

// Definir el framebuffer y el color de limpieza
extern std::vector<Color> framebuffer;
extern Color clearColor;

#endif // GLOBALS_H
