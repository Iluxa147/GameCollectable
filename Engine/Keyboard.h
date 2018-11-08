#pragma once
#include <queue>
#include <bitset>

class Keyboard
{
	friend class MainWindow;
	
public:
	class Event
	{
	public:
		enum Type
		{
			Press,
			Release,
			Invalid
		};

	private:
		Type type_;
		unsigned char code_;

	public:
		Event() :
			type_(Invalid),
			code_(0u)
		{}

		Event(Type type, unsigned char code) :
			type_(type),
			code_(code)
		{}

		bool IsPress() const
		{
			return type_ == Press;
		}

		bool IsRelease() const
		{
			return type_ == Release;
		}

		bool IsValid() const
		{
			return type_ != Invalid;
		}
		unsigned char GetCode() const
		{
			return code_;
		}
	};

public:
	Keyboard() = default;
	Keyboard(const Keyboard&) = delete;
	Keyboard& operator = (const Keyboard&) = delete;
	bool IsKeyPressed(unsigned char keycode) const;
};