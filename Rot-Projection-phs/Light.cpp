#include <cmath>
#include "Light.h"
#include "Settings.h"

Light::Light(Settings settings)
{
    // No need to position light because we only need light direction
    m_lightVertex.x = 0.f;
    m_lightVertex.y = 0.f;
    m_lightVertex.z = 0.f;

    float nx = settings.GetLightDirectionX();
    float ny = settings.GetLightDirectionY();
    float nz = settings.GetLightDirectionZ();
    float directionNorm = std::sqrt(nx * nx + ny * ny + nz * nz);
    if (directionNorm != 0.f)
    {
        m_lightVertex.nx = nx / directionNorm;
        m_lightVertex.ny = ny / directionNorm;
        m_lightVertex.nz = nz / directionNorm;
    }
}