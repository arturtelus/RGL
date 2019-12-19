#include "rgl_name.h"

namespace rgl
{
	GLName::GLName(GLuint gl_name)
		: name_{ gl_name }
	{
	}

	GLName::~GLName()
	{
		name_ = GLuint{};
	}

	GLName::GLName(GLName&& other) noexcept
		: name_{ other.name_ }
	{
		other.name_ = GLuint{};
	}

	GLName& GLName::operator=(GLName&& other) noexcept
	{
		if (&other != this)
		{
			name_ = other.name_;
			other.name_ = GLuint{};
		}
		return *this;
	}
}