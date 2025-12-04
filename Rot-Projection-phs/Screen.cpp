#include "Screen.h"

Screen::Screen(Settings settings) : _settings(settings)
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
            std::cout << m_pixels[y * _settings.GetScreenW() + x];
        }
        std::cout << "\n";
    }

    _settings.PrintInfo();
}

void Screen::DrawMesh(Mesh const& mesh)
{
    for (Vertex v : mesh.GetVertices())
    {
        // Evite division par 0, provisoire si pas encore de vraie projection
        if (v.z == 0) v.z = 1;

        // Projection 1:1 simple + recentrage dans l'écran
        v.x = v.x * _settings.GetScreenPosition() + (_settings.GetScreenW() * 0.5f);
        v.y = v.y * _settings.GetScreenPosition() + (_settings.GetScreenH() * 0.5f);

        int u = std::round(v.x);
        int j = std::round(v.y);
        float ooz = 1.0f / v.z;

        if (u >= 0 && u < _settings.GetScreenW() &&
            j >= 0 && j < _settings.GetScreenH())
        {
            int idx = j * _settings.GetScreenW() + u;

            if (ooz > m_oozBuffer[idx]) // Z-buffer ASCII
            {
                m_oozBuffer[idx] = ooz;
                m_pixels[idx] = _settings.GetScreenMeshProjection();
            }
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
