#include "file.h"

namespace syriana{
	namespace utils{

		string File::ReadFile(char* filePath){
			FILE* file;
			char* line = new char[100];	
			string text = "";	

			file = fopen(filePath, "r");
			if (file != NULL){
				while (fgets(line, 100, file) != NULL)
					text.append(line);
				
				return text;
			}
			return "";
		}

	}
}