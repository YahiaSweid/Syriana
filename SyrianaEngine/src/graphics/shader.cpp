#include "shader.h"

namespace syriana{
	namespace graphics{

		Shader::Shader(){
			m_ProgramID = LoadShaders();
		}
		Shader::~Shader(){}
		Shader::Shader(const char* vertexFile, const char* fragmentFile){
			m_ProgramID = LoadShaders();
		}

		GLuint Shader::LoadShaders(){
			GLuint program = glCreateProgram();
			GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

			std::string vertexShaderFileString = utils::File::ReadFile("src/shaders/basic.vs");
			std::string fragmentShaderFileString = utils::File::ReadFile("src/shaders/basic.fs");

			const char* vertexShaderFile = vertexShaderFileString.c_str();
			const char* fragmentShaderFile = fragmentShaderFileString.c_str();

			glShaderSource(vertexShader, 1, &vertexShaderFile, NULL);
			glCompileShader(vertexShader);

			GLint result;
			glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE){
				GLint length;
				glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertexShader, length, &length, &error[0]);
				std::cout << "Failed to compile vertex shader!" << std::endl << &error[0] << std::endl;
				glDeleteShader(vertexShader);
				return 0;
			}
			std::cout << "Vertex compiled" << std::endl;



			glShaderSource(fragmentShader, 1, &fragmentShaderFile, NULL);
			glCompileShader(fragmentShader);

			glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);
			if (result == GL_FALSE){
				GLint length;
				glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(fragmentShader, length, &length, &error[0]);
				std::cout << "Failed to compile fragment shader!" << std::endl << &error[0] << std::endl;
				glDeleteShader(fragmentShader);
				return 0;
			}
			std::cout << "fragment compiled" << std::endl;


			glAttachShader(program, vertexShader);
			glAttachShader(program, fragmentShader);

			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			return program;
		}

		GLint Shader::GetUniformLocation(const GLchar* name){
			return glGetUniformLocation(m_ProgramID, name);
		}
		void Shader::SetUniform1f(const GLchar* var, const GLfloat value) {
			glUniform1f(GetUniformLocation(var), value);
		}
		void Shader::SetUniform1fv(const GLchar* var, const GLfloat* value, const int count){
			glUniform1fv(GetUniformLocation(var), count, value);
		}
		void Shader::SetUniform1i(const GLchar* var, const GLint value){
			glUniform1i(GetUniformLocation(var), value);
		}
		void Shader::SetUniform1iv(const GLchar* var, const GLint* value, const int count){
			glUniform1iv(GetUniformLocation(var), count, value);
		}
		void Shader::SetUniform2f(const GLchar* var, const maths::Vector2& value){
			glUniform2f(GetUniformLocation(var), value.x, value.y);
		}
		void Shader::SetUniform3f(const GLchar* var, const maths::Vector3& value){
			glUniform3f(GetUniformLocation(var), value.x, value.y, value.z);
		}
		void Shader::SetUniform4f(const GLchar* var, const maths::Vector4& value){
			glUniform4f(GetUniformLocation(var), value.x, value.y, value.z, value.w);
		}
		void Shader::SetUniformMat4(const GLchar* var, const maths::Matrix4& value){
			glUniformMatrix4fv(GetUniformLocation(var), 1, GL_FALSE, value.elements);
		}

		void Shader::Enable() const{
			glUseProgram(m_ProgramID);
		}
		void Shader::Disable() const {
			glUseProgram(0);
		}

	}
}


