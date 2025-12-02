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

    Model bird("res/objects/bird.obj");
    Model dragon("res/objects/dragon.obj");
    Model frog("res/objects/frog.obj");

    Shader shader("res/shaders/vShader.glsl", "res/shaders/fShader.glsl");
    Texture tex("res/textures/crate.png");

    Renderer render;

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    while (!window.isClosed())
    {
        window.ProcessInput();
        render.Clear();

        float timeValue = glfwGetTime();

        glm::vec3 initialPos = glm::vec3(3.0f, 2.0f, 5.0f);
        glm::vec3 finalPos = glm::mat3(1.0f, 0.0f, 0.0f, 0.0f, cos(timeValue), -sin(timeValue), 0.0f, sin(timeValue), cos(timeValue)) * initialPos;

        glm::mat4 view = glm::lookAt(
            initialPos,
            glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec3(0.0f, 1.0f, 0.0f)
        );

        // Perspective:
         glm::mat4 projection = glm::perspective(glm::radians(45.0f),
                                                 (float)SCR_WIDTH / SCR_HEIGHT,
                                                 0.1f, 100.0f);

        // Orthographic:
        //glm::mat4 projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 100.0f);


        shader.Bind();
        shader.SetUniform4x4("view", view);
        shader.SetUniform4x4("projection", projection);

        glm::mat4 modelBird = glm::translate(glm::mat4(1.0f), glm::vec3(-3.0f, 0.0f, 0.0f));
        modelBird = glm::rotate(modelBird, glm::radians(50 * timeValue), glm::vec3(1.0f, 0.0f, 0.0f));
        shader.SetUniform4x4("model", modelBird);
        bird.Draw(shader, tex);

        glm::mat4 modelDragon = glm::mat4(1.0f);
        modelDragon = glm::rotate(modelDragon, glm::radians(50 * timeValue), glm::vec3(0.0f, 1.0f, 0.0f));
        shader.SetUniform4x4("model", modelDragon);
        dragon.Draw(shader, tex);

        glm::mat4 modelFrog = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f));
        modelFrog = glm::scale(modelFrog, glm::vec3(0.2f));
        modelFrog = glm::rotate(modelFrog, glm::radians(50 * timeValue), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.SetUniform4x4("model", modelFrog);
        frog.Draw(shader, tex);

        window.SwapAndPoll();
    }

    window.CloseWindow();
    return 0;
}