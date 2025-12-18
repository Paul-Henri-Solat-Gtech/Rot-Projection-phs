#include "Screen.h"

Screen::Screen(Settings settings) : _settings(settings), 
m_pixels(_settings.GetScreenW()* _settings.GetScreenH(), '.'),
m_oozBuffer(_settings.GetScreenW()* _settings.GetScreenH(), 0.f)
{
    int size = _settings.GetScreenW() * _settings.GetScreenH();
    m_pixels.resize(size, _settings.GetScreenBackground());
    m_oozBuffer.resize(size, 0.0f);
}

void Screen::ResetBuffers()
{
    std::fill(m_pixels.begin(), m_pixels.end(), _settings.GetScreenBackground());
    std::fill(m_oozBuffer.begin(), m_oozBuffer.end(), 0.0f);
}

void Screen::Display()
{
    // Affiche le contenu de m_pixels
    for (int y = 0; y < _settings.GetScreenH(); y++)
    {
        for (int x = 0; x < _settings.GetScreenW(); x++)
        {
            std::cout << m_pixels[_settings.GetScreenW() * y + x];
        }
        std::cout << std::endl;
    }

    //_settings.PrintInfo();
}

void Screen::Display(Mesh const& mesh)
{
    std::fill(m_pixels.begin(), m_pixels.end(), _settings.GetScreenBackground());
    DrawMesh(mesh);
    Display();
}

void Screen::DrawMesh(Mesh const& mesh, Light const& light)
{
    std::fill(m_oozBuffer.begin(), m_oozBuffer.end(), 0.f);
    for (Vertex vertex : mesh.GetVertices())
    {
        _ProjectInCenterScreenSpace(vertex);
        _ProjectInTopLeftScreenSpace(vertex);
        int u = std::round(vertex.x);
        int v = std::round(vertex.y);
        float ooz = 1.f / vertex.z;

        if (_IsVertexInScreen(u, v) && ooz > m_oozBuffer[v * _settings.GetScreenW() + u])
        {
            float L = vertex.ComputeIllumination(light);
            if (L>0) 
            {
                m_pixels[v * _settings.GetScreenW() + u] = ".,-~:;=!*#$@"[(int)(L*12)];
            }

            m_oozBuffer[v * _settings.GetScreenW() + u] = ooz;
            //m_pixels[v * _settings.GetScreenW() + u] = _settings.GetScreenMeshProjection();
        }
    }
}

void Screen::Clear()
{
    std::string ansi_clear = "\033[2J";
    std::string ansi_firstPos = "\033[H";
    std::string ansi_hideCursor = "\033[?25l";

    printf(ansi_clear.c_str());
    printf(ansi_firstPos.c_str());
    printf(ansi_hideCursor.c_str());
}

void Screen::_ProjectInCenterScreenSpace(Vertex& vertex)
{
    vertex.z += _settings.GetMeshPosition();
    vertex.x = _settings.GetScreenPosition() * vertex.x / vertex.z;
    vertex.y = _settings.GetScreenPosition() * vertex.y / vertex.z / 2.f;
}

void Screen::_ProjectInTopLeftScreenSpace(Vertex& vertex)
{
    vertex.x += _settings.GetScreenW() / 2;
    vertex.y += _settings.GetScreenH() / 2;
}

bool Screen::_IsVertexInScreen(int u, int v)
{
    return u >= 0 && u < _settings.GetScreenW() && v >= 0 && v < _settings.GetScreenH();
}
