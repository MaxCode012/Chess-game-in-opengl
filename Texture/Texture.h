#pragma once

#include <glad/glad.h>
#include <stb_image.h>
#include <string>
#include <iostream>

class Texture
{
public:
     unsigned int ID;
     int width, height, nrChannels;

     Texture(const std::string &path);
     ~Texture();

     void Bind(unsigned int slot = 0) const;
     void Unbind();
};
