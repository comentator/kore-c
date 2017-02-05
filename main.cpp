#include <Kore/pch.h>

#include <Kore/Graphics/Graphics.h>
#include <Kore/Graphics/Shader.h>
#include <Kore/IO/FileReader.h>
#include <Kore/System.h>

#include <limits>
#include <stdio.h>
#include <stdlib.h>

using namespace Kore;

namespace {
    Shader* vertexShader;
    Shader* fragmentShader;
    Program* program;
    VertexBuffer* vertices;
    IndexBuffer* indices;

    void update() {
        printf("update\n");
        Graphics::begin();
        Graphics::clear(Kore::Graphics::ClearColorFlag);

        // program->set();
        // Graphics::setVertexBuffer(*vertices);
        // Graphics::setIndexBuffer(*indices);
        // Graphics::drawIndexedVertices();

        Graphics::end();
        Graphics::swapBuffers();
    }
}

extern "C" void init_kore(const char *title, int width, int height) {
    Kore::System::setName((char*)title);
    Kore::System::setup();

    width = Kore::min(width, Kore::System::desktopWidth());
    height = Kore::min(height, Kore::System::desktopHeight());

    Kore::WindowOptions options;
    options.title = "";
    options.width = width;
    options.height = height;
    options.x = Kore::System::desktopWidth() / 2 - width / 2;
    options.y = Kore::System::desktopHeight() / 2 - height / 2;
    options.targetDisplay = -1;
    options.mode = Kore::WindowModeWindow;
    options.rendererOptions.depthBufferBits = 16;
    options.rendererOptions.stencilBufferBits = 8;
    options.rendererOptions.textureFormat = 0;
    options.rendererOptions.antialiasing = 1;

    Kore::System::initWindow(options);

    Kore::System::setCallback(update);
}

extern "C" void run_kore() {
    Kore::System::start();
}
