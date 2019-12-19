#include "rgl_loader.h"

#include<GL/glew.h>
#ifdef DEBUG
#include<iostream>
#endif // GL_DEBUG

namespace rgl
{
	void LoadGLExtensions()
	{
		if (GLenum err{ glewInit() }; err != GLEW_OK)
		{
			throw std::runtime_error("GLEW failed to initialize!");
		}

#ifdef DEBUG
		if (GLEW_VERSION_4_3)
		{
			glEnable(GL_DEBUG_OUTPUT);
			glDebugMessageCallback(static_cast<GLDEBUGPROC>([](GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
				{
					std::cerr
						<< "GL ERROR! \nSource: " << source << '\n'
						<< "Type: " << type << '\n'
						<< "ID: " << id << '\n'
						<< "Severity: " << severity << '\n'
						<< "Length: " << length << '\n'
						<< "Message: " << message << '\n'
						<< "UserParam: " << userParam << '\n';
				}), NULL);
		}

		std::clog
			<< "Vendor: " << glGetString(GL_VENDOR) << '\n'
			<< "Renderer: " << glGetString(GL_RENDERER) << '\n'
			<< "Version: " << glGetString(GL_VERSION) << '\n'
			<< "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << '\n';
#endif // GL_DEBUG
	}
}