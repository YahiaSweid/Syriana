#include <iostream>
#include "src\graphics\window.h"
#include "src\graphics\simplelayer2d.h"
#include "src\graphics\group2d.h"
#include "src\graphics\sprite.h"
#include "src\graphics\texture.h"
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
	
	Shader shader;
	shader.Enable();
	shader.SetUniformMat4("projectionMatrix", Matrix4::Orthographic(0, 800, 0, 800 / 16 * 9, -100, 100));

	SimpleLayer2D background(&shader);

	SimpleLayer2D layer(&shader);
	
	
	Texture* textures[] = {
		new Texture("./res/test.png"),
		new Texture("./res/face.jpg")
	};

	for (int i = 0; i < 25; i++){
		for (int j = 0; j < 18; j++){
			background.Add(new Sprite(Vector3(i * 32, j * 32, 0), Vector2(32.0, 32.0),
				textures[0],
				Vector4((float)(rand() % 1000) / 1000, (float)(rand() % 1000) / 1000, (float)(rand() % 1000) / 1000, 1)));
		}
	}


	Group2D* group = new Group2D(Matrix4::Translate(Vector3(128, 128, 0)));
	group->Add(new Sprite(Vector3(0, 0, 0), Vector2(128.0, 64.0), Vector4(0.1, 0.2, 0.3, 1.0)));
	group->Add(new Sprite(Vector3(32, 16, 0), Vector2(64.0, 32.0), Vector4(1.0, 0.0, 0.8, 1.0)));
	group->Add(new Sprite(Vector3(32 + 32 / 2, 32 - 8, 0), Vector2(32.0, 16.0), Vector4(0.0, 0.0, 1.0, 1.0)));
	layer.Add(group);
	
	
	GLfloat texIDs[] = {
		1, 2, 3, 4
	};
	shader.SetUniform1fv("textures", texIDs, 4);
	

	/////
	int frames = 0;
	long long timer = GetCurrentEpochToMillis();
	float dt = 0.f;

	long long lastTime = GetCurrentEpochToMillis();
	long long currentTime = 0;
	/////

	float counter = 0.0;
	float step = 0;
	while (!window.IsClosed()){
		/////
		currentTime = GetCurrentEpochToMillis();
		dt = (currentTime - lastTime) / (1000.0 / 60.f);
		lastTime = currentTime;
		/////
		window.ClearScreen();

		background.Render();
		
		layer.Render();
		
		step += 0.01;
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