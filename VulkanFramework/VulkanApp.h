#pragma once
#include "VulkanBaseApp.h"
#include "glm/glm.hpp"
namespace vkw {
	class Buffer;
	class Texture;
}
class VulkanApp : vkw::VulkanBaseApp
{
public:
	VulkanApp(vkw::VulkanDevice* pDevice);
	~VulkanApp();
	void Render() override;
	bool Update(float dTime) override;
	void Init(float width, float height) override;
	void Cleanup() override;

private:
	void CreateStorageBuffers();
	void CreateUniformBuffers();
	void UpdateUniformBuffers();
	void CreateTextureTarget();
	void CreateGraphicsPipeline();
	void CreateDescriptorPool();
	void CreateDescriptorSet();
	void CreateComputePipeline();
	void BuildDrawCommandBuffers();
	void BuildComputeCommandBuffers();


	void DestroyStorageBuffers();
	void DestroyUniformBuffers();
	void DestroyTextureTarget();
	void DestroyGraphicsPipeline();
	void DestroyDescriptorPool();
	void DestroyComputePipeline();

	vkw::Buffer*			m_pSphereGeomBuffer = nullptr;
	vkw::Buffer*			m_pPlaneGeomBuffer = nullptr;
	vkw::Buffer*			m_pTriangleGeomBuffer = nullptr;

	vkw::Buffer*			m_pUniformBuffer = nullptr;

	vkw::Texture*			m_pTexture = nullptr;

	struct Sphere {									
		glm::vec3 pos;
		float radius;
		glm::vec3 diffuse;
		float specular;
		uint32_t id;								
		glm::ivec3 _pad;
	};

	struct Plane {
		glm::vec3 normal;
		float distance;
		glm::vec3 diffuse;
		float specular;
		uint32_t id;
		glm::ivec3 _pad;
	};

	struct Triangle
	{
		glm::vec3 p1;
		int id;
		glm::vec3 p2;
		float specular;
		glm::vec3 p3;
		int pad1;
		glm::vec3 normal;
		int pad2;
		glm::vec3 diffuse;
		int pad3;
	};

	struct UBOCompute {
		glm::vec3 lightPos;
		float aspectRatio = 800.f/600.f;						
		glm::vec4 fogColor{0.f, 0.f, 0.f, 0.f};
	
		glm::vec3 pos = { 0.0f, 0.0f, 4.0f };
		glm::vec3 lookat {0.0f, 0.5f, 0.0f};
		float fov = 10.0f;

	} m_UniformBufferData;


	VkPipeline				m_GraphicsPipeline = VK_NULL_HANDLE;
	VkPipelineLayout		m_GraphicsPipelineLayout = VK_NULL_HANDLE;
	VkDescriptorSetLayout	m_GraphicsDescriptorSetLayout = VK_NULL_HANDLE;
	VkDescriptorSet			m_GraphicsDescriptorSet = VK_NULL_HANDLE;

	VkDescriptorPool		m_DescriptorPool = VK_NULL_HANDLE;

	VkQueue					m_ComputeQueue = VK_NULL_HANDLE;
	VkPipeline				m_ComputePipeline = VK_NULL_HANDLE;
	VkPipelineLayout		m_ComputePipelineLayout;
	VkCommandPool			m_ComputeCommandPool = VK_NULL_HANDLE;
	VkCommandBuffer			m_ComputeCommandBuffer = VK_NULL_HANDLE;
	VkFence					m_ComputeFence = VK_NULL_HANDLE;
	VkDescriptorSet			m_ComputeDescriptorSet = VK_NULL_HANDLE;
	VkDescriptorSetLayout	m_ComputeDescriptorSetLayout = VK_NULL_HANDLE;

	float					m_AccuTime{};
};

