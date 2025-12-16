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

    Model kocka1("res/objects/dragon.obj");
    Model kocka2("res/objects/kocka.obj");
    Model kocka3("res/objects/bird.obj");

    Shader shader("res/shaders/vShader.glsl", "res/shaders/fShader.glsl");
    Texture tex("res/textures/crate.png");

    Renderer render;

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glm::vec3 cameraPos = glm::vec3(0.0f, 10.0f * cos(glm::radians(45.0f)), 10.0f * sin(glm::radians(45.0f)));
    glm::vec3 lightPos(8.0f, 3.0f, 0.0f);

    while (!window.isClosed())
    {
        window.ProcessInput();
        render.Clear();

        float timeValue = glfwGetTime();

        glm::mat4 view = glm::lookAt(
            cameraPos,
            glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec3(0.0f, 1.0f, 0.0f)
        );

        glm::vec3 lightColor(cos(glm::radians(100 * timeValue)), sin(glm::radians(100 * timeValue)), 0.0f);

        // Perspective:
         glm::mat4 projection = glm::perspective(glm::radians(45.0f),
                                                 (float)SCR_WIDTH / SCR_HEIGHT,
                                                 0.1f, 100.0f);

        // Orthographic:
        //glm::mat4 projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 100.0f);


        shader.Bind();
        shader.SetUniform4x4("view", view);
        shader.SetUniform4x4("projection", projection);

        shader.SetUniformVec3("lightColor", lightColor);
        shader.SetUniformVec3("lightPos", lightPos);
        shader.SetUniformVec3("viewPos", cameraPos);

        shader.SetUniformVec3("objectColor", 1.0f, 0.0f, 0.0f);
        glm::mat4 modelKocka1 = glm::translate(glm::mat4(1.0f), glm::vec3(-3.5f, 0.0f, 0.0f));
        shader.SetUniform4x4("model", modelKocka1);
        kocka1.Draw(shader, tex);

        shader.SetUniformVec3("objectColor", 0.0f, 1.0f, 0.0f);
        glm::mat4 modelKocka2 = glm::translate(glm::mat4(1.0f), glm::vec3(-0.5f, 0.0f, 0.0f));
        shader.SetUniform4x4("model", modelKocka2);
        kocka2.Draw(shader, tex);

        shader.SetUniformVec3("objectColor", 0.0f, 0.2f, 1.0f);
        glm::mat4 modelKocka3 = glm::translate(glm::mat4(1.0f), glm::vec3(2.5f, 0.0f, 0.0f));
        shader.SetUniform4x4("model", modelKocka3);
        kocka3.Draw(shader, tex);

        shader.SetUniformVec3("lightColor", 1.0f, 1.0f, 1.0f);
        shader.SetUniformVec3("lightPos", lightPos);

        lightPos.x = 5.0f + 3.0f * cos(timeValue);
        lightPos.z = 3.0f * sin(timeValue);

        window.SwapAndPoll();
    }

    window.CloseWindow();
    return 0;
}