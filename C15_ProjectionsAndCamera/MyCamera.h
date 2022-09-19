/*----------------------------------------------
Programmer: Alberto Bobadilla (labigm@gmail.com)
Date: 2017/06
----------------------------------------------*/
#ifndef __MYCAMERACLASS_H_
#define __MYCAMERACLASS_H_

#include "BTX/BTX.h"

namespace BTX
{

class MyCamera
{
	vector3 m_v3Position = vector3(0.0f, 0.0f, 10.0f); //Where my camera is located
	vector3 m_v3Target = vector3(0.0f, 0.0f, 0.0f); //What I'm looking at
	vector3 m_v3Up = vector3(0.0f, 1.0f, 0.0f); //What is up

	vector3 m_v3Forward = vector3(0.0f, 0.0f,-1.0f); //View vector
	vector3 m_v3Upward = vector3(0.0f, 1.0f, 0.0f); //where my head is pointing up
	vector3 m_v3Rightwart = vector3(0.0f, 1.0f, 0.0f); //What is to my right
	
	matrix4 m_m4View; //View matrix
	matrix4 m_m4Projection; //Projection Matrix
public:
	/*
	USAGE: Constructor
	ARGUMENTS: ---
	OUTPUT: the class object
	*/
	MyCamera();

	/*
	USAGE: constructor
	ARGUMENTS:
	-	vector3 a_v3Position -> Where my camera is located
	-	vector3 a_v3Target -> What I'm looking at
	-	vector3 a_v3Upward -> What is up
	OUTPUT: ---
	*/
	MyCamera(vector3 a_v3Position, vector3 a_v3Target, vector3 a_v3Upward);

	/*
	USAGE: Copy constructor
	ARGUMENTS: MyCamera const& other -> object to copy
	OUTPUT: ---
	*/
	MyCamera(MyCamera const& other);

	/*
	USAGE: Copy Assignment operator
	ARGUMENTS: MyCamera const& other -> object to copy
	OUTPUT: ---
	*/
	MyCamera& operator=(MyCamera const& other);

	/*
	USAGE: Initialize the class
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void Init(void);

	/*
	USAGE: Release pointers in the class
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void Release(void);

	/*
	USAGE: swap the content with an incoming object
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void Swap(MyCamera& other);

	/*
	USAGE: Destructor
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	~MyCamera(void);

	/*
	USAGE: Sets the position of the camera
	ARGUMENTS: vector3 a_v3Position -> Position where we want the camera to be
	OUTPUT: ---
	*/
	void SetPosition(vector3 a_v3Position);

	/*
	USAGE: Gets the position of the camera
	ARGUMENTS: ---
	OUTPUT: position of the camera
	*/
	vector3 GetPosition(void);

	/*
	USAGE: Sets the target of the camera
	ARGUMENTS: vector3 a_v3Target -> What we want the camera to look at
	Think of the target as the direction you are looking in an FPS game, 
	whatever the target is set to is the exact direction you will be facing.
	OUTPUT: ---
	*/
	void SetTarget(vector3 a_v3Target);

	/*
	USAGE: Gets the target of the camera
	ARGUMENTS: ---
	OUTPUT: target of the camera
	*/
	vector3 GetTarget(void);

	/*
	USAGE: Sets the upwards vector of the camera
	ARGUMENTS: vector3 a_v3Up -> What up means in the world
	This will be the upwards vector which defaults to the global Y-axis.
	However changing it will allow your camera to move upwards relative to 
	the direction you are looking.
	OUTPUT: ---
	*/
	void SetUp(vector3 a_v3Up);

	/*
	USAGE: Gets the upwards vector of the camera
	ARGUMENTS: ---
	OUTPUT: upwards vector of the camera
	*/
	vector3 GetUp(void);

	/*
	USAGE: Gets the projection matrix of the camera
	ARGUMENTS: ---
	OUTPUT: projection matrix of the camera
	This matrix will determine how objects look in the world based on different factors.
	Matrix may make things look distorted or normal depending on the values put in while calculating,
	and it is fed into rendering methods for displaying objects
	*/
	matrix4 GetProjectionMatrix(void);

	/*
	USAGE: Gets the view matrix of the camera
	ARGUMENTS: ---
	OUTPUT: view matrix of the camera
	This matrix will determine where the camera is, 
	where it is looking at, and what is considered upwards for it. 
	It is fed into rendering methods for displaying objects
	*/
	matrix4 GetViewMatrix(void);

	/*
	USAGE: Resets the camera to default values
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void ResetCamera(void);

	/*
	USAGE: Set the position target and up of the camera at once
	ARGUMENTS:
	-	vector3 a_v3Position -> Where my camera is located
	-	vector3 a_v3Target -> What I'm looking at
	-	vector3 a_v3Upward -> What is up
	These arguments are all straight forward, however the point of the method is to combine all 3
	functions into one in case you are looking to change them all with just one line of code
	OUTPUT: ---
	*/
	void SetPositionTargetAndUpward(vector3 a_v3Position, vector3 a_v3Target, vector3 a_v3Upward = AXIS_Y);

	/*
	USAGE: Calculate what the camera should be looking at with the values of position target and up
	This will be done by taking in those 3 values and setting where the camera is in the world, the direction it will be facing,
	and the upwards vector. This view matrix will then be passed into render functions when trying to display objects in the world.
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void CalculateViewMatrix(void);

	/*
	USAGE: Calculate how the camera sees the world
	This method will take into account different values such as the camera's FOV, aspect ratio, 
	near clipping plane, and far clipping plane. The combination of all these values
	will determine how the objects rendered in the world will look, if done correctly things will
	display normally but if not they may be distorted. This method will also be passed into render functions 
	when trying to display objects in the world.
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void CalculateProjectionMatrix(void);

};

} //namespace Simplex

#endif //__MYCAMERACLASS_H_

  /*
  USAGE:
  ARGUMENTS: ---
  OUTPUT: ---
  */