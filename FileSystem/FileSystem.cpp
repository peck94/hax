#include "FileSystem.h"
using namespace std;
using namespace sel;

FileSystem::FileSystem(Computer* computer) {
    this->computer = computer;
    root = new Directory("/");
    dir = root;

    dir->addDirectory(new Directory("/home"));
    dir->addDirectory(new Directory("/var"));
    dir->addDirectory(new Directory("/bin"));
    dir->addDirectory(new Directory("/etc"));

    dir->getDirs()["/etc"]->addFile("passwd", "");
    dir->getDirs()["/etc"]->addFile("hosts", "");
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

void FileSystem::ls() {
    for(auto p: dir->getDirs()) {
        computer->run("print(\"" + p.first + "\")");
    }
    for(auto p: dir->getFiles()) {
        computer->run("print(\"" + p.first + "\")");
    }
}

std::string FileSystem::cat(std::string name) {
    if(dir->getFiles().find(name) == dir->getFiles().end()) {
        return "";
    }else{
        return dir->getFiles()[name];
    }
}

FileSystem::~FileSystem() {
    delete root;
}

Directory *FileSystem::getRoot() {
    return root;
}

Directory *FileSystem::getCurrent() {
    return dir;
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

void Directory::addFile(std::string name, std::string contents) {
    files[name] = contents;
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

std::map<std::string, std::string> Directory::getFiles() {
    return files;
}
