#pragma once
#include <vector>
#include <string>
#include "EntityLoader.h"
class SaveInterface
{
	std::string saveLoadPath;
protected:
	inline void setSaveLoadPath(std::string slPath) { saveLoadPath = slPath; }
	inline std::string getSaveLoadPath(std::string slPath) { return saveLoadPath; }
public:
	SaveInterface();
	~SaveInterface();
	SaveInterface(const SaveInterface& save) = delete;
	SaveInterface(SaveInterface&& save) = delete;
	SaveInterface& operator=(const SaveInterface& save) = delete;
	SaveInterface& operator=(SaveInterface&& save) = delete;

	virtual void save() = 0;
	virtual void load() = 0;
};

