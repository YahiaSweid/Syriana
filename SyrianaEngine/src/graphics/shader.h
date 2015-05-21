#pragma once

#include <vector>
#include <GL/glew.h>
#include "../maths/vector2.h"
#include "../maths/vector3.h"
#include "../maths/vector4.h"
#include "../maths/matrix4.h"
#include "../utils/file.h"


namespace syriana{
	using namespace maths;
	namespace graphics{

		class Shader{
		private:
			GLuint m_ProgramID;
		public:
			Shader();
			Shader(const char* vertexFile, const char* fragmentFile);
			~Shader();

			GLuint LoadShaders();		// Returns program id that contains the shaders

			GLint GetUniformLocation(const GLchar* name);
			void SetUniform1f(const GLchar* var, const GLfloat value);
			void SetUniform1i(const GLchar* var, const GLint value);
			void SetUniform2f(const GLchar* var, const Vector2& value);
			void SetUniform3f(const GLchar* var, const Vector3& value);
			void SetUniform4f(const GLchar* var, const Vector4& value);
			void SetUniformMat4(const GLchar* var, const Matrix4& value);

			void Enable() const;
			void Disable() const;
		};

	}
}