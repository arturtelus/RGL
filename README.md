# RGL

RAII management for opengl objects(+GLEW).

[OpenGL object](https://www.khronos.org/opengl/wiki/OpenGL_Object)

## Features

- RAII principle for regular opengl objects.
- Shader compilation and program linking boilerplate code.

## Building

- C++ 17
- CMake 3.15

## Sample code

```cpp
	//Create GL 4.3+ window first

	//Init glew and setup debug callback.
	rgl::LoadGLExtensions();

	//Arrays of objects with RAII
	rgl::Buffers<6> buffers{};
	rgl::VertexArrays<3> vaos{};
	rgl::Queries<4> queries{};
	rgl::ProgramPipelines<2> program_pipelines{};
	rgl::TransformFeedbacks<4> transform_feedbacks{};
	rgl::Samplers<5> samplers{};
	rgl::Textures<5> textures{};
	rgl::Renderbuffers<6> renderbuffers{};
	rgl::Framebuffers<4> framebuffers{};

	//Use gl names
	glBindVertexArray(vaos.Names()[0]);
		
	constexpr auto shader_version{ "#version 430 core" };
	constexpr auto v_shader_src{ R"(
		in vec2 vert_position;
		void main()
		{
			gl_Position = vec4(vert_position, 0.0, 1.0);
		}
	)" };
	constexpr auto f_shader_src{ R"(
		out vec4 frag_col;
		void main()
		{
			frag_col = vec4(1.0, 0.0, 0.0, 1.0);
		}
	)" };

	//Create shader program with fixed stages
	rgl::ShaderProgram fixed_program{};
	{
		rgl::Shader vert_shader(GL_VERTEX_SHADER);
		vert_shader.CompileShader({ "#version 430 core", v_shader_src });

		rgl::Shader frag_shader(GL_FRAGMENT_SHADER);
		frag_shader.CompileShader({ shader_version, f_shader_src });
		
		glAttachShader(fixed_program.Name(), vert_shader.Name());
		glAttachShader(fixed_program.Name(), frag_shader.Name());

		fixed_program.LinkProgram();

		glDetachShader(fixed_program.Name(), vert_shader.Name());
		glDetachShader(fixed_program.Name(), frag_shader.Name());
	}

	//Create separate shader program
	rgl::ShaderProgram separate_program{ GL_VERTEX_SHADER, {
		"#version 430 core",
		R"(
			out gl_PerVertex 
			{
				vec4 gl_Position;
				float gl_PointSize; 
				float gl_ClipDistance[];
			};
		)",
		v_shader_src
	} };
```
