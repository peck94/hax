//
// Created by pecky on 9/6/16.
//

#ifndef HAX_FILESYSTEM_H
#define HAX_FILESYSTEM_H

#include <string>
#include <map>
#include <vector>
#include "../Computer/Computer.h"

class Computer;

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

    /**state(line.c_str());
     * Directory dtor.
     * Destroys all subdirs.
     */
    ~Directory();
};

class FileSystem {
private:
    /*
     * Current directory.
     */
    Directory* dir;

    /*
     * Root directory.
     */
    Directory* root;

    /*
     * Computer that hosts this file system.
     */
    Computer* computer;

public:
    /**
     * Initialize.
     */
    FileSystem(Computer* computer);

    /**
     * Commands exposed to scripts.
     */
    std::string pwd();
    bool cd(std::string name);
    void ls();
    void cat(std::string name);

    /**
     * Getters.
     */
    Directory* getRoot();
    Directory* getCurrent();

    /**
     * FileSystem dtor.
     */
    ~FileSystem();
};


#endif //HAX_FILESYSTEM_H
