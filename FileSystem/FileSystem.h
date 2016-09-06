//
// Created by pecky on 9/6/16.
//

#ifndef HAX_FILESYSTEM_H
#define HAX_FILESYSTEM_H

#include <string>
#include <map>
#include <vector>

class FileSystem {
private:
    /*
     * Current directory.
     */
    Directory* dir;

public:
    /**
     * Initialize.
     */
    FileSystem();

    /**
     * Commands exposed to scripts.
     */
    std::string pwd();
    bool cd(std::string name);
    std::vector<std::string> ls();
    std::string cat(std::string name);
};

class Directory {
private:
    /*
     * Name of this directory.
     */
    std::string name;

    /*
     * List of files in this directory.
     */
    std::vector<std::string> files;

    /*
     * List of directories in this directory.
     */
    std::map<std::string, Directory*> dirs;

public:
    /**
     * Directory ctor.
     */
    Directory(std::string name);

    /**
     * Getters.
     */
    std::string getName();

    /**
     * Commands.
     */
    void addDirectory(Directory* dir);
    void addFile(std::string name);
    void setParent(Directory* dir);
    std::map<std::string, Directory*> getDirs();

    /**
     * Directory dtor.
     * Destroys all subdirs.
     */
    ~Directory();
};


#endif //HAX_FILESYSTEM_H
