#pragma once

#include<string_view>
#include<initializer_list>
#include "rgl_name.h"

namespace rgl
{
	///Object manager for opengl shader program.
	class ShaderProgram : public GLName
	{
		///glGetProgramiv wrapper
		///@param name - name of a valid shader program object
		///@param pname - paramenter name
		static GLint GetProgramParam(const GLuint name, const GLenum pname) noexcept;

		///Creates separate shader program from sources.
		///@param shader_type type of shader
		///@param sources list of sources
		static GLuint CreateSeparateProgram(const GLuint shader_type, const std::initializer_list<std::string_view>& sources) noexcept;

		///Creates new gl shader program.
		static GLuint CreateProgram() noexcept;

		///Prints shader compilation info log
		static bool CheckLinkStatus(const GLuint name) noexcept;

		///Deletes opengl shader program
		///@param name - name of the program to delete.
		static void DeleteProgram(const GLuint name) noexcept;

	public:

		///Creates empty program object.
		ShaderProgram() noexcept;

		///Creates separate shader program from sources.
		///@param shader_type type of shader
		///@param sources list of sources
		ShaderProgram(const GLuint shader_type, std::initializer_list<std::string_view> && sources);

		///Deletes gl shader program object.
		~ShaderProgram();

		///Move construct shader program. Transfer gl object ownership.
		///@param other shader to move from
		ShaderProgram(ShaderProgram && other) noexcept;

		///Move assign. Transfer gl object ownership.
		///@param other shader to move from
		ShaderProgram & operator=(ShaderProgram && other) noexcept;
		
		///Link program using set of unique shader objects.
		bool LinkProgram() const noexcept;
	};
}