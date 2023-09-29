#include "Mesh.h"
#include "objectMeshSummon.h"
#include "Render.h"

int main() {
	// glfw initiatizer
	glfwInit();
	// Tells glfw what type of opengl I use
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// could change dynamically
	int width = 2000; int height = 2000;

	// window init takes width, height, name, fullscreen or not,?
	GLFWwindow* window = glfwCreateWindow(width, height, "AstroDynPro", NULL, NULL);
	// Error check
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	// Load GLAD and configure to OpenGL
	gladLoadGL();
	// Specify the window dimensions
	glViewport(0, 0, width, height);

	//------------------------------------------------------------------------------------------------------------

	// Celestial Textures, parameters:
	//const char* path to picture, light reflection texture type, texture unit number, color pixel format, color pixel data type
	Texture mercuryT[] = {
		Texture("Textures/SQmercury.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE)
	};
	Texture venusT[] = {
		Texture("Textures/SQvenus.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE)
	};
	Texture earthT[] = {
		Texture("Textures/earth4096.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE)
	};
	Texture moonT[] = {
		Texture("Textures/moon4096.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE)
	};
	Texture marsT[] = {
		Texture("Textures/SQmars.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE)
	};
	Texture jupiterT[] = {
		Texture("Textures/SQjupiter.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE)
	};
	Texture saturnT[] = {
		Texture("Textures/SQsaturn.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE)
	};
	Texture saturnRT[] = {
		Texture("Textures/SQsaturnRings.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE)
	};
	Texture uranusT[] = {
		Texture("Textures/SQuranus.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE)
	};
	Texture neptuneT[] = {
		Texture("Textures/SQneptune.jpg", "diffuse", 0, GL_RGB, GL_UNSIGNED_BYTE)
	};

	// Celestial Body initialization

	Object mercuryObj;
	mercuryObj.Sphere(0.0351f, 0.2f, 0.4f, 0.3f); // initialize as sphere
	std::vector <Texture> mercuryTex(mercuryT, mercuryT + sizeof(mercuryT) / sizeof(Texture));
	glm::vec3 mercuryPos = glm::vec3(61.4f, 0.0f, 0.0f);
	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f); // dummy color, dull object
	Shader dullShader("default.vert", "default.frag"); // Initialize dull shader program
	Mesh mercury("Mercury", mercuryObj.vertices, mercuryObj.indices, mercuryTex, false, false, lightColor, mercuryPos, &dullShader, 0.00001651f);
	mercury.AxialTilt(2);
	
	// Venus Mesh
	Object venusObj;
	venusObj.Sphere(0.0869f, 0.2f, 0.4f, 0.3f); // initialize as sphere
	std::vector <Texture> venusTex(venusT, venusT + sizeof(venusT) / sizeof(Texture));
	glm::vec3 venusPos = glm::vec3(143.6f, 0.0f, 0.0f);
	Mesh venus("Venus", venusObj.vertices, venusObj.indices, venusTex, false, false, lightColor, venusPos, &dullShader, 0.00002447f);
	venus.AxialTilt(3);
	
	// Earth Mesh creation
	Object earthObj;
	//earthObj.Box(0.5f, 0.2f, 0.4f, 0.3f); // initialize as box
	earthObj.Sphere(0.0916f, 0.2f, 0.4f, 0.3f); // initialize as sphere
	std::vector <Texture> earthTex(earthT, earthT + sizeof(earthT) / sizeof(Texture));
	glm::vec3 earthPos = glm::vec3(200.0f, 0.0f, 0.0f); 
	// Initialize shader program
	Shader dullShader3("default.vert", "default.frag");
	Mesh earth("Earth", earthObj.vertices, earthObj.indices, earthTex, false, false, lightColor, earthPos, &dullShader, 0.000030027f);
	earth.AxialTilt(23.5);

	// Moon Mesh creation
	Object moonObj;
	moonObj.Sphere(0.0249f, 0.8f, 0.8f, 0.8f); // initialize as box
	std::vector <Texture> moonTex(moonT, moonT + sizeof(moonT) / sizeof(Texture));
	glm::vec3 moonPos = glm::vec3(205.229f, 0.0f, 0.0f); 
	Mesh moon("Moon", moonObj.vertices, moonObj.indices, moonTex, false, false, lightColor, moonPos, &dullShader, 0.00004f); // mass needs changing
	moon.AxialTilt(1.5);

	// Mars Mesh
	Object marsObj;
	marsObj.Sphere(0.0487f, 0.2f, 0.4f, 0.3f); // initialize as sphere
	std::vector <Texture> marsTex(marsT, marsT + sizeof(marsT) / sizeof(Texture));
	glm::vec3 marsPos = glm::vec3(276.28f, 0.0f, 0.0f);
	Mesh mars("Mars", marsObj.vertices, marsObj.indices, marsTex, false, false, lightColor, marsPos, &dullShader, 0.00003213f);
	mars.AxialTilt(25);

	// Jupiter Mesh
	Object jupiterObj;
	jupiterObj.Sphere(1.0276f, 0.2f, 0.4f, 0.3f); // initialize as sphere
	std::vector <Texture> jupiterTex(jupiterT, jupiterT + sizeof(jupiterT) / sizeof(Texture));
	glm::vec3 jupiterPos = glm::vec3(990.0f, 0.0f, 0.0f);
	Mesh jupiter("Jupiter", jupiterObj.vertices, jupiterObj.indices, jupiterTex, false, false, lightColor, jupiterPos, &dullShader, 0.009546f);
	jupiter.AxialTilt(3);

	// Saturn Mesh
	Object saturnObj;
	saturnObj.Sphere(0.8370f, 0.2f, 0.4f, 0.3f); // initialize as sphere
	std::vector <Texture> saturnTex(saturnT, saturnT + sizeof(saturnT) / sizeof(Texture));
	glm::vec3 saturnPos = glm::vec3(1808.0f, 0.0f, 0.0f);
	Mesh saturn("Saturn", saturnObj.vertices, saturnObj.indices, saturnTex, false, false, lightColor, saturnPos, &dullShader, 0.002857f);
	saturn.AxialTilt(26.73);

	Object saturnRings;
	saturnRings.Rings(0.93416f, 1.94745f, 0.2f, 0.4f, 0.3f); // accurate size compared to saturn's radius
	std::vector <Texture> saturnRTex(saturnRT, saturnRT + sizeof(saturnRT) / sizeof(Texture));
	Mesh saturnR("Saturn's Rings", saturnRings.vertices, saturnRings.indices, saturnRTex, false, true, lightColor, saturnPos, &dullShader, 0.002857f);
	saturnR.AxialTilt(26.73);

	// Uranus Mesh
	Object uranusObj;
	uranusObj.Sphere(0.3645f, 0.2f, 0.4f, 0.3f); // initialize as sphere
	std::vector <Texture> uranusTex(uranusT, uranusT + sizeof(uranusT) / sizeof(Texture));
	glm::vec3 uranusPos = glm::vec3(3680.0f, 0.0f, 0.0f);
	Mesh uranus("Uranus", uranusObj.vertices, uranusObj.indices, uranusTex, false, false, lightColor, uranusPos, &dullShader, 0.0004365f);
	uranus.AxialTilt(97.7);

	// Neptune Mesh
	Object neptuneObj;
	neptuneObj.Sphere(0.3539f, 0.2f, 0.4f, 0.3f); // initialize as sphere
	std::vector <Texture> neptuneTex(neptuneT, neptuneT + sizeof(neptuneT) / sizeof(Texture));
	glm::vec3 neptunePos = glm::vec3(5962.0f, 0.0f, 0.0f);
	Mesh neptune("Neptune", neptuneObj.vertices, neptuneObj.indices, neptuneTex, false, false, lightColor, neptunePos, &dullShader, 0.0005149f);
	neptune.AxialTilt(28);

	// Sun Mesh creation
	Object sunObj;
	sunObj.Sphere(10.0f, 1.0f, 1.0f, 1.0f);
	std::vector <Texture> sunTex(neptuneT, neptuneT + sizeof(neptuneT) / sizeof(Texture));
	glm::vec3 lightPos = glm::vec3(0.0f, 0.0f, 0.0f);
	// Initialize shader program
	Shader lightShader("light.vert", "light.frag");
	Mesh sun("Sun", sunObj.vertices, sunObj.indices, sunTex, true, false, lightColor, lightPos, &lightShader, 10.0f);

	// set uniforms for emission light shaders
	sun.emissionShader();
	// set uniforms for dull shaders
	mercury.dullShader(sun);
	venus.dullShader(sun);
	earth.dullShader(sun);
	moon.dullShader(sun);
	mars.dullShader(sun);
	jupiter.dullShader(sun);
	saturn.dullShader(sun);
	saturnR.dullShader(sun);
	uranus.dullShader(sun);
	neptune.dullShader(sun);

	// set of all bodies rendered
	const int numBodies = 11;
	Mesh* bodies[numBodies] = { &sun, &mercury, &venus, &earth, &moon, &mars, &jupiter, &saturn, &saturnR, &uranus, &neptune};
	glm::vec3* bodyPos[numBodies];
	

	// Acheive 3D depth
	glEnable(GL_DEPTH_TEST);

	// Create Camera with initial position
	Camera camera(width, height, glm::vec3(130.0f, 0.0f, 0.0f));

	// Create Renderer and initialize
	RenderSet Renderer(window, camera, width, height);
	Renderer.set();
	
	bool skyboxOn = true;
	float dt = 1.0f;

	float prevTime = glfwGetTime();
	// keeps window open
	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.24f, 0.28f, 0.45f, 1.0f);
		float currTime = glfwGetTime();
		
		// pass positions of objects for focus
		for (int i = 0; i < numBodies; i++) {
			bodyPos[i] = &(bodies[i]->Pos);
		}

		// for movement inputs
		(camera).smoothInputs(window, bodyPos); 
		if (currTime - prevTime > 0.08) {
			prevTime = currTime;
			// for single click inputs
			(camera).hardInputs(window, bodyPos, numBodies);
			if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) { // toggles skybox
				skyboxOn = !skyboxOn;
			}
			// time warp
			if (glfwGetKey(window, GLFW_KEY_RIGHT_BRACKET) == GLFW_PRESS) {
				dt /= 2; // time step increase
			}
			else if (glfwGetKey(window, GLFW_KEY_LEFT_BRACKET) == GLFW_PRESS) {
				dt *= 2; // time step decrease
			}
		}
		(camera).updateMatrix(45.0f, 0.1f, 6100.0f); // to be able to see the sun from neptune

		//Render scene
		Renderer.ShadowRender(bodies, numBodies, &camera);
		Renderer.Move(bodies, dt);
		if (skyboxOn) { 
			Renderer.RenderSkyBox(&camera);
		}

		//update image each frame
		glfwSwapBuffers(window);
		// constantly checks current state of window 
		glfwPollEvents();
	}

	// terminatation handling

	dullShader.Delete();
	lightShader.Delete();
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}