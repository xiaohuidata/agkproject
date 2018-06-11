// Includes
#include <vector>
#include "template.h"

// Namespace
using namespace AGK;

app App;

std::vector<unsigned int> m_Resource;
unsigned int m_Mouse;

unsigned int m_Switch;
unsigned int m_On;
unsigned int m_Off;
unsigned int m_Light;
unsigned int m_Light_On;
unsigned int m_Light_Off;
unsigned int m_Background;
unsigned int m_MouseHeight;
unsigned int m_MouseWidth;
unsigned int m_Light_Height;
unsigned int m_Light_Width;


void app::Begin(void)
{
	agk::SetVirtualResolution (1024, 768);
	agk::SetClearColor( 151,170,204 ); // light blue
	agk::SetSyncRate(60,0);
	agk::SetScissor(0,0,0,0);

	agk::SetWindowTitle("Sprite Mouse");

	m_Resource.push_back(agk::LoadImage("_mouse.png"));
	m_Mouse = agk::CreateSprite(m_Resource[0]);
	m_MouseHeight = agk::GetSpriteHeight(m_Mouse);
	m_MouseWidth = agk::GetSpriteWidth(m_Mouse);

	m_Resource.push_back(agk::LoadImage("21.png"));
	m_Resource.push_back(agk::LoadImage("20.png"));
	m_On = agk::CreateSprite(m_Resource[1]);
	m_Off = agk::CreateSprite(m_Resource[2]);
	agk::SetSpritePosition(m_On, 98, 488);
	agk::SetSpritePosition(m_Off, 100, 500);

	m_Resource.push_back(agk::LoadImage("11.png"));
	m_Resource.push_back(agk::LoadImage("10.png"));
	m_Light_On = agk::CreateSprite(m_Resource[3]);
	m_Light_Off = agk::CreateSprite(m_Resource[4]);
	m_Light_Height = agk::GetSpriteHeight(m_Light_On);
	m_Light_Width = agk::GetSpriteWidth(m_Light_On);
	agk::SetSpriteAngle(m_Light_On, 180);
	agk::SetSpriteAngle(m_Light_Off, 180);
	agk::SetSpritePosition(m_Light_On, (1024 - m_Light_Width) / 2 + 1, 0);
	agk::SetSpritePosition(m_Light_Off, (1024 - m_Light_Width) / 2, 0);
	
	m_Resource.push_back(agk::LoadImage("3.png"));
	m_Background = agk::CreateSprite(m_Resource[5]);

	agk::SetSpritePosition(m_Background, 0, 0);
	agk::SetSpriteDepth(m_Background, 100);

	m_Switch = m_Off;
	m_Light = m_Light_Off;

	// 隐藏鼠标（0隐藏，1可见）
	//agk::SetRawMouseVisible(0);
}

int app::Loop (void)
{
//	agk::Print( agk::ScreenFPS() );
	// 鼠标跟踪
	unsigned int m_MouseX = agk::GetRawMouseX();
	unsigned int m_MouseY = agk::GetRawMouseY();

	agk::SetSpritePosition(m_Mouse, m_MouseX, m_MouseY);

	// 按下左键
/*	if (agk::GetRawMouseLeftPressed())
	{
		agk::SetRawMouseVisible(1);
	}
	// 按下右键
	if (agk::GetRawMouseRightPressed())
	{
		agk::SetRawMouseVisible(0);
	}
	// agk::GetRawMouseLeftReleased和agk::GetRawMouseRightRelesased函数分别判断是否松开左右键。松开1，否则0
	// agk::GetRawMousLeftState和agk::GetRawMouseMouseRightState函数分别判断是否按住左右键。站住1，否则0*/

	// agk::GetSpriteHit() 判断鼠标指针是否碰到精灵
	if (agk::GetRawMouseLeftPressed() && agk::GetSpriteHit(m_MouseX, m_MouseY) == m_Switch)
	{
		if (m_Switch == m_Off)
		{
			m_Switch = m_On;
			m_Light = m_Light_On;
			agk::SetSpriteDepth(m_Off, 11);
			agk::SetSpriteDepth(m_On, 10);
			agk::SetSpriteVisible(m_Light_On, 1);
			agk::SetSpriteVisible(m_Light_Off, 0);
		}
		else
		{
			m_Switch = m_Off;
			m_Light = m_Light_Off;
			agk::SetSpriteDepth(m_Off, 10);
			agk::SetSpriteDepth(m_On, 11); 
			agk::SetSpriteVisible(m_Light_On, 0);
			agk::SetSpriteVisible(m_Light_Off, 1);
		}
	}

	agk::Sync();

	return 0; // return 1 to close app
}


void app::End (void)
{

}
