#pragma once

#include <string>
using namespace std;

namespace syriana{
	namespace utils{

		class File{
		public:
			static string ReadFile(char* filePath);
		};


	}
}