#include "framebuffer.h"
#include "vertex.h"

Framebuffer framebuffer(800, 600, Color(0, 0, 128)); // NAVY_BLUE

void render() {
    framebuffer.clear();

    std::vector<Vertex> vertices = {
            Vertex(377, 249),
            Vertex(411, 197),
            Vertex(436, 249)
    };

    framebuffer.drawAndFillPolygon(vertices, Color(255, 255, 255), Color(255, 0, 0)); // Blanco para las líneas, rojo para el relleno

    framebuffer.renderBuffer();
}

int main() {
    render();
    return 0;
}
