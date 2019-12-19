#include "rgl_shader_program.h"

#include<vector>
#ifdef DEBUG
#include<iostream>
#endif
#include "rgl_shader.h"

namespace rgl
{
	GLint ShaderProgram::GetProgramParam(const GLuint name, const GLenum pname) noexcept
	{
		GLint param{};
		glGetProgramiv(name, pname, &param);
		return param;
	}

	GLuint ShaderProgram::CreateProgram() noexcept
	{
		auto program_name{ glCreateProgram() };
#ifdef DEBUG
		std::clog << "[ShaderProgram][CreateProgram]: " << program_name << '\n';
#endif // DEBUG
		return program_name;
	}

	GLuint ShaderProgram::CreateSeparateProgram(const GLuint shader_type, const std::initializer_list<std::string_view>& sources) noexcept
	{
		std::vector<const GLchar*> shader_sources{};
		for (auto str : sources)
		{
			shader_sources.push_back(str.data());
		}
		GLuint separate_program{ glCreateShaderProgramv(shader_type, static_cast<GLsizei>(shader_sources.size()), shader_sources.data()) };
#ifdef DEBUG
		std::clog << "[ShaderProgram][CreateSeparateProgram]: " << separate_program << '\n';
#endif // DEBUG
		CheckLinkStatus(separate_program);
		return separate_program;
	}

	void ShaderProgram::DeleteProgram(const GLuint name) noexcept
	{
#ifdef DEBUG
		std::clog << "[ShaderProgram][DeleteProgram]: " << name << '\n';
#endif // DEBUG
		glDeleteProgram(name);
	}

	ShaderProgram::ShaderProgram() noexcept
		: GLName{ CreateProgram() }
	{
	}

	ShaderProgram::ShaderProgram(const GLuint shader_type, std::initializer_list<std::string_view>&& sources)
		: GLName{ CreateSeparateProgram(shader_type, sources) }
	{
	}

	ShaderProgram::ShaderProgram(ShaderProgram&& other) noexcept
		: GLName(std::move(other))
	{
	}

	ShaderProgram::~ShaderProgram()
	{
		DeleteProgram(GLName::name_);
	}

	ShaderProgram& ShaderProgram::operator=(ShaderProgram&& other) noexcept
	{
		if (&other != this)
		{
			DeleteProgram(GLName::name_);
			GLName::operator=(std::move(other));
		}
		return *this;
	}

	bool ShaderProgram::CheckLinkStatus(const GLuint name) noexcept
	{
		if (GetProgramParam(name, GL_LINK_STATUS) == GL_TRUE)
		{
#ifdef DEBUG
			std::clog << "[ShaderProgram][LinkProgram] Linked program: " << name << '\n';
#endif // DEBUG
			return true;
		}
#ifdef DEBUG
		else
		{
			try
			{
				std::string info_log(GetProgramParam(name, GL_INFO_LOG_LENGTH), '\0');
				glGetProgramInfoLog(name, static_cast<GLsizei>(info_log.size()), NULL, (GLchar*)info_log.c_str());
				std::cerr << "[ShaderProgram][LinkProgram] Linking error. Message: \n" << info_log << '\n';
			}
			catch (...)
			{
				return false;
			}
		}
#endif // DEBUG
		return false;
	}

	bool ShaderProgram::LinkProgram() const noexcept
	{
		glLinkProgram(GLName::name_);
		return CheckLinkStatus(GLName::name_);
	}
}