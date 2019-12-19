#pragma once

#include<string_view>
#include<initializer_list>
#include"rgl_name.h"

namespace rgl
{
	///Object wrapper for opengl shader.
	class Shader : public GLName
	{
		///Stored type of gl shader.
		GLenum type_;

		///glGetShaderiv wrapper.
		///@param name - opengl shader object 
		///@param pname - parameter name
		static GLint GetShaderParam(const GLuint name, const GLenum pname) noexcept;

		///Creates empty shader object.
		///@param type - opengl shader type
		static GLuint CreateShader(const GLenum type) noexcept;

		///Deletes opengl shader object.
		///@param name - opengl shader name
		static void DeleteShader(const GLuint name) noexcept;

	public:

		///Creates empty shader object of "type".
		///@param type - opengl shader type
		///@throws std::runtime_error if glCreateShader fails.
		explicit Shader(const GLenum type);

		///Deletes stored gl_shader object.
		~Shader();

		///Move constructs new shader. Transfers gl object ownership.
		///@param other shader to move from
		Shader(Shader&& other) noexcept;

		///Transfers gl object ownership, old gl object is deleted.
		///@param other shader to move from
		Shader& operator=(Shader&& other) noexcept;

		///Copy construct is deleted.
		Shader(Shader& other) = delete;

		///Copy assign is deleted.
		Shader& operator=(Shader& other) = delete;

		///Sets type of shader. If "type" is different than stored type, shader object is recreated.
		///@param type - opengl shader type
		void SetType(const GLenum type) noexcept;

		///Gets type of stored shader object.
		GLenum GetType() const noexcept { return type_; };

		///Compiles or recompile shader object 
		///@param source_string - shader source string
		bool CompileShader(std::initializer_list<std::string_view>&& sources) const;
	};
}

