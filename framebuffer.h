#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <vector>
#include <fstream>
#include <cmath>
#include "color.h"
#include "vertex.h"

class Framebuffer {
private:
    std::vector<Color> buffer;
    Color clearColor;
    int width, height;

public:
    Framebuffer(int _width, int _height, Color clearCol = Color(0, 0, 0))
            : buffer(_width * _height), clearColor(clearCol), width(_width), height(_height) { }

    void clear() {
        for(auto& pixel : buffer) {
            pixel = clearColor;
        }
    }

    void putPixel(const Vertex& vertex, const Color& color) {
        if (vertex.x < 0 || vertex.y < 0 || vertex.x >= width || vertex.y >= height) {
            // Fuera de los límites del framebuffer
            return;
        }
        buffer[vertex.y * width + vertex.x] = color;
    }

    void drawLine(const Vertex& v1, const Vertex& v2, const Color& color) {
        int x1 = v1.x;
        int y1 = v1.y;
        int x2 = v2.x;
        int y2 = v2.y;

        int dx = abs(x2 - x1);
        int dy = abs(y2 - y1);

        int sx = (x1 < x2) ? 1 : -1;
        int sy = (y1 < y2) ? 1 : -1;

        int err = dx - dy;

        while (true) {
            putPixel(Vertex(x1, y1), color);

            if (x1 == x2 && y1 == y2) break;

            int e2 = err * 2;
            if (e2 > -dy) {
                err -= dy;
                x1 += sx;
            }
            if (e2 < dx) {
                err += dx;
                y1 += sy;
            }
        }
    }

    void drawPolygon(const std::vector<Vertex>& vertices, const Color& color) {
        for (size_t i = 0; i < vertices.size(); i++) {
            drawLine(vertices[i], vertices[(i+1) % vertices.size()], color);
        }
    }

    void renderBuffer() {
        std::ofstream ofs("out.bmp", std::ios::binary);

        // Tamaño de la imagen en bytes
        unsigned int fileSize = 54 + 3 * width * height;

        // Escribir la cabecera del BMP
        ofs << 'B' << 'M'
            << writeInt(fileSize)
            << writeInt(0)
            << writeInt(54)
            << writeInt(40)
            << writeInt(width)
            << writeInt(height)
            << writeShort(1)
            << writeShort(24)
            << writeInt(0)
            << writeInt(3 * width * height)
            << writeInt(0)
            << writeInt(0)
            << writeInt(0)
            << writeInt(0);

        // Escribir los datos de los píxeles
        for (auto& pixel : buffer) {
            ofs << pixel.b << pixel.g << pixel.r;
        }

        ofs.close();
    }

    // Funciones auxiliares para escribir datos en el archivo de salida
    std::string writeInt(unsigned int value) {
        std::string ret;
        for (int i = 0; i < 4; i++) {
            ret += static_cast<char>(value & 0xFF);
            value >>= 8;
        }
        return ret;
    }
    std::string writeShort(unsigned short value) {
        std::string ret;
        for (int i = 0; i < 2; i++) {
            ret += static_cast<char>(value & 0xFF);
            value >>= 8;
        }
        return ret;
    }
    bool lineIntersection(const Vertex& v1, const Vertex& v2, int y, int& x) {
        if ((v1.y <= y && v2.y > y) || (v2.y <= y && v1.y > y)) {
            x = v1.x + (v2.x - v1.x) * (y - v1.y) / (float)(v2.y - v1.y);
            return true;
        }
        return false;
    }

    void fillPolygon(const std::vector<Vertex>& vertices, const Color& color) {
        int minY = vertices[0].y, maxY = vertices[0].y;
        for (const auto& vertex : vertices) {
            minY = std::min(minY, vertex.y);
            maxY = std::max(maxY, vertex.y);
        }

        for (int y = minY; y <= maxY; y++) {
            std::vector<int> intersections;
            for (size_t i = 0; i < vertices.size(); i++) {
                int x;
                if (lineIntersection(vertices[i], vertices[(i+1)%vertices.size()], y, x)) {
                    intersections.push_back(x);
                }
            }

            std::sort(intersections.begin(), intersections.end());

            for (size_t i = 0; i < intersections.size(); i += 2) {
                for (int x = intersections[i]; x < intersections[i+1]; x++) {
                    putPixel(Vertex(x, y), color);
                }
            }
        }
    }

};

#endif // FRAMEBUFFER_H
