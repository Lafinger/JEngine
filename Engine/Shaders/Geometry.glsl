#type vertex
#version 450 core

layout(location = 0) in vec3 a_Pos;
layout(location = 1) in int a_EntityID;


struct VertexOutput
{
	vec3 WorldPos;
};
layout (location = 0) out VertexOutput Output;
layout (location = 1) out flat int v_EntityID;

layout(std140, binding = 0) uniform Camera
{
	mat4 u_ViewProjection;
};

uniform mat4 u_modelMat4;
uniform mat4 u_projectionMat4;

void main()
{
    Output.WorldPos = vec3(u_modelMat4 * vec4(a_Pos, 1.0));
    v_EntityID = a_EntityID;

    gl_Position =  u_projectionMat4 * vec4(Output.WorldPos, 1.0);
}

#type fragment
#version 450 core

out vec4 FragColor;
out int color2;

struct VertexOutput
{
	vec3 WorldPos;
};

layout (location = 0) in VertexOutput Input;
layout (location = 1) in flat int v_EntityID;

void main()
{
    vec3 color = vec3(1.0);

    // gamma correct
    color = pow(color, vec3(1.0/2.2)); 

    FragColor = vec4(color , 1.0);

    color2 = v_EntityID;
}