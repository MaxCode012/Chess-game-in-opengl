#include "Texture.h"

Texture::Texture(const std::string &path)
{
     glGenTextures(1, &ID);
     glBindTexture(GL_TEXTURE_2D, ID);

     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

     stbi_set_flip_vertically_on_load(true);

     unsigned char *data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
     if (data)
     {
          GLenum format = (nrChannels == 4) ? GL_RGBA : GL_RGB;

          glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
          glGenerateMipmap(GL_TEXTURE_2D);
     }
     else
     {
          std::cout << "Failed to load texture: " << path << std::endl;
     }
     stbi_image_free(data);
}

Texture::~Texture()
{
     glDeleteTextures(1, &ID);
}

void Texture::Bind(unsigned int slot) const
{
     glActiveTexture(GL_TEXTURE_2D + slot);
     glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::Unbind()
{
     glBindTexture(GL_TEXTURE_2D, 0);
}
