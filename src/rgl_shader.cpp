#include "rgl_shader.h"

#include<vector>
#include<string>
#ifdef DEBUG
#include<iostream>
#endif

namespace rgl
{
	GLint Shader::GetShaderParam(const GLuint name, const GLenum pname) noexcept
	{
		GLint param{};
		glGetShaderiv(name, pname, &param);
		return param;
	}

	GLuint Shader::CreateShader(const GLenum type) noexcept
	{
		GLuint shader_name{ glCreateShader(type) };

#ifdef DEBUG
		std::clog << "[Shader][CreateShader] " << shader_name << '\n';
#endif // DEBUG

		return shader_name;
	}

	void Shader::DeleteShader(const GLuint name) noexcept
	{
		if (glIsShader(name))
		{
#ifdef DEBUG
			std::clog << "[Shader][DeleteShader] " << name << '\n';
#endif // DEBUG
			glDeleteShader(name);
		}
	}

	Shader::Shader(const GLenum type)
		: GLName{ CreateShader(type) }
		, type_{ type }
	{
	}

	Shader::Shader(Shader&& other) noexcept
		: GLName{ std::move(other) }
		, type_{ other.type_ }
	{
		other.type_ = GLenum{};
	}

	Shader& Shader::operator=(Shader&& other) noexcept
	{
		if (&other != this)
		{
			DeleteShader(GLName::name_);
			GLName::operator=(std::move(other));
			type_ = other.type_;
			other.type_ = GLenum{};
		}

		return *this;
	}

	Shader::~Shader()
	{
		DeleteShader(GLName::name_);
		type_ = GLenum{};
	}

	void Shader::SetType(const GLenum new_type) noexcept
	{
		if (type_ != new_type)
		{
			DeleteShader(GLName::name_);
			GLName::name_ = CreateShader(new_type);
			type_ = new_type;
		}
	}

	bool Shader::CompileShader(std::initializer_list<std::string_view>&& sources) const
	{
		if (glIsShader(GLName::name_) && sources.size() > size_t{ 0 })
		{
			std::vector<const GLchar*> shader_sources{};
			for (auto str : sources)
			{
				shader_sources.push_back(str.data());
			}

			glShaderSource(GLName::name_, static_cast<GLsizei>(shader_sources.size()), shader_sources.data(), NULL);
			glCompileShader(GLName::name_);

			if (GetShaderParam(GLName::name_, GL_COMPILE_STATUS) == GL_TRUE)
			{
#ifdef DEBUG
				std::clog << "[Shader][CompileShader] Compiled shader: " << GLName::name_ << '\n';
#endif // DEBUG
				return true;
			}
			else
			{
				try
				{
					std::string info_log(GetShaderParam(GLName::name_, GL_INFO_LOG_LENGTH), '\0');
					glGetShaderInfoLog(GLName::name_, static_cast<GLsizei>(info_log.size()), NULL, (GLchar*)info_log.c_str());
#ifdef DEBUG
					std::cerr << "[Shader][CompileShader] Compilation error. Message: " << info_log << '\n';
#endif // DEBUG
				}
				catch (...)
				{
					return false;
				}
			}
		}
		return false;
	}
}	