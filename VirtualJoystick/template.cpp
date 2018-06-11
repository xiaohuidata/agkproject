// Includes

#include "template.h"



// Namespace

using namespace AGK;



app App;







void app::Begin(void)

{

	agk::SetWindowTitle("Virtual Joystick");



	agk::SetVirtualResolution (DEVICE_WIDTH, DEVICE_HEIGHT);

//	agk::SetClearColor( 151,170,204 ); // light blue

//	agk::SetSyncRate(60,0);

//	agk::SetScissor(0,0,0,0);





	// 增加虚拟手柄  1-4

	// agk::AddVirtualJoystick(index, x, y, Size);



	// 设置虚拟手柄位置

	// agk::SetVirtualJoystickPosition(Index, x, y);



	// 设置虚拟手柄大小

	// agk::SetVirtualJoystickSize(Index, Size);



	// 设置虚拟手柄透明度

	// agk::SetVirtualJoystickAlpha(Index, Alpha1, Alpha2);

	// Alpha 0-255， Alpha1手柄外圈的值，Alpha2手柄内圈的值。0完全透明，255完全不透明。



	// 设置禁用或启用虚拟手柄  0禁用，1启动

	// agk::SetVirtualJoystickActive(Index, Active);



	// 设置虚拟手柄的可见性  0隐藏手柄，1显示

	// agk::SetVirtualJoystickVisible(Index, Visible);



	// 更改虚拟手柄的图像

	// agk::SetVirtualJoystickImageOuter(Index, Image); 内圈 图像1

	// agk::SetVirtualJoystickImageInner(Index, Image); 外圈 图像2



	// 判断虚拟手柄是否存在     return 1 存在，0 不存在

	// int virtualJoystickExists = agk::GetVirtualJoystickExists(1);



	// 删除虚拟手柄

	// agk::DeleteVirtualJoystick(2);



	// 设置虚拟手柄的死亡区域      所以虚拟手柄的敏感度      死亡区域值为1将完全禁用手柄（最不敏感），为0则最敏感。  默认0.15。

	// agk::SetVirtualJoystickDeadZone(0.05);



	// 获取虚拟手柄的输入

	// float joystickX = agk::GetVirtualJoystickX(Index);

	// float joystickY = agk::GetVirtualJoystickY(Index);



	SpriteIndex = agk::CreateSprite(agk::LoadImage("rabbit.png"));

	float joyX = DEVICE_WIDTH / 2;

	float joyY = DEVICE_HEIGHT - JoySize / 2;



	agk::AddVirtualJoystick(1, 50, 50, 100);

//	agk::AddVirtualJoystick(1, 50, 50, 50);

//	agk::SetVirtualJoystickVisible(1, 1);

	agk::SetVirtualJoystickPosition(1, joyX, joyX);

}



int app::Loop (void)

{

//	if (agk::GetVirtualJoystickExists(1))

//		agk::Print( agk::ScreenFPS() );



	float joystickX = agk::GetVirtualJoystickX(1);

	float joystickY = agk::GetVirtualJoystickY(1);



	// 两个函数，返回的是-0.9到0.9的值，具体取决于按下箭的箭头键

	float directionX = agk::GetDirectionX();

	float directionY = agk::GetDirectionY();



	float spriteX = agk::GetSpriteX(SpriteIndex);

	float spriteY = agk::GetSpriteY(SpriteIndex);



	float moveX = spriteX + joystickX + directionX;

	float moveY = spriteY + joystickY + directionY;



	agk::SetSpritePosition(SpriteIndex, moveX, moveY);





	// Key Pressed

	// Tab 按下时返回 1

	int tabPressed = agk::GetRawKeyPressed(AGK_KEY_TAB);

	// 按住空格 1

	int spacePressed = agk::GetRawKeyPressed(AGK_KEY_SPACE);

	// 松起回车 1

	int entPressed = agk::GetRawKeyPressed(AGK_KEY_ENTER);

	// 判断按下的最后一个键

	int keyCode = agk::GetRawLastKey();



	switch (keyCode)

	{

	case AGK_KEY_SPACE:

		agk::Print("You pressed the spacebar.");

		break;

	case AGK_KEY_ENTER:

		agk::Print("You presed the enter key.");

		break;

	default:
		agk::Print("Press the spacebar or enter key.");
		break;

	}



	agk::Sync();



	return 0; // return 1 to close app

}

void app::End (void)

{

}