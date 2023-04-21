#pragma once

#include "../GameObject.hpp"

class Player : public GameObject
{
public:
	void Start() override;
	void Update() override;
};