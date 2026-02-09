#include "SteeringBehaviors.h"

#include <iostream>

#include "GameAIProg/Movement/SteeringBehaviors/SteeringAgent.h"

//SEEK
//*******
// TODO: Do the Week01 assignment :^)
SteeringOutput Seek::CalculateSteering(float DeltaT, ASteeringAgent & Agent)
{
	SteeringOutput Steering{};
	
	Steering.LinearVelocity = Target.Position - Agent.GetPosition();
	//	linearvelocity is already normalized in steeringagent.cpp
	
	
	// add debug rendering for grades (Agent.GetWorld())
	
	return Steering;
}

SteeringOutput Flee::CalculateSteering(float DeltaT, ASteeringAgent & Agent)
{
	SteeringOutput Steering{};
	
	Steering.LinearVelocity = Agent.GetPosition() - Target.Position;
	//	linearvelocity is already normalized in steeringagent.cpp
	
	
	// add debug rendering for grades 
	
	return Steering;
}

SteeringOutput Arrive::CalculateSteering(float DeltaT, ASteeringAgent & Agent)
{
	const float Distance = FVector2D::Distance(Agent.GetPosition(), Target.Position);
	const float BaseMaxSpeed = Agent.GetMaxLinearSpeed();
	SteeringOutput Steering{};
	if (Distance <= TargetRadius)
	{
		Agent.SetMaxLinearSpeed(0.0f);
		std::cout << "small";
	}
	else if (Distance <= SlowRadius)
	{
		Agent.SetMaxLinearSpeed(Distance);
	}
	else
	{
		Agent.SetMaxLinearSpeed(BaseMaxSpeed);
		Steering.LinearVelocity = Target.Position - Agent.GetPosition();
		std::cout << "big";

	}
	//	linearvelocity is already normalized in steeringagent.cpp
	
	
	// add debug rendering for grades 
	
	return Steering;
}