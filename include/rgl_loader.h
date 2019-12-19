#pragma once

namespace rgl
{
	/** @defgroup free_functions Free functions.
	*  This is the group of available free functions.
	*  @{
	*/

	///Loads opengl extensions using glew, sets up debug callback.
	///@throws std::runtime_error if extensions loading fails.
	void LoadGLExtensions();

	/** @} */
}

