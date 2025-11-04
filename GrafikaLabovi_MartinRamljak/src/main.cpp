#include <iostream>
#include <string>

#include "Window.h"
#include "Renderer.h"
#include "Model.h"
#include "Shader.h"
#include "Texture.h"

#include "glm/glm.hpp"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    float offsetX = 0.5f;
    float offsetY = 0.3f;
    glm::vec3 color(0.0f, 1.0f, 0.7f);

    Window window("Vjezba3", SCR_WIDTH, SCR_HEIGHT);
  
    Model model("res/models/rectangle.obj");
    Shader shader("res/shaders/vShader.glsl", "res/shaders/fShader.glsl");
    Texture tex("res/textures/crate.png");

    Renderer render;
    while (!window.isClosed())
    {
        window.ProcessInput();
        render.Clear();

        shader.SetUniformVec2("offset", offsetX, offsetY);
        shader.SetUniformVec3("color", color);

        model.Draw(shader, tex);

        window.SwapAndPoll();
    }

    window.CloseWindow();

    return 0;
}