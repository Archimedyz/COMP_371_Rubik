//--------------------------------------------------------------------------------------------------------------
// Contributors
// Nicholas Dudek
// 
//--------------------------------------------------------------------------------------------------------------



#include "Projectile.h"
#include "Variables.h"
#include "Renderer.h"
#include <string>
// Include GLEW - OpenGL Extension Wrangler
#include <GL/glew.h>
#include "Loader.h"


time_t Projectile::LastFired = 0;
std::vector<glm::vec3> Projectile::vArray;
unsigned int Projectile::vertexbuffer;
unsigned int Projectile::uvbuffer;
unsigned int Projectile::normalbuffer;
unsigned int Projectile::elementbuffer;
std::vector<unsigned short> Projectile::indices;

void Projectile::LoadBuffers()
{
#if defined(PLATFORM_OSX)
	const char * modelPath = "Models/bullet.obj";
#else
	const char * modelPath = "../Resources/Models/bullet2.obj";
#endif
	Loader::loadModel(modelPath, Projectile::vArray, Projectile::vertexbuffer, Projectile::uvbuffer, Projectile::normalbuffer, Projectile::elementbuffer, Projectile::indices);
}


Projectile::Projectile()
{
	name = "PROJECTILE";
}

Projectile::~Projectile()
{
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
	glDeleteBuffers(1, &elementbuffer);
}

Projectile::Projectile(glm::vec3 o, glm::vec3 d)
{
	ka = 0.5f;
	kd = 0.3f;
	ks = 0.7f;
	n = 100.0f;
	CollisionsOn = true;
	mPosition = o;
	mDirection = glm::normalize(d);
	mCollisionRadius = 1;
	mSpeed = 45;
	name = "PROJECTILE";
}

void Projectile::Update(float dt)
{
	mPosition = mPosition + (mDirection*mSpeed*dt);
}

void Projectile::Draw()
{
	Model::Draw();

	GLuint WorldMatrixLocation = glGetUniformLocation(Renderer::GetShaderProgramID(), "WorldTransform");
	glUniformMatrix4fv(WorldMatrixLocation, 1, GL_FALSE, &GetWorldMatrix()[0][0]);

	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
		0,                  // attribute
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
		);

	// 2nd attribute buffer : UVs
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glVertexAttribPointer(
		1,                                // attribute
		2,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
		);

	// 3rd attribute buffer : normals
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
	glVertexAttribPointer(
		2,                                // attribute
		3,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
		);

	// Index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);

	// Draw the triangles !
	glDrawElements(
		GL_TRIANGLES,      // mode
		indices.size(),    // count
		GL_UNSIGNED_SHORT,   // type
		(void*)0           // element array buffer offset
		);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}

void Projectile::SetDirection(glm::vec3 dir)
{
	mDirection = dir;
}

void Projectile::SetLastFired(time_t t)
{
	LastFired = t;
}

glm::vec3 Projectile::GetDirection()
{
	return mDirection;
}

time_t Projectile::GetLastFired()
{
	return LastFired;
}

void Projectile::RenderShadowVolume(glm::vec4 a)
{

}