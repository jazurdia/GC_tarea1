#include "framebuffer.h"
#include "vertex.h"

Color currentColor;
Framebuffer framebuffer(800, 600, Color(0, 0, 128)); // NAVY_BLUE

void render() {
    framebuffer.clear();

    currentColor = Color(255, 255, 255); // WHITE
    std::vector<Vertex> vertices = {Vertex(10, 10), Vertex(300, 300), Vertex(600, 50)};
    framebuffer.fillPolygon(vertices, currentColor);
    framebuffer.renderBuffer();
}

int main() {
    render();
    return 0;
}
