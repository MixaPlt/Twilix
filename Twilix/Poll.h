#pragma once
class Poll
{
	struct Type
	{
		unsigned int val;
		bool operator == (const Type &a)
		{
			if (a.val == val)
				return 1;
			return 0;
		}
		bool operator == (unsigned int &a)
		{
			if (a == val)
				return 1;
			return 0;
		}
		void operator = (const unsigned int &a)
		{
			val = a;
		}
		Type(const unsigned int &a)
		{
			val = a;
		}
	};

public:
	Poll(const Type &type);
	~Poll();
	Type type;
	static const Type Closed;
};

