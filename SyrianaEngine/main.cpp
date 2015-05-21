#include <iostream>
#include "src\graphics\window.h"
#include "src\graphics\renderer2d.h"
#include "src\graphics\sprite.h"
#include "src\maths\vector2.h"
#include "src\maths\vector3.h"
#include "src\maths\vector4.h"
#include "src\graphics\shader.h"
#include <chrono>
#include <vector>
#include <time.h>

using namespace syriana::graphics;
using namespace syriana::maths;

/////
long long GetCurrentEpochToMillis(){
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
}
/////

std::vector<Sprite*> sprites;


int main(){
	srand(time(NULL));

	Window window("Test Syriana Engine", 800, 800 / 16 * 9);
	Renderer2D renderer;

	Shader shader;
	shader.Enable();
	shader.SetUniformMat4("projectionMatrix", Matrix4::Orthographic(0, 800, 0, 800 / 16 * 9, 100, -100));

	
	for (int i = 0; i < 25; i++){
		for (int j = 0; j < 18; j++){
			sprites.push_back(new Sprite(Vector3(i * 32, j * 32, 0), Vector2(32.0, 32.0),
				Vector4((float)(rand() % 1000) / 1000, (float)(rand() % 1000) / 1000, (float)(rand() % 1000) / 1000, 1)));
		}
	}
	
	/////
	int frames = 0;
	long long timer = GetCurrentEpochToMillis();
	float dt = 0.f;

	long long lastTime = GetCurrentEpochToMillis();
	long long currentTime = 0;
	/////

	float counter = 0.0;
	while (!window.IsClosed()){
		/////
		currentTime = GetCurrentEpochToMillis();
		dt = (currentTime - lastTime) / (1000.0 / 60.f);
		lastTime = currentTime;
		/////
		window.ClearScreen();

		renderer.Prepare();
		for (int i = 0; i < sprites.size(); i++)
			renderer.Push(sprites[i]);
		//renderer.Push(&sprite);
		//renderer.Push(&sprite2);
		renderer.End();

		renderer.Render();

		counter += 0.1;
		window.Update();

		/////
		frames++;
		if (GetCurrentEpochToMillis() - timer > 1000){
			timer += 1000;
			std::cout << "FPS " << frames << std::endl;
			frames = 0;
		}
		/////
	}


	return 0;
}