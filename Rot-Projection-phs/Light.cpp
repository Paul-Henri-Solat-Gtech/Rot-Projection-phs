#include "Light.h"

Light::Light(Settings settings)
{
	m_lightVertex.x = 0.f;
	m_lightVertex.y = 0.f;
	m_lightVertex.z = 0.f;

	float nx = settings.GetLightDirectionX();
	float ny = settings.GetLightDirectionY();
	float nz = settings.GetLightDirectionZ();

	m_lightVertex.nx = nx;
	m_lightVertex.ny = ny;
	m_lightVertex.nz = nz;
}