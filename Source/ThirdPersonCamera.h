//
// COMP 371 Assignment Framework
//
// Created by Nicolas Bergeron on 8/7/14.
// Updated by Gary Chang on 28/1/15
//
// Copyright (c) 2014-2015 Concordia University. All rights reserved.
//

#pragma once

#include "Camera.h"
#include "Model.h"

class ThirdPersonCamera : public Camera
{
public:
    ThirdPersonCamera(Model* targetModel);
    virtual ~ThirdPersonCamera();

    virtual void Update(float dt);
    virtual glm::mat4 GetViewMatrix() const;

private:
	void TranslateControls(float dt, bool space, bool shift, bool a, bool d, bool w, bool s, bool mouseLeft);
    virtual void CalculateCameraBasis();
	bool isUpBetween90and270() const;
	bool isTargetModelOutOfBounds() const;
	std::vector<float> getVHAnglesBetweenVectors(glm::vec3 vector1, glm::vec3 vector2) const;
    Model* mTargetModel;
    
    // Cartesian Coordinates
    float mHorizontalAngle;
    float mVerticalAngle;
    float mRadius;
    
    // Camera Vectors
    glm::vec3 mPosition;
    glm::vec3 mLookAt;
    glm::vec3 mRight;
	glm::vec3 mUp;

	// movement speeds
	float mModelHorizontalSensitivity;
	float mModelVerticalSensitivity;
	float mModelStandardSpeed;
	float mModelAcceration;
	float mModelDeceleration;
	float mModelCurrentSpeed;
	float mModelAnimationSpeed;
	static const float SPEED_INCREASE_PERCENTAGE;
	static const float SPEED_DECREASE_PERCENTAGE;

	// animation variables
	float mModelCurrentPitch;
	float mModelCurrentYaw;
	float mModelCurrentRoll;
	static const float MAX_ANIMATION_PITCH_ANGLE;
	static const float MAX_ANIMATION_YAW_ANGLE;
	static const float MAX_ANIMATION_ROLL_ANGLE;

	// player variables
	static const float PLAYER_BOUNDING_GAME_RADIUS;
};