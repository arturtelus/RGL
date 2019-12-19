#pragma once

#include<GL/glew.h>
#include<cstdint>
#include<array>

namespace rgl
{
	/** \addtogroup type_aliases
	*  @{
	*/

	///Array size type alias.
	using SizeT = std::uint32_t;

	///Array type alias.
	template<SizeT array_size>
	using ArrayT = std::array<GLuint, array_size>;

	/** @}*/
	
	///This class manages array of opengl object names.
	template<SizeT array_size, GLenum gl_type>
	class GLNames
	{
		///Stored ogl names.
		ArrayT<array_size> gl_names_;

	public:

		///Constructs array of opengl objects.
		GLNames() noexcept;

		///Deletes array of opengl objects.
		~GLNames() noexcept;

		///Moves opengl names into this.
		GLNames(GLNames&& other) noexcept;

		///Deletes stored opengl objects and moves names into this.
		GLNames& operator=(GLNames&& other) noexcept;

		///Copy construction is deleted.
		GLNames(GLNames& other) = delete;

		///Copy assignment is deleted.
		GLNames& operator=(GLNames& other) = delete;

		///Get stored opengl names.
		const ArrayT<array_size>& Names() const noexcept { return gl_names_; };
	};

	template<SizeT array_size, GLenum gl_type>
	inline GLNames<array_size, gl_type>::GLNames() noexcept
		: gl_names_{}
	{
		GenerateGLObjects(gl_type, static_cast<GLsizei>(array_size), gl_names_.data());
	}

	template<SizeT array_size, GLenum gl_type>
	inline GLNames<array_size, gl_type>::~GLNames() noexcept
	{
		DeleteGLObjects(gl_type, static_cast<GLsizei>(array_size), gl_names_.data());
	}

	template<SizeT array_size, GLenum gl_type>
	inline GLNames<array_size, gl_type>::GLNames(GLNames&& other) noexcept
		: gl_names_{}
	{
		gl_names_.swap(other.gl_names_);
		other.gl_names_.fill(GLuint{});
	}

	template<SizeT array_size, GLenum gl_type>
	inline GLNames<array_size, gl_type>& GLNames<array_size, gl_type>::operator=(GLNames&& other) noexcept
	{
		if (&other != this)
		{
			DeleteGLObjects(gl_type, static_cast<GLsizei>(array_size), gl_names_.data());
			gl_names_.swap(other.gl_names_);
			other.gl_names_.fill(GLuint{});
		}
		return *this;
	}
}