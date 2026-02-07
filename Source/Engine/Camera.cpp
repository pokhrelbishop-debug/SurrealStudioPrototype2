// Camera.cpp
#include "Camera.h"

namespace SurrealStudio {

    Camera::Camera(const glm::vec3& startPosition, const glm::vec3& startUp, float startYaw, float startPitch) noexcept
    {
        m_Position = startPosition;
        m_Up = startUp;
        m_Yaw = startYaw;
        m_Pitch = startPitch;

        m_MovementSpeed = 5.0f;
        m_MouseSensitivity = 0.1f;

        UpdateCameraVectors();
    }

    void Camera::MoveForward(float deltaTime) noexcept
    {
        float velocity = m_MovementSpeed * deltaTime;
        m_Position += m_Direction * velocity;
    }

    void Camera::MoveRight(float deltaTime) noexcept
    {
        float velocity = m_MovementSpeed * deltaTime;
        m_Position += m_Right * velocity;
    }

    void Camera::MoveUp(float deltaTime) noexcept
    {
        float velocity = m_MovementSpeed * deltaTime;
        m_Position += m_Up * velocity;
    }

    void Camera::Rotate(float deltaYaw, float deltaPitch) noexcept
    {
        m_Yaw += deltaYaw * m_MouseSensitivity;
        m_Pitch += deltaPitch * m_MouseSensitivity;

        // Clamp pitch to avoid flipping
        if (m_Pitch > glm::radians(89.0f))
        {
            m_Pitch = glm::radians(89.0f);
        }
        if (m_Pitch < glm::radians(-89.0f))
        {
            m_Pitch = glm::radians(-89.0f);
        }

        UpdateCameraVectors();
    }

    void Camera::UpdateCameraVectors() noexcept
    {
        // Compute new direction
        m_Direction.x = glm::cos(m_Yaw) * glm::cos(m_Pitch);
        m_Direction.y = glm::sin(m_Pitch);
        m_Direction.z = glm::sin(m_Yaw) * glm::cos(m_Pitch);
        m_Direction = glm::normalize(m_Direction);

        // Recompute Right and Up vectors
        m_Right = glm::normalize(glm::cross(m_Direction, m_Up));
        m_Up = glm::cross(m_Right, m_Direction);
    }

    glm::mat4 Camera::GetViewMatrix() const noexcept
    {
        glm::vec3 target = m_Position + m_Direction;
        return glm::lookAt(m_Position, target, m_Up);
    }
}
