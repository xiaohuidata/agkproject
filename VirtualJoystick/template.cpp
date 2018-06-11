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





	// ���������ֱ�  1-4

	// agk::AddVirtualJoystick(index, x, y, Size);



	// ���������ֱ�λ��

	// agk::SetVirtualJoystickPosition(Index, x, y);



	// ���������ֱ���С

	// agk::SetVirtualJoystickSize(Index, Size);



	// ���������ֱ�͸����

	// agk::SetVirtualJoystickAlpha(Index, Alpha1, Alpha2);

	// Alpha 0-255�� Alpha1�ֱ���Ȧ��ֵ��Alpha2�ֱ���Ȧ��ֵ��0��ȫ͸����255��ȫ��͸����



	// ���ý��û����������ֱ�  0���ã�1����

	// agk::SetVirtualJoystickActive(Index, Active);



	// ���������ֱ��Ŀɼ���  0�����ֱ���1��ʾ

	// agk::SetVirtualJoystickVisible(Index, Visible);



	// ���������ֱ���ͼ��

	// agk::SetVirtualJoystickImageOuter(Index, Image); ��Ȧ ͼ��1

	// agk::SetVirtualJoystickImageInner(Index, Image); ��Ȧ ͼ��2



	// �ж������ֱ��Ƿ����     return 1 ���ڣ�0 ������

	// int virtualJoystickExists = agk::GetVirtualJoystickExists(1);



	// ɾ�������ֱ�

	// agk::DeleteVirtualJoystick(2);



	// ���������ֱ�����������      ���������ֱ������ж�      ��������ֵΪ1����ȫ�����ֱ�������У���Ϊ0�������С�  Ĭ��0.15��

	// agk::SetVirtualJoystickDeadZone(0.05);



	// ��ȡ�����ֱ�������

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



	// �������������ص���-0.9��0.9��ֵ������ȡ���ڰ��¼��ļ�ͷ��

	float directionX = agk::GetDirectionX();

	float directionY = agk::GetDirectionY();



	float spriteX = agk::GetSpriteX(SpriteIndex);

	float spriteY = agk::GetSpriteY(SpriteIndex);



	float moveX = spriteX + joystickX + directionX;

	float moveY = spriteY + joystickY + directionY;



	agk::SetSpritePosition(SpriteIndex, moveX, moveY);





	// Key Pressed

	// Tab ����ʱ���� 1

	int tabPressed = agk::GetRawKeyPressed(AGK_KEY_TAB);

	// ��ס�ո� 1

	int spacePressed = agk::GetRawKeyPressed(AGK_KEY_SPACE);

	// ����س� 1

	int entPressed = agk::GetRawKeyPressed(AGK_KEY_ENTER);

	// �жϰ��µ����һ����

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