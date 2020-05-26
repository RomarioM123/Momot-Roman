#pragma once
class PointerCount
{
private:
	int pointerCount = 0;

public:
	void Increment() { ++pointerCount; }

	int Decrement() { return --pointerCount; }

	int GetPointerCount() const { return pointerCount; }
};

