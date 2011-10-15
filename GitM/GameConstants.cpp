#include <GitM/GameConstants.h>
#include <Base/Base.h>

namespace PlayerConst {
	// Player Physics Constants
	const float JumpPower = 3.0f;
	const float Accel = 0.02f;
	const float MaxSpeed = 6.0f;
	const float MaxSpeedRt2 = MaxSpeed / sqrt(2.0f); // Used for jumping horizontally

	// Player Dimensions
	const float Width = 0.5f;
	const float Height = 1.0f;

	// Jump Sensor Constants
	const float JumpSensorWidth = Width / 2.0f;
	const float JumpSensorHeight = 0.1f;
	const float JumpSensorOffsetX = 0.0f;
	const float JumpSensorOffsetY = -(Height / 2.0f) - JumpSensorHeight;
};