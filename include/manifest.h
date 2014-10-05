#ifndef MANIFEST_H
#define MANIFEST_H

#include <iostream>

namespace pm {
	/**
	*
	*/
	class manifest {
	public:
		/**
		*
		*/
		manifest();

		/**
		*
		*/
		virtual ~manifest();

		/**
		*
		*/
		static bool create_new_manifest(std::string path);
	private:
		static const char default_manifest[];
	};
};

#endif