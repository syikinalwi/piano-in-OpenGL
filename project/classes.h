#include "initials.h"

class Piano
{
private:
public:
	Piano();
	void whiteKey(double nextkey);
	void blackKey(double nextkey);
	void movePiano();
};

class Hand
{
private:

public:
	Hand();
	void drawHandLeft();
	void drawHandRight();
	void leftFingers1();
	void leftFingers2();
	void leftFingers3();
	void leftFingers4();
	void rightFingers1();
	void rightFingers2();
	void rightFingers3();
	void rightFingers4();
};