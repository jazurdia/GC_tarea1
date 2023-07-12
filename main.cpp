#include "framebuffer.h"
#include "vertex.h"

Framebuffer framebuffer(800, 600, Color(0, 0, 128)); // NAVY_BLUE

void render() {
    framebuffer.clear();

    std::vector<Vertex> vertices = {
            Vertex(321, 335),
            Vertex(288, 286),
            Vertex(339, 251),
            Vertex(374, 302)
    };

    framebuffer.drawAndFillPolygon(vertices, Color(255, 255, 255), Color(0, 0, 255)); // Blanco para las líneas, azul para el relleno

    framebuffer.renderBuffer();
}

int main() {
    render();
    return 0;
}
