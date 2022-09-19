#include "AppClass.h"
void Application::InitVariables(void)
{
	////Change this to your name and email
	m_sProgrammer = "Tyler Garcia - tmg7946@rit.edu";
	vector3 v3Position(0.0f, 0.0f, 10.0f);
	vector3 v3Target = ZERO_V3;
	vector3 v3Upward = AXIS_Y;
	m_pCameraMngr->SetPositionTargetAndUpward(v3Position, v3Target, v3Upward);

	//Allocate the memory for the Meshes
	m_uMeshCount = 11;
	for (int i = 0; i < m_uMeshCount; i++)
	{
		MyMesh* mesh = new MyMesh();
		meshVector.push_back(mesh);
		meshVector[i]->GenerateCube(1.0f, C_BLACK);
	}
		
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();

	//Update Entity Manager
	m_pEntityMngr->Update();

	//Add objects to render list
	m_pEntityMngr->AddEntityToRenderList(-1, true);
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	int i = 0;

	//Calculate the model, view and projection matrix
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();
	matrix4 m4View = m_pCameraMngr->GetViewMatrix();

	matrix4 m4Scaling = glm::scale(IDENTITY_M4, vector3(1.0f, 1.0f, 1.0f));
	static float shiftValue = 0.0f; // Will be used to move the entire shape
	matrix4 m4Translation = glm::translate(IDENTITY_M4, vector3(shiftValue, 2.0f, 3.0f));
	matrix4 m4Translation2 = glm::translate(IDENTITY_M4, vector3(shiftValue + 1.0f, 2.0f, 3.0f));
	matrix4 m4Translation3 = glm::translate(IDENTITY_M4, vector3(shiftValue + 2.0f, 2.0f, 3.0f));
	matrix4 m4Translation4 = glm::translate(IDENTITY_M4, vector3(shiftValue - 1.0f, 2.0f, 3.0f));
	matrix4 m4Translation5 = glm::translate(IDENTITY_M4, vector3(shiftValue - 2.0f, 2.0f, 3.0f));
	matrix4 m4Translation6 = glm::translate(IDENTITY_M4, vector3(shiftValue, 1.0f, 3.0f));
	matrix4 m4Translation7 = glm::translate(IDENTITY_M4, vector3(shiftValue, 0.0f, 3.0f));
	matrix4 m4Translation8 = glm::translate(IDENTITY_M4, vector3(shiftValue, -1.0f, 3.0f));
	matrix4 m4Translation9 = glm::translate(IDENTITY_M4, vector3(shiftValue, -2.0f, 3.0f));
	matrix4 m4Translation10 = glm::translate(IDENTITY_M4, vector3(shiftValue, -3.0f, 3.0f));
	matrix4 m4Translation11 = glm::translate(IDENTITY_M4, vector3(shiftValue, -4.0f, 3.0f));

	shiftValue += 0.05f; // Shifts the shape over by adjusting the shiftValue variable
	matrix4 m4Model = m4Scaling * m4Translation;
	matrix4 m4Model2 = m4Scaling * m4Translation2;
	matrix4 m4Model3 = m4Scaling * m4Translation3;
	matrix4 m4Model4 = m4Scaling * m4Translation4;
	matrix4 m4Model5 = m4Scaling * m4Translation5;
	matrix4 m4Model6 = m4Scaling * m4Translation6;
	matrix4 m4Model7 = m4Scaling * m4Translation7;
	matrix4 m4Model8 = m4Scaling * m4Translation8;
	matrix4 m4Model9 = m4Scaling * m4Translation9;
	matrix4 m4Model10 = m4Scaling * m4Translation10;
	matrix4 m4Model11 = m4Scaling * m4Translation11;

	// Renders the top of the T
	meshVector[i]->Render(m4Projection, m4View, m4Model);
	i++;
	meshVector[i]->Render(m4Projection, m4View, m4Model2);
	i++;
	meshVector[i]->Render(m4Projection, m4View, m4Model3);
	i++;
	meshVector[i]->Render(m4Projection, m4View, m4Model4);
	i++;
	meshVector[i]->Render(m4Projection, m4View, m4Model5);
	i++;

	// Renders the stalk of the T
	meshVector[i]->Render(m4Projection, m4View, m4Model6);
	i++;
	meshVector[i]->Render(m4Projection, m4View, m4Model7);
	i++;
	meshVector[i]->Render(m4Projection, m4View, m4Model8);
	i++;
	meshVector[i]->Render(m4Projection, m4View, m4Model9);
	i++;
	meshVector[i]->Render(m4Projection, m4View, m4Model10);
	i++;
	meshVector[i]->Render(m4Projection, m4View, m4Model11);
	i++;


	// draw a skybox
	m_pModelMngr->AddSkyboxToRenderList();

	//render list call
	m_uRenderCallCount = m_pModelMngr->Render();

	//clear the render list
	m_pModelMngr->ClearRenderList();

	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	//Release meshes
	std::vector<MyMesh*> meshVector;
	int size = meshVector.size();
	for (uint i = 0; i < size; ++i)
	{
		if (meshVector[i] != nullptr)
		{
			delete meshVector[i];
			meshVector[i] = nullptr;
		}
	}

	//release GUI
	ShutdownGUI();
}