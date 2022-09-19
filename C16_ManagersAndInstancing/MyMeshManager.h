/*----------------------------------------------
Programmer: Alberto Bobadilla (labigm@gmail.com)
Date: 2021/06
----------------------------------------------*/
#ifndef __MYMESHMANAGER_H_
#define __MYMESHMANAGER_H_
#include "BTX/BTX.h"
#include "MyCamera.h"
namespace BTX
{

//MyMeshManager singleton
class MyMeshManager
{
	MyCamera* m_pCamera = nullptr; //Camera to use for all meshes
	std::vector<Mesh*> m_meshList; //List of all the meshes added to the system
	std::vector<std::vector<matrix4>> m_renderList; //list of lists of render calls
	static MyMeshManager* m_pInstance; // Singleton pointer

public:
	//Singleton Methods
	/*
	USAGE: Gets/Constructs the singleton pointer
	*/
	static MyMeshManager* GetInstance();
	/*
	USAGE: Destroys the singleton and releases its memory
	*/
	static void ReleaseInstance(void);
	/*
	USAGE: Adds a mesh to the list of meshes
	ARGUMENTS: Mesh* a_pMesh -> mesh to add
	OUTPUT: Index of the mesh in the list. If the index is -1 there was an error
	somewhere while adding the mesh.
	*/
	int AddMesh(Mesh* a_pMesh);
	/*
	USAGE: Gets the Mesh pointer from the map by name;
	WARNING: DO NOT change the name of the mesh or it will lose its position in map
	DO NOT delete the pointer outside of the manager
	ARGUMENTS: String a_sName -> name of the inquired mesh
	OUTPUT: index of the mesh in the mesh list, -1 if not found
	*/
	int GetMeshIndex(Mesh* a_pMesh);
	/*
	USAGE: Returns the mesh specified by index from the list of Meshes
	ARGUMENTS: uint nMesh -> index of the mesh
	OUTPUT: Inquired mesh
	*/
	Mesh* GetMesh(uint nMesh);
	/*
	USAGE: Generates a cube
	ARGUMENTS:
	-	float a_fSize -> Size of each side
	-	vector3 a_v3Color -> Color of the mesh
	OUTPUT: Index of the generated Mesh
	*/
	int GenerateCube(float a_fSize, vector3 a_v3Color = C_WHITE);
	/*
	USAGE:Generates a cone mesh
	ARGUMENTS:
	-	float a_fRadius -> radius
	-	float a_fHeight -> how tall is the mesh
	-	int a_nSubdivisions -> divisions of the cap
	-	vector3 a_v3Color -> Color of the mesh
	OUTPUT: Index of the generated Mesh
	*/
	int GenerateCone(float a_fRadius, float a_fHeight, int a_nSubdivisions, vector3 a_v3Color = C_WHITE);
	/*
	USAGE: Generates a cylinder mesh
	ARGUMENTS:
	-	float a_fRadius -> radius
	-	float a_fHeight -> how tall is the mesh
	-	int a_nSubdivisions -> divisions on the cap
	-	vector3 a_v3Color -> Color of the mesh
	OUTPUT: Index of the generated Mesh
	*/
	int GenerateCylinder(float a_fRadius, float a_fHeight, int a_nSubdivisions, vector3 a_v3Color = C_WHITE);
	/*
	USAGE: Generates a tube mesh
	ARGUMENTS:
	-	float a_fOuterRadius -> outer radius
	-	float a_fInnerRadius -> inner radius
	-	float a_fHeight -> how tall is the mesh
	-	int a_nSubdivisions -> divisions on the cap
	-	4a_v3Color -> Color of the mesh
	OUTPUT: Index of the generated Mesh
	*/
	int GenerateTube(float a_fOuterRadius, float a_fInnerRadius, float a_fHeight, int a_nSubdivisions, vector3 a_v3Color = C_WHITE);
	/*
	USAGE: Generates a torus mesh
	ARGUMENTS:
	-	float a_fOuterRadius -> Outer radius
	-	float a_fInnerRadius -> Inner Radius
	-	int a_nSubdivisionHeight -> divisions vertical
	-	int a_nSubdivisionAxis -> divisions along the roundness of the mesh
	-	a_v3Color -> Color of the mesh
	OUTPUT: Index of the generated Mesh
	*/
	int GenerateTorus(float a_fOuterRadius, float a_fInnerRadius, int a_nSubdivisionHeight, int a_nSubdivisionAxis, vector3 a_v3Color = C_WHITE);
	/*
	USAGE: Generates a Sphere mesh
	ARGUMENTS:
	-	float a_fDiameter -> diameter of the sphere (radius times 2)
	-	int a_nSubdivisions -> Number of divisions, not a lot of difference in shapes larger than 3 subdivisions
	-	a_v3Color -> Color of the mesh
	OUTPUT: Index of the generated Mesh
	*/
	int GenerateSphere(float a_fDiameter, int a_nSubdivisions, vector3 a_v3Color = C_WHITE);
	/*
	USAGE: Renders the cube on the specified position
	ARGUMENTS:	matrix4 a_m4ToWorld -> Space to render the primitive onto
	This matrix will include transformation information such as the primitive's
	position, orientation, and scale.
	*/
	void AddCubeToRenderList(matrix4 a_m4ToWorld);
	/*
	USAGE: Renders the cone on the specified position
	ARGUMENTS:	matrix4 a_m4ToWorld -> Space to render the primitive onto
	This matrix will include transformation information such as the primitive's
	position, orientation, and scale.
	*/
	void AddConeToRenderList(matrix4 a_m4ToWorld);
	/*
	USAGE: Renders the cylinder on the specified position
	ARGUMENTS:	matrix4 a_m4ToWorld -> Space to render the primitive onto
	This matrix will include transformation information such as the primitive's
	position, orientation, and scale.
	*/
	void AddCylinderToRenderList(matrix4 a_m4ToWorld);
	/*
	USAGE: Renders the tube on the specified position
	ARGUMENTS:	matrix4 a_m4ToWorld -> Space to render the primitive onto
	This matrix will include transformation information such as the primitive's
	position, orientation, and scale.
	*/
	void AddTubeToRenderList(matrix4 a_m4ToWorld);
	/*
	USAGE: Renders the torus on the specified position
	ARGUMENTS:	matrix4 a_m4ToWorld -> Space to render the primitive onto
	This matrix will include transformation information such as the primitive's
	position, orientation, and scale.
	*/
	void AddTorusToRenderList(matrix4 a_m4ToWorld);
	/*
	USAGE: Renders the sphere on the specified position
	ARGUMENTS:	matrix4 a_m4ToWorld -> Space to render the primitive onto
	This matrix will include transformation information such as the primitive's
	position, orientation, and scale.
	*/
	void AddSphereToRenderList(matrix4 a_m4ToWorld);
	/*
	USAGE: Finds the specified mesh and specifies a transform to display
	This method will go to the index specified in the mesh manager and check if
	there is a mesh there. If there is it will use the new transform and apply it to that mesh.
	ARGUMENTS:
	-	uint a_nIndex -> index of the mesh to apply transform to
	-	matrix4 a_m4Transform -> transform to apply
	OUTPUT: returns the name of the mesh that will render
	*/
	void AddMeshToRenderList(uint a_nIndex, matrix4 a_m4Transform);
	/*
	USAGE: Applies a transform to display to the specified mesh, the mesh will be lookout
	for in the map of meshes, using the mesh index if known will result in faster additions
	ARGUMENTS:
	-	Mesh* a_pMesh -> mesh to apply transform to
	-	matrix4 a_m4Transform -> transform to apply
	int a_Render = SOLID -> render options SOLID | WIRE
	OUTPUT: returns the name of the mesh that will render
	*/
	void AddMeshToRenderList(Mesh* a_pMesh, matrix4 a_m4Transform);
	/*
	USAGE: Clears the map of transforms
	*/
	void ClearRenderList(void);
	/*
	USAGE: Draws all the meshes in the transform map
	*/
	void Render(void);
	/*
	USAGE: Get the number of meshes in the mesh manager
	OUTPUT: number of meshes
	*/
	uint GetMeshCount(void);
	/*
	USAGE: Sets the camera to use for mesh drawing
	ARGUMENTS: a_pCamera -> The camera being passed in
	*/
	void SetCamera(MyCamera* a_pCamera);
private:
	//Rule of 3
	/*
	USAGE: Constructor
	ARGUMENTS: ---
	OUTPUT:
	*/
	MyMeshManager(void);
	/*
	USAGE: Copy Constructor
	ARGUMENTS:
	OUTPUT:
	*/
	MyMeshManager(MyMeshManager const& other);
	/*
	USAGE: Copy Assignment Operator
	ARGUMENTS:
	OUTPUT:
	*/
	MyMeshManager& operator=(MyMeshManager const& other);
	/*
	USAGE: Destructor
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	~MyMeshManager(void);
	//Other methods
	/*
	USAGE: Initializes the objects fields
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void Init(void);
	/*
	USAGE: Releases the objects memory
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void Release(void);
};

} //namespace BTX

#endif //__MyMeshManager_H_
/*
USAGE:
ARGUMENTS: ---
OUTPUT: ---
*/