#include "framebuffer.h"
#include "vertex.h"

Framebuffer framebuffer(800, 600, Color(0, 0, 128)); // NAVY_BLUE

void render() {
    framebuffer.clear();

    // Definir los vértices del polígono principal
    std::vector<Vertex> mainPolygonVertices = {
            Vertex(413, 177), Vertex(448, 159), Vertex(502, 88), Vertex(553, 53),
            Vertex(535, 36), Vertex(676, 37), Vertex(660, 52), Vertex(750, 145),
            Vertex(761, 179), Vertex(672, 192), Vertex(659, 214), Vertex(615, 214),
            Vertex(632, 230), Vertex(580, 230), Vertex(597, 215), Vertex(552, 214),
            Vertex(517, 144), Vertex(466, 180)
    };

    // Definir los vértices del agujero
    std::vector<Vertex> holeVertices = {
            Vertex(682, 175), Vertex(708, 120), Vertex(735, 148), Vertex(739, 170)
    };

    // Dibujar y rellenar el polígono principal
    framebuffer.drawAndFillPolygon(mainPolygonVertices, Color(255, 255, 255), Color(0, 255, 0)); // Blanco para las líneas, verde para el relleno

    // Rellenar el agujero con el color de fondo
    framebuffer.fillPolygon(holeVertices, Color(0, 0, 128)); // Azul oscuro para el relleno

    // Dibujar la orilla del agujero
    framebuffer.drawPolygon(holeVertices, Color(0, 255, 0)); // Verde para las líneas

    framebuffer.renderBuffer();
}

int main() {
    render();
    return 0;
}
