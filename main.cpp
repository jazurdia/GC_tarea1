#include "framebuffer.h"
#include "vertex.h"

Framebuffer framebuffer(800, 600, Color(0, 0, 128)); // NAVY_BLUE

void render() {
    framebuffer.clear();

    std::vector<Vertex> vertices = {Vertex(10, 10), Vertex(300, 300), Vertex(600, 50)};
    framebuffer.drawAndFillPolygon(vertices, Color(255, 0, 0), Color(0, 255, 0));
    // Rojo para las líneas, verde para el relleno
    framebuffer.renderBuffer();
}

int main() {
    render();
    return 0;
}
