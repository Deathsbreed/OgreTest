#include <iostream>

#include <Ogre.h>

int main() {
	std::string resourcePath = "../assets/";

	Ogre::Root *root = new Ogre::Root(resourcePath + "plugins.cfg", resourcePath + "ogre.cfg", "Ogre.log");

	if(!root->showConfigDialog()) return 1;

	Ogre::ConfigFile cf;
	cf.load(resourcePath + "resources.cfg");

	Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();

	Ogre::String secName, typeName, archName;
	while(seci.hasMoreElements()) {
		secName = seci.peekNextKey();
		Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
		Ogre::ConfigFile::SettingsMultiMap::iterator itr;

		for(itr = settings->begin(); itr != settings->end(); itr++) {
			typeName = itr->first;
			archName = itr->second;

			Ogre::ResourceGroupManager::getSingleton().addResourceLocation(archName, typeName, secName);
		}
	}

	Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

	Ogre::RenderWindow* window = root->initialise(true);
	Ogre::SceneManager* smgr = root->createSceneManager(Ogre::ST_GENERIC);

	// INPUT
	size_t windowHnd = 0;
	window->getCustomAttribute("WINDOW", &windowHnd);
	
	while(true) {
		Ogre::WindowEventUtilities::messagePump();

		if(root->renderOneFrame() == false) break;
	}

	delete root;
	return 0;
}
