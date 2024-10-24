#pragma once

class Scene
{
public:
	Scene(SceneIds sceneId);
	virtual ~Scene() = default;

	virtual void Init();
	virtual void Update(float dt);
	virtual void Render(sf::RenderWindow& window);
	virtual void Release();

	virtual GameObject* AddGameObject(GameObject* obj);
	virtual void RemoveGameObjectSingle(GameObject* obj);
	virtual int RemoveGameObjectAll(const std::string& name, std::list<GameObject*>& objectList);
	virtual GameObject* FindGameObjectSingle(const std::string& name);
	virtual int FindGameObjectAll(const std::string& name, std::list<GameObject*>& objectList);

protected:
	const SceneIds sceneId;
	std::list<GameObject*> gameObjectList;
};