#pragma once
class Poll
{
public:
	Poll(unsigned int event);
	~Poll();
	unsigned int event;
	static const unsigned int Exit = 0;
	static const unsigned int MainMenuItemSelected = 1;
};

