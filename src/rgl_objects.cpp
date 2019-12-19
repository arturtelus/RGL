#include "rgl_objects.h"

#ifdef DEBUG
#include<iostream>
#endif

namespace rgl
{
	void GenerateGLObjects(const GLenum object_type, const GLsizei array_size, GLenum* array_ptr) noexcept
	{
		switch (object_type)
		{
		case GL_BUFFER:
			glGenBuffers(array_size, array_ptr);
#ifdef DEBUG
			std::clog << "[glGenBuffers]: " << array_size << ' ' << array_ptr << '\n';
#endif // DEBUG
			break;
		case GL_VERTEX_ARRAY:
			glGenVertexArrays(array_size, array_ptr);
#ifdef DEBUG
			std::clog << "[glGenVertexArrays]: " << array_size << ' ' << array_ptr << '\n';
#endif // DEBUG
			break;
		case GL_QUERY:
			glGenQueries(array_size, array_ptr);
#ifdef DEBUG
			std::clog << "[glGenQueries]: " << array_size << ' ' << array_ptr << '\n';
#endif // DEBUG
			break;
		case GL_PROGRAM_PIPELINE:
			glGenProgramPipelines(array_size, array_ptr);
#ifdef DEBUG
			std::clog << "[glGenProgramPipelines]: " << array_size << ' ' << array_ptr << '\n';
#endif // DEBUG
			break;
		case GL_TRANSFORM_FEEDBACK:
			glGenTransformFeedbacks(array_size, array_ptr);
#ifdef DEBUG
			std::clog << "[glGenTransformFeedbacks]: " << array_size << ' ' << array_ptr << '\n';
#endif // DEBUG
			break;
		case GL_SAMPLER:
			glGenSamplers(array_size, array_ptr);
#ifdef DEBUG
			std::clog << "[glGenSamplers]: " << array_size << ' ' << array_ptr << '\n';
#endif // DEBUG
			break;
		case GL_TEXTURE:
			glGenTextures(array_size, array_ptr);
#ifdef DEBUG
			std::clog << "[glGenTextures]: " << array_size << ' ' << array_ptr << '\n';
#endif // DEBUG
			break;
		case GL_RENDERBUFFER:
			glGenRenderbuffers(array_size, array_ptr);
#ifdef DEBUG
			std::clog << "[glGenRenderbuffers]: " << array_size << ' ' << array_ptr << '\n';
#endif // DEBUG
			break;
		case GL_FRAMEBUFFER:
			glGenFramebuffers(array_size, array_ptr);
#ifdef DEBUG
			std::clog << "[glGenFramebuffers]: " << array_size << ' ' << array_ptr << '\n';
#endif // DEBUG
			break;
		default:
			break;
		}
	}

	void DeleteGLObjects(const GLenum object_type, const GLsizei array_size, GLenum* array_ptr) noexcept
	{
		switch (object_type)
		{
		case GL_BUFFER:
			glDeleteBuffers(array_size, array_ptr);
#ifdef DEBUG
			std::clog << "[glDeleteBuffers]: " << array_size << ' ' << array_ptr << '\n';
#endif // DEBUG
			break;
		case GL_VERTEX_ARRAY:
			glDeleteVertexArrays(array_size, array_ptr);
#ifdef DEBUG
			std::clog << "[glDeleteVertexArrays]: " << array_size << ' ' << array_ptr << '\n';
#endif // DEBUG
			break;
		case GL_QUERY:
			glDeleteQueries(array_size, array_ptr);
#ifdef DEBUG
			std::clog << "[glDeleteQueries]: " << array_size << ' ' << array_ptr << '\n';
#endif // DEBUG
			break;
		case GL_PROGRAM_PIPELINE:
			glDeleteProgramPipelines(array_size, array_ptr);
#ifdef DEBUG
			std::clog << "[glDeleteProgramPipelines]: " << array_size << ' ' << array_ptr << '\n';
#endif // DEBUG
			break;
		case GL_TRANSFORM_FEEDBACK:
			glDeleteTransformFeedbacks(array_size, array_ptr);
#ifdef DEBUG
			std::clog << "[glDeleteTransformFeedbacks]: " << array_size << ' ' << array_ptr << '\n';
#endif // DEBUG
			break;
		case GL_SAMPLER:
			glDeleteSamplers(array_size, array_ptr);
#ifdef DEBUG
			std::clog << "[glDeleteSamplers]: " << array_size << ' ' << array_ptr << '\n';
#endif // DEBUG
			break;
		case GL_TEXTURE:
			glDeleteTextures(array_size, array_ptr);
#ifdef DEBUG
			std::clog << "[glDeleteTextures]: " << array_size << ' ' << array_ptr << '\n';
#endif // DEBUG
			break;
		case GL_RENDERBUFFER:
			glDeleteRenderbuffers(array_size, array_ptr);
#ifdef DEBUG
			std::clog << "[glDeleteRenderbuffers]: " << array_size << ' ' << array_ptr << '\n';
#endif // DEBUG
			break;
		case GL_FRAMEBUFFER:
			glDeleteFramebuffers(array_size, array_ptr);
#ifdef DEBUG
			std::clog << "[glDeleteFramebuffers]: " << array_size << ' ' << array_ptr << '\n';
#endif // DEBUG
			break;
		default:
			break;
		}
	}
}