//
// Created by pecky on 9/6/16.
//

#include "FileSystem.h"
using namespace std;

FileSystem::FileSystem() {

}

std::string FileSystem::pwd() {
    return dir->getName();
}

bool FileSystem::cd(std::string name) {
    if(dir->getDirs().find(name) != dir->getDirs().end()) {
        dir = dir->getDirs()[name];
        return true;
    }else{
        return false;
    }
}

std::vector<std::string> FileSystem::ls() {
    vector<string> names;
    for(auto p: dir->getDirs()) {
        names.push_back(p.first);
    }

    return names;
}

std::string FileSystem::cat(std::string name) {
    return "lol";
}

std::string Directory::getName() {
    return name;
}

Directory::Directory(string name) {
    this->name = name;
}

Directory::~Directory() {
    for(auto p: dirs) {
        delete p.second;
    }
}

void Directory::addFile(std::string name) {
    files.push_back(name);
}

void Directory::addDirectory(Directory *dir) {
    dirs[dir->getName()] = dir;
    dir->setParent(this);
}

void Directory::setParent(Directory *dir) {
    dirs[".."] = dir;
}

std::map<std::string, Directory *> Directory::getDirs() {
    return dirs;
}
