#version 330 core
out vec4 FragColor;
in vec2 TexCoord;

uniform vec3 squareColor;
uniform sampler2D texture1; 
uniform bool usingTexture;

void main()
{
    vec4 backgroundColor = vec4(squareColor, 1.0);

    if(usingTexture)
    {
        vec4 texColor = texture(texture1, TexCoord);

        FragColor = mix(backgroundColor, texColor, texColor.a);
    }
    else
    {
        FragColor = backgroundColor;
    }
}