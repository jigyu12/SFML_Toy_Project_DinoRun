#pragma once

template<typename T>
class ResourceManager
{
public:
	static ResourceManager& GetInstance()
	{													
		static ResourceManager instance;
		return instance;								
	}

	void Init()
	{
		Release();
	}

	void Update()
	{

	}

	void Render()
	{

	}

	void Release()
	{
		for (const auto& pair : resources)
		{
			delete pair.second.second;
		}
		resources.clear();
	}

	bool Load(const std::string& id, const std::string& path)
	{
		if (resources.find(id) != resources.end())
			return false;

		T* resource = new T();
		bool success = resource->loadFromFile(path);

		if (success)
			resources.insert({ id, std::make_pair(path, resource) });
		else
			delete resource;

		return success;
	}

	bool Unload(const std::string& id)
	{
		auto iter = resources.find(id);

		if (iter == resources.end())
			return false;

		delete iter->second.second;
		resources.erase(iter);

		return true;
	}

	T& Get(const std::string& id)
	{
		T none;
		auto iter = resources.find(id);

		if (iter == resources.end())
		{
			return none;
		}

		return *(iter->second.second);
	}

private:
	ResourceManager() {}
	ResourceManager(const ResourceManager&) {}
	ResourceManager& operator=(const ResourceManager&) {}
	~ResourceManager() 
	{
		Release();
	}

	std::unordered_map<std::string, std::pair<std::string ,T*>> resources;
};