#pragma once

#include<GL/glew.h>

namespace rgl
{
	///This class holds single opengl object name.
	class GLName
	{
	protected:

		///Name of opengl object.
		GLuint name_{};

	public:
		
		///Creates object handle to single opengl object.
		///@param gl_name - opengl object's name
		explicit GLName(const GLuint gl_name = GLuint{});

		///Destructor.
		~GLName();

		///Move constructs handle to opengl object.
		GLName(GLName&& other) noexcept;

		///Transfers name_.
		GLName& operator=(GLName&& other) noexcept;

		///Copy construction is deleted.
		GLName(GLName& other) = delete;

		///Copy assign is deleted.
		GLName& operator=(GLName& other) = delete;

		///Get opengl object name.
		GLuint Name() const noexcept { return name_; };
	};

}