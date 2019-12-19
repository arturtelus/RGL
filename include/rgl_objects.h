#pragma once

#include "rgl_names.h"

namespace rgl
{
	/** \addtogroup free_functions
	*  @{
	*/

	///Calls glGen functions.
	///@param object_type glObject enum
	///@param array_size 
	///@param array_ptr 
	void GenerateGLObjects(const GLenum object_type, const GLsizei array_size, GLenum* array_ptr) noexcept;

	///Calls glDelete functions.
	///@param object_type glObject enum
	///@param array_size 
	///@param array_ptr 
	void DeleteGLObjects(const GLenum object_type, const GLsizei array_size, GLenum* array_ptr) noexcept;

	/** @}*/

	/** @defgroup type_aliases Type aliases.
	*  This is the group of available type aliases.
	*  @{
	*/

	///Manages array of buffers.
	template<SizeT array_size>
	using Buffers = GLNames<array_size, GL_BUFFER>;

	///Manages array of vertex arrays.
	template<SizeT array_size>
	using VertexArrays = GLNames<array_size, GL_VERTEX_ARRAY>;

	///Manages array of queires.
	template<SizeT array_size>
	using Queries = GLNames<array_size, GL_QUERY>;

	///Manages array of program pipelines.
	template<SizeT array_size>
	using ProgramPipelines = GLNames<array_size, GL_PROGRAM_PIPELINE>;
	
	///Manages array of transform feedbacks.
	template<SizeT array_size>
	using TransformFeedbacks = GLNames<array_size, GL_TRANSFORM_FEEDBACK>;

	///Manages array of samplers.
	template<SizeT array_size>
	using Samplers = GLNames<array_size, GL_SAMPLER>;

	///Manages array of textures.
	template<SizeT array_size>
	using Textures = GLNames<array_size, GL_TEXTURE>;

	///Manages array of renderbuffers.
	template<SizeT array_size>
	using Renderbuffers = GLNames<array_size, GL_RENDERBUFFER>;

	///Manages array of framebuffers.
	template<SizeT array_size>
	using Framebuffers = GLNames<array_size, GL_FRAMEBUFFER>;

	/** @} */
}