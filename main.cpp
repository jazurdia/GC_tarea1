#include "framebuffer.h"
#include "vertex.h"

Framebuffer framebuffer(800, 600, Color(0, 0, 128)); // NAVY_BLUE

void render() {
    framebuffer.clear();


    std::vector<Vertex> vertices = {
            Vertex(165, 380),
            Vertex(185, 360),
            Vertex(180, 330),
            Vertex(207, 345),
            Vertex(233, 330),
            Vertex(230, 360),
            Vertex(250, 380),
            Vertex(220, 385),
            Vertex(205, 410),
            Vertex(193, 383)
    };

    framebuffer.drawAndFillPolygon(vertices, Color(255, 255, 255), Color(255, 255, 0)); // Blanco para las líneas, amarillo para el relleno

    framebuffer.renderBuffer();
}

int main() {
    render();
    return 0;
}
