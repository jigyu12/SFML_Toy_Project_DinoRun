#pragma once

enum class SceneIds
{
	None = -1,
	MainTitleScene,
	GameScene,
	Count,
};

// TopLeft, MiddleCenter, BottomRight etc....
enum class Origins
{
	None = -1,
	TL, TC, TR,
	ML, MC, MR,
	BL, BC, BR,
	Custom,
	Count,
};