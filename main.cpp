#include "framebuffer.h"
#include "vertex.h"

Framebuffer framebuffer(800, 600, Color(0, 0, 128)); // NAVY_BLUE

void render() {
    framebuffer.clear();

    // Polígono 1
    std::vector<Vertex> vertices1 = {
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
    framebuffer.drawAndFillPolygon(vertices1, Color(255, 255, 255), Color(255, 255, 0)); // Blanco para las líneas, amarillo para el relleno

    // Polígono 2
    std::vector<Vertex> vertices2 = {
            Vertex(321, 335),
            Vertex(288, 286),
            Vertex(339, 251),
            Vertex(374, 302)
    };
    framebuffer.drawAndFillPolygon(vertices2, Color(255, 255, 255), Color(0, 0, 255)); // Blanco para las líneas, azul para el relleno

    // Polígono 3
    std::vector<Vertex> vertices3 = {
            Vertex(377, 249),
            Vertex(411, 197),
            Vertex(436, 249)
    };
    framebuffer.drawAndFillPolygon(vertices3, Color(255, 255, 255), Color(255, 0, 0)); // Blanco para las líneas, rojo para el relleno

    // Polígono 4
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
