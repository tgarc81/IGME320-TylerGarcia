/*----------------------------------------------
Programmer: Alberto Bobadilla (labigm@gmail.com)
Date: 2021/06
----------------------------------------------*/
#ifndef __MYRIGIDBODY_H_
#define __MYRIGIDBODY_H_

#include "BTX\BTX.h"

namespace BTX
{

//System Class
class MyRigidBody
{
	ModelManager* m_pModelMngr = nullptr; //for displaying the Rigid Body

	bool m_bVisibleBS = false; //Visibility of bounding sphere
	bool m_bVisibleOBB = true; //Visibility of Oriented bounding box
	bool m_bVisibleARBB = true; //Visibility of axis (Re)aligned bounding box

	float m_fRadius = 0.0f; //Radius

	vector3 m_v3ColorColliding = C_RED; //Color when colliding
	vector3 m_v3ColorNotColliding = C_WHITE; //Color when not colliding

	vector3 m_v3Center = ZERO_V3; //center point in local space
	vector3 m_v3MinL = ZERO_V3; //minimum coordinate in local space (for OBB)
	vector3 m_v3MaxL = ZERO_V3; //maximum coordinate in local space (for OBB)

	vector3 m_v3MinG = ZERO_V3; //minimum coordinate in global space (for ARBB)
	vector3 m_v3MaxG = ZERO_V3; //maximum coordinate in global space (for ARBB)

	vector3 m_v3HalfWidth = ZERO_V3; //half the size of the Oriented Bounding Box
	vector3 m_v3ARBBSize = ZERO_V3;// size of the Axis (Re)Alligned Bounding Box

	matrix4 m_m4ToWorld = IDENTITY_M4; //Matrix that will take us from local to world coordinate

	std::set<MyRigidBody*> m_CollidingRBSet; //set of rigid bodies this one is colliding with

public:
	/*
	Usage: Constructor
	Arguments: std::vector<vector3> a_pointList -> list of points to make the Rigid Body for
	These points are what make up the model, which will be used to calculate points for the
	Rigid body's shape.
	Output: class object instance
	*/
	MyRigidBody(std::vector<vector3> a_pointList);
	/*
	Usage: Copy Constructor
	Arguments: class object to copy
	Output: class object instance
	*/
	MyRigidBody(MyRigidBody const& other);
	/*
	Usage: Copy Assignment Operator
	Arguments: class object to copy
	Output: ---
	*/
	MyRigidBody& operator=(MyRigidBody const& other);
	/*
	Usage: Destructor
	Arguments: ---
	Output: ---
	*/
	~MyRigidBody(void);
	/*
	Usage: Changes object contents for other object's
	Arguments: other -> object to swap content from
	*/
	void Swap(MyRigidBody& other);

	/*
	USAGE: Will render the Rigid Body at the model to world matrix
	*/
	void AddToRenderList(void);
	/*
	USAGE: Clears the list of collisions in the world
	*/
	void ClearCollidingList(void);

	/*
	USAGE: Mark collision with the incoming Rigid Body
	ARGUMENTS: MyRigidBody* other -> inspected rigid body
	*/
	void AddCollisionWith(MyRigidBody* other);

	/*
	USAGE: Remove marked collision with the incoming Rigid Body
	ARGUMENTS: MyRigidBody* other -> inspected rigid body
	*/
	void RemoveCollisionWith(MyRigidBody* other);

	/*
	USAGE: Tells if the object is colliding with the incoming one
	ARGUMENTS: other -> The Object being tested for collision with current Rigidbody
	OUTPUT: Whether or not the two objects are colliding
	*/
	bool IsColliding(MyRigidBody* const other);
#pragma region Accessors
	/*
	Usage: Gets visibility of bounding sphere
	Output: visibility
	*/
	bool GetVisibleBS(void);
	/*
	Usage: Sets visibility of bounding sphere
	Arguments: bool a_bVisibility -> visibility to set
	*/
	void SetVisibleBS(bool a_bVisibility);
	/*
	Usage: Gets visibility of oriented bounding box
	Output: visibility
	*/
	bool GetVisibleOBB(void);
	/*
	Usage: Sets visibility of oriented bounding box
	Arguments: bool a_bVisibility -> visibility to set
	*/
	void SetVisibleOBB(bool a_bVisibility);
	/*
	Usage: Gets visibility of axis (re)aligned bounding box
	Output: visibility
	*/
	bool GetVisibleARBB(void);
	/*
	Usage: Sets visibility of axis (re)aligned bounding box
	Arguments: bool a_bVisibility -> visibility to set
	*/
	void SetVisibleARBB(bool a_bVisibility);
	/*
	Usage: Gets the color when colliding
	Output: color
	*/
	vector3 GetColorColliding(void);
	/*
	Usage: Sets the color when colliding
	Arguments: vector3 a_v3Color -> color
	*/
	void SetColorColliding(vector3 a_v3Color);
	/*
	Usage: Gets the color when not colliding
	Output: color
	*/
	vector3 GetColorNotColliding(void);
	/*
	Usage: Sets the color when colliding
	Arguments: vector3 a_v3Color -> color
	*/
	void SetColorNotColliding(vector3 a_v3Color);
	/*
	Usage: Gets visibility
	Output: visibility
	*/
	bool GetVisible(void);
	/*
	Usage: Gets radius
	Output: radius
	*/
	float GetRadius(void);
	/*
	Usage: Gets the color
	Output: color
	*/
	vector3 GetColor(void);
	/*
	Usage: Sets the color
	Arguments: vector3 a_v3Color -> color
	*/
	void SetColor(vector3 a_v3Color);
	/*
	Usage: Gets center in local space
	Center will be relative to the points contained in the model,
	and will not include anything from other objects in the world
	Output: center
	*/
	vector3 GetCenterLocal(void);
	/*
	Usage: Gets minimum vector in local space
	Point will be relative to the points contained in the model,
	and will not include anything from other objects in the world
	Output: min vector
	*/
	vector3 GetMinLocal(void);
	/*
	Usage: Gets maximum vector in local space
	Point will be relative to the points contained in the model,
	and will not include anything from other objects in the world
	Output: max vector
	*/
	vector3 GetMaxLocal(void);
	/*
	Usage: Gets center in global space
	Center will be relative to all objects in the world
	Output: center
	*/
	vector3 GetCenterGlobal(void);
	/*
	Usage: Gets minimum vector in local space
	Point will be relative to all objects in the world
	Output: min vector
	*/
	vector3 GetMinGlobal(void);
	/*
	Usage: Gets max vector in global space
	Point will be relative to all objects in the world
	Output: max vector
	*/
	vector3 GetMaxGlobal(void);
	/*
	Usage: Gets the size of the model divided by 2
	Output: halfwidth vector
	This vector will be used to store the half widths in the
	x-direction, y-direction, and z-direction
	*/
	vector3 GetHalfWidth(void);
	/*
	Usage: Gets Model to World matrix
	Output: The Model Matrix containing information in Global Space
	*/
	matrix4 GetModelMatrix(void);
	/*
	Usage: Sets Model to World matrix
	Arguments: The Model Matrix containing information in Global Space
	*/
	void SetModelMatrix(matrix4 a_m4ModelMatrix);
#pragma endregion

private:
	/*
	Usage: Deallocates member fields
	Arguments: ---
	Output: ---
	*/
	void Release(void);
	/*
	Usage: Allocates member fields
	Arguments: ---
	Output: ---
	*/
	void Init(void);
};//class

} //namespace BTX

#endif //__MYRIGIDBODY_H_

/*
USAGE:
ARGUMENTS: ---
OUTPUT: ---
*/