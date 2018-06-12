#pragma once
class efekt_wizualny:public Drawable
{
protected:
	Texture texture;
	Sprite sprite;
	Clock frame_Time;
public:
	virtual void next_frame() = 0;
	efekt_wizualny();
	~efekt_wizualny();
	void draw(RenderTarget &target, RenderStates state)const override;	
};