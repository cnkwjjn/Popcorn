﻿#pragma once

#include "Falling_Letter.h"
#include "Ball.h"


class ALevel: public AHit_Checker
{
public:
	ALevel();

	virtual bool Check_Hit(double next_x_pos, double next_y_pos, ABall *ball);

	void Init();
	void Set_Current_Level(char level[AsConfig::Level_Height][AsConfig::Level_Width]);
	void Act();
	void Draw(HDC hdc, RECT &paint_area);
	bool Get_Falling_Letter(int &index, AFalling_Letter **falling_letter);

	//AActive_Brick Active_Brick;
	static char Level_01[AsConfig::Level_Height][AsConfig::Level_Width];
	static char Test_Level[AsConfig::Level_Height][AsConfig::Level_Width];

private:
	void On_Hit(int brick_x, int brick_y);
	bool Add_Falling_Letter(int brick_x, int brick_y, EBrick_Type brick_type);
	void Add_Active_Brick(int brick_x, int brick_y, EBrick_Type brick_type);
	bool Check_Vertical_Hit(double next_x_pos, double next_y_pos, int level_x, int level_y, ABall *ball, double &reflection_pos);
	bool Check_Horizontal_Hit(double next_x_pos, double next_y_pos, int level_x, int level_y, ABall *ball, double &reflection_pos);
	void Draw_Brick(HDC hdc, RECT& brick_rect, EBrick_Type brick_type);
	void Draw_Graphic_Object(HDC hdc, RECT& paint_area, AGraphics_Objects** graphics_obj_array, int max_obj_count);
	void Act_Object(AGraphics_Objects** graphics_obj_array, int max_obj_count);

	RECT Level_Rect;

	double Current_Brick_Left_X, Current_Brick_Right_X;
	double Current_Brick_Top_Y, Current_Brick_Low_Y;

	char Current_Level[AsConfig::Level_Height][AsConfig::Level_Width];
	int Active_Bricks_Count;
	AActive_Brick *Active_Bricks[AsConfig::Max_Active_Bricks_Count];
	int Falling_Letters_Count;
	AFalling_Letter *Falling_Letters[AsConfig::Max_Falling_Letters_Count];
};
//------------------------------------------------------------------------------------------------------------
