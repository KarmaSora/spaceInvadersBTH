#pragma once

#include <map>
#include <memory>
#include <string>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

using namespace std;

namespace Engine {
	class AssetManager {
	private:
		map<int, unique_ptr<sf::Texture>> m_textures;
		map<int, unique_ptr<sf::Font>> m_fonts;
	public:
		AssetManager();
		~AssetManager();

		// Function to add a texture to the manager.
		// Parameters:
		//   - id: Unique identifier for the texture.
		//   - file: File path to the texture.
		//   - wantRepeated: Optional flag for repeated texture sampling (default is false).
		void addTexture(int id, const string& file, bool wantRepated = false);
		void addFont(int id, const string& file); //Adds a font to the manager

		const sf::Texture& getTexture(int id) const;
		const sf::Font& getFont(int id) const;
	};
}