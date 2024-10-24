#pragma once

class GameManager
{
	DECLARE_SINGLETON(GameManager);

public:
	void Init();
	void Update();
	void Render();
	void Release();

	void CalculateTime(sf::Time& dt);

	float GetTime() const { return time; }
	float GetDeltaTime() const { return deltaTime; }
	float GetRealTime() const { return realTime; }
	float GetRealDeltaTime() const { return realDeltaTime; }
	float GetTimeScale() const { return timeScale; }
	float GetScore() const { return score; }

	void SetTimeScale(const float newTimeScale) { timeScale = newTimeScale; }
	void SetScore(const float amount) { score += amount; }
	
	bool IsLive() { return isLive; }
	bool IsSpriteCollision(GameObject* obj1, GameObject* obj2);

private:
	float time;
	float deltaTime;
	float realTime;
	float realDeltaTime;
	float timeScale;

	float score;

	bool isLive;
};