#pragma once

#define DECLARE_SINGLETON(classname)					\
private:												\
	classname() {}										\
	classname(const classname&) {}						\
	classname& operator=(const classname&) {}			\
	~classname() {}										\
														\
public:													\
	static classname& GetInstance()						\
	{													\
		static classname instance;						\
		return instance;								\
	}

#define GET_SINGLETON(classname) (classname::GetInstance())

#define TEX_MANAGER (ResourceManager<sf::Texture>::GetInstance())
#define FONT_MANAGER (ResourceManager<sf::Font>::GetInstance())