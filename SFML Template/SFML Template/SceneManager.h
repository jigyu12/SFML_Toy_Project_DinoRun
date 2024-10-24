#pragma once

class SceneManager
{
	DECLARE_SINGLETON(SceneManager);

public:
	void Init();
	void Update(float dt);
	void Render(sf::RenderWindow& window);
	void Release();

	SceneIds GetCurrentSceneId() const { return currentSceneId; }
	Scene* GetCurrentScene() const { return currentScene; }
	void ChangeScene(SceneIds id);

private:
	std::vector<Scene*> scenes;

	SceneIds startSceneId;
	SceneIds currentSceneId;

	Scene* currentScene;
};