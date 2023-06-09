#ifndef EDITORCAMERA_H
#define EDITORCAMERA_H

#include <glm/glm.hpp>

#include "Runtime/Core/Utils/Timestep.hpp"
#include "Runtime/Application/Camera/Camera.hpp"
#include "Runtime/Application/Event/Event.hpp"
#include "Runtime/Application/Event/MouseEvent.hpp"

namespace JEngine 
{
	class EditorCamera : public Camera
	{
	public:
		EditorCamera() = default;
		EditorCamera(float fov, float aspectRatio, float nearClip, float farClip);

		void OnUpdate(Timestep ts);
		void OnEvent(Event& e);

		[[nodiscard]] inline float GetDistance() const { return mDistance; }
		inline void SetDistance(float distance) { mDistance = distance; }

		inline void SetViewportSize(float width, float height) { mViewportWidth = width; mViewportHeight = height; UpdateProjection(); }

		[[nodiscard]] const glm::mat4& GetViewMatrix() const { return mViewMatrix; }
		[[nodiscard]] glm::mat4 GetViewProjection() const { return mProjection * mViewMatrix; }

		[[nodiscard]] glm::vec3 GetUpDirection() const;
		[[nodiscard]] glm::vec3 GetRightDirection() const;
		[[nodiscard]] glm::vec3 GetForwardDirection() const;
		[[nodiscard]] const glm::vec3& GetPosition() const { return mPosition; }
		[[nodiscard]] glm::quat GetOrientation() const;
					  
		[[nodiscard]] float GetPitch() const { return mPitch; }
		[[nodiscard]] float GetYaw() const { return mYaw; }

		[[nodiscard]] float GetNearPlane() const { return mNearClip; }
		[[nodiscard]] float GetFarPlane() const { return mFarClip; }

		[[nodiscard]] float GetFOV() const { return mFOV; }
		[[nodiscard]] float GetAspect() const { return mAspectRatio; }

		void SetCenter(const glm::vec3& center);
	private:
		void UpdateProjection();
		void UpdateView();

		bool OnMouseScroll(MouseScrolledEvent& e);

		void MousePan(const glm::vec2& delta);
		void MouseRotate(const glm::vec2& delta);
		void MouseZoom(float delta);

		glm::vec3 CalculatePosition() const;

		std::pair<float, float> PanSpeed() const;
		float RotationSpeed() const;
		float ZoomSpeed() const;
	public:
		float mCameraSpeed = 1.0f;
	private:
		float mFOV = 45.0f, mAspectRatio = 1.778f, mNearClip = 0.1f, mFarClip = 1000.0f;

		glm::mat4 mViewMatrix;
		glm::vec3 mPosition = { 0.0f, 0.0f, 0.0f };
		glm::vec3 mFocalPoint = { 0.0f, 0.0f, 0.0f };

		glm::vec2 mInitialMousePosition = { 0.0f, 0.0f };

		float mDistance = 10.0f;
		float mPitch = 0.0f, mYaw = 0.0f;

		float mViewportWidth = 1280, mViewportHeight = 720;

		bool bInit = true;
	};
}


#endif //!EDITORCAMERA_H