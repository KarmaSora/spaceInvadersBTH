#include "AssetManager.h"

Engine::AssetManager::AssetManager()
{
}

Engine::AssetManager::~AssetManager()
{
}

void Engine::AssetManager::addTexture(int id, const string& file, bool wantRepated)
{
    auto texture = make_unique < sf::Texture>();

    if (texture->loadFromFile(file)) {
        texture->setRepeated(wantRepated);
        m_textures[id] = move(texture);
    }
}

void Engine::AssetManager::addFont(int id, const string& file)
{
    auto font = make_unique<sf::Font>();

    if (font->loadFromFile(file)) {
        m_fonts[id] = move(font);
    }
}

const sf::Texture& Engine::AssetManager::getTexture(int id) const
{
    return *(m_textures.at(id).get());
}

const sf::Font& Engine::AssetManager::getFont(int id) const
{
    return *(m_fonts.at(id).get());
}
