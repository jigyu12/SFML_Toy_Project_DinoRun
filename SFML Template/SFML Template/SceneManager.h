#pragma once

class SceneManager
{
	DECLARE_SINGLETON(SceneManager);

public:
	void Init();
	void Update(float dt);
	void Render(sf::RenderWindow& window);
	void Release();

	SceneIds GetCurrentScene() const { return currentScene; }
	void ChangeScene(SceneIds id);

private:
	std::vector<Scene*> scenes;

	SceneIds startScene;
	SceneIds currentScene;
};