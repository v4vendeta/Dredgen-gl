#pragma once
#include <cstdint>
#include "Light.h"
#include <vector>
#include <memory>
#include "Shader.h"
#include <unordered_map>
#include <string>
#include "Model.h"
class Shadowpass
{
public:
	Shadowpass() = default;
	Shadowpass(std::shared_ptr<Light> light);
	~Shadowpass();
	uint32_t GetShadowTex()const;
	void Draw(std::unordered_map <std::string,std::shared_ptr<Model>>& scene);
private:
	uint32_t shadow_fbo, shadow_tex;
	const uint32_t width = 512, height = 512;
	std::shared_ptr<Shader> shadowshader{};
};