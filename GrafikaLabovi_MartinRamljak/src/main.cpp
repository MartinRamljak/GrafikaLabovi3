#include <iostream>
#include <string>

#include "Window.h"
#include "Renderer.h"
#include "Model.h"
#include "Shader.h"
#include "Texture.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    Window window("Vjezba4", SCR_WIDTH, SCR_HEIGHT);

    Model rectangle("res/models/rectangle.obj");
    Model dragon("res/models/dragon.obj");

    Shader shader("res/shaders/vShader.glsl", "res/shaders/fShader.glsl");
    Texture tex("res/textures/crate.png");

    Renderer render;

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    while (!window.isClosed())
    {
        window.ProcessInput();
        render.Clear();

        glm::mat4 view = glm::lookAt(
            glm::vec3(3.0f, 2.0f, 5.0f),   // camera position
            glm::vec3(0.0f, 0.0f, 0.0f),   // look at center
            glm::vec3(0.0f, 1.0f, 0.0f)    // up vector
        );

        // Perspective:
         glm::mat4 projection = glm::perspective(glm::radians(45.0f),
                                                 (float)SCR_WIDTH / SCR_HEIGHT,
                                                 0.1f, 100.0f);

        // Orthographic:
        //glm::mat4 projection = glm::ortho(-6.0f, 6.0f, -4.0f, 4.0f, 0.1f, 100.0f);


        shader.Bind();
        shader.SetUniform4x4("view", view);
        shader.SetUniform4x4("projection", projection);

        glm::mat4 modelRect = glm::translate(glm::mat4(1.0f), glm::vec3(-3.0f, 0.0f, 0.0f));
        shader.SetUniform4x4("model", modelRect);
        rectangle.Draw(shader, tex);

        glm::mat4 modelDragon = glm::mat4(1.0f);
        modelDragon = glm::scale(modelDragon, glm::vec3(0.5f));
        shader.SetUniform4x4("model", modelDragon);
        dragon.Draw(shader, tex);

        window.SwapAndPoll();
    }

    window.CloseWindow();
    return 0;
}