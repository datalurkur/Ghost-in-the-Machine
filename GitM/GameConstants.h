#ifndef GAMECONSTANTS_H
#define GAMECONSTANTS_H

namespace PlayerConst {
	// Player Physics Constants
	extern const float JumpPower;
	extern const float Accel;
	extern const float MaxSpeed;
	extern const float MaxSpeedRt2; // Used for jumping horizontally

	// Player Dimensions
	extern const float Width;
	extern const float Height;

	// Jump Sensor Constants
	extern const float JumpSensorWidth;
	extern const float JumpSensorHeight;
	extern const float JumpSensorOffsetX;
	extern const float JumpSensorOffsetY;
};

#endif