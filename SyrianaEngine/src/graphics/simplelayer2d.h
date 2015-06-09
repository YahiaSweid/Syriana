#include "layer2d.h"

namespace syriana{
	namespace graphics{
		class SimpleLayer2D : public Layer2D{
		public:
			SimpleLayer2D(Shader* shader);
			~SimpleLayer2D();
		};
	}
}