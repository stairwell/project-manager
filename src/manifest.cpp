#include <fstream>
#include <libconfig.h++>
#include <manifest.h>
#include <config.h>

pm::manifest::manifest() {

}

pm::manifest::~manifest() {

}

bool pm::manifest::create_new_manifest(std::string path) {
	libconfig::Config cfg;
	libconfig::Setting& root = cfg.getRoot();

	root.add("version", libconfig::Setting::TypeString) = PACKAGE_VERSION;

	libconfig::Setting& project = root.add("project", libconfig::Setting::TypeGroup);

	project.add("files", libconfig::Setting::TypeList);

	try {
		cfg.writeFile(path.c_str());
		return true;
	} catch(const libconfig::FileIOException &fioex) {
	
	}
	return false;
}