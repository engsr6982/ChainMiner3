// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Core.hpp"

#define BEFORE_EXTRA

#undef BEFORE_EXTRA

struct FileInfo {

#define AFTER_EXTRA

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_FILEINFO
public:
    struct FileInfo& operator=(struct FileInfo const &) = delete;
    FileInfo(struct FileInfo const &) = delete;
    FileInfo() = delete;
#endif

public:
    MCAPI FileInfo(class Core::Path, int, std::string);
    MCAPI ~FileInfo();

protected:

private:

};